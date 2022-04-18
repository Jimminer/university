#include <stdio.h>

double volume(float, float, int);

int main(void)
{
double vol;
vol = volume(12.2, 5.67, 0.99);
printf("volume: %f", vol);
return 0;
}
double volume(float s1, float s2, int s3)
{
return s1 * s2 * s3;
}