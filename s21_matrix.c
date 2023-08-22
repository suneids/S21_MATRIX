#include <stdlib.h>
#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result)
{
    int result_status = OK;
    if(rows < 1 || columns < 1) result_status = INCORRECT_MATRIX_ERROR;
    if(result_status == OK){
        result->rows = rows;
        result->columns = columns;
        result->matrix = (double **)calloc(rows, sizeof(double *));
        if(result->matrix == NULL) result_status = INCORRECT_MATRIX_ERROR;
        for(int i = 0; i < rows && !result_status; i++){
            result->matrix[i] = (double *)calloc(columns, sizeof(double*));
            if(result->matrix[i] == NULL) result_status = INCORRECT_MATRIX_ERROR;
        }
    }
    return result_status;
}

void s21_remove_matrix(matrix_t *A){
    if(A != NULL){
        for(int i = 0; i < A->rows; i++){
            if(A->matrix[i]!=NULL)
                free(A->matrix[i]);
        }
        free(A);
    }
}


int s21_eq_matrix(matrix_t *A, matrix_t *B){
    int result = s21_matrix_size_equal(A, B);
    if(result){
        for(int i = 0; (i < A->rows) && result; i++){
            for(int j = 0; (j < A->columns) && result; j++){
                if(A->matrix[i][j] != B->matrix[i][j]){
                    result = FAILURE;
                }        
            }
        }
    }
    return result;
}

int s21_matrix_size_equal(matrix_t *A, matrix_t *B){
    int result = SUCCESS;
    if(s21_matrix_is_not_null(A) && s21_matrix_is_not_null(B)){
        if(!(A->rows == B->rows) || !(A->columns == B->columns)){
            result = FAILURE;
        }
    }
    else{
        result = FAILURE;
    }
    return result;
}

int s21_matrix_is_not_null(matrix_t *A){
    int result = SUCCESS;
    if(A != NULL){
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
    int result_status = OK;
    if(s21_matrix_size_equal(A, B)){
        if(result != NULL) s21_remove_matrix(result);
        if(!s21_create_matrix(A->rows, A->columns, result)){
            result_status = INCORRECT_MATRIX_ERROR;
        }
        for(int i = 0; (i < A->rows) && !result_status; i++){
            for(int j = 0; j < A->columns; j++){
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];     
            }
        }
    }
    else{
        result_status = CALCULATION_ERROR;
    }
    return result_status;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    int result_status = OK;
    if(s21_matrix_size_equal(A, B)){
        if(result != NULL) s21_remove_matrix(result);
        if(!s21_create_matrix(A->rows, A->columns, result)){
            result_status = INCORRECT_MATRIX_ERROR;
        }
        for(int i = 0; (i < A->rows) && !result_status; i++){
            for(int j = 0; j < A->columns; j++){
                result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];     
            }
        }
    }
    else{
        result_status = CALCULATION_ERROR;
    }
    return result_status;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result){
    int result_status = OK;
    if(!s21_matrix_is_not_null(A)){
        result_status = INCORRECT_MATRIX_ERROR;
    }
    else{
        if(result != NULL) s21_remove_matrix(result);
        if(!s21_create_matrix(A->rows, A->columns, result)){
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
    if(s21_matrix_is_not_null(A) && s21_matrix_is_not_null(B) && (A->columns == B->rows)){
        if(result != NULL) s21_remove_matrix(result);
        if(!s21_create_matrix(A->rows, B->columns, result)){
            result_status = INCORRECT_MATRIX_ERROR;
        }
        for(int i = 0; (i < A->rows) && !result_status; i++){
            for(int j = 0; j < B->columns; j++){
                int adding_element = 0;
                for(int k = 0; k < A->columns; k++){
                    adding_element += A->matrix[i][k]*B->matrix[k][j];
                }
                result[i][j] += A->matrix[i][k]*B->matrix[k][i];
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
    if(!s21_matrix_is_not_null(A))
        result_status = INCORRECT_MATRIX_ERROR;
    if(!result_status){
        if(result != NULL) s21_remove_matrix(result);
        if(!s21_create_matrix(A->columns, B->rows, result)){
            result_status = INCORRECT_MATRIX_ERROR;
        }
    }
    for(int i = 0; (i < A->rows) && !result_status; i++){
        for(int j = 0; j < A->columns; j++){
            result[j][i] = A[i][j];
        }
    }
    return result_status;
}

