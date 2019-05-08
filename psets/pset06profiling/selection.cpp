// csort.cpp
// This is a sample code that runs okay, has a bad coding style.
// Reference: Fundamentals of Data Structures by Horowitz, Sahni
//
// When you compile the following code in Visual Studio, you may
// get the warning about scanf() or others. Then enter an addtional
// compiler option /wd4996 in the following:
// Project Properties -> C/C++ -> Command Line -> Additonal Options

#include <iostream>
#include <cstdlib>

#define MAX_SIZE 100

void selectionSort(int[], int);

#if 0
int main(void) {
	int i, n;
	int *list;
	using namespace std;


	while(1){
		cout << "Enter the number of samples: ";
		cin >> n;

		if(n == 0)
			exit(1);
		else if(n > 0 && n <= MAX_SIZE)
			break;

		cout << "Error! Enter a number between 1 to 100" << endl;
	}

	list = new int[n];

	cout << endl << "UnSorted array:" << endl;
	for (i = 0; i < n; i++) {       // randomly generate numbers
		list[i] = rand() % 1000;
		cout << list[i] << " ";
	}

	selectionSort(list, n);

	cout << endl << "Sorted array:" << endl;
	for (i = 0; i < n; i++) {
		cout << list[i] << " ";
	}
	cout << endl;

	delete [] list;
	list = nullptr;

	return EXIT_SUCCESS;
}
#endif

void selectionSort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
			temp = list[i];
			list[i] = list[min];
			list[min] = temp;
	}
}
