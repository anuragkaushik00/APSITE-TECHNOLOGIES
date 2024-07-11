#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Student structure
struct Student {
    int rollNumber;
    string firstName;
    string lastName;
    string course;
};

// Function to add a student
void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter roll number: ";
    cin >> newStudent.rollNumber;
    
    // Check for uniqueness of roll number
    if (find_if(students.begin(), students.end(),
                [&newStudent](const Student& s) { return s.rollNumber == newStudent.rollNumber; }) != students.end()) {
        cout << "Error: Roll number already exists.\n";
        return;
    }

    cout << "Enter first name: ";
    cin >> newStudent.firstName;
    cout << "Enter last name: ";
    cin >> newStudent.lastName;
    cout << "Enter course: ";
    cin >> newStudent.course;

    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}

// Function to find a student by roll number
void findStudentByRoll(const vector<Student>& students) {
    int rollNumber;
    cout << "Enter roll number: ";
    cin >> rollNumber;

    auto it = find_if(students.begin(), students.end(),
                      [&rollNumber](const Student& s) { return s.rollNumber == rollNumber; });

    if (it != students.end()) {
        cout << "Student found:\n";
        cout << "Roll Number: " << it->rollNumber << endl;
        cout << "First Name: " << it->firstName << endl;
        cout << "Last Name: " << it->lastName << endl;
        cout << "Course: " << it->course << endl;
    } else {
        cout << "Student not found.\n";
    }
}

// Function to find a student by first name
void findStudentByName(const vector<Student>& students) {
    string firstName;
    cout << "Enter first name: ";
    cin >> firstName;

    for (const auto& student : students) {
        if (student.firstName == firstName) {
            cout << "Student found:\n";
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Last Name: " << student.lastName << endl;
            cout << "Course: " << student.course << endl;
        }
    }
}

// Function to find students registered in a course
void findStudentsByCourse(const vector<Student>& students) {
    string course;
    cout << "Enter course: ";
    cin >> course;

    for (const auto& student : students) {
        if (student.course == course) {
            cout << "Student found:\n";
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "First Name: " << student.firstName << endl;
            cout << "Last Name: " << student.lastName << endl;
        }
    }
}

// Function to count the number of students
void countStudents(const vector<Student>& students) {
    cout << "Total number of students: " << students.size() << endl;
}

// Function to delete a student
void deleteStudent(vector<Student>& students) {
    int rollNumber;
    cout << "Enter roll number: ";
    cin >> rollNumber;

    auto it = find_if(students.begin(), students.end(),
                      [&rollNumber](const Student& s) { return s.rollNumber == rollNumber; });

    if (it != students.end()) {
        students.erase(it);
        cout << "Student deleted successfully!\n";
    } else {
        cout << "Student not found.\n";
    }
}

// Function to update a student
void updateStudent(vector<Student>& students) {
    int rollNumber;
    cout << "Enter roll number: ";
    cin >> rollNumber;

    auto it = find_if(students.begin(), students.end(),
                      [&rollNumber](const Student& s) { return s.rollNumber == rollNumber; });

    if (it != students.end()) {
        cout << "What do you want to update?\n";
        cout << "1. First name\n";
        cout << "2. Last name\n";
        cout << "3. Course\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter new first name: ";
                cin >> it->firstName;
                break;
            case 2:
                cout << "Enter new last name: ";
                cin >> it->lastName;
                break;
            case 3:
                cout << "Enter new course: ";
                cin >> it->course;
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }

        cout << "Student updated successfully!\n";
    } else {
        cout << "Student not found.\n";
    }
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Information Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Find Student by Roll Number\n";
        cout << "3. Find Student by First Name\n";
        cout << "4. Find Students by Course\n";
        cout << "5. Count Students\n";
        cout << "6. Delete Student\n";
        cout << "7. Update Student\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                findStudentByRoll(students);
                break;
            case 3:
                findStudentByName(students);
                break;
            case 4:
                findStudentsByCourse(students);
                break;
            case 5:
                countStudents(students);
                break;
            case 6:
                deleteStudent(students);
                break;
            case 7:
                updateStudent(students);
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 8);

    return 0;
}