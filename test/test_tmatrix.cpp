#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(10);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	const int Size = 10;
	TMatrix<int> source_mtx(Size), copied_mtx(Size);
	source_mtx[8][8] = 8;
	source_mtx[2][4] = 7;

	copied_mtx = source_mtx;

	ASSERT_EQ(source_mtx, copied_mtx);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	const int Size = 10;
	TMatrix<int> source_mtx(Size), copied_mtx(Size);

	copied_mtx = source_mtx;

	ASSERT_NE(&source_mtx[0][0], &copied_mtx[0][0]);
}

TEST(TMatrix, can_get_size)
{
	const int Size = 5;
	TMatrix<int> m(5);

	ASSERT_EQ(Size, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(4);
	m[0][0] = 4;

	EXPECT_EQ(4, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(4);

	ASSERT_ANY_THROW(m[-1][2] = 5);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(4);

	ASSERT_ANY_THROW(m[-1][5] = 5);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(4);

	ASSERT_NO_THROW(m == m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	const int Size = 10;
	TMatrix<int> m1(Size), m2(Size);

	ASSERT_EQ(m1, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	const int Size = 10;
	TMatrix<int> m1(Size), m2(Size * 2);

	m2 = m1;

	ASSERT_EQ(Size, m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	const int Size = 10;
	TMatrix<int> m1(Size), m2(Size * 2);

	ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	const int Size = 10;
	TMatrix<int> m1(Size), m2(Size);

	ASSERT_EQ(m1, m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	const int Size = 10;
	TMatrix<int> m1(Size);

	ASSERT_EQ(m1, m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	const int Size = 10;
	TMatrix<int> m1(Size), m2(Size * 2);

	ASSERT_NE(m1, m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	const int Size = 10;
	TMatrix<int> m1(Size), m2(Size);

	ASSERT_NO_THROW(m1 = m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	const int Size = 10;
	TMatrix<int> m1(Size), m2(Size * 2);

	ASSERT_ANY_THROW(m1 = m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	const int Size = 10;
	TMatrix<int> m1(Size), m2(Size);

	ASSERT_NO_THROW(m1 = m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	const int Size = 10;
	TMatrix<int> m1(Size), m2(Size * 2);

	ASSERT_ANY_THROW(m1 = m1 - m2);
}

