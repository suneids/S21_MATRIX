#include "s21_matrix.h"
#include <stdio.h>
#define RAND_MAX 20
#define DBL_MIN -20.0
#define DBL_MAX 20.0

int main() {

	{
		matrix_t A, B, C;
		s21_create_matrix(3, 3, &A);
		s21_create_matrix(3, 3, &C);
		C.matrix[0][0] = 44300.0 / 367429.0;
		C.matrix[0][1] = -236300.0 / 367429.0;
		C.matrix[0][2] = 200360.0 / 367429.0;
		C.matrix[1][0] = 20600.0 / 367429.0;
		C.matrix[1][1] = 56000.0 / 367429.0;
		C.matrix[1][2] = -156483.0 / 367429.0;
		C.matrix[2][0] = 30900.0 / 367429.0;
		C.matrix[2][1] = 84000.0 / 367429.0;
		C.matrix[2][2] = -51010.0 / 367429.0;
		A.matrix[0][0] = 2.8;
		A.matrix[0][1] = 1.3;
		A.matrix[0][2] = 7.01;
		A.matrix[1][0] = -1.03;
		A.matrix[1][1] = -2.3;
		A.matrix[1][2] = 3.01;
		A.matrix[2][0] = 0;
		A.matrix[2][1] = -3;
		A.matrix[2][2] = 2;
		s21_inverse_matrix(&A, &B);
		/*s21_calc_complements(&A, &B);
		double k = 0;
		matrix_t G;
		s21_create_matrix(2, 2, &G);
		G.matrix[0][0] = 1;
		G.matrix[0][1] = 7;
		G.matrix[1][0] = 0;
		G.matrix[1][1] = 2;
		s21_determinant(&A, &k);
		printf("\n||%lf||", k);
		output(&B);*/
		int res = s21_eq_matrix(&C, &B);
		printf("%d %d\n", res, SUCCESS);
		s21_remove_matrix(&A);
		s21_remove_matrix(&B);
		s21_remove_matrix(&C);
	}

	return 0;
}
