#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAX_NAME_CHARS 31
#define MAX_EGN_CHARS 11
#define MAX_FACULTY_NUMBER_CHARS 7
#define MAX_GRADES_NUMBER 10


typedef struct {
	char name[MAX_NAME_CHARS];
	char EGN[MAX_EGN_CHARS];
	char facultyNumber[MAX_FACULTY_NUMBER_CHARS];
	float grades[MAX_GRADES_NUMBER];
	float averageGrade;
	// gender ?
} student;


int readNumberOfStudents(int* numberOfStudents) { // Pointer arg, bcs we need to change the value in main function.
	printf("How many students are in the group? ");
	scanf_s("%d", numberOfStudents);

	if (*numberOfStudents <= 0) {
		printf("Invalid Students' Number.");
		return 0;
	}
	return 1;
}

void readStudentsInformation(student* students, int numberOfStudents) {
	char studentGrades[256];

	for (int currentStudentNum = 0; currentStudentNum < numberOfStudents; currentStudentNum++) {
		printf("Student Number: #%d...\n", currentStudentNum + 1);

		// %(30|10|6)s ==> WIDTH SPECIFICATION || (unsigned)strlen(students[currentStudentNum].nam -> BUFFER SIZE.

		printf("---Student's Name: "); scanf_s("%30s", students[currentStudentNum].name, MAX_NAME_CHARS);

		printf("---Student's EGN : "); scanf_s("%10s", students[currentStudentNum].EGN, MAX_EGN_CHARS);

		printf("---Student's Faculty Number: "); scanf_s("%6s", students[currentStudentNum].facultyNumber, MAX_FACULTY_NUMBER_CHARS);

		(void)getchar(); // ignore returned char -> \n.

		printf("---Student's 10 Grades | n1, n2, n3 ... : ");  fgets(studentGrades, sizeof(studentGrades), stdin);


		for (int currentStudentGrade = 0; currentStudentGrade < MAX_GRADES_NUMBER; currentStudentGrade++) {

		}

		// students[currentStudentNum] = student;
	}

	printf("asd");
}


int main() {
	int numberOfStudents;

	if (!readNumberOfStudents(&numberOfStudents)) {
		return 0;
	}

	student* students = malloc(sizeof(student) * numberOfStudents);

	readStudentsInformation(students, numberOfStudents);




	

	

	


	return 0;
}