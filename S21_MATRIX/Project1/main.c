#include "s21_matrix.h"
#include <stdio.h>
#define RAND_MAX 20
#define DBL_MIN -20.0
#define DBL_MAX 20.0
void output(matrix_t *A);
double get_rand(double min, double max);

int main() {


	{
	  matrix_t A, B, R;
	  s21_create_matrix(3, 3, &B);
	  s21_create_matrix(3, 3, &A);
	  B.matrix[0][0] = 1;
	  B.matrix[0][1] = 2;
	  B.matrix[0][2] = 3;
	  B.matrix[1][0] = 0;
	  B.matrix[1][1] = 4;
	  B.matrix[1][2] = 2;
	  B.matrix[2][0] = 5;
	  B.matrix[2][1] = 2;
	  B.matrix[2][2] = 1;
	
	  A.matrix[0][0] = 0;
	  A.matrix[0][1] = 10;
	  A.matrix[0][2] = -20;
	  A.matrix[1][0] = 4;
	  A.matrix[1][1] = -14;
	  A.matrix[1][2] = 8;
	  A.matrix[2][0] = -8;
	  A.matrix[2][1] = -2;
	  A.matrix[2][2] = 4;
	
	  int code = s21_calc_complements(&B, &R);
	  printf("%d %d\n", code, OK);
	  printf("%d %d\n", s21_eq_matrix(&R, &A), SUCCESS);
	  s21_remove_matrix(&B);
	  s21_remove_matrix(&R);
	  s21_remove_matrix(&A);
	}

	{
	  matrix_t A, B, R;
	  s21_create_matrix(3, 3, &A);
	  s21_create_matrix(3, 3, &B);
	
	  A.matrix[0][0] = 5;
	  A.matrix[0][1] = -1;
	  A.matrix[0][2] = 1;
	  A.matrix[1][0] = 2;
	  A.matrix[1][1] = 3;
	  A.matrix[1][2] = 4;
	  A.matrix[2][0] = 1;
	  A.matrix[2][1] = 0;
	  A.matrix[2][2] = 3;
	
	  s21_calc_complements(&A, &R);
	
	  B.matrix[0][0] = 9;
	  B.matrix[0][1] = -2;
	  B.matrix[0][2] = -3;
	  B.matrix[1][0] = 3;
	  B.matrix[1][1] = 14;
	  B.matrix[1][2] = -1;
	  B.matrix[2][0] = -7;
	  B.matrix[2][1] = -18;
	  B.matrix[2][2] = 17;
	
	  printf("%d %d\n", s21_eq_matrix(&R, &B), SUCCESS);
	  s21_remove_matrix(&A);
	  s21_remove_matrix(&B);
	  s21_remove_matrix(&R);
	}

	{
	  matrix_t B, R;
	  s21_create_matrix(2, 3, &B);
	
	  B.matrix[0][0] = 1;
	  B.matrix[0][1] = 2;
	  B.matrix[0][2] = 3;
	  B.matrix[1][0] = 0;
	  B.matrix[1][1] = 4;
	  B.matrix[1][2] = 2;
	
	  int code = s21_calc_complements(&B, &R);
	
	  printf("%d %d\n", code, CALCULATION_ERROR);
	  s21_remove_matrix(&B);
	  s21_remove_matrix(&R);
	}

	{
	  matrix_t *B = NULL;
	  matrix_t *R = NULL;
	  int res = s21_calc_complements(B, R);
	  printf("%d %d\n", res, INCORRECT_MATRIX_ERROR);
	}

	{
	  matrix_t A, B, C;
	  s21_create_matrix(3, 3, &A);
	  s21_create_matrix(3, 3, &C);
	  A.matrix[0][0] = 1.0;
	  A.matrix[0][1] = 2.0;
	  A.matrix[0][2] = 3.0;
	  A.matrix[1][0] = 0.0;
	  A.matrix[1][1] = 4.0;
	  A.matrix[1][2] = 2.0;
	  A.matrix[2][0] = 5.0;
	  A.matrix[2][1] = 2.0;
	  A.matrix[2][2] = 1.0;
	  s21_calc_complements(&A, &B);
	  C.matrix[0][0] = 0.0;
	  C.matrix[0][1] = 10.0;
	  C.matrix[0][2] = -20.0;
	  C.matrix[1][0] = 4.0;
	  C.matrix[1][1] = -14.0;
	  C.matrix[1][2] = 8.0;
	  C.matrix[2][0] = -8.0;
	  C.matrix[2][1] = -2.0;
	  C.matrix[2][2] = 4.0;
	  int res = s21_eq_matrix(&B, &C);
	  printf("%d %d\n", res, SUCCESS);
	  s21_remove_matrix(&A);
	  s21_remove_matrix(&B);
	  s21_remove_matrix(&C);
	}

	{
	  matrix_t a = {0};
	  s21_create_matrix(3, 3, &a);
	  matrix_t res = {0};
	  s21_create_matrix(3, 3, &res);
	  matrix_t m;
	  res.matrix[0][0] = 0;
	  res.matrix[0][1] = 10;
	  res.matrix[0][2] = -20;
	  res.matrix[1][0] = 4;
	  res.matrix[1][1] = -14;
	  res.matrix[1][2] = 8;
	  res.matrix[2][0] = -8;
	  res.matrix[2][1] = -2;
	  res.matrix[2][2] = 4;
	
	  a.matrix[0][0] = 1;
	  a.matrix[0][1] = 2;
	  a.matrix[0][2] = 3;
	  a.matrix[1][0] = 0;
	  a.matrix[1][1] = 4;
	  a.matrix[1][2] = 2;
	  a.matrix[2][0] = 5;
	  a.matrix[2][1] = 2;
	  a.matrix[2][2] = 1;
	  s21_calc_complements(&a, &m);
	  printf("%d %d\n", s21_eq_matrix(&res, &m), SUCCESS);
	  s21_remove_matrix(&m);
	  s21_remove_matrix(&a);
	  s21_remove_matrix(&res);
	}

	{
	  matrix_t a = {0};
	  matrix_t b = {0};
	  printf("%d %d\n", s21_calc_complements(&a, &b), INCORRECT_MATRIX_ERROR);
	}

	{
	  matrix_t a = {0};
	  matrix_t b = {0};
	  s21_create_matrix(1, 2, &a);
	  printf("%d %d\n", s21_calc_complements(&a, &b), CALCULATION_ERROR);
	  s21_remove_matrix(&a);
	}

	{
	  const int size = 3;
	  matrix_t m = {0};
	  s21_create_matrix(size, size, &m);
	  m.matrix[0][0] = 1;
	  m.matrix[0][1] = 2;
	  m.matrix[0][2] = 3;
	  m.matrix[1][1] = 4;
	  m.matrix[1][2] = 2;
	  m.matrix[2][0] = 5;
	  m.matrix[2][1] = 2;
	  m.matrix[2][2] = 1;
	
	  matrix_t expected = {0};
	  s21_create_matrix(size, size, &expected);
	  expected.matrix[0][1] = 10;
	  expected.matrix[0][2] = -20;
	  expected.matrix[1][0] = 4;
	  expected.matrix[1][1] = -14;
	  expected.matrix[1][2] = 8;
	  expected.matrix[2][0] = -8;
	  expected.matrix[2][1] = -2;
	  expected.matrix[2][2] = 4;
	
	  matrix_t res = {0};
	  s21_calc_complements(&m, &res);
	
	  printf("%d %d\n", s21_eq_matrix(&expected, &res), SUCCESS);
	  s21_remove_matrix(&m);
	  s21_remove_matrix(&res);
	  s21_remove_matrix(&expected);
	}

	
	 {
	  matrix_t A;
	  double B, R = 1.25;
	  s21_create_matrix(1, 1, &A);
	
	  A.matrix[0][0] = 1.25;
	
	  s21_determinant(&A, &B);
	  printf("__%.10lf__\n", (fabs(B) - fabs(R)) < 1e-7);
	
	  s21_remove_matrix(&A);
	}

	{
	  matrix_t A;
	  double B, R = -69;
	  s21_create_matrix(3, 3, &A);
	
	  A.matrix[0][0] = 0.25;
	  A.matrix[0][1] = 1.25;
	  A.matrix[0][2] = 2.25;
	  A.matrix[1][0] = 3.25;
	  A.matrix[1][1] = 10;
	  A.matrix[1][2] = 5.25;
	  A.matrix[2][0] = 6.25;
	  A.matrix[2][1] = 7.25;
	  A.matrix[2][2] = 8.25;
	
	  s21_determinant(&A, &B);
	
	  printf("__%.10lf__\n", (fabs(B) - fabs(R)));
	
	  s21_remove_matrix(&A);
	}
	
	{
	  matrix_t A;
	  double B, R = -2;
	  s21_create_matrix(3, 3, &A);
	
	  A.matrix[0][0] = 2;
	  A.matrix[0][1] = 4;
	  A.matrix[1][0] = -5;
	  A.matrix[1][1] = -7;
	
	  s21_determinant(&A, &B);
	
	  printf("__%.10lf__\n", (fabs(B) - fabs(R)));
	
	  s21_remove_matrix(&A);
	}

	
	{
	  matrix_t A;
	  double B, R = -2;
	  s21_create_matrix(3, 3, &A);
	
	  A.matrix[0][0] = 2;
	  A.matrix[0][1] = 4;
	  A.matrix[0][2] = -6;
	  A.matrix[1][0] = -5;
	  A.matrix[1][1] = -7;
	  A.matrix[1][2] = 5;
	  A.matrix[2][0] = 3;
	  A.matrix[2][1] = 5;
	  A.matrix[2][2] = -6;
	
	  s21_determinant(&A, &B);
	
	  printf("__%.10lf__\n", (fabs(B) - fabs(R)) < 1e-7);
	
	  s21_remove_matrix(&A);
	}

	
	{
	  matrix_t A;
	  double B, R = 25;
	  s21_create_matrix(3, 3, &A);
	
	  A.matrix[0][0] = -3;
	  A.matrix[0][1] = 4;
	  A.matrix[0][2] = -6;
	  A.matrix[1][0] = 2;
	  A.matrix[1][1] = -7;
	  A.matrix[1][2] = 5;
	  A.matrix[2][0] = -4;
	  A.matrix[2][1] = 5;
	  A.matrix[2][2] = -6;
	
	  s21_determinant(&A, &B);
	
	  printf("__%.10lf__\n", (fabs(B) - fabs(R)) < 1e-7);
	
	  s21_remove_matrix(&A);
	}

	{
	  matrix_t A;
	  double B, R = 23;
	  s21_create_matrix(3, 3, &A);
	
	  A.matrix[0][0] = -3;
	  A.matrix[0][1] = 2;
	  A.matrix[0][2] = -6;
	  A.matrix[1][0] = 2;
	  A.matrix[1][1] = -5;
	  A.matrix[1][2] = 5;
	  A.matrix[2][0] = -4;
	  A.matrix[2][1] = 3;
	  A.matrix[2][2] = -6;
	
	  s21_determinant(&A, &B);
	
	  printf("__%lf__\n", (fabs(B) - fabs(R)) < 1e-7);
	
	  s21_remove_matrix(&A);
	}

	{
	  matrix_t A;
	  double B, R = -8;
	  s21_create_matrix(3, 3, &A);
	
	  A.matrix[0][0] = -3;
	  A.matrix[0][1] = 2;
	  A.matrix[0][2] = 4;
	  A.matrix[1][0] = 2;
	  A.matrix[1][1] = -5;
	  A.matrix[1][2] = -7;
	  A.matrix[2][0] = -4;
	  A.matrix[2][1] = 3;
	  A.matrix[2][2] = 5;
	
	  s21_determinant(&A, &B);
	
	  printf("__%lf__\n", (fabs(B) - fabs(R)) < 1e-7);
	
	  s21_remove_matrix(&A);
	}

	{
	  matrix_t A;
	  double B, R = 18;
	  s21_create_matrix(4, 4, &A);
	
	  A.matrix[0][0] = 3;
	  A.matrix[0][1] = -3;
	  A.matrix[0][2] = -5;
	  A.matrix[0][3] = 8;
	  A.matrix[1][0] = -3;
	  A.matrix[1][1] = 2;
	  A.matrix[1][2] = 4;
	  A.matrix[1][3] = -6;
	  A.matrix[2][0] = 2;
	  A.matrix[2][1] = -5;
	  A.matrix[2][2] = -7;
	  A.matrix[2][3] = 5;
	  A.matrix[3][0] = -4;
	  A.matrix[3][1] = 3;
	  A.matrix[3][2] = 5;
	  A.matrix[3][3] = -6;
	
	  s21_determinant(&A, &B);
	
	  printf("__%lf__\n", (fabs(B) - fabs(R)) < 1e-7);
	
	  s21_remove_matrix(&A);
	}

	{
	  matrix_t A;
	  double B, R = -69.0 / 4.0;
	  s21_create_matrix(5, 5, &A);
	
	  A.matrix[0][0] = 0.25;
	  A.matrix[0][1] = 1.25;
	  A.matrix[0][2] = 2.25;
	  A.matrix[0][3] = 3.25;
	  A.matrix[0][4] = 2.25;
	  A.matrix[1][0] = 3.25;
	  A.matrix[1][1] = 10;
	  A.matrix[1][2] = 5.25;
	  A.matrix[1][3] = 5.25;
	  A.matrix[1][4] = 5.25;
	  A.matrix[2][0] = 6.25;
	  A.matrix[2][1] = 7.25;
	  A.matrix[2][2] = 8.25;
	  A.matrix[2][3] = 6.25;
	  A.matrix[2][4] = 6.25;
	  A.matrix[3][0] = 6.25;
	  A.matrix[3][1] = 7.25;
	  A.matrix[3][2] = 8.25;
	  A.matrix[3][3] = 6.25;
	  A.matrix[3][4] = 7.25;
	  A.matrix[4][0] = 6.25;
	  A.matrix[4][1] = 7.25;
	  A.matrix[4][2] = 8.25;
	  A.matrix[4][3] = 6;
	  A.matrix[4][4] = 8.25;
	
	  s21_determinant(&A, &B);
	
	  printf("__%lf__\n", (fabs(B) - fabs(R)) < 1e-7);
	
	  s21_remove_matrix(&A);
	}

	{
	  matrix_t A;
	  double B;
	  s21_create_matrix(4, 5, &A);
	  int res = s21_determinant(&A, &B);
	  printf("%d %d\n", res, CALCULATION_ERROR);
	  s21_remove_matrix(&A);
	}

	{
	  matrix_t a;
	  double number;
	  s21_create_matrix(4, 4, &a);
	  a.matrix[0][0] = 1;
	  a.matrix[0][1] = 2;
	  a.matrix[0][2] = 3;
	  a.matrix[0][3] = 13;
	  a.matrix[1][0] = 4;
	  a.matrix[1][1] = 5;
	  a.matrix[1][2] = 6;
	  a.matrix[1][3] = 16;
	  a.matrix[2][0] = 7;
	  a.matrix[2][1] = 8;
	  a.matrix[2][2] = 90;
	  a.matrix[2][3] = 19;
	  a.matrix[3][0] = 1;
	  a.matrix[3][1] = 7;
	  a.matrix[3][2] = 7;
	  a.matrix[3][3] = 17;
	
	  s21_determinant(&a, &number);
	  printf("%d %d\n", number, 13608);
	  s21_remove_matrix(&a);
	}
	/*
	{
	  matrix_t *B = NULL;
	  double re = 0;
	  int res = s21_determinant(B, &re);
	  printf("%d %d\n", res, INCORRECT_MATRIX_ERROR);
	}

	{
	  const int size = 5;
	  matrix_t m = {0};
	  s21_create_matrix(size, size, &m);
	
	  for (int i = 0; i < size; i++)
	    for (int j = 0; j < size; j++) m.matrix[i][j] = j;
	  double res = 0;
	  int code = s21_determinant(&m, &res);
	  printf("%lf %lf\n", res, 0);
	  printf("%d %d\n", code, OK);
	
	  s21_remove_matrix(&m);
	}

	{
	  const int size = 4;
	  matrix_t m = {0};
	  s21_create_matrix(size, size, &m);
	
	  for (int i = 0; i < size; i++)
	    for (int j = 0; j < size; j++) m.matrix[i][j] = j + i;
	
	  double res = 0;
	  int code = s21_determinant(&m, &res);
	  printf("%lf %lf\n", res, 0);
	  printf("%d %d\n", code, OK);
	
	  s21_remove_matrix(&m);
	}

	{
	  const int size = 5;
	  matrix_t m = {0};
	  s21_create_matrix(size, size, &m);
	  m.matrix[0][1] = 6;
	  m.matrix[0][2] = -2;
	  m.matrix[0][3] = -1;
	  m.matrix[0][4] = 5;
	  m.matrix[1][3] = -9;
	  m.matrix[1][4] = -7;
	  m.matrix[2][1] = 15;
	  m.matrix[2][2] = 35;
	  m.matrix[3][1] = -1;
	  m.matrix[3][2] = -11;
	  m.matrix[3][3] = -2;
	  m.matrix[3][4] = 1;
	  m.matrix[4][0] = -2;
	  m.matrix[4][1] = -2;
	  m.matrix[4][2] = 3;
	  m.matrix[4][4] = -2;
	
	  double res = 0;
	  int code = s21_determinant(&m, &res);
	  printf("%lf %lf\n", res, 2480);
	  printf("%d %d\n", code, OK);
	
	  s21_remove_matrix(&m);
	}

	{
	  const int size = 3;
	  matrix_t m = {0};
	  s21_create_matrix(size, size, &m);
	  m.matrix[0][0] = 2;
	  m.matrix[0][1] = 3;
	  m.matrix[0][2] = 1;
	  m.matrix[1][0] = 7;
	  m.matrix[1][1] = 4;
	  m.matrix[1][2] = 1;
	  m.matrix[2][0] = 9;
	  m.matrix[2][1] = -2;
	  m.matrix[2][2] = 1;
	
	  double res = 0;
	  int code = s21_determinant(&m, &res);
	  printf("%lf %lf\n", res);
	  printf("%d %d\n", code, OK);
	
	  s21_remove_matrix(&m);
	}

	{
	  const int size = 2;
	  matrix_t m = {0};
	  s21_create_matrix(size, size, &m);
	  m.matrix[0][0] = -5;
	  m.matrix[0][1] = -4;
	  m.matrix[1][0] = -2;
	  m.matrix[1][1] = -3;
	
	  double res = 0;
	  int code = s21_determinant(&m, &res);
	  printf("%lf %lf\n", res, 7);
	  printf("%d %d\n", code, OK);
	
	  s21_remove_matrix(&m);
	}*/

	return 0;
}


double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}

void output(matrix_t* A) {
	for (int i = 0; i < A->rows; i++)
	{
		for (int j = 0; j < A->columns; j++)
			printf("%lf ", A->matrix[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("\n");
}