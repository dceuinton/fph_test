#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SensorFile {
	public:
		SensorFile(string filePath);

		bool eof();
		void readLine();
		void writeLine(ofstream &outputFile);
		void close();

	private:
		ifstream mFile;
		unsigned int mTime;
		double mValue;
		char mC;
};