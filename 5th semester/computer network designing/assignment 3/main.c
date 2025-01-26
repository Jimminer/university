// N -> Omades xriston
// C -> Miki kimatos
// T -> Monades evrous zonis
// K -> Arithmos ipiresion

// band -> Apaitisis evrous zonis
// service -> Rithmos eksipiretisis
// A -> Fortio kinisis
// Q ->
// L -> Rithmoi afksisis
// j -> Katelimena miki kimatos

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double EMLM(int jj, int N1, int T1, double L[], double service[], int band[]);
double factorial(int n);

int main() {
    int N, C, T, K;
    double lambda;
    int *band;
    double *A, *L, *service;
    double temp1, *temp2, *temp3, temp4;
    double Q = 0;
    double *P;

    FILE *fp;
    fp = fopen("input.txt", "r");
    fscanf(fp, "%i", &N);
    fscanf(fp, "%i", &C);
    fscanf(fp, "%i", &T);
    fscanf(fp, "%i", &K);

    fclose(fp);

    band = (int *)malloc((K + 1) * sizeof(int));
    A = (double *)malloc((K + 1) * sizeof(double));
    L = (double *)malloc((K + 1) * sizeof(double));
    service = (double *)malloc((K + 1) * sizeof(double));
    temp2 = (double *)malloc((K + 1) * sizeof(double));
    temp3 = (double *)malloc((C + 1) * sizeof(double));
    P = (double *)malloc((C + 1) * sizeof(double));

    printf("N = %i\n\n", N);

    for (int i = 1; i <= K; i++) {
        printf("Input L for service %i: ", i);
        scanf("%lf", &L[i]);
        printf("Input service for service %i: ", i);
        scanf("%lf", &service[i]);
        printf("Input band for service %i: ", i);
        scanf("%i", &band[i]);
        printf("\n");

        A[i] = L[i] / service[i];
        lambda += L[i];
    }

    


    for (int i = 1; i <= K; i++) {
        // temp1 = A[i] * EMLM(0) / EMLM(band[i]);
        temp1 = A[i] * EMLM(0, N, T, L, service, band) / EMLM(band[i], N, T, L, service, band);
        temp2[i] = 0;

        for (int j = 1; j <= T; j++) {
            // temp2[i] += EMLM(j);
            temp2[i] += EMLM(j, N, T, L, service, band);
        }

        // Q += temp1 * service[i] * temp1 * (EMLM(band[i]) + temp2[i]);
        Q += temp1 * service[i] * temp1 * (EMLM(band[i], N, T, L, service, band) / temp2[i]);
    }

    temp4 = 0;
    for (int i = 0; i <= C; i++) {
        temp3[i] = 1;

        for (int j=1; j<=i; j++) {
            temp3[i] *= (N-(j-1));
        }

        temp4 += pow(lambda/Q, i) * temp3[i] / factorial(i);
    }

    for (int i = 0; i <= C; i++) {
        temp3[i] = 1;

        for (int j=1; j<=i; j++) {
            temp3[i] = temp3[i] * (N-(j-1));
        }

        P[i] = (pow((lambda/Q), i) * temp3[i]) / (temp4 * factorial(i));
    }

    
    // find the minimum wavelength in order for the loss probability to be less than 0.02


    printf("P[C] = %lf%%\n", P[C] * 100);

    for (int i = C; i >= 0; i--){
        if (P[i] < 0.02) {
            printf("\nMinimum wavelength: %i\n", i);
            break;
        }
    }

    free(band);
    free(A);
    free(L);
    free(service);
    free(temp2);
    free(temp3);
    free(P);

    return 0;
}
double EMLM(int jj, int N1, int T1, double L[], double service[], int band[]) {
    double A[3];
    double sum[T1 + 1];
    double q[200];
    double q1[T1 + 1];
    double q2[T1 + 1];
    double G;
    int K = 2;

    for (int i = 1; i <= K; i++) {
        A[i] = L[i] / service[i];
    }

    for (int j = 1; j <= T1; j++) {
        sum[j] = 0;
    }
    q[0] = 1;
    G = q[0];
    for (int i = -(N1 - T1 - 1); i <= -1; i++) {
        q[i] = 0;
    }

    for (int j = 1; j <= T1; j++) {
        for (int i = 1; i <= K; i++) {
            sum[j] = sum[j] + A[i] * band[i] * q[j - band[i]];
        }
        q[j] = sum[j] / j;
        G = G + q[j];
    }
    for (int j = 0; j <= T1; j++) {
        q1[j] = q[j] / G;
        if (jj == j) {
            q2[jj] = q1[j];
        }
    }

    return q1[jj];
}


// double EMLM(int jj, int N, int T, int K, int *band, double *L, double *service) {
//     double A[3];
//     double q[100];
//     double q1[100];
//     double q2[100];
//     double sum[100];
//     double sum2[100];

//     for (int i = 1; i <= K; i++) {
//         A[i] = L[i] / service[i];
//     }

//     for (int j = 1; j <= T; j++) {
//         sum[j] = 0;
//         sum2[j] = 0;
//     }

//     q[0] = 1;
//     double G = q[0];

//     for (int i = -(N - T - 1); i <= -1; i++) {
//         q[i] = 0;
//     }

//     for (int j = 1; j <= T; j++) {
//         for (int i = 1; i <= K; i++) {
//             sum[j] += A[i] * band[i] * q[j - band[i]];
//         }

//         q[j] = sum[j] / j;
//         G = G + q[j];
//     }

//     for (int j = 0; j <= T; j++) {
//         q1[j] = q[j] / G;

//         if (jj == j) {
//             q2[jj] = q1[j];
//         }
//     }

//     return (q1[jj]);
// }

double factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    double result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}