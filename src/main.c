#include <stdio.h>
#include <stdlib.h>
#include "../include/student.h"

// ─── Display Menu ─────────────────────────────────────────────────
void displayMenu() {
    printf(CYAN "\n╔══════════════════════════════════════╗\n" RESET);
    printf(CYAN "║" RESET BOLD "    STUDENT MANAGEMENT SYSTEM  v1.0  " RESET CYAN "║\n" RESET);
    printf(CYAN "╠══════════════════════════════════════╣\n" RESET);
    printf(CYAN "║" RESET "  1. ➕ Add Student                    " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  2. 📋 View All Students              " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  3. 🔍 Search Student                 " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  4. ✏️  Update Student                 " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  5. 🗑️  Delete Student                 " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  6. 🚪 Exit                           " CYAN "║\n" RESET);
    printf(CYAN "╚══════════════════════════════════════╝\n" RESET);
    printf("  Enter your choice: ");
}

// ─── Main Entry Point ─────────────────────────────────────────────
int main() {
    int choice;

    printf(GREEN "\n  ╔══════════════════════════════════════╗\n");
    printf(      "  ║  Welcome to Student Management System ║\n");
    printf(      "  ╚══════════════════════════════════════╝\n\n" RESET);

    loadFromFile();  // Load existing data on startup

    do {
        displayMenu();

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf(RED "  [!] Please enter a number.\n" RESET);
            choice = 0;
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: addStudent();      break;
            case 2: viewAllStudents(); break;
            case 3: searchStudent();   break;
            case 4: updateStudent();   break;
            case 5: deleteStudent();   break;
            case 6:
                saveToFile();
                printf(GREEN "\n  Goodbye! Data saved.\n\n" RESET);
                break;
            default:
                printf(RED "\n  [!] Invalid choice (1–6).\n" RESET);
        }
    } while (choice != 6);

    return 0;
}