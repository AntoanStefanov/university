#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct {
	char name[31];
	char EGN[11];
	char facultyNumber[7];
	float grades[10];
} student;


void readNumberOfStudents(int* numberOfStudents) { // Pointer arg, bcs we need to change the value in main function.
	printf("How many students are in the group? ");
	scanf_s("%d", numberOfStudents);
}


int main() {
	int numberOfStudents;
	readNumberOfStudents(&numberOfStudents);
	if (numberOfStudents <= 0) {
		printf("Invalid Student's Number.");
		return -1;
	}

	

	


	return 0;
}