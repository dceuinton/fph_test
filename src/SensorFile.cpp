#include "SensorFile.h"

SensorFile::SensorFile(string filePath) {
	mFile.open(filePath);

	if (!mFile.good()) {
		cout << "ERROR: problem with file: " << filePath << endl;
		exit(1);
	}
}

bool SensorFile::eof() {
	return mFile.eof();
}

void SensorFile::readLine() {
	mFile >> mTime >> mC >> mValue;
}

void SensorFile::writeLine(ofstream &outputFile) {
	outputFile << mTime << mC << mValue << mC;
}

void SensorFile::close() {
	mFile.close();
}