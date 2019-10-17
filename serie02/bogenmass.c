#include <stdio.h>

/*
    A recursive function which subtracts 360 from a 
    given degree value until value < 360
*/
double reduce_degrees(double degrees) {
  if (degrees >= 360.) {
    return reduce_degrees(degrees - 360.);
  }
  return degrees;
}

/*
    Converts degrees to randians.
    Outputs a reduced form in the interval [0, 2*pi)
*/
double bogenmass(double degrees) {
  // round down first
  
  // no loops allowed duh
  //while (degrees > 360.) {
  //  degrees = degrees - 360.;
  //}
 
  degrees = reduce_degrees(degrees);
  
  return (degrees * 3.141592) / 180;
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
  printf("Radians: %lf\n", (degrees * 3.1415) / 180); 
}

