#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/*
    Converts degrees to radians.
    Outputs a reduced form in the interval [0, 2*pi)
*/
double bogenmass(double degrees) {
  return (fmod(degrees, 360) * M_PI) / 180;
}

int main() {
  double degrees;
  
  // input
  printf("Degress (°): ");
  scanf("%lf", &degrees);
    
  // validate input
  if (degrees <= 0) {
    printf("Only positive numbers allowed.\n");
    return 0;
  }

  // convert and output
  printf("Radians: %lf\n", bogenmass(degrees)); 
}

