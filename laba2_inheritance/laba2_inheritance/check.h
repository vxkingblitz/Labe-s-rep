#pragma once
#include "MMM.h"

class check_Matrix_for_simple_num : public Matrix {
protected:

	bool isPrime(int num);


	bool check_simple_num(int arr[], int size);

public:

	check_Matrix_for_simple_num(int size_r, int size_c);

	int how_many_cols();

	bool check_simple_num_in_ordinary();
};
