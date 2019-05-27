
/** TODO: 
	- Get input from 3 different files
	- Handle input in chunks
	- Connect input to output file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	string inputFileName = "flow_test.csv";
	string outputFileName = "results.csv";

	ifstream inputFile(inputFileName, ifstream::in);

	int xt(-1), yt(-1), zt(-1);
	double x(-1.0), y(-1), z(-1);
	char c('z');
	vector<int> xTimes, yTimes, zTimes; 				// Could be worth using arrays as simpler
	vector<double> xValues, yValues, zValues;

	while (inputFile >> xt >> c >> x) {
		xTimes.push_back(xt);
		xValues.push_back(x);
	}

	for (int i = 0; i < xTimes.size(); ++i)	{
		cout << xTimes[i] << ", " << xValues[i] << endl;
	}

	ofstream outputFile(outputFileName, ios::out | ios::app);

	if (outputFile.is_open()) {
		for (int i = 0; i < xTimes.size(); ++i) {
			outputFile << xTimes[i] << "," << xValues[i] << "\n";
		}
	}

	inputFile.close();
	outputFile.close();

	return 0;
}