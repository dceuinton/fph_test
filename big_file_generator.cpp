#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
	
	string fileName = "flowTest.csv";
	int iterations = 5000000;

	if (argc >= 2) {
		fileName.assign(argv[1]);
	}
	if (argc == 3) {
		iterations = strtol(argv[2], NULL, 10);
	}

	cout << "Generating file: " << fileName << " with " << iterations << " lines" << endl;

	ofstream outputFile(fileName, ios::app);

	for (int i = 0; i < iterations; ++i) {
		outputFile << 1558857153 << "," << 12.65 << "\n";
	}

	outputFile.close();

	return 0;
}