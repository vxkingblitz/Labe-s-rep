#pragma once

class Matrix{
public:
	Matrix(int size_r, int size_c);
	void show_Matrix();
	bool Check();
	int how_many();

protected:
	int* merge_Matrix();
	bool optimized_bubble_sort(int arr[], int n);
	int size_cols;
	int size_rows;
	int matrix[100][100];
public:

};
