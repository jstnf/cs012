using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student {
    private:
      string name;
      int totalQuizScore;
      int numQuizzes;
    public:
      Student(const string);
      Student(const string, const int);
      string get_name() const;
      void add_quiz(const int);
      int get_total_score() const;
      int get_average_score() const;
}

#endif STUDENT_H