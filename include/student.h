#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define NAME_LEN     50
#define FILE_NAME    "students.dat"

// ─── Struct: Blueprint of a Student record ───────────────────────
typedef struct {
    int  id;
    char name[NAME_LEN];
    int  age;
    float gpa;
} Student;

// ─── Function Prototypes ──────────────────────────────────────────
void addStudent();
void viewAllStudents();
void searchStudent();
void deleteStudent();
void updateStudent();
void saveToFile(Student students[], int count);
int  loadFromFile(Student students[]);

#endif