#include <iostream>
#include <ctime>
#include "check.h"

using namespace std;



int main() {
	Matrix smt(3,3);
	smt.show_Matrix();

	if (smt.Check()) {
		cout << endl << "Array is sorted" << endl;
	}
	else {
		cout << endl << "Array is not sorted" << endl;
	}

	cout << "---\t" << smt.how_many() << "\trows sorted!" << endl;

	check_Matrix_for_simple_num Students(3,3);
	
	cout <<"----\t" << Students.how_many_cols() << "\tcols is simple" << endl;

	if (Students.check_simple_num_in_ordinary()) {
		cout << "Array is full with Prime nums" << endl;
	}
	else {
		cout << "Array is not full with Prime nums" << endl;
	}


}