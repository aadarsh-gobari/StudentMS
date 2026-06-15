#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/student.h"

// ─── Global State ─────────────────────────────────────────────────
Student students[MAX_STUDENTS];
int     studentCount = 0;

// ─────────────────────────────────────────────────────────────────
// UTILITY: Clear leftover characters from input buffer
// Called after every scanf to prevent ghost inputs
// ─────────────────────────────────────────────────────────────────
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ─────────────────────────────────────────────────────────────────
// UTILITY: Print a visual divider line
// ─────────────────────────────────────────────────────────────────
void printDivider() {
    printf(CYAN "  ──────────────────────────────────────\n" RESET);
}

// ─────────────────────────────────────────────────────────────────
// UTILITY: Check if a student ID already exists
// Returns 1 (true) if found, 0 (false) if not
// ─────────────────────────────────────────────────────────────────
int idExists(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) return 1;
    }
    return 0;
}

// ─────────────────────────────────────────────────────────────────
// FEATURE 1: Add a New Student
// Concepts: struct field assignment, input validation, arrays
// ─────────────────────────────────────────────────────────────────
void addStudent() {
    // Check capacity
    if (studentCount >= MAX_STUDENTS) {
        printf(RED "\n  [!] Storage full. Cannot add more students.\n" RESET);
        return;
    }

    Student newStudent;

    printf(GREEN "\n  ╔══════════════════════════════════════╗\n");
    printf(      "  ║         ADD NEW STUDENT              ║\n");
    printf(      "  ╚══════════════════════════════════════╝\n" RESET);

    // ── ID ──────────────────────────────────────────────────────
    while (1) {
        printf("  Enter Student ID   : ");
        if (scanf("%d", &newStudent.id) != 1) {
            printf(RED "  [!] Invalid ID. Numbers only.\n" RESET);
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        if (newStudent.id <= 0) {
            printf(RED "  [!] ID must be a positive number.\n" RESET);
            continue;
        }
        if (idExists(newStudent.id)) {
            printf(RED "  [!] ID %d already exists. Use a unique ID.\n" RESET,
                   newStudent.id);
            continue;
        }
        break;  // Valid ID
    }

    // ── Name ────────────────────────────────────────────────────
    printf("  Enter Student Name : ");
    scanf(" %49[^\n]", newStudent.name);
    clearInputBuffer();

    // ── Age ─────────────────────────────────────────────────────
    while (1) {
        printf("  Enter Age          : ");
        if (scanf("%d", &newStudent.age) != 1 ||
            newStudent.age < 5 || newStudent.age > 100) {
            printf(RED "  [!] Enter a valid age (5–100).\n" RESET);
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        break;
    }

    // ── Course ──────────────────────────────────────────────────
    printf("  Enter Course       : ");
    scanf(" %49[^\n]", newStudent.course);
    clearInputBuffer();

    // ── GPA ─────────────────────────────────────────────────────
    while (1) {
        printf("  Enter GPA (0.0–4.0): ");
        if (scanf("%f", &newStudent.gpa) != 1 ||
            newStudent.gpa < 0.0 || newStudent.gpa > 4.0) {
            printf(RED "  [!] GPA must be between 0.0 and 4.0.\n" RESET);
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        break;
    }

    // ── Save to array ───────────────────────────────────────────
    students[studentCount] = newStudent;
    studentCount++;

    printf(GREEN "\n  [✔] Student '%s' added successfully! (Total: %d)\n" RESET,
           newStudent.name, studentCount);
}

// ─────────────────────────────────────────────────────────────────
// FEATURE 2: View All Students
// Concepts: loop through array, formatted printf table
// ─────────────────────────────────────────────────────────────────
void viewAllStudents() {
    printf(CYAN "\n  ╔══════════════════════════════════════════════════════════════╗\n");
    printf(     "  ║                  ALL STUDENTS RECORD                        ║\n");
    printf(     "  ╚══════════════════════════════════════════════════════════════╝\n" RESET);

    if (studentCount == 0) {
        printf(YELLOW "  [i] No students found. Add some first!\n" RESET);
        return;
    }

    // ── Table Header ────────────────────────────────────────────
    printf(BOLD);
    printf("\n  %-6s %-20s %-5s %-20s %-6s\n",
           "ID", "Name", "Age", "Course", "GPA");
    printf(RESET);
    printDivider();

    // ── Table Rows ──────────────────────────────────────────────
    for (int i = 0; i < studentCount; i++) {
        // Color GPA: green if >=3.5, yellow if >=2.5, red if below
        const char *gpaColor =
            (students[i].gpa >= 3.5) ? GREEN :
            (students[i].gpa >= 2.5) ? YELLOW : RED;

        printf("  %-6d %-20s %-5d %-20s %s%.2f%s\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].course,
               gpaColor, students[i].gpa, RESET);
    }

    printDivider();
    printf(BOLD "  Total Students: %d\n\n" RESET, studentCount);
}

// ─────────────────────────────────────────────────────────────────
// STUBS — Implemented in upcoming days
// ─────────────────────────────────────────────────────────────────
void searchStudent() {
    printf(YELLOW "\n  [?] Search — Coming Day 3\n" RESET);
}

void updateStudent() {
    printf(YELLOW "\n  [~] Update — Coming Day 3\n" RESET);
}

void deleteStudent() {
    printf(YELLOW "\n  [-] Delete — Coming Day 4\n" RESET);
}

void saveToFile() {
    printf(YELLOW "\n  [S] Save to File — Coming Day 4\n" RESET);
}

void loadFromFile() {
    printf(YELLOW "\n  [L] Load from File — Coming Day 4\n" RESET);
}