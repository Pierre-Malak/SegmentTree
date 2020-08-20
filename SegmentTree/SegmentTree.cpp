//#include "pch.h"
#include "Header.h"
#include <iostream>
using namespace std;

int main() {
	//2, 5, 1, 4, 9, 3 
	int arraySize, option2, from, to;
	int option = 0;
	cout << "Enter the array size." << endl;
	cin >> arraySize;
	int* arr = new int[arraySize];
	cout << "Enter the array values" << endl;
	for (int i = 0; i < arraySize; i++) {
		cin >> arr[i];
	}
	while (option != 3) {
		cout << "1- Sum tree" << endl;
		cout << "2- Minimum tree" << endl;
		cout << "3- Exit" << endl;
		cin >> option;
		option2 = 0;
		if (option == 3) { return 0; }
		SegmentTree tree(arr, arraySize, option);
		while (option2 != 6) {
			cout << "1- Display the tree values" << endl;
			cout << "2- Sum between two indexes" << endl;
			cout << "3- Minimum number between two indexes" << endl;
			cout << "4- update value in array" << endl;
			cout << "5- insert new element" << endl;
			cout << "6- Go back" << endl;
			cin >> option2;
			if (option2 == 1) {
				cout << "The tree values are: " << endl;
				tree.display();
			}
			else if (option2 == 2) {
				cout << "Enter index (from and to). " << endl;
				cin >> from >> to;
				cout << "The sum is " << tree.getSum(from, to) << endl;

			}
			else if (option2 == 3) {
				cout << "Enter index (from and to)." << endl;
				cin >> from >> to;
				cout << "The minimum is " << tree.getMin(from, to) << endl;

			}
			else if (option2 == 4) {
				cout << "Enter index and new value" << endl;
				cin >> from >> to;
				tree.updateValue(from, to);
				cout << "Value has been updated" << endl;
			}
			else if (option2 == 5) {
				cout << "Enter value." << endl;
				cin >> from;
				tree.insert(from);
			}
		}
	}
}
