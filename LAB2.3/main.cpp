#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   if (argc != 3) {
	   cout << "Usage: progname inputFile outputFile" << endl;
	   return 1;
   }
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   
   // Create input stream and open input csv file.
   ifstream inFS(inputFile);
   
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!inFS.is_open()) {
	   cout << "Error opening " << inputFile << endl;
	   return 1;
   }
   
   // Read in integers from input file to vector.
   vector<int> intVector;
   string inputString;
   int inputInt;
   bool done = false;
   while (!done) {
	   inFS >> inputInt;
	   intVector.push_back(inputInt);
	   if (!inFS.eof()) { // After grabbing int, check for more
		   inFS.clear(); // Clear the error state
		   char dummyChar;
		   inFS >> dummyChar; // Take the comma
	   }
	   else
	   {
		   done = true; // we've reached the end, so we're done
	   }
   }
   
   // Close input stream.
   inFS.close();
   
   // Get integer average of all values read in.4
   int average;
   int total = 0;
   
   for (unsigned i = 0; i < intVector.size(); ++i) {
	   total = total + intVector.at(i);
   }
   average = total / intVector.size();
   
   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned i = 0; i < intVector.size(); ++i) {
	   intVector.at(i) = intVector.at(i) - average;
   }
   
   // Create output stream and open/create output csv file.
   ofstream outFS(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open()) {
	   cout << "Error opening " << outputFile << endl;
	   return 1;
   }
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned i = 0; i < intVector.size(); ++i) {
	   outFS << intVector.at(i);
	   if (i + 1 < intVector.size()) {
		   outFS << ',';
	   }
   }
   
   // Close output stream.
   outFS.close();
   
   return 0;
}