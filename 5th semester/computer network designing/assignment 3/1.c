#include <stdio.h>
#include <math.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
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
    // printf("q1[%i] = %lf\n", jj, q1[jj]);
    return q1[jj];
}

int main() {
    int K = 2;
    int N = 50;
    int C = 32;
    double L[K + 1];
    double service[K + 1];
    int band[K + 1];
    double A[K + 1];
    double lamda = 0;
    double y[3];
    double temp4[3];
    double serv = 0;
    double temp1[C + 1];
    double temp2;
    double temp3[C + 1];
    double P[C + 1];
    int T = 80;

    printf("N = %d\n\n", N);

    for (int i = 1; i <= K; i++) {
        printf("Input L for service %d: ", i);
        scanf("%lf", &L[i]);
        printf("Input service for service %d: ", i);
        scanf("%lf", &service[i]);
        printf("Input band for service %d: ", i);
        scanf("%d", &band[i]);
        printf("\n");
    }

    for (int i = 1; i <= K; i++) {
        A[i] = L[i] / service[i];
        printf("A[%i] = %lf\n", i, A[i]);
        lamda = lamda + L[i];
        printf("lambda: %lf\n", lamda);
    }

    for (int k = 1; k <= K; k++) {
        y[k] = (A[k] * EMLM(0, N, T, L, service, band) / EMLM(band[k], N, T, L, service, band));
        temp4[k] = 0;
        for (int j = 1; j <= T; j++) {
            temp4[k] = temp4[k] + EMLM(j, N, T, L, service, band);
        }
        serv = serv + (service[k] * y[k] * (EMLM(band[k], N, T, L, service, band) / temp4[k]));
        printf("serv: %lf\n", serv);
    }
    temp2 = 0;
    for (int i = 0; i <= C; i++) {
        temp1[i] = 1;
        for (int j = 1; j <= i; j++) {
            temp1[i] = temp1[i] * (N - (j - 1));
        }
        temp2 = temp2 + pow(lamda / serv, i) * temp1[i] / factorial(i);
        printf("temp4: %lf\n", temp2);
        printf("lambda: %lf\n", lamda);
        printf("Q: %lf\n", serv);
        printf("i: %i\n", i);
        printf("temp3[%i]: %lf\n", i, temp1[i]);
        printf("factorial(%i): %i\n", i, factorial(i));
    }
    printf("temp2: %lf\n", temp2);

    for (int i = 0; i <= C; i++) {
        temp3[i] = 1;
        for (int j = 1; j <= i; j++) {
            temp3[i] = temp3[i] * (N - (j - 1));
        }
        P[i] = (pow((lamda / serv), i) * temp3[i]) / (temp2 * factorial(i));
    }
    printf("P(C) = %.3lf%%\n", P[C]);

    return 0;
}