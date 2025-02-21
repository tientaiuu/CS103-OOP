#include "Student.h"

int main() {
    CClassStudent classStudent;
    classStudent.Input();

    cout << "List of students:" << endl;
    classStudent.Output();

    cout << "Max student: " << endl;
    CStudent* maxStudent = classStudent.Max();
    if (maxStudent != nullptr) {
        cout << *maxStudent << endl;
    } else {
        cout << "No student found." << endl;
    }

    cout << "Min student: " << endl;
    CStudent* minStudent = classStudent.Min();
    if (minStudent != nullptr) {
        cout << *minStudent << endl;
    } else {
        cout << "No student found." << endl;
    }

    cout << "Ranking of students:" << endl;
    classStudent.Rank();

    long idToDelete;
    cout << "ID to delete: ";
    cin >> idToDelete;
    classStudent.Delete(idToDelete);
    cout << "List of students after delete: " << endl;
    classStudent.Output();

    long idToFind;
    cout << "ID to find: ";
    cin >> idToFind;
    CStudent* foundStudent = classStudent.Find(idToFind);
    if (foundStudent != nullptr) {
        cout << "Student found:" << endl;
        cout << *foundStudent << endl;
    } else {
        cout << "Student not found." << endl;
    }

    return 0;
}