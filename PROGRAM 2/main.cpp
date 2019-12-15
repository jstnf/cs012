#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here

Date::Date() {
	this->day = 1;
	this->month = 1;
	this->monthName = this->name(this->month);
	this->year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y) {
	bool error = false;
	this->year = y;
	
	if (m > 12) {
		this->month = 12;
		this->monthName = "December";
		error = true;
	}
	else if (m < 1) {
		this->month = 1;
		this->monthName = "January";
		error = true;
	}
	else {
		this->month = m;
		this->monthName = this->name(m);
	}
	
	if (d > this->daysPerMonth(this->month, y)) {
		this->day = this->daysPerMonth(this->month, y);
		error = true;
	}
	else if (d < 1) {
		this->day = 1;
		error = true;
	}
	else
	{
		this->day = d;
	}
	
	if (error) {
		cout << "Invalid date values: Date corrected to ";
		printNumeric();
		cout << "." << endl;
	}
}

Date::Date(const string &mn, unsigned d, unsigned y) {
	// if name is invalid, return 13 from number()
	if (this->number(mn) == 13) {
		this->month = 1;
		this->monthName = "January";
		this->day = 1;
		this->year = 2000;
		cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
	}
	else {
		this->monthName = mn;
		this->month = this->number(mn);
		this->year = y;
        bool error = false;
		if (d > this->daysPerMonth(this->month, this->year)) {
			this->day = this->daysPerMonth(this->month, this->year);
			error = true;
		}
        else if (d < 1)
        {
            this->day = 1;
            error = true;
        }
		else
		{
			this->day = d;
		}
        
        // convert lower to upper case
        if (this->monthName.at(0) > 96) {
            this->monthName.at(0) = this->monthName.at(0) - 32;
        }
        
        if (error) {
            cout << "Invalid date values: Date corrected to ";
			printNumeric();
			cout << "." << endl;
        }
	}
}

void Date::printNumeric() const {
	cout << this->month << "/" << this->day << "/" << this->year;
}

void Date::printAlpha() const {
	cout << this->monthName << " " << this->day << ", " << this->year;
}

bool Date::isLeap(unsigned y) const {
	if (y % 4 == 0) {
		if (y % 100 == 0) {
			return y % 400 == 0;
		}
		return true;
	}
    return false;
}

/*
* 31    January
* 28/29 February
* 31    March
* 30    April
* 31    May
* 30    June
* 31    July
* 31    August
* 30    September
* 31    October
* 30    November
* 31    December
*/
unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
	if (m == 2) {
		if (this->isLeap(y)) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		return 31;
	}
	else {
		return 30;
	}
}

string Date::name(unsigned m) const {
	vector<string> monthNames = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	return monthNames.at(m - 1);
}

unsigned Date::number(const string &mn) const {
	string tM = mn;
	if (tM == "january" || tM == "January") {
		return 1;
	}
	else if (tM == "february" || tM == "February") {
		return 2;
	}
	else if (tM == "march" || tM == "March") {
		return 3;
	}
	else if (tM == "april" || tM == "April") {
		return 4;
	}
	else if (tM == "may" || tM == "May") {
		return 5;
	}
	else if (tM == "june" || tM == "June") {
		return 6;
	}
	else if (tM == "july" || tM == "July") {
		return 7;
	}
	else if (tM == "august" || tM == "August") {
		return 8;
	}
	else if (tM == "september" || tM == "September") {
		return 9;
	}
	else if (tM == "october" || tM == "October") {
		return 10;
	}
	else if (tM == "november" || tM == "November") {
		return 11;
	}
	else if (tM == "december" || tM == "December") {
		return 12;
	}
	else {
		return 13;
	}
}

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
