#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
struct Student
{
    int id;
    char name[50];
    char course[20];
    int semester;
    float cgpa;
    struct Student *next;
};

// Function to add a new student to the database
void addStudent(struct Student **head)
{
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    if (newStudent == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter ID: ");
    scanf("%d", &newStudent->id);
    printf("Enter Name: ");
    scanf("%s", newStudent->name);
    printf("Enter Course: ");
    scanf("%s", newStudent->course);
    printf("Enter Semester: ");
    scanf("%d", &newStudent->semester);
    printf("Enter CGPA: ");
    scanf("%f", &newStudent->cgpa);
    newStudent->next = *head;
    *head = newStudent;
    printf("Student added successfully.\n");
}

// Function to display details of all students in BCA course
void displayBCAStudents(struct Student *head)
{
    printf("Students in BCA course:\n");
    while (head != NULL)
    {
        if (strcmp(head->course, "BCA") == 0)
        {
            printf("ID: %d, Name: %s, Course: %s, Semester: %d, CGPA: %.2f\n", head->id, head->name, head->course, head->semester, head->cgpa);
        }
        head = head->next;
    }
}

// Function to display details of students with CGPA 10
void displayStudentsWithCGPA10(struct Student *head)
{
    printf("Students with CGPA 10:\n");
    while (head != NULL)
    {
        if (head->cgpa == 10.0)
        {
            printf("ID: %d, Name: %s, Course: %s, Semester: %d, CGPA: %.2f\n", head->id, head->name, head->course, head->semester, head->cgpa);
        }
        head = head->next;
    }
}

// Function to edit student data
void editStudent(struct Student *head, int id)
{
    while (head != NULL)
    {
        if (head->id == id)
        {
            printf("Enter new Name: ");
            scanf("%s", head->name);
            printf("Enter new Course: ");
            scanf("%s", head->course);
            printf("Enter new Semester: ");
            scanf("%d", &head->semester);
            printf("Enter new CGPA: ");
            scanf("%f", &head->cgpa);
            printf("Student data updated successfully.\n");
            return;
        }
        head = head->next;
    }
    printf("Student not found.\n");
}

// Function to delete student record
void deleteStudent(struct Student **head, int id)
{
    struct Student *temp = *head, *prev = NULL;
    if (temp != NULL && temp->id == id)
    {
        *head = temp->next;
        free(temp);
        printf("Student record deleted successfully.\n");
        return;
    }
    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Student not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Student record deleted successfully.\n");
}

// Function to display menu options
void displayMenu()
{
    printf("\nStudent Database Management System\n");
    printf("1. Add Student\n");
    printf("2. Display BCA Students\n");
    printf("3. Display Students with CGPA 10\n");
    printf("4. Edit Student Data\n");
    printf("5. Delete Student Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    struct Student *head = NULL;
    int choice, id;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent(&head);
            break;
        case 2:
            displayBCAStudents(head);
            break;
        case 3:
            displayStudentsWithCGPA10(head);
            break;
        case 4:
            printf("Enter ID of student to edit: ");
            scanf("%d", &id);
            editStudent(head, id);
            break;
        case 5:
            printf("Enter ID of student to delete: ");
            scanf("%d", &id);
            deleteStudent(&head, id);
            break;
        case 6:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}