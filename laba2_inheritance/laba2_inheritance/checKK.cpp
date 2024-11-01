#include "check.h"


bool check_Matrix_for_simple_num:: isPrime(int num) {
	if (num <= 1)
		return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

bool check_Matrix_for_simple_num:: check_simple_num(int arr[], int size) {
	bool flag;
	for (int i = 0; i < size; i++)
	{
		flag = isPrime(arr[i]);
		if (!flag)
			break;

	}
	return flag;
}

check_Matrix_for_simple_num::check_Matrix_for_simple_num(int size_r, int size_c) : Matrix(size_r, size_c) {}


int check_Matrix_for_simple_num::how_many_cols() {
	int counter = 0;
	for (int i = 0; i < size_cols; i++)
	{
		bool check = check_Matrix_for_simple_num::check_simple_num(matrix[i], size_rows);
		if (check) {
			counter++;
		}
	}
	return counter;
}

bool check_Matrix_for_simple_num::check_simple_num_in_ordinary() {
	int* arr = merge_Matrix();
	bool flag;
	for (int i = 0; i < size_cols * size_rows; i++)
	{
		flag = isPrime(arr[i]);
		if (!flag)
			break;
	}
	return flag;
}