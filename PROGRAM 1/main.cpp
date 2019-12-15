#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main(int argc, char* argv[]) {
	// Check for appropriate args
	if (argc != 2) {
		cout << "Usage: progname inputFile" << endl;
		return 1;
	}
	
	// Declare vectors
	vector<double> angles;
	vector<double> lifts;
	
	// Get filename
	string filename = argv[1];
	
	// Read the data and insert into vectors
	readData(filename, angles, lifts);
	
	// Check order and reorder
	if (!isOrdered(angles)) {
		reorder(angles, lifts);
	}
	
	// Keep repeating until you get no
	bool doAgain = true;
	while (doAgain) {
		// Get the user's flight-path angle, keep trying until in-bounds
		bool inBounds = false;
		double newAngle;
		while (!inBounds) {
			cout << "What flight-path angle?" << endl;
			cout << "Min: " << angles.at(0) << " Max: " << angles.at(angles.size() - 1) << endl;
			cin >> newAngle;
			if (newAngle >= angles.at(0) && newAngle <= angles.at(angles.size() - 1)) {
				inBounds = true;
			}
			else {
				cout << "The angle is out of bounds. Please try again." << endl;
			}
		}
		
		// Output the result
		cout << "Coefficient of lift: " << interpolation(newAngle, angles, lifts) << endl;
		
		// Ask if they want to do it again
		bool validAnswer = false;
		while (!validAnswer) {
			string option;
			cout << "Would you like to calculate another angle? (Enter 'Yes' or 'No'): " << endl;
			cin >> option;
			
			if (option == "Yes") {
				validAnswer = true; // doAgain is already true
			}
			else if (option == "No") {
				validAnswer = true;
				doAgain = false;
				cout << "Goodbye!" << endl;
			}
			else {
				cout << "Invalid answer." << endl;
			}
		}
	}
	
	return 0;
}

void readData(const string &filename, vector<double> &angles, vector<double> &lifts) {
	ifstream inFS(filename);
	
	if (!inFS.is_open()) {
		cout << "Error opening " << filename << endl;
		exit(1);
	}
	
	double angleInput;
	double liftInput;
	
	while (inFS >> angleInput) {
		if (inFS >> liftInput) { // Immediately try for a second double
			angles.push_back(angleInput);
			lifts.push_back(liftInput);
		}
		else { // There was an odd number of doubles, discard last input
			break; // End the loop
		}
	}
	
	// Close the ifstream
	inFS.close();
}

bool isOrdered(const vector<double> &angles) {
    if (angles.size() == 0) {
        return true;
    }
    
	double lastAngle = angles.at(0);
	
	for (unsigned i = 1; i < angles.size(); ++i) {
		if (angles.at(i) < lastAngle) {
			return false;
		}
		
		lastAngle = angles.at(i);
	}
	
	return true;
}

void reorder(vector<double> &angles, vector<double> &lifts) {
    for (unsigned i = 0; i < angles.size(); ++i) {
        unsigned indexOfSmallest = i;
        for (unsigned j = i; j < angles.size(); ++j) {
            if (angles.at(j) < angles.at(indexOfSmallest)) {
                indexOfSmallest = j;
            }
        }
        
        double tempAngle = angles.at(indexOfSmallest);
        double tempLift = lifts.at(indexOfSmallest);
        
        angles.erase(angles.begin() + indexOfSmallest);
        lifts.erase(lifts.begin() + indexOfSmallest);
        
        angles.insert(angles.begin() + i, tempAngle);
        lifts.insert(lifts.begin() + i, tempLift);
    }
}

double interpolation(double angle, const vector<double> &angles, const vector<double> &lifts) {
	unsigned next = 1; // This will land on the index that is next in angles from angle
	
	while (angle > angles.at(next)) {
		++next;
	}
	
	/*
	*  part1 = (b - a) / (c - a)
	*  part2 = f(c) - f(a)
	*  eq: f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))
	*/ 
	double part1 = (angle - angles.at(next - 1)) / (angles.at(next) - angles.at(next - 1));
	double part2 = lifts.at(next) - lifts.at(next - 1);
	
	return lifts.at(next - 1) + part1 * part2;
}