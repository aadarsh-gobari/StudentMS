#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define NAME_LEN     50
#define FILE_NAME    "students.dat"

// ─── ANSI Color Codes for terminal styling ───────────────────────
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"
#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define BOLD    "\033[1m"

// ─── Struct: Blueprint of a Student record ───────────────────────
typedef struct {
    int  id;
    char name[NAME_LEN];
    int  age;
    float gpa;
    char  course[NAME_LEN];
} Student;

// ─── Shared Global State (declared in student.c) ─────────────────
extern Student students[MAX_STUDENTS];
extern int     studentCount;


// ─── Function Prototypes ──────────────────────────────────────────
void addStudent();
void viewAllStudents();
void searchStudent();
void deleteStudent();
void updateStudent();
void saveToFile();
void loadFromFile();
int  idExists(int id);
void clearInputBuffer();
void printDivider();

#endif