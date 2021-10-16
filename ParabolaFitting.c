/* ------------------------------------------------------------------
Project:	   Fitting a Parabola to Three Points
Class:		CS2263 with Dr. McNally
Author:		Tyler Travis
Date:       October 9th, 2020
 --------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  double Determinant(double Matrix[]);

  // Data Declaration

  double x1, y1, x2, y2, x3, y3;
  double Matrix[9];
  double A, B, C;
  double vertexX;
  double vertexY;

  // Getting user input.

  printf("Please input the first x input. (m)\n");
  scanf("%lf", & x1);
  printf("Please input the first y input. (m)\n");
  scanf("%lf", & y1);
  printf("Please input the second x input. (m)\n");
  scanf("%lf", & x2);
  printf("Please input the second y input. (m)\n");
  scanf("%lf", & y2);
  printf("Please input the third x input. (m)\n");
  scanf("%lf", & x3);
  printf("Please input the third y input. (m)\n");
  scanf("%lf", & y3);
  printf(" ");
  
  printf("\n\n\n");

  // Building Each Determinate Array (replacing each row with outputs).

  double D[9] = {
                 x1 * x1, x1, 1,
                 x2 * x2, x2, 1,
                 x3 * x3, x3, 1
                 };
                 
  double Da[9] = {
                 y1, x1, 1,
                 y2, x2, 1,
                 y3, x3, 1
                 };
  
  double Db[9] = {
                 x1 * x1, y1, 1,
                 x2 * x2, y2, 1,
                 x3 * x3, y3, 1
  };
  
  double Dc[9] = {
                 x1 * x1, x1, y1,
                 x2 * x2, x2, y2,
                 x3 * x3, x3, y3
  };

  // Data Minipulation

  // Evaluating Determinants of Each

  double DeterminantD = Determinant(D);
  double DeterminantDa = Determinant(Da);
  double DeterminantDb = Determinant(Db);
  double DeterminantDc = Determinant(Dc);

  // Evaluating A, B & C.

  A = DeterminantDa / DeterminantD;
  B = DeterminantDb / DeterminantD;
  C = DeterminantDc / DeterminantD;

  // Determining Roots 

  double root1, root2;

  // Determining if there is no roots.

  if ((pow(B, 2) - (4 * A * C)) < 0) {
    printf("You have no distinct roots.\n");
  }

  // If not, solve quadratic.
  
  else {
    
    root1 = ((-1 * B) + pow((pow(B, 2) - (4 * A * C)), .5)) / (2 * A);
    root2 = ((-1 * B) - pow((pow(B, 2) - (4 * A * C)), .5)) / (2 * A);

    // Getting Vertex Value for X, Y

    vertexX = (root1 + root2) / 2;
    vertexY = A * pow(vertexX, 2) + (B * vertexX) + C;

  }

  // Data Output
  printf("The quadratic fit is %lf^2 + %lf + %lf.\n", A, B, C);
  printf("Highest Point: %lf f(%lf) (m).\n",vertexY,vertexX);
  printf("The object will hit the ground at %lf meters.",root2);

}

// Function Called To Equate A Matrix's Determinant

double Determinant(double Matrix[]) {

  // Declaring variables to simplify code.

  double firstpart;
  double secondpart;
  double thirdpart;

  // Computing Determinant

  firstpart = Matrix[0] * ((Matrix[4] * Matrix[8]) - (Matrix[5] * Matrix[7]));
  secondpart = Matrix[1] * ((Matrix[3] * Matrix[8]) - (Matrix[5] * Matrix[6]));
  thirdpart = Matrix[2] * ((Matrix[3] * Matrix[7]) - (Matrix[4] * Matrix[6]));

  double total = firstpart - secondpart + thirdpart;

  return total;
}