#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 20

// Structure to hold student information
struct Student {
  char id[MAX_ID_LENGTH];
  char name[MAX_NAME_LENGTH];
  int age;
};

// Function to add a new student record
void addStudent(struct Student **students, int *numStudents) {
  struct Student newStudent;

  printf("Enter student ID: ");
  scanf("%s", newStudent.id);

  printf("Enter student name: ");
  scanf("%s", newStudent.name);

  printf("Enter student age: ");
  scanf("%d", &newStudent.age);

  // Allocate memory for new student
  *students = realloc(*students, (*numStudents + 1) * sizeof(struct Student));

  // Add new student to the end of the array
  (*students)[*numStudents] = newStudent;

  (*numStudents)++;
}

// Function to delete a student record by ID
void deleteStudent(struct Student *students, int *numStudents) {
  char idToDelete[MAX_ID_LENGTH];
  int i, found = 0;

  printf("Enter ID of student to delete: ");
  scanf("%s", idToDelete);

  for (i = 0; i < *numStudents; i++) {
    if (strcmp(students[i].id, idToDelete) == 0) {
      // Move all students after this one up by one position
      memmove(&students[i], &students[i + 1],
              (*numStudents - i - 1) * sizeof(struct Student));
      (*numStudents)--;
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Student with ID %s not found\n", idToDelete);
  }
}

// Function to update student record by ID
void updateStudent(struct Student *students, int numStudents) {
  char idToUpdate[MAX_ID_LENGTH];
  int i, found = 0;

  printf("Enter ID of student to update: ");
  scanf("%s", idToUpdate);

  for (i = 0; i < numStudents; i++) {
    if (strcmp(students[i].id, idToUpdate) == 0) {
      printf("Enter new name for student: ");
      scanf("%s", students[i].name);

      printf("Enter new age for student: ");
      scanf("%d", &students[i].age);

      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Student with ID %s not found\n", idToUpdate);
  }
}

// Function to display all student records
void displayStudents(struct Student *students, int numStudents) {
  int i;

  printf("\nStudent Records:\n");
  printf("ID\t\tName\t\tAge\n");
  printf("--------------------------------\n");
  for (i = 0; i < numStudents; i++) {
    printf("%s\t\t%s\t\t%d\n", students[i].id, students[i].name,
           students[i].age);
  }
  printf("\n");
}

int main() {
  struct Student *students = NULL;
  int numStudents = 0;
  int choice;

  do {
    printf("1. Add Student\n");
    printf("2. Delete Student\n");
    printf("3. Update Student\n");
    printf("4. Display Students\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      addStudent(&students, &numStudents);
      break;
    case 2:
      deleteStudent(students, &numStudents);
      break;
    case 3:
      updateStudent(students, numStudents);
      break;
    case 4:
      displayStudents(students, numStudents);
      break;
    case 5:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice. Please enter a number between 1 and 5.\n");
    }
  } while (choice != 5);

  // Free dynamically allocated memory
  free(students);

  return 0;
}
