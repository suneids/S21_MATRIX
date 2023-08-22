#include "s21_matrix.h"
#include <stdio.h>

int main() {
	matrix_t A, B, C = {0};
	s21_create_matrix(3, 3, &A), s21_create_matrix(3, 3, &B);
	A.matrix[0][0] = 1.0;
	A.matrix[0][1] = 2.0;
	A.matrix[0][2] = 3.0;
	A.matrix[1][0] = 0.0;
	A.matrix[1][1] = 4.0;
	A.matrix[1][2] = 5.0;
	A.matrix[2][0] = 0.0;
	A.matrix[2][1] = 0.0;
	A.matrix[2][2] = 6.0;
	B.matrix[0][0] = 1.0;
	B.matrix[0][1] = 0.0;
	B.matrix[0][2] = 0.0;
	B.matrix[1][0] = 2.0;
	B.matrix[1][1] = 0.0;
	B.matrix[1][2] = 0.0;
	B.matrix[2][0] = 3.0;
	B.matrix[2][1] = 4.0;
	B.matrix[2][2] = 1.0;
	s21_sum_matrix(&A, &B, &C);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%lf ", C.matrix[i][j]);
		printf("\n");
	}
	return 0;
}