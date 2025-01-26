#include <math.h>
#include "funcs.h"

double yFunc1(double y0, double dt, int steps, double *results){
    if (steps == 0){
        results[steps] = y0 / (1 - dt);
        return results[steps];
    }

    results[steps] = yFunc1(y0, dt, steps-1, results) / (1 - dt);
    return results[steps];
}

double yFunc2(double y0, double dt, int steps, double *results){
    if (steps == 0){
        results[steps] = y0 + (dt * (1 + 5 * cos(5 * dt * steps)));
        return results[steps];
    }

    results[steps] = yFunc2(y0, dt, steps-1, results) + (dt * (1 + 5 * cos(5 * dt * steps)));
    return results[steps];
}