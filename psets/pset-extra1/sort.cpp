#include <iostream>
#include <cmath>
#include <cassert>
#include "sort.h"
using namespace std;

int ascending (int a, int b) {return a - b;}
int descending(int a, int b) {return b - a;}


void print_list(int *list, int n) {
	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
}


#if 1
int main(int argc, char *argv[]) {
	/*
	int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
	const int N = sizeof(list) / sizeof(list[0]);
	*/

	int N;

	if(argc > 1){
		//N = atoi(argv[1]);
		N = strtol(argv[1], NULL, 0);
	}
	else if(N <= 0){
		cout << "Your input(" << N << ") cannot be processed";
		cout << "Usage: sort [N]\n";
		exit(0);
	}
	else{
		cout << "Enter a number of samples to sort: ";
		cin >> N;
	}



	// int *list = (int *)malloc(N * sizeof(int));
	int *list = new(nothrow) int[N];
	assert(list != nullptr);

	cout << "Testcase: Not passing a default argument: quickSort(list, N)" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "NOTsorted: ";
	for (int i = 0; i < N; i++)
		list[i] = rand() % N;
	print_list(list, N);
	cout << "sorted: ";
	fps[2](list, N, ascending);
	print_list(list, N);
	cout << endl;

	cout << "Testcase: Passing a function pointer: quickSort(list, N, ascending)" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "NOTsorted: ";
	for (int i = 0; i < N; i++)
		list[i] = rand() % N;
	print_list(list, N);
	cout << "Ascending sorted: ";
	fps[2](list, N, ascending);
	print_list(list, N);
	cout << endl;

	cout << "Testcase: Passing a function pointer: quickSort(list, N, descending)" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "NOTsorted: ";
	for (int i = 0; i < N; i++)
		list[i] = rand() % N;
	print_list(list, N);
	cout << "Descending sorted: ";
	fps[2](list, N, descending);
	print_list(list, N);
	cout << endl;


	char algorithm_list[4][20] = {"bubbleSort", "insertionSort", "quickSort", "selectionSort"};

	void (*fps[])(int *, int, int (*cmp)(int,int)) = {bubbleSort, insertionSort, quickSort, selectionSort};
	const int fps_size = sizeof(fps)/sizeof(fps[0]);

	cout << "Testcase: Using an array of function pointers" << endl;

	for(int j = 0; j < fps_size; j++){
		for (int i = 0; i < N; i++)
			list[i] = rand() % N;

		cout << "NOTsorted" << "[" << algorithm_list[j] << "]: " << endl;
		print_list(list, N);
		fps[j](list, N, ascending);
		cout << "Ascending sorted" << "[" << algorithm_list[j] << "]: " << endl;
		print_list(list, N);
		cout << "Descending sorted" << "[" << algorithm_list[j] << "]: " << endl;
		fps[j](list, N, descending);
		print_list(list, N);
		cout << endl;
	}

	delete[] list;
	cout << "Happy Coding~~\n";
}
#endif
