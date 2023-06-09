
using namespace std;

#include <iostream>
#include <string>
#include <algorithm>

class Student {
private:
    std::string name;
    int id;
    double gpa;

public:
    void setName(const std::string& studentName) {
        name = studentName;
    }

    void setID(int studentID) {
        id = studentID;
    }

    void setGPA(double studentGPA) {
        gpa = studentGPA;
    }

    std::string getName() const {
        return name;
    }

    int getID() const {
        return id;
    }

    double getGPA() const {
        return gpa;
    }
};

bool compareByGPA(const Student& student1, const Student& student2) {
    return student1.getGPA() > student2.getGPA();
}

int main() {
  int MAX_STUDENTS ;
  cout << "Enter the number of students: ";
  cin >>MAX_STUDENTS;
    
  Student students[MAX_STUDENTS];

    std::cout << "Welcome to the student information system!" << std::endl;
    std::cout << "Enter information for " << MAX_STUDENTS << " students:" << std::endl;

    for (int i = 0; i < MAX_STUDENTS; i++) {
        std::string name;
        int id;
        double gpa;

        std::cout << "\nStudent " << (i + 1) << ":\n";
        std::cout << "Enter name: ";
        std::getline(std::cin >> std::ws, name);

        std::cout << "Enter ID: ";
        std::cin >> id;

        std::cout << "Enter GPA: ";
        std::cin >> gpa;

        students[i].setName(name);
        students[i].setID(id);
        students[i].setGPA(gpa);
    }

    // Sort students by GPA in descending order
    std::sort(students, students + MAX_STUDENTS, compareByGPA);

    std::cout << "\nStudent Information (sorted by GPA in descending order):\n";
    for (int i = 0; i < MAX_STUDENTS; i++) {
        std::cout << "Student " << (i + 1) << ":\n";
        std::cout << "Name: " << students[i].getName() << std::endl;
        std::cout << "ID: " << students[i].getID() << std::endl;
        std::cout << "GPA: " << students[i].getGPA() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Thank you for using the student information system!" << std::endl;

    return 0;
}




