
//START_TEST(compliment_test_1) {
//  matrix_t A, B, R;
//  s21_create_matrix(3, 3, &B);
//  s21_create_matrix(3, 3, &A);
//  B.matrix[0][0] = 1;
//  B.matrix[0][1] = 2;
//  B.matrix[0][2] = 3;
//  B.matrix[1][0] = 0;
//  B.matrix[1][1] = 4;
//  B.matrix[1][2] = 2;
//  B.matrix[2][0] = 5;
//  B.matrix[2][1] = 2;
//  B.matrix[2][2] = 1;
//
//  A.matrix[0][0] = 0;
//  A.matrix[0][1] = 10;
//  A.matrix[0][2] = -20;
//  A.matrix[1][0] = 4;
//  A.matrix[1][1] = -14;
//  A.matrix[1][2] = 8;
//  A.matrix[2][0] = -8;
//  A.matrix[2][1] = -2;
//  A.matrix[2][2] = 4;
//
//  int code = s21_calc_complements(&B, &R);
//  ck_assert_int_eq(code, OK);
//  ck_assert_int_eq(s21_eq_matrix(&R, &A), SUCCESS);
//  s21_remove_matrix(&B);
//  s21_remove_matrix(&R);
//  s21_remove_matrix(&A);
//}
//END_TEST
//
//START_TEST(compliment_test_2) {
//  matrix_t A, B, R;
//  s21_create_matrix(3, 3, &A);
//  s21_create_matrix(3, 3, &B);
//
//  A.matrix[0][0] = 5;
//  A.matrix[0][1] = -1;
//  A.matrix[0][2] = 1;
//  A.matrix[1][0] = 2;
//  A.matrix[1][1] = 3;
//  A.matrix[1][2] = 4;
//  A.matrix[2][0] = 1;
//  A.matrix[2][1] = 0;
//  A.matrix[2][2] = 3;
//
//  s21_calc_complements(&A, &R);
//
//  B.matrix[0][0] = 9;
//  B.matrix[0][1] = -2;
//  B.matrix[0][2] = -3;
//  B.matrix[1][0] = 3;
//  B.matrix[1][1] = 14;
//  B.matrix[1][2] = -1;
//  B.matrix[2][0] = -7;
//  B.matrix[2][1] = -18;
//  B.matrix[2][2] = 17;
//
//  ck_assert_int_eq(s21_eq_matrix(&R, &B), SUCCESS);
//  s21_remove_matrix(&A);
//  s21_remove_matrix(&B);
//  s21_remove_matrix(&R);
//}
//END_TEST
//
//START_TEST(compliment_test_not_square) {
//  matrix_t B, R;
//  s21_create_matrix(2, 3, &B);
//
//  B.matrix[0][0] = 1;
//  B.matrix[0][1] = 2;
//  B.matrix[0][2] = 3;
//  B.matrix[1][0] = 0;
//  B.matrix[1][1] = 4;
//  B.matrix[1][2] = 2;
//
//  int code = s21_calc_complements(&B, &R);
//
//  ck_assert_int_eq(code, CALCULATION_ERROR);
//  s21_remove_matrix(&B);
//  // s21_remove_matrix(&R);
//}
//END_TEST
//
//START_TEST(null_compliments) {
//  matrix_t *B = NULL;
//  matrix_t *R = NULL;
//  int res = s21_calc_complements(B, R);
//  ck_assert_int_eq(res, INCORRECT_MATRIX_ERROR);
//}
//END_TEST
//
//START_TEST(s21_calc_compl_1) {
//  matrix_t A, B, C;
//  s21_create_matrix(3, 3, &A);
//  s21_create_matrix(3, 3, &C);
//  A.matrix[0][0] = 1.0;
//  A.matrix[0][1] = 2.0;
//  A.matrix[0][2] = 3.0;
//  A.matrix[1][0] = 0.0;
//  A.matrix[1][1] = 4.0;
//  A.matrix[1][2] = 2.0;
//  A.matrix[2][0] = 5.0;
//  A.matrix[2][1] = 2.0;
//  A.matrix[2][2] = 1.0;
//  s21_calc_complements(&A, &B);
//  C.matrix[0][0] = 0.0;
//  C.matrix[0][1] = 10.0;
//  C.matrix[0][2] = -20.0;
//  C.matrix[1][0] = 4.0;
//  C.matrix[1][1] = -14.0;
//  C.matrix[1][2] = 8.0;
//  C.matrix[2][0] = -8.0;
//  C.matrix[2][1] = -2.0;
//  C.matrix[2][2] = 4.0;
//  int res = s21_eq_matrix(&B, &C);
//  ck_assert_int_eq(res, SUCCESS);
//  s21_remove_matrix(&A);
//  s21_remove_matrix(&B);
//  s21_remove_matrix(&C);
//}
//END_TEST
//
//START_TEST(s21_calc_compl_2) {
//  matrix_t a = {0};
//  s21_create_matrix(3, 3, &a);
//  matrix_t res = {0};
//  s21_create_matrix(3, 3, &res);
//  matrix_t m;
//  res.matrix[0][0] = 0;
//  res.matrix[0][1] = 10;
//  res.matrix[0][2] = -20;
//  res.matrix[1][0] = 4;
//  res.matrix[1][1] = -14;
//  res.matrix[1][2] = 8;
//  res.matrix[2][0] = -8;
//  res.matrix[2][1] = -2;
//  res.matrix[2][2] = 4;
//
//  a.matrix[0][0] = 1;
//  a.matrix[0][1] = 2;
//  a.matrix[0][2] = 3;
//  a.matrix[1][0] = 0;
//  a.matrix[1][1] = 4;
//  a.matrix[1][2] = 2;
//  a.matrix[2][0] = 5;
//  a.matrix[2][1] = 2;
//  a.matrix[2][2] = 1;
//  s21_calc_complements(&a, &m);
//  ck_assert_int_eq(s21_eq_matrix(&res, &m), SUCCESS);
//  s21_remove_matrix(&m);
//  s21_remove_matrix(&a);
//  s21_remove_matrix(&res);
//}
//END_TEST
//
//START_TEST(empty) {
//  matrix_t a = {0};
//  matrix_t b = {0};
//  ck_assert_int_eq(s21_calc_complements(&a, &b), INCORRECT_MATRIX_ERROR);
//}
//END_TEST
//
//START_TEST(size_mismatch) {
//  matrix_t a = {0};
//  matrix_t b = {0};
//  s21_create_matrix(1, 2, &a);
//  ck_assert_int_eq(s21_calc_complements(&a, &b), CALCULATION_ERROR);
//  s21_remove_matrix(&a);
//}
//END_TEST
//
//START_TEST(complements) {
//  const int size = 3;
//  matrix_t m = {0};
//  s21_create_matrix(size, size, &m);
//  m.matrix[0][0] = 1;
//  m.matrix[0][1] = 2;
//  m.matrix[0][2] = 3;
//  m.matrix[1][1] = 4;
//  m.matrix[1][2] = 2;
//  m.matrix[2][0] = 5;
//  m.matrix[2][1] = 2;
//  m.matrix[2][2] = 1;
//
//  matrix_t expected = {0};
//  s21_create_matrix(size, size, &expected);
//  expected.matrix[0][1] = 10;
//  expected.matrix[0][2] = -20;
//  expected.matrix[1][0] = 4;
//  expected.matrix[1][1] = -14;
//  expected.matrix[1][2] = 8;
//  expected.matrix[2][0] = -8;
//  expected.matrix[2][1] = -2;
//  expected.matrix[2][2] = 4;
//
//  matrix_t res = {0};
//  s21_calc_complements(&m, &res);
//
//  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);
//  s21_remove_matrix(&m);
//  s21_remove_matrix(&res);
//  s21_remove_matrix(&expected);
//}
//END_TEST
//
//// Определитель матрицы
//
//START_TEST(determinant_test_1) {
//  matrix_t A;
//  double B, R = 1.25;
//  s21_create_matrix(1, 1, &A);
//
//  A.matrix[0][0] = 1.25;
//
//  s21_determinant(&A, &B);
//  ck_assert((fabs(B) - fabs(R)) < 1e-7);
//
//  s21_remove_matrix(&A);
//}
//END_TEST
//
//START_TEST(determinant_test_2) {
//  matrix_t A;
//  double B, R = -69;
//  s21_create_matrix(3, 3, &A);
//
//  A.matrix[0][0] = 0.25;
//  A.matrix[0][1] = 1.25;
//  A.matrix[0][2] = 2.25;
//  A.matrix[1][0] = 3.25;
//  A.matrix[1][1] = 10;
//  A.matrix[1][2] = 5.25;
//  A.matrix[2][0] = 6.25;
//  A.matrix[2][1] = 7.25;
//  A.matrix[2][2] = 8.25;
//
//  s21_determinant(&A, &B);
//
//  ck_assert((fabs(B) - fabs(R)) < 1e-7);
//
//  s21_remove_matrix(&A);
//}
//END_TEST
//
//START_TEST(determinant_test_2x2) {
//  matrix_t A;
//  double B, R = -2;
//  s21_create_matrix(3, 3, &A);
//
//  A.matrix[0][0] = 2;
//  A.matrix[0][1] = 4;
//  A.matrix[1][0] = -5;
//  A.matrix[1][1] = -7;
//
//  s21_determinant(&A, &B);
//
//  ck_assert((fabs(B) - fabs(R)) < 1e-7);
//
//  s21_remove_matrix(&A);
//}
//END_TEST
//
//START_TEST(determinant_test_3x3_1) {
//  matrix_t A;
//  double B, R = -2;
//  s21_create_matrix(3, 3, &A);
//
//  A.matrix[0][0] = 2;
//  A.matrix[0][1] = 4;
//  A.matrix[0][2] = -6;
//  A.matrix[1][0] = -5;
//  A.matrix[1][1] = -7;
//  A.matrix[1][2] = 5;
//  A.matrix[2][0] = 3;
//  A.matrix[2][1] = 5;
//  A.matrix[2][2] = -6;
//
//  s21_determinant(&A, &B);
//
//  ck_assert((fabs(B) - fabs(R)) < 1e-7);
//
//  s21_remove_matrix(&A);
//}
//END_TEST
//
//START_TEST(determinant_test_3x3_2) {
//  matrix_t A;
//  double B, R = 25;
//  s21_create_matrix(3, 3, &A);
//
//  A.matrix[0][0] = -3;
//  A.matrix[0][1] = 4;
//  A.matrix[0][2] = -6;
//  A.matrix[1][0] = 2;
//  A.matrix[1][1] = -7;
//  A.matrix[1][2] = 5;
//  A.matrix[2][0] = -4;
//  A.matrix[2][1] = 5;
//  A.matrix[2][2] = -6;
//
//  s21_determinant(&A, &B);
//
//  ck_assert((fabs(B) - fabs(R)) < 1e-7);
//
//  s21_remove_matrix(&A);
//}
//END_TEST
//
//START_TEST(determinant_test_3x3_3) {
//  matrix_t A;
//  double B, R = 23;
//  s21_create_matrix(3, 3, &A);
//
//  A.matrix[0][0] = -3;
//  A.matrix[0][1] = 2;
//  A.matrix[0][2] = -6;
//  A.matrix[1][0] = 2;
//  A.matrix[1][1] = -5;
//  A.matrix[1][2] = 5;
//  A.matrix[2][0] = -4;
//  A.matrix[2][1] = 3;
//  A.matrix[2][2] = -6;
//
//  s21_determinant(&A, &B);
//
//  ck_assert((fabs(B) - fabs(R)) < 1e-7);
//
//  s21_remove_matrix(&A);
//}
//END_TEST
//
//START_TEST(determinant_test_3x3_4) {
//  matrix_t A;
//  double B, R = -8;
//  s21_create_matrix(3, 3, &A);
//
//  A.matrix[0][0] = -3;
//  A.matrix[0][1] = 2;
//  A.matrix[0][2] = 4;
//  A.matrix[1][0] = 2;
//  A.matrix[1][1] = -5;
//  A.matrix[1][2] = -7;
//  A.matrix[2][0] = -4;
//  A.matrix[2][1] = 3;
//  A.matrix[2][2] = 5;
//
//  s21_determinant(&A, &B);
//
//  ck_assert((fabs(B) - fabs(R)) < 1e-7);
//
//  s21_remove_matrix(&A);
//}
//END_TEST
//
//START_TEST(determinant_test_4x4) {
//  matrix_t A;
//  double B, R = 18;
//  s21_create_matrix(4, 4, &A);
//
//  A.matrix[0][0] = 3;
//  A.matrix[0][1] = -3;
//  A.matrix[0][2] = -5;
//  A.matrix[0][3] = 8;
//  A.matrix[1][0] = -3;
//  A.matrix[1][1] = 2;
//  A.matrix[1][2] = 4;
//  A.matrix[1][3] = -6;
//  A.matrix[2][0] = 2;
//  A.matrix[2][1] = -5;
//  A.matrix[2][2] = -7;
//  A.matrix[2][3] = 5;
//  A.matrix[3][0] = -4;
//  A.matrix[3][1] = 3;
//  A.matrix[3][2] = 5;
//  A.matrix[3][3] = -6;
//
//  s21_determinant(&A, &B);
//
//  ck_assert((fabs(B) - fabs(R)) < 1e-7);
//
//  s21_remove_matrix(&A);
//}
//END_TEST
//
//START_TEST(determinant_test_5x5) {
//  matrix_t A;
//  double B, R = -69.0 / 4.0;
//  s21_create_matrix(5, 5, &A);
//
//  A.matrix[0][0] = 0.25;
//  A.matrix[0][1] = 1.25;
//  A.matrix[0][2] = 2.25;
//  A.matrix[0][3] = 3.25;
//  A.matrix[0][4] = 2.25;
//  A.matrix[1][0] = 3.25;
//  A.matrix[1][1] = 10;
//  A.matrix[1][2] = 5.25;
//  A.matrix[1][3] = 5.25;
//  A.matrix[1][4] = 5.25;
//  A.matrix[2][0] = 6.25;
//  A.matrix[2][1] = 7.25;
//  A.matrix[2][2] = 8.25;
//  A.matrix[2][3] = 6.25;
//  A.matrix[2][4] = 6.25;
//  A.matrix[3][0] = 6.25;
//  A.matrix[3][1] = 7.25;
//  A.matrix[3][2] = 8.25;
//  A.matrix[3][3] = 6.25;
//  A.matrix[3][4] = 7.25;
//  A.matrix[4][0] = 6.25;
//  A.matrix[4][1] = 7.25;
//  A.matrix[4][2] = 8.25;
//  A.matrix[4][3] = 6;
//  A.matrix[4][4] = 8.25;
//
//  s21_determinant(&A, &B);
//
//  ck_assert((fabs(B) - fabs(R)) < 1e-7);
//
//  s21_remove_matrix(&A);
//}
//END_TEST
//
//START_TEST(determinant_not_square) {
//  matrix_t A;
//  double B;
//  s21_create_matrix(4, 5, &A);
//  int res = s21_determinant(&A, &B);
//  ck_assert_int_eq(res, CALCULATION_ERROR);
//  s21_remove_matrix(&A);
//}
//END_TEST
//
//START_TEST(determinant_test_4x4_2) {
//  matrix_t a;
//  double number;
//  s21_create_matrix(4, 4, &a);
//  a.matrix[0][0] = 1;
//  a.matrix[0][1] = 2;
//  a.matrix[0][2] = 3;
//  a.matrix[0][3] = 13;
//  a.matrix[1][0] = 4;
//  a.matrix[1][1] = 5;
//  a.matrix[1][2] = 6;
//  a.matrix[1][3] = 16;
//  a.matrix[2][0] = 7;
//  a.matrix[2][1] = 8;
//  a.matrix[2][2] = 90;
//  a.matrix[2][3] = 19;
//  a.matrix[3][0] = 1;
//  a.matrix[3][1] = 7;
//  a.matrix[3][2] = 7;
//  a.matrix[3][3] = 17;
//
//  s21_determinant(&a, &number);
//  ck_assert_int_eq(number, 13608);
//  s21_remove_matrix(&a);
//}
//END_TEST
//
//START_TEST(null_determinate) {
//  matrix_t *B = NULL;
//  double re = 0;
//  int res = s21_determinant(B, &re);
//  ck_assert_int_eq(res, INCORRECT_MATRIX_ERROR);
//}
//END_TEST
//
//START_TEST(determinant_test_3) {
//  const int size = 5;
//  matrix_t m = {0};
//  s21_create_matrix(size, size, &m);
//
//  for (int i = 0; i < size; i++)
//    for (int j = 0; j < size; j++) m.matrix[i][j] = j;
//  double res = 0;
//  int code = s21_determinant(&m, &res);
//  ck_assert_double_eq_tol(res, 0, 1e-6);
//  ck_assert_int_eq(code, OK);
//
//  s21_remove_matrix(&m);
//}
//END_TEST
//
//START_TEST(determinant_test_4) {
//  const int size = 4;
//  matrix_t m = {0};
//  s21_create_matrix(size, size, &m);
//
//  for (int i = 0; i < size; i++)
//    for (int j = 0; j < size; j++) m.matrix[i][j] = j + i;
//
//  double res = 0;
//  int code = s21_determinant(&m, &res);
//  ck_assert_double_eq_tol(res, 0, 1e-6);
//  ck_assert_int_eq(code, OK);
//
//  s21_remove_matrix(&m);
//}
//END_TEST
//
//START_TEST(determinant_test_5) {
//  const int size = 5;
//  matrix_t m = {0};
//  s21_create_matrix(size, size, &m);
//  m.matrix[0][1] = 6;
//  m.matrix[0][2] = -2;
//  m.matrix[0][3] = -1;
//  m.matrix[0][4] = 5;
//  m.matrix[1][3] = -9;
//  m.matrix[1][4] = -7;
//  m.matrix[2][1] = 15;
//  m.matrix[2][2] = 35;
//  m.matrix[3][1] = -1;
//  m.matrix[3][2] = -11;
//  m.matrix[3][3] = -2;
//  m.matrix[3][4] = 1;
//  m.matrix[4][0] = -2;
//  m.matrix[4][1] = -2;
//  m.matrix[4][2] = 3;
//  m.matrix[4][4] = -2;
//
//  double res = 0;
//  int code = s21_determinant(&m, &res);
//  ck_assert_double_eq_tol(res, 2480, 1e-6);
//  ck_assert_int_eq(code, OK);
//
//  s21_remove_matrix(&m);
//}
//END_TEST
//
//START_TEST(determinant_test_6) {
//  const int size = 3;
//  matrix_t m = {0};
//  s21_create_matrix(size, size, &m);
//  m.matrix[0][0] = 2;
//  m.matrix[0][1] = 3;
//  m.matrix[0][2] = 1;
//  m.matrix[1][0] = 7;
//  m.matrix[1][1] = 4;
//  m.matrix[1][2] = 1;
//  m.matrix[2][0] = 9;
//  m.matrix[2][1] = -2;
//  m.matrix[2][2] = 1;
//
//  double res = 0;
//  int code = s21_determinant(&m, &res);
//  ck_assert_double_eq_tol(res, -32, 1e-6);
//  ck_assert_int_eq(code, OK);
//
//  s21_remove_matrix(&m);
//}
//END_TEST
//
//START_TEST(determinant_test_7) {
//  const int size = 2;
//  matrix_t m = {0};
//  s21_create_matrix(size, size, &m);
//  m.matrix[0][0] = -5;
//  m.matrix[0][1] = -4;
//  m.matrix[1][0] = -2;
//  m.matrix[1][1] = -3;
//
//  double res = 0;
//  int code = s21_determinant(&m, &res);
//  ck_assert_double_eq_tol(res, 7, 1e-6);
//  ck_assert_int_eq(code, OK);
//
//  s21_remove_matrix(&m);
//}
//END_TEST
//
//// Обратная матрица
//
//START_TEST(inverse_1) {
//  matrix_t A, B, C;
//  s21_create_matrix(3, 3, &A);
//  s21_create_matrix(3, 3, &C);
//  C.matrix[0][0] = 44300.0 / 367429.0;
//  C.matrix[0][1] = -236300.0 / 367429.0;
//  C.matrix[0][2] = 200360.0 / 367429.0;
//  C.matrix[1][0] = 20600.0 / 367429.0;
//  C.matrix[1][1] = 56000.0 / 367429.0;
//  C.matrix[1][2] = -156483.0 / 367429.0;
//  C.matrix[2][0] = 30900.0 / 367429.0;
//  C.matrix[2][1] = 84000.0 / 367429.0;
//  C.matrix[2][2] = -51010.0 / 367429.0;
//  A.matrix[0][0] = 2.8;
//  A.matrix[0][1] = 1.3;
//  A.matrix[0][2] = 7.01;
//  A.matrix[1][0] = -1.03;
//  A.matrix[1][1] = -2.3;
//  A.matrix[1][2] = 3.01;
//  A.matrix[2][0] = 0;
//  A.matrix[2][1] = -3;
//  A.matrix[2][2] = 2;
//  s21_inverse_matrix(&A, &B);
//
//  int res = s21_eq_matrix(&B, &C);
//  ck_assert_int_eq(res, SUCCESS);
//  s21_remove_matrix(&A);
//  s21_remove_matrix(&B);
//  s21_remove_matrix(&C);
//}
//END_TEST
//
//
//START_TEST(inverse_2) {
//  matrix_t A, C;
//  s21_create_matrix(3, 3, &A);
//  s21_create_matrix(3, 3, &C);
//  C.matrix[0][0] = 1.0;
//  C.matrix[0][1] = -1.0;
//  C.matrix[0][2] = 1.0;
//  C.matrix[1][0] = -38.0;
//  C.matrix[1][1] = 41.0;
//  C.matrix[1][2] = -34.0;
//  C.matrix[2][0] = 27.0;
//  C.matrix[2][1] = -29.0;
//  C.matrix[2][2] = 24.0;
//  A.matrix[0][0] = 2.0;
//  A.matrix[0][1] = 5.0;
//  A.matrix[0][2] = 7.0;
//  A.matrix[1][0] = 6.0;
//  A.matrix[1][1] = 3.0;
//  A.matrix[1][2] = 4.0;
//  A.matrix[2][0] = 5.0;
//  A.matrix[2][1] = -2.0;
//  A.matrix[2][2] = -3.0;
//  matrix_t B;
//  s21_inverse_matrix(&A, &B);
//  int res = s21_eq_matrix(&B, &C);
//  ck_assert_int_eq(res, SUCCESS);
//  s21_remove_matrix(&A);
//  s21_remove_matrix(&B);
//  s21_remove_matrix(&C);
//}
//END_TEST
//
//START_TEST(inverse_3) {
//  const int size = 3;
//  matrix_t m = {0};
//  s21_create_matrix(size, size, &m);
//
//  m.matrix[0][0] = 2;
//  m.matrix[0][1] = 5;
//  m.matrix[0][2] = 7;
//  m.matrix[1][0] = 6;
//  m.matrix[1][1] = 3;
//  m.matrix[1][2] = 4;
//  m.matrix[2][0] = 5;
//  m.matrix[2][1] = -2;
//  m.matrix[2][2] = -3;
//
//  matrix_t res = {0};
//  s21_inverse_matrix(&m, &res);
//
//  matrix_t expected = {0};
//  s21_create_matrix(size, size, &expected);
//  expected.matrix[0][0] = 1;
//  expected.matrix[0][1] = -1;
//  expected.matrix[0][2] = 1;
//  expected.matrix[1][0] = -38;
//  expected.matrix[1][1] = 41;
//  expected.matrix[1][2] = -34;
//  expected.matrix[2][0] = 27;
//  expected.matrix[2][1] = -29;
//  expected.matrix[2][2] = 24;
//
//  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);
//
//  s21_remove_matrix(&expected);
//  s21_remove_matrix(&res);
//  s21_remove_matrix(&m);
//}
//END_TEST
//
//START_TEST(inverse_normal) {
//  matrix_t m = {0};
//  matrix_t expected = {0};
//  int codec1, codec2;
//  codec1 = s21_create_matrix(3, 3, &m);
//  if (!codec1) codec2 = s21_create_matrix(3, 3, &expected);
//
//  if (!codec1 && !codec2) {
//    m.matrix[0][0] = 2;
//    m.matrix[0][1] = 5;
//    m.matrix[0][2] = 7;
//
//    m.matrix[1][0] = 6;
//    m.matrix[1][1] = 3;
//    m.matrix[1][2] = 4;
//
//    m.matrix[2][0] = 5;
//    m.matrix[2][1] = -2;
//    m.matrix[2][2] = -3;
//
//    expected.matrix[0][0] = 1;
//    expected.matrix[0][1] = -1;
//    expected.matrix[0][2] = 1;
//
//    expected.matrix[1][0] = -38;
//    expected.matrix[1][1] = 41;
//    expected.matrix[1][2] = -34;
//
//    expected.matrix[2][0] = 27;
//    expected.matrix[2][1] = -29;
//    expected.matrix[2][2] = 24;
//    matrix_t result = {0};
//    int code = s21_inverse_matrix(&m, &result);
//
//    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
//    ck_assert_int_eq(code, OK);
//
//    s21_remove_matrix(&m);
//    s21_remove_matrix(&result);
//    s21_remove_matrix(&expected);
//  }
//}
//END_TEST
//
//START_TEST(inverse_not_sqare) {
//  matrix_t m = {0};
//  matrix_t result = {0};
//  int codec = s21_create_matrix(1, 4, &m);
//  if (!codec) {
//    int code = s21_inverse_matrix(&m, &result);
//    ck_assert_int_eq(code, CALCULATION_ERROR);
//    s21_remove_matrix(&m);
//  }
//}
//END_TEST
//
//START_TEST(inverse_zero_det) {
//  matrix_t m = {0};
//  matrix_t result = {0};
//  int codec = s21_create_matrix(1, 1, &m);
//  if (!codec) {
//    int code = s21_inverse_matrix(&m, &result);
//    ck_assert_int_eq(code, CALCULATION_ERROR);
//    s21_remove_matrix(&m);
//  }
//}
//END_TEST
//
//START_TEST(inverse_INCORRECT_MATRIX_ERROR) {
//  matrix_t m = {0};
//  matrix_t result = {0};
//  int code = s21_inverse_matrix(&m, &result);
//  ck_assert_int_eq(code, INCORRECT_MATRIX_ERROR);
//}
//END_TEST*/
