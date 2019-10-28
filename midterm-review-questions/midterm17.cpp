#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string fileName;
    int spaces;
    
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " file_name" << endl;
        return 1;
    }
    else if (argc == 2) {
        fileName = argv[1];
        spaces = 3;
    }
    else {
        fileName = argv[1];
        istringstream inSS(argv[2]);
        inSS >> spaces;
    }
    
    ifstream inFS;
    inFS.open(fileName);
    
    if (!inFS.is_open()) {
        cout << "Unable to open file " << fileName << "." << endl;
        return 1;
    }
    
    string str;
    string all;
    bool first = true;
    
    while (getline(inFS, str, '\t')) {
        if (first) {
            first = false;
        }
        else {
            all.insert(all.size(), spaces, ' ');
        }
        
        all += str;
    }
    
    inFS.close();
    
    ofstream outFS;
    outFS.open(fileName); // overwrites the file
    
    if (!outFS.is_open()) {
        cout << "Unable to open file " << fileName << "." << endl;
        return 1;
    }
    
    outFS << all;
    
    outFS.close();
    
    return 0;
}