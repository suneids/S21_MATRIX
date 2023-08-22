#include "s21_matrix.h"
#include <stdio.h>
void output(matrix_t *A);

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
	output(&C);
	s21_sub_matrix(&A, &B, &C);
	output(&C);

	A.matrix[0][0] = 1.0;
	A.matrix[0][1] = 2.0;
	A.matrix[0][2] = 3.0;
	A.matrix[1][0] = 0.0;
	A.matrix[1][1] = 4.0;
	A.matrix[1][2] = 2.0;
	A.matrix[2][0] = 2.0;
	A.matrix[2][1] = 3.0;
	A.matrix[2][2] = 4.0;

	s21_mult_number(&A, 2, &C);
	output(&C);

	matrix_t D, E;
	s21_create_matrix(3, 2, &D), s21_create_matrix(2, 3, &E);

	D.matrix[0][0] = 1.0;
	D.matrix[0][1] = 4.0;
	D.matrix[1][0] = 2.0;
	D.matrix[1][1] = 5.0;
	D.matrix[2][0] = 3.0;
	D.matrix[2][1] = 6.0;

	E.matrix[0][0] = 1.0;
	E.matrix[0][1] = -1.0;
	E.matrix[0][2] = 1.0;
	E.matrix[1][0] = 2.0;
	E.matrix[1][1] = 3.0;
	E.matrix[1][2] = 4.0;

	s21_mult_matrix(&D, &E, &C);
	output(&C);

	D.matrix[0][0] = 1.0;
	D.matrix[0][1] = 4.0;
	D.matrix[1][0] = 2.0;
	D.matrix[1][1] = 5.0;
	D.matrix[2][0] = 3.0;
	D.matrix[2][1] = 6.0;
	s21_transpose(&D, &C);
	output(&C);


	return 0;
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