#include <iostream>
#include <vector>
#include <iomanip> // Required for setprecision

using namespace std;

// Function to convert grade letter to grade points
double gradeToPoints(char grade) {
    switch (toupper(grade)) { // Convert to uppercase for case-insensitivity
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return -1.0; // Indicate invalid grade
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // Vectors to store course details
    vector<char> grades(numCourses);
    vector<int> creditHours(numCourses);

    double totalGradePoints = 0.0;
    int totalCredits = 0;

    // Input course details and calculate total grade points and credits
    for (int i = 0; i < numCourses; ++i) {
        cout << "\nCourse " << i + 1 << ":\n";
        
        // Input and validate grade
        char grade;
        cout << "Enter grade (A, B, C, D, F): ";
        cin >> grade;
        double points = gradeToPoints(grade);
        while (points == -1.0) { // Keep prompting for valid grade
            cout << "Invalid grade. Please enter A, B, C, D, or F: ";
            cin >> grade;
            points = gradeToPoints(grade);
        }
        grades[i] = toupper(grade);

        // Input and validate credit hours
        int credits;
        cout << "Enter credit hours: ";
        cin >> credits;
        while (credits <= 0) { // Ensure positive credit hours
            cout << "Credit hours must be positive. Enter again: ";
            cin >> credits;
        }
        creditHours[i] = credits;

        totalGradePoints += points * credits;
        totalCredits += credits;
    }

    // Display individual course grades
    cout << "\n--- Individual Course Grades ---\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course " << i + 1 << ": Grade " << grades[i] << ", Credits " << creditHours[i] << endl;
    }

    // Calculate and display CGPA
    if (totalCredits > 0) {
        double cgpa = totalGradePoints / totalCredits;
        cout << "\n------------------------------\n";
        cout << "Total Credits Completed: " << totalCredits << endl;
        cout << fixed << setprecision(2) << "Final CGPA: " << cgpa << endl; // Format to two decimal places
    } else {
        cout << "\nNo courses entered, CGPA cannot be calculated.\n";
    }

    return 0;
}
