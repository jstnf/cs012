#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(const string filename);

int main() {
   string filename;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Sum: " << fileSum(filename) << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum(const string filename) {
   ifstream inFS(filename);
   
   if (!inFS.is_open()) {
	   cout << "Error opening " << filename << endl;
	   exit(1);
   }
   
   int sum = 0;
   int input;
   
   while (inFS >> input) {
	   sum = sum + input;
   }
   
   return sum;
}