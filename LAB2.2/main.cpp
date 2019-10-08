#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(const string, const char);

int main() {
   string filename;
   char ch;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;
   
   cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(const string filename, const char chr) {
	ifstream inFS(filename);
	
	if (!inFS.is_open()) {
		cout << "Error opening " << filename << endl;
		exit(1);
	}
	
	int result = 0;
	char charInput;
	
	while (inFS.get(charInput)) {
		if (chr == charInput) {
			++result;
		}
	}
	
	return result;
}