#include <stdio.h>
#include <stdlib.h>
#include "../include/student.h"

// ─── Display Menu ─────────────────────────────────────────────────
void displayMenu() {
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║    STUDENT MANAGEMENT SYSTEM  v1.0  ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  1. Add Student                      ║\n");
    printf("║  2. View All Students                ║\n");
    printf("║  3. Search Student                   ║\n");
    printf("║  4. Update Student                   ║\n");
    printf("║  5. Delete Student                   ║\n");
    printf("║  6. Exit                             ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("  Enter your choice: ");
}

// ─── Main Entry Point ─────────────────────────────────────────────
int main() {
    int choice;

    printf("\n  Welcome to Student Management System\n");

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent();      break;
            case 2: viewAllStudents(); break;
            case 3: searchStudent();   break;
            case 4: updateStudent();   break;
            case 5: deleteStudent();   break;
            case 6:
                printf("\n  Exiting... Goodbye!\n\n");
                break;
            default:
                printf("\n  [!] Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}