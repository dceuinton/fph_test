#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "timer.h"
#include "SensorFile.h"

using namespace std;

int main(int argc, char** argv) {

	Timer stopwatch;

	string flowFileName = "flow_test.csv";
	string pressureFileName = "pressure_test.csv";
	string humidityFileName = "humidity_test.csv";
	string outputFileName = "blackbox_results.csv";

	if (argc == 1) {
		cout << "Using default settings" << endl;
	} else if (argc == 4) {
		flowFileName.assign(argv[1]);
		pressureFileName.assign(argv[2]);
		humidityFileName.assign(argv[3]);
	} else if (argc == 5) {
		flowFileName.assign(argv[1]);
		pressureFileName.assign(argv[2]);
		humidityFileName.assign(argv[3]);
		outputFileName.assign(argv[4]);
	} else {
		cout << "Usage: ./main <flow csv filepath> <pressure csv filepath> <humidity csv filepath> <optional: output csv filename>" << endl;
		return -1;
	}

	ifstream flowFile(flowFileName, ifstream::in);
	ifstream pressureFile(pressureFileName, ifstream::in);
	ifstream humidityFile(humidityFileName, ifstream::in);
	ofstream outputFile(outputFileName, ios::out | ios::app);

	unsigned int flowTime(-1), pressureTime(-1), humidityTime(-1);
	double flowValue(-1), pressureValue(-1), humidityValue(-1);
	char c(',');

	stopwatch.start();

	while (!flowFile.eof() || !pressureFile.eof() || !humidityFile.eof()) {
		
		if (!flowFile.eof()) {
			flowFile >> flowTime >> c >> flowValue;
			outputFile << flowTime << c << flowValue << c;
		} else {
			outputFile << c << c;
		}

		if (!pressureFile.eof()) {
			pressureFile >> pressureTime >> c >> pressureValue;
			outputFile << pressureTime << c << pressureValue << c;
		} else {
			outputFile << c << c;
		}

		if (!humidityFile.eof()) {
			humidityFile >> humidityTime >> c >> humidityValue;
			outputFile << humidityTime << c << humidityValue;
		} else {
			outputFile << c;
		}

		outputFile << "\n";
	}

	stopwatch.stop();

	cout << "Time taken in milliseconds for reading and writing was: " << stopwatch.milliseconds() << endl;

	flowFile.close();
	pressureFile.close();
	humidityFile.close();
	outputFile.close();

	return 0;
}