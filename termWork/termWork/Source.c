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

		// %(30|10|6)s ==> WIDTH SPECIFICATION || MAX_(NAME|EGN|FACULTY_NUMBER)_CHARS -> BUFFER SIZE.
		printf("---Student's Name: "); scanf_s("%30s", students[currentStudentNum].name, MAX_NAME_CHARS);

		printf("---Student's EGN : "); scanf_s("%10s", students[currentStudentNum].EGN, MAX_EGN_CHARS);

		printf("---Student's Faculty Number: "); scanf_s("%6s", students[currentStudentNum].facultyNumber, MAX_FACULTY_NUMBER_CHARS);

		(void)getchar(); // ignore returned char -> \n.

		printf("---Student's 10 Grades | n1, n2, n3, ... n10: ");  fgets(studentGrades, sizeof(studentGrades), stdin);

		// !!!!!!!!!!!!!!!!!!! SPLIT GRADES' STRING !!!!!!!!!!!!!!!!!!!!!!
		char* next_token = NULL;
		char* token;
		int currentGradeNum = 0;
		token = strtok_s(studentGrades, ", ", &next_token);
		while (token && currentGradeNum < MAX_GRADES_NUMBER) {
			// DO A GRADE(TOKEN) CHECK IF < 2 || > 6
			students[currentStudentNum].grades[currentGradeNum] = atof(token);
			currentGradeNum++;
			token = strtok_s(NULL, ", ", &next_token);
		}
		// !!!!!!!!!!!!!!!!!!! SPLIT GRADES' STRING !!!!!!!!!!!!!!!!!!!!!!
	}
}

void displayMenu() {
	printf("\t\tMENU\n");
	printf("1.---Create file with students' information.\n");
	printf("2.---Calculate Average Grade For Every Student.\n");
	printf("3.---Display Men's Faculty Numbers With More Than 5 Very Bad Grades.\n");
	printf("4.---Display Menu.\n");
	printf("5.---EXIT\n");
}

void createFile() {
	printf("Not working at moment\n");
}

void calculateAvgGrades(student* students, int numberOfStudents) {
	student student;
	float avgGrade;

	for (int currentStudentNum = 0; currentStudentNum < numberOfStudents; currentStudentNum++) {

		float totalGrade = 0;
		student = students[currentStudentNum];

		for (int currentStudentGrade = 0; currentStudentGrade < MAX_GRADES_NUMBER; currentStudentGrade++) {
			totalGrade += student.grades[currentStudentGrade];
		}

		avgGrade = totalGrade / MAX_GRADES_NUMBER;

		printf("Faculty Number: %s. Name: %s. Average Grade: %.2f\n", student.facultyNumber, student.name, avgGrade);
	}

}

void displayMenWithBadGrades(student* students, int numberOfStudents) {
	student student;
	int noOne = 1;

	for (int currentStudentNum = 0; currentStudentNum < numberOfStudents; currentStudentNum++) {
		student = students[currentStudentNum];

		char beforeLastChar = student.EGN[8];
		int beforeLastDigit = atoi(&beforeLastChar);

		if (beforeLastDigit % 2 == 0) { // MALE
			float grade;
			int counter = 0;

			for (int currentStudentGrade = 0; currentStudentGrade < MAX_GRADES_NUMBER; currentStudentGrade++) {
				grade = student.grades[currentStudentGrade];
				if (grade < 3) {
					counter++;
				}
			}

			if (counter > 5) {
				printf("Faculty Number: %s\n", student.facultyNumber);
				noOne = 0;
			}
		}
	}

	if (noOne) {
		printf("No Men With 5 Or More Very Bad Grades.\n");
	}
}

int main() {
	int numberOfStudents;
	int menuNumber;

	if (!readNumberOfStudents(&numberOfStudents)) {
		return 0;
	}

	student* students = malloc(sizeof(student) * numberOfStudents);

	readStudentsInformation(students, numberOfStudents);
	displayMenu();

	do {
		printf("Choose from 1-5 Options: "); scanf_s("%d", &menuNumber); (void)getchar();

		switch (menuNumber) {
			case 1: createFile(); break;
			case 2: calculateAvgGrades(students, numberOfStudents); break;
			case 3: displayMenWithBadGrades(students, numberOfStudents); break;
			case 4: displayMenu(); break;
			case 5: printf("Goodbye! Have a nice day!\n"); break;
			default: printf("No such function.\n");
		}

	} while (menuNumber != 5);

	return 0;
}