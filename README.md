# Fisher & Paykel Healthcare Product Development Engineer Challenge

## How to build and run the project

I have used GNU Make to build the project. Once that is set up. Simply type `make` when in the folder to build the executable, and then run `./main <flow.csv> <pressure.csv> <humdity.csv>` or use `main.exe` depending on which system you're on. I have tested this on Windows 10 and on Ubuntu 18. 

I have included my own CSV files that I tested the program on. 

1. flow_test.csv
2. pressure_test.csv
3. humdity_test.csv

The first three are my default settings so if you run `./main` with no arguments, it will use those files.

## Description

### End result
I chose to build a simple solution to this problem. The program takes in three csv files and outputs one csv file. This seemed like a simple way to solve the problem as it satisfies the requirements of being able to "record all the inputs in an efficient manner that can later be inspected and played back". CSVs are ideal for this purpose because common programs like but excel and calc make it easy for anyone to review data, run calculations, and graph data. 

### Assumptions about input CSV files
I assume that each sensor outputs an unsingned int as a time value and then a double that is its measurement at that time. So each line in the sensor file may look like `1558857157,69.25` for example. 

### Design
Initially, I followed a procedural approach to the problem, where I went through and solved it. The reason for this was that the problem is simple enough that writing classes actually increases code length. However, in the end I rewrote it with a **SensorFile** class because I was doing the same operations on each of the three input CSVs over a couple of times over, and that's a good point to put those things into a class. 

### Side Note
I also wrote a very small Timer class to time my program as it went up against big files and to test different approaches to the problem. This is completely irrelevant to the problem and was just for me to check my work, but I left it in there because it gives you a time output, which may be interesting. 

I also wrote a small program big_file_generator.cpp. This was just for me to make files that were thousands of entries long to test my program against and time. 

You can use big_file_generator by typing `make generate` and then `./generate <filename to create.csv> <number of entries>`. This is how I tested my program on larger file sizes. I didn't upload any of these files though, as they are easy to create and a pain to upload. 

