#ifndef S21_MATRIX
#define S21_MATRIX
// Для s21_eq_matrix
#define SUCCESS 1
#define FAILURE 0
// Общие
#define OK 0
#define INCORRECT_MATRIX_ERROR 1
#define CALCULATION_ERROR 2
#define eps 1e-7

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_matrix_size_equal(matrix_t *A, matrix_t *B);
int s21_matrix_is_not_null(matrix_t *A);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t* A, matrix_t* result);
int s21_determinant(matrix_t* A, double* result);
int s21_minor(matrix_t* A, matrix_t* result, int n_row, int n_col);
int is_square_matrix(matrix_t *A);
#endif 
