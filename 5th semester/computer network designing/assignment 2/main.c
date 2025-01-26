#include <stdio.h>
#include <math.h>

int factorial(int n) {
    if (n < 0){
        return -1;
    }
    if (n <= 1){
        return 1;
    }

    return n * factorial(n - 1);
}

int main() {
    int fiberCount; // F
    int wavelengthSize; // W
    long long transmissionRate; // C
    int serviceCount; // K
    long long packetLength; // length
    int usePriority;

    printf("At any time, enter '-1' or press Ctrl-C to exit the program\n\n");

    printf("Do you want to use service priority? (1 for yes, 0 for no): ");
    scanf("%i", &usePriority);
    if (usePriority != 1){
        usePriority = 0;
    }

    printf("Enter the fiber count: ");
    scanf("%i", &fiberCount);
    if (fiberCount < 0){
        printf("Exiting\n");
        return 0;
    }

    printf("Enter the wavelength size: ");
    scanf("%i", &wavelengthSize);
    if (wavelengthSize < 0){
        printf("Exiting\n");
        return 0;
    }

    printf("Enter the transmission rate (in gigabits/second): ");
    scanf("%li", &transmissionRate);
    if (transmissionRate < 0){
        printf("Exiting\n");
        return 0;
    }
    transmissionRate *= 1000 * 1000 * 1000;

    printf("Enter the service count: ");
    scanf("%i", &serviceCount);
    if (serviceCount < 0){
        printf("Exiting\n");
        return 0;
    }

    printf("Enter the packet length (in kilobytes): ");
    scanf("%li", &packetLength);
    if (packetLength < 0){
        printf("Exiting\n");
        return 0;
    }
    packetLength *= 8 * 1024;

    while(1){
        printf("\n\n    Input the data for the services\n\n");
        long long packetArrivalRate[serviceCount]; // L
        // long long packetLength[serviceCount]; // length
        double servicePriority[serviceCount];

        for (int i = 0; i < serviceCount; i++) {
            printf("    Enter the packet arrival rate for service %i: ", i + 1);
            scanf("%li", &packetArrivalRate[i]);
            if (packetArrivalRate[i] < 0){
                printf("Exiting\n");
                return 0;
            }

            // printf("    Enter the packet length for service %i (in kilobytes): ", i + 1);
            // scanf("%li", &packetLength[i]);
            // if (packetLength[i] < 0){
            //     printf("Exiting\n");
            //     return 0;
            // }
            // packetLength[i] *= 8 * 1024;

            if (usePriority){
                printf("    Enter the packet discard probability for service %i: ", i + 1);
                scanf("%lf", &servicePriority[i]);
                if (servicePriority[i] < 0){
                    printf("Exiting\n");
                    return 0;
                }
            }

            printf("\n");
        }

        long long totalPacketArrivalRate = 0; // lambda
        for (int i = 0; i < serviceCount; i++) {
            if (!usePriority){
               totalPacketArrivalRate += packetArrivalRate[i];
            }
            else{
                totalPacketArrivalRate += packetArrivalRate[i] * (1 - servicePriority[i]);
            }
        }

        double occupationRate = 0; // mu
        for (int i = 0; i < serviceCount; i++) {
            occupationRate += (double) transmissionRate / packetLength;
        }

        double P[wavelengthSize + 1];

        double P0Product = 1;
        double P0sum = 0;
        for (int n=0; n<=wavelengthSize; n++){
            P0Product = 1;
            for (int j=1; j<=n; j++){
                P0Product *= (fiberCount * wavelengthSize) - (j - 1);
            }

            P0sum += pow(totalPacketArrivalRate / occupationRate, n) * (P0Product / factorial(n));
        }

        P[0] = 1 / P0sum;

        double PiProduct = 1;
        for (int i=1; i<=wavelengthSize; i++){
            PiProduct = 1;
            for (int j=1; j<=i; j++){
                PiProduct *= (fiberCount * wavelengthSize) - (j - 1);
            }

            P[i] = pow(totalPacketArrivalRate / occupationRate, i) * (PiProduct / factorial(i)) * P[0];
        }

        if (!usePriority){
            printf("    Packet loss probability: %.2lf%%\n", P[wavelengthSize]*100);
        }
        else{
            for (int i = 0; i < serviceCount; i++) {
                printf("    Packet loss probability for service %i: %.2lf%%\n", i + 1, (P[wavelengthSize] * (1 - servicePriority[i]) + servicePriority[i]) * 100);
            }
        }
    }
}




// #include <stdio.h>
// #include <math.h>

// // Function to calculate factorial
// double factorial(int n) {
//     if (n == 0 || n == 1) {
//         return 1;
//     } else {
//         return n * factorial(n - 1);
//     }
// }

// int main() {
//     // Input parameters
//     int F, W, K;
//     double C;
//     printf("Enter values for F, W, K, C: ");
//     scanf("%d %d %d %lf", &F, &W, &K, &C);
//     C = C * 1000000;

//     // Arrays for service lengths and packet lengths
//     int L[K];
//     double length[K];

//     // Read service lengths and packet lengths
//     for (int i = 0; i < K; i++) {
//         printf("Enter values for L[%d] and length[%d]: ", i, i);
//         scanf("%d %lf", &L[i], &length[i]);
//     }

//     // Calculate lambda (total service length)
//     int lambda = 0;
//     for (int i = 0; i < K; i++) {
//         lambda += L[i];
//     }

//     // Calculate mu (total C/length[i])
//     double mu = 0.0;
//     for (int i = 0; i < K; i++) {
//         mu += (double) C / (length[i] * 8 * 1024);
//     }

//     // Initialize temporary variables
//     double temp1 = 1.0, temp2 = 0.0, temp3 = 1.0;

//     // Calculate P(0)
//     for (int n = 0; n <= W; n++) {
//         for (int j = 1; j <= n; j++) {
//             temp1 *= (F * W) - j + 1;
//         }
//         temp2 += pow(lambda / mu, n) * (temp1 / factorial(n));
//     }

//     // Calculate P(i) and PE[i] for i = 0 to W
//     double PE[W + 1];
//     for (int i = 0; i <= W; i++) {
//         for (int j = 1; j <= i; j++) {
//             temp3 *= (F * W) - j + 1;
//         }
//         PE[i] = pow(lambda / mu, i) * temp3 / temp2 * factorial(i);
//     }

//     // Calculate probability of packet loss Pen[W]
//     double PenW = PE[W];

//     // Print the result
//     printf("Probability of packet loss (Pen[W]): %f\n", PenW);

//     return 0;
// }