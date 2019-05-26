
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	string inputFileName = "test1.csv";

	ifstream inputFile(inputFileName, ifstream::in);

	int xt(-1), yt(-1), zt(-1);
	double x(-1.0), y(-1), z(-1);
	char c('z');
	vector<int> xTimes, yTimes, zTimes; 
	vector<double> xValues, yValues, zValues;

	while (inputFile >> xt >> c >> x >> c >> yt >> c >> y >> c >> zt >> c >> z) {
		xTimes.push_back(xt);
		xValues.push_back(x);
		yTimes.push_back(yt);
		yValues.push_back(y);
		zTimes.push_back(zt);
		zValues.push_back(z);
	}

	for (int i = 0; i < xTimes.size(); ++i)	{
		cout << xTimes[i] << endl;
	}

	cout << "Hello world!" << endl;

	return 0;
}