			    //	Author:Nirali Miyatra
			    //	Doc:9th Feb 2025
			    //	Objective:Create a student record management system
#include<stdio.h>
#include<conio.h>
struct Student {
    int id;
    char name[100];
    int maths, science, english;
    int totalMarks;
}s;//End of structure

struct Student students[100];  // Array to store students
int totalStudents = 0;  // Number of students

// Function to add a student
void addStudent()
{
		int i;
		if (totalStudents >= 100)
		{
			printf("Student list is full!\n");
			return;
		}//end of if

		printf("Enter Student ID: ");
		scanf("%d", &s.id);

		printf("Enter Student Name:");
		scanf("%s",&s.name);

		printf("Enter Maths Marks: ");
		scanf("%d", &s.maths);

		printf("Enter Science Marks: ");
		scanf("%d", &s.science);

		printf("Enter English Marks: ");
		scanf("%d", &s.english);

		s.totalMarks = s.maths + s.science + s.english;

		students[totalStudents] = s;
		totalStudents++;

		printf("Student added successfully!\n");
}//end of func add student

// Function to display all students
void displayStudents()
{
	int i;
	if (totalStudents == 0)
	{
		printf("No students found!\n");
		return;
	}//end of if

	printf("\n----- Student Records -----\n");

	for (i = 0; i < totalStudents; i++)
	{
		printf("\nID:%d\nName: %s\nMaths: %d\nScience: %d\nEnglish: %d\nTotal Marks: %d\n",
		students[i].id,students[i].name, students[i].maths,
		students[i].science, students[i].english, students[i].totalMarks);
	}//end of for loop
}//end of Display all student func

// Function to search for a student by ID
void searchStudent()
{
	int id,i, found = 0;
	printf("Enter Student ID to search: ");
	scanf("%d", &id);

	for (i = 0; i < totalStudents; i++)
	{
		if (students[i].id == id)
		{
			printf("\nID: %d\nname:%s\nMaths: %d\nScience: %d\nEnglish: %d\nTotal Marks: %d\n",
			students[i].id, students[i].maths,
			students[i].science, students[i].english, students[i].totalMarks);
			found = 1;
			break;
		}//end of if
	}//end of for loop

	if (found != 1)
	{
		printf("Student not found!\n");
	}//end of if
}//end of search func

// Function to delete a student by ID
void deleteStudent()
{
	int id,i,j, found = 0;
	printf("Enter Student ID to delete: ");
	scanf("%d", &id);

	for (i = 0; i < totalStudents; i++)
	{
		if (students[i].id == id)
		{
			for (j = i; j < totalStudents - 1; j++)
			{
				students[j] = students[j + 1];
			}//end of inner loop
			totalStudents--;
			found = 1;
			printf("Student deleted successfully!\n");
			break;
	}//end of if
    }//end of outer loop

	if (found!=1)
	{
		printf("Student not found!\n");
	}//end of if
}//end of delete func

// Function to update a student record
void updateStudent()
{
	int id,i, found = 0;
	printf("Enter Student ID to update: ");
	scanf("%d", &id);

	for (i = 0; i < totalStudents; i++)
	{
		if (students[i].id == id)
		{
			printf("Enter New Maths Marks: ");
			scanf("%d", &students[i].maths);
			printf("Enter New Science Marks: ");
			scanf("%d", &students[i].science);
			printf("Enter New English Marks: ");
			scanf("%d", &students[i].english);

			students[i].totalMarks = students[i].maths + students[i].science + students[i].english;

			found = 1;
			printf("Student record updated successfully!\n");
			break;
		}//end of if
	}//end of for loop

	if(found!=1)
	{
		printf("Student not found!\n");
	}//end of if
}//end of update func

// Function to find the student with highest marks
void highestMarks()
{
	int maxIndex,i;
	if (totalStudents == 0)
	{
		printf("No students found!\n");
		return;
	}//end of if

	maxIndex = 0;

	for (i = 1; i < totalStudents; i++)
	{
		if (students[i].totalMarks > students[maxIndex].totalMarks)
		{
			maxIndex = i;
		}//end of if
	}//end of for loop
	printf("\nStudent with highest marks:\nID: %d\nTotal Marks: %d\n",
	students[maxIndex].id, students[maxIndex].totalMarks);
}//end of highest func

// Function to count total students
void countStudents()
{
    printf("Total number of students: %d\n", totalStudents);
}

// Function to reverse the student list
void reverseStudents()
{
	int i;
	if(totalStudents == 0)
	{
		printf("No students found!\n");
		return;
	}//end of if

	for (i = 0; i < totalStudents / 2; i++)
	{
		struct Student temp = students[i];
		students[i] = students[totalStudents - i - 1];
		students[totalStudents - i - 1] = temp;
	}//end of for loop

	printf("Student list reversed successfully!\n");
}//end of reverse func

// Function to sort students by marks
void sortStudents(int order)
{
	int i,j;
	if (totalStudents == 0)
	{
		printf("No students found!\n");
		return;
	}//end of if

	for (i = 0; i < totalStudents - 1; i++)
	{
		for (j = 0; j < totalStudents - i - 1; j++)
		{
			if ((order == 1 && students[j].totalMarks > students[j + 1].totalMarks) ||
			(order == 2 && students[j].totalMarks < students[j + 1].totalMarks))
			{
				struct Student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}//end of if
		}//end of inner loop
	}//end of outer loop

	printf("Students sorted successfully!\n");
}//emd of sort func

// Function to calculate average marks
void averageMarks()
{
	float totalMarks,i;
	if (totalStudents == 0)
	{
		printf("No students found!\n");
		return;
	}//end of if

	totalMarks = 0;
	for (i = 0; i < totalStudents; i++)
	{
		totalMarks += students[i].totalMarks;
	}//end of for loop
	printf("Average Marks of all students: %.2f\n", totalMarks / totalStudents);
}//end of average func

// Main function
int main()
{
	int choice;
	clrscr();
	while (1)
	{
		printf("\n----- Student Record Management System -----\n");
		printf("1. Add Student\n2. Display All Students\n3. Search Student\n4. Delete Student\n5. Update Student\n");
		printf("6. Highest Marks\n7. Count Students\n8. Reverse List\n9. Sort Students (1: Asc, 2: Desc)\n");
		printf("10. Average Marks\n11. Exit\nEnter choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1: addStudent();
			break;

			case 2: displayStudents();
			break;

			case 3: searchStudent();
			break;

			case 4: deleteStudent();
			break;

			case 5: updateStudent();
			break;

			case 6: highestMarks();
			break;

			case 7: countStudents();
			break;

			case 8: reverseStudents();
			break;

			case 9: scanf("%d", &choice);
			sortStudents(choice);
			break;

			case 10: averageMarks();
			break;

			case 11:
			return 0;

			default:
			printf("Invalid choice! Try again.\n");
		}//end of switch
	}//end of while
}//end of main fuc
