#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct {
	char name[31];
	char EGN[11];
	char facultyNumber[7];
	float grades[10];
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


int main() {
	int numberOfStudents;

	if (!readNumberOfStudents(&numberOfStudents)) {
		return 0;
	}




	

	

	


	return 0;
}