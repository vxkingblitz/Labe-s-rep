#include <iostream>
#include <ctime>
#include "MMM.h"


using namespace std;


	Matrix::Matrix(int size_r, int size_c) : size_cols(size_c), size_rows(size_r) {
		srand(time(NULL));
		for (int i = 0; i < size_rows; i++)
		{
			for (int j = 0; j < size_cols; j++)
			{
				matrix[i][j] = rand() % 10;

			}
		}
	}
	void Matrix:: show_Matrix() {
		for (int i = 0; i < size_rows; i++)
		{
			cout << "{" << '\t';
			for (int j = 0; j < size_cols; j++)
			{
				cout << matrix[i][j] << '\t';
			}
			cout << "}" << endl;
		}
	}

	bool Matrix:: Check() {
		int* array = merge_Matrix();
		bool check_ordinary = optimized_bubble_sort(array, size_rows * size_cols);
		return check_ordinary;
	}

	int Matrix:: how_many() {
		int counter = 0;
		for (int i = 0; i < size_rows; i++)
		{
			bool check = optimized_bubble_sort(matrix[i], size_cols);
			if (check) {
				counter++;
			}
		}
		return counter;
	}


	int* Matrix:: merge_Matrix() {
		static int array[100] = {};
		int k = 0;
		for (int i = 0; i < size_rows; i++)
		{
			for (int j = 0; j < size_cols; j++)
			{
				array[k] = matrix[i][j];
				k++;
			}
		}
		return array;
	}

	bool Matrix:: optimized_bubble_sort(int arr[], int n) {
		bool check = true;
		for (int i = 0; i < n - 1; i++)
		{
			bool swapped = false;
			for (int j = 0; j < n - i - 1; j++)
			{
				if (arr[j] > arr[j + 1]) {
					swapped = true;
					check = false;
				}
			}
			if (!swapped)
				break;

		}
		return check;
	}
