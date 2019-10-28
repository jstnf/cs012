#include <string>
#include <vector>

using namespace std;

#include "Student.h"

Student::Student(const string name) {
    this->name = name;
    totalQuizScore = 0;
    numQuizzes = 0;
}

Student::Student(const string name, const int score) {
    this->name = name;
    totalQuizScore = score;
    numQuizzes = 1;
}

string Student::get_name() const {
    return name;
}

void Student::add_quiz(const int score) {
    totalQuizScore += score;
    numQuizzes++;
}

int Student::get_total_score() const {
    return totalQuizScore;
}

int Student::get_average_score() const {
    return totalQuizScore / numQuizzes;
}