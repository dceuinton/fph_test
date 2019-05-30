/*
Author:  Dale Euinton
Purpose: The goal of this program is to take 3 CSV files from 3 different sensors
		 and combine them into 1 CSV with all the data. Each file will have a time
		 measurement and a sensor value to add to the CSV and each sensor is given
		 its own columns in which to store the values.

Note:	 SensorFile handles the reading and writing of values of a input file. 
		 Timer handles some basic clock functions for measuring the program.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "timer.h"
#include "SensorFile.h"

using namespace std;

int main(int argc, char** argv) {

	Timer stopwatch;

	// Initial values to test with
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

	SensorFile flowFile(flowFileName);
	SensorFile pressureFile(pressureFileName);
	SensorFile humidityFile(humidityFileName);
	ofstream outputFile(outputFileName, ios::out | ios::app);

	char c(',');

	stopwatch.start();

	while (!flowFile.eof() || !pressureFile.eof() || !humidityFile.eof()) {
		
		if (!flowFile.eof()) {
			flowFile.readLine();
			flowFile.writeLine(outputFile);
		} else {
			outputFile << c << c;
		}

		if (!pressureFile.eof()) {
			pressureFile.readLine();
			pressureFile.writeLine(outputFile);
		} else {
			outputFile << c << c;
		}

		if (!humidityFile.eof()) {
			humidityFile.readLine();
			humidityFile.writeLine(outputFile);
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