/*
* On my honour, I pledge that I have neither received nor provided improper
* assistance in the completion of this assignment.
* Signed: ______youyoungkim_______   Section: ___03____   Student Number: ________21800147_________
*/


#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "nowic.h"

using namespace std;

const int STARTING_SAMPLES = 100;

void bubbleSort(int *list, int n);
void insertionSort(int *list, int n);
void quickSort(int *list, int n);
void selectionSort(int *list, int n);

void sortProfiling(void (*sortFunc)(int *, int), int *list, int n,  int starting_samples = STARTING_SAMPLES);

void printList(int *list, int n, int max_print, int per_line);
void randomize(int list[], int n);

// Randomize: shuffle the sequence
// For every sample, starting from the first element in the list,
// it is swapped with the element randomly selected by the index
// generated by a 'real' (not pseudo) random number out of from
// 0 to N - 1.
// Hint: Refer to rand() and srand() function document.
void randomize(int list[], int n) {
	DPRINT(cout << ">randomize...N=" << n << endl;)
	srand((unsigned)time(NULL));

	int j = 0;
	int temp = 0;
	for(int i = 0; i < n; i++){
		j = rand() % n;
		temp = list[i];
		list[i] = list[j];
		list[j] = temp;

	}

	DPRINT(cout << "<randomize" << endl;)
}

// When we have a long list, we want to print some in the front
// part of the list and some in the rear part of the list.
//
// The max+print specifies the number of samples in either front
// or rear part of the list.  The per_line determines how many
// samples prints per line.
//
// If max_print is larger than or equal to the sample size N,
// prints max_print/2 samples only.
// For example:
// Case 1) N = 12, max_print = 100, per_line = 20
//		0	1	2	3	4	5
//		6	7	8	9  10  11
// Case 2) N = 12, max_print = 100, per_line = 4
//		0	1	2	3
//		4	5
//		6	7	8	9
//	   10  11
// Case 3) N = 12, max_print = 4, per_line = 6
//		0	1	2	3
//		8	9  10  11
// There should be a line feed between the front part and
// the rear part.
// Observe the sample runs using sortx.exe provided with you.

// Optionally, you may have this kind of a help function.
// void _printList(int *list, int start, int end, int per_line)

//void printList(int *list, int N, int max_print, int per_line)
void printList(int *list, int N, int max_print, int per_line){
	DPRINT(cout << ">printList...N=" << N << " max_print=" << max_print << endl;)

		// your code here
		// Optionally, you may create a help function such as _printList()/
		int number;

    if (max_print >= N / 2){
      int a = 0;
			for(int i = 0; i < N; i++){
        a++;
				cout << setw(10) << list[i];
				if(a == per_line){
					a = 0;
          cout << endl;
				}
			}
			cout << endl;
    }
  	else {
      if (max_print >= N) max_print = N / 2;
  		number = N - max_print;
      int a = 0;
			for(int i = 0; i < max_print; i++){
        a++;
				cout << setw(10) << list[i];
				if(a == per_line){
					a = 0;
          cout << endl;
				}
			}
			cout << endl;

      a = 0;
			for(int i = number; i < N; i++){
				a++;
        cout << setw(10) << list[i];
				if(a == per_line){
					a = 0;
          cout << endl;
				}
			}
      cout << endl;
  	}

	DPRINT(cout << "<printList" << endl;)
}

// sortDriver to test sort functions or algorithms.
int main(int argc, char *argv[]) {
	int N = 0;						// default sample size
	int keyin;
	int *list = NULL;				// input and output buffer
	int max_print = 10;				// default max_print(=front_part+last_part)
	int per_line = max_print / 2;	// default samples per line to print
	clock_t start, end;
	char randomized = 'N';
	char option_char;
	char option_str[512];
	char algorithm_list[4][20] = {"Bubble", "Insertion", "Quicksort", "Selection"};
	enum algorithm_enum { BUBBLE, INSERTION, QUICKSORT, SELECTION };
	int  algorithm_chosen = SELECTION;  // default algorithm chosenconst int STARTING_SAMPLES = 100;
	DPRINT(cout << ">main...N=" << N << endl;)


	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);
  void(*sortFn[])(int *, int) = { bubbleSort, insertionSort, quickSort, selectionSort };

	do {
		sprintf(option_str, "[sort=%s N=%d randomized=%c max_print=%d per_line=%d]",
			algorithm_list[algorithm_chosen], N, randomized, max_print, per_line);
		cout << "\n\tOPTIONS: " << option_str << "\n"
			"\tn - number of samples size and initialize\n"
			"\tr - randomize(shuffle) input samples\n"
      "\ta - algorithm to run\n"
      "\ts - sort()\n"
      "\tp - profiling\n"
      "\tm - max samples to display per front or rear\n"
			"\td - max samples to display per line\n";


		option_char = GetChar("\tCommand(q to quit): ");
		DPRINT(cout << "option_char = " << option_char << endl;)

		switch (option_char) {
		case 'a': DPRINT(cout << "case = " << option_char << endl;)

			switch (GetChar("\tEnter b for bubble, i for insertion, s for selection, q for quick sort: ")) {

			// your code here
      case 'b':	algorithm_chosen = 0;
								break;

			case 'i': algorithm_chosen = 1;
								break;

			case 'q': algorithm_chosen = 2;
								break;

      case 's': algorithm_chosen = 3;
          			break;

			default: { cout << "\tNo such an algorithm available. Try it again.\n"; break; }
			}

			//////////////
			break;

		case 'n': DPRINT(cout << "case = " << option_char;)

			keyin = GetInt("\tEnter input sample size: ");
			if (keyin < 1) {
				cout << "\tExpecting a number larger than 0";
				break;
			}

			// set N with the new keyin value
			N = keyin;
			// before allocating the new list, free the old list if not NULL
			list = nullptr;
			// allocate memory for new data samples
			list = new int[N];
			// Fill the list with numbers from 0 to n - 1
			for(int i = 0; i < N; i++){
				list[i] = i;
			}

			printList(list, N, max_print, per_line);


			break;

		case 'r': DPRINT(cout << "case = " << option_char << endl;)
			if (N <= 1) {
				cout << "\tSet sample size first or larger\n";
				break;
			}

			randomize(list, N);
			printList(list, N, max_print, per_line);

			break;

		case 's': DPRINT(cout << "case = " << option_char << endl;)
			if (N <= 0) {
				cout << "\tSet sample size first\n";
				break;
			}
			cout << "\tThe clock ticks and " << algorithm_list[algorithm_chosen] << " begins...\n";
			start = clock();

			sortFn[algorithm_chosen](list, N);

			printList(list, N, max_print, per_line);

			end = clock();
			cout << endl << "\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";
			break;

    case 'p': DPRINT(cout << "case = " << option_char << endl;)

      if (N <= 0) {
        cout << "\tFor profiling, set sample size > 100\n";
        break;
      }

      sortProfiling(sortFn[algorithm_chosen], list, N, STARTING_SAMPLES);

  		break;

		case 'm': DPRINT(cout << "case = " << option_char << endl;)

			cout << "\tEnter max sample size to display: ";
			cin >> max_print;

			printList(list, N, max_print, per_line);

			break;
		case 'd': DPRINT(cout << "case = " << option_char << endl;)

			cout << "\tEnter max sample per line to display: ";
			cin >> per_line;

			printList(list, N, max_print, per_line);

			break;
		default:
			break;
		}
	} while (option_char != 'q');

	if (list != NULL) free(list);
	// system("pause");
	DPRINT(cout << ">main" << endl;)
	return EXIT_SUCCESS;
}