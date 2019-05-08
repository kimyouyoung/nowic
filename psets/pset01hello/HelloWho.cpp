#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    // Use setvbuf() to prevent the output from buffered on console.
    // setvbuf(stdout, NULL, _IONBF, 0);

	for (int i = 0; i < argc; i++)
		cout << argv[i] << "!\n";

	cout << "Hello World!\n";

    // Use system("pause") to prevent the terminal from disappearing
    // as soon as the program terminates such as Visual Studio sometimes.
    // system("pause");
    return EXIT_SUCCESS;
}
