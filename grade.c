#include <stdio.h>
#include <string.h>

struct Student
{
    int roll;
    char name[50];
    float marks[5];
    char grade[3];
    char result[5];
};

struct Student s[100];
int count = 0;

void addStudent()
{
    int i, pass = 1;
    float total = 0, percentage;

    printf("\nEnter Roll Number: ");
    scanf("%d", &s[count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[count].name);

    printf("Enter marks of 5 subjects:\n");

    for(i = 0; i < 5; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s[count].marks[i]);

        total += s[count].marks[i];

        if(s[count].marks[i] < 40)
            pass = 0;
    }

    percentage = total / 5;

    if(pass == 0 || percentage < 50)
    {
        strcpy(s[count].grade, "F");
        strcpy(s[count].result, "FAIL");
    }
    else
    {
        strcpy(s[count].result, "PASS");

        if(percentage >= 90)
            strcpy(s[count].grade, "A+");
        else if(percentage >= 80)
            strcpy(s[count].grade, "A");
        else if(percentage >= 70)
            strcpy(s[count].grade, "B");
        else if(percentage >= 60)
            strcpy(s[count].grade, "C");
        else
            strcpy(s[count].grade, "D");
    }

    printf("\nGrade: %s", s[count].grade);
    printf("\nResult: %s\n", s[count].result);

    count++;
}

void displayStudents()
{
    int i;

    if(count == 0)
    {
        printf("\nNo records found!\n");
        return;
    }

    for(i = 0; i < count; i++)
    {
        printf("\nName: %s", s[i].name);
        printf("\nRoll Number: %d", s[i].roll);
        printf("\nGrade: %s", s[i].grade);
        printf("\nResult: %s\n", s[i].result);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- STUDENT RESULT ANALYZER ---\n");
        printf("1. Add Student\n");
        printf("2. Display Results\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(count < 100)
                    addStudent();
                else
                    printf("Student limit reached!\n");
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 3);

    return 0;
}