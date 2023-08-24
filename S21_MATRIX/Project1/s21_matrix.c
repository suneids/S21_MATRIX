#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result)
{
    int result_status = OK;
    if(rows < 1 || columns < 1) result_status = INCORRECT_MATRIX_ERROR;
    if (result == NULL) result_status = INCORRECT_MATRIX_ERROR;
    if(result_status == OK){
        result->rows = rows;
        result->columns = columns;
        result->matrix = (double **)calloc(rows, sizeof(double *));
        if(result->matrix == NULL) result_status = INCORRECT_MATRIX_ERROR;
        for(int i = 0; i < rows && !result_status; i++){
            result->matrix[i] = (double *)calloc(columns, sizeof(double));
            if(result->matrix[i] == NULL) result_status = INCORRECT_MATRIX_ERROR;
        }
    }
    return result_status;
}

void s21_remove_matrix(matrix_t *A){
    if(A != NULL && A->matrix != NULL){
        for(int i = 0; i < A->rows; i++){
            if(A->matrix[i] != NULL)
                free(A->matrix[i]);
        }
        free(A->matrix);
    }
}


int s21_eq_matrix(matrix_t *A, matrix_t *B){
    int result = s21_matrix_size_equal(A, B) == 0? SUCCESS : FAILURE;
    if(result){
        for(int i = 0; (i < A->rows) && result; i++){
            for(int j = 0; (j < A->columns) && result; j++){
                if((A->matrix[i][j] - B->matrix[i][j] >= eps) ||
                   (B->matrix[i][j] - A->matrix[i][j] >= eps)){
                    result = FAILURE;
                }        
            }
        }
    }
    return result;
}

int s21_matrix_size_equal(matrix_t *A, matrix_t *B){
    int result = OK;
    if(s21_matrix_is_not_null(A) && s21_matrix_is_not_null(B)){
        if(!(A->rows == B->rows) || !(A->columns == B->columns)){
            result = CALCULATION_ERROR;
        }
    }
    else{
        result = INCORRECT_MATRIX_ERROR;
    }
    return result;
}

int s21_matrix_is_not_null(matrix_t *A){
    int result = SUCCESS;
    if(A != NULL && A->matrix != NULL){
        for(int i = 0; (i < A->rows) && result; i++){
            if(A->matrix[i] == NULL){
                result = FAILURE;
            }
        }
    }
    else{
        result = FAILURE;
    }
    return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    int result_status = s21_matrix_size_equal(A, B);
    if(result_status == OK){
        if(s21_create_matrix(A->rows, A->columns, result)){
            result_status = INCORRECT_MATRIX_ERROR;
        }
        for(int i = 0; (i < A->rows) && !result_status; i++){
            for(int j = 0; j < A->columns; j++){
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];     
            }
        }
    }
    return result_status;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    int result_status = s21_matrix_size_equal(A, B);
    if(result_status == OK){
        if(s21_create_matrix(A->rows, A->columns, result)){
            result_status = INCORRECT_MATRIX_ERROR;
        }
        for(int i = 0; (i < A->rows) && !result_status; i++){
            for(int j = 0; j < A->columns; j++){
                result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];     
            }
        }
    }
    return result_status;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result){
    int result_status = OK;
    if(!s21_matrix_is_not_null(A)){
        result_status = INCORRECT_MATRIX_ERROR;
    }
    else{
        if((A != result) && s21_create_matrix(A->rows, A->columns, result)){
            result_status = INCORRECT_MATRIX_ERROR;
        }
        for(int i = 0; (i < A->rows) && !result_status; i++){
            for(int j = 0; j < A->columns; j++){
                result->matrix[i][j] = A->matrix[i][j]*number;     
            }
        }
    }
    return result_status;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    int result_status = OK;
    if(s21_matrix_is_not_null(A) && s21_matrix_is_not_null(B)){
        if(A->columns != B->rows)
        	result_status = CALCULATION_ERROR;
        if(!result_status && s21_create_matrix(A->rows, B->columns, result)){
            result_status = INCORRECT_MATRIX_ERROR;
        }
        for(int i = 0; (i < A->rows) && !result_status; i++){
            for(int j = 0; j < B->columns; j++){
                int adding_element = 0;
                for(int k = 0; k < A->columns; k++){
                    adding_element += A->matrix[i][k]*B->matrix[k][j];
                }
                result->matrix[i][j] = adding_element;
            }    
        }
    }
    else{
        result_status = INCORRECT_MATRIX_ERROR;
    }
    return result_status;
}

int s21_transpose(matrix_t *A, matrix_t *result){
    int result_status = OK;
    matrix_t temp;
    if(!s21_matrix_is_not_null(A))
        result_status = INCORRECT_MATRIX_ERROR;
    if (!result_status && !s21_create_matrix(A->columns, A->rows, &temp)) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                temp.matrix[j][i] = A->matrix[i][j];
            }
        }
        result->matrix = temp.matrix;
        result->rows = temp.rows;
        result->columns = temp.columns;

    }
    else {
        result_status = INCORRECT_MATRIX_ERROR;
    }
    return result_status;
}

int s21_calc_complements(matrix_t* A, matrix_t* result) {
    int result_status = is_square_matrix(A);
    if (!result_status) {
        matrix_t temp;
        result_status = s21_create_matrix(A->rows, A->columns, &temp);
        for (int i = 0; i < (A->rows) && !result_status; i++) {
            for (int j = 0; j < A->rows; j++) {
                double minor = 0.0;
                matrix_t min1;
                s21_minor(A, &min1, i, j);
                s21_determinant(&min1, &minor);
                temp.matrix[i][j] = minor * pow(-1, i + j);
                s21_remove_matrix(&min1);
            }
        }
        result->matrix = temp.matrix;
        result->rows = temp.rows;
        result->columns = temp.columns;
    }
    else {
        if(result!=NULL) result->matrix = NULL;
    }
    return result_status;
}


int s21_determinant(matrix_t* A, double* result) {
    int result_status = is_square_matrix(A);
    if (!result_status) {
        double det = 0.0, minor_det = 0.0;
        if (A->columns == 0) {
            *result = 0;
        }
        else if(A->columns == 1){
            *result = A->matrix[0][0];
        }
        else if (A->columns == 2) {
            *result = (A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0]);
        }
        else {
            matrix_t minor;
            for (int i = 0; i < A->rows; i++) {
                result_status = s21_minor(A, &minor, i, 0);
                if (!result_status) {
                    s21_determinant(&minor, &minor_det);
                    int sign = (i % 2 == 0) ? 1 : -1;
                    det += sign * A->matrix[i][0] * minor_det;
                    s21_remove_matrix(&minor);
                }
            }
            *result = det;
        }
    }
    return result_status;
}

int s21_minor(matrix_t* A, matrix_t* result, int n_row, int n_col) {
    int result_status = s21_create_matrix(A->rows - 1, A->columns - 1, result);
    int i = 0, j = 0;
    for (int row = 0; (row < A->rows) && !result_status; row++) {
        if(row != n_row){
            for (int column = 0; column < A->columns; column++) {
                if(n_col != column){
                    result->matrix[i][j] = A->matrix[row][column];
                    j++;
                }
            }
            j = 0;
            i++;
        }
    }
    return result_status;
}

int s21_inverse_matrix(matrix_t* A, matrix_t* result){
    int result_status = is_square_matrix(A);
    if(!result_status){
    	double determinant = 0.0;
    	result_status = s21_determinant(A, &determinant);
    	if(!result_status && determinant == 0) 
    		result_status = CALCULATION_ERROR;
    	if(!result_status){
            s21_calc_complements(A, result);
            s21_transpose(result, result);
            s21_mult_number(result, 1/determinant, result);
	    }
    }    
    return result_status; 
}

int is_square_matrix(matrix_t* A) {
    int result_status = OK;
    if (!s21_matrix_is_not_null(A))
        result_status = INCORRECT_MATRIX_ERROR;
    else if (!(A->columns == A->rows) && (A->rows > -1))
        result_status = CALCULATION_ERROR;
    return result_status;
}
