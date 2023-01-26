#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

struct student {
	char name[31];
	char egn[11];
	char faculty_number[7];
	float grades[10];
};

int main()
{
	int student_num = 0;
	printf("Students Number: ");
	scanf("%d", &student_num);
	getchar();

	struct student* students = malloc(sizeof(struct student) * student_num);

	for (int stud_num = 0; stud_num < student_num; stud_num++) {
		printf("Name: "); gets(students[stud_num].name);
		printf("Egn: "); scanf("%s", students[stud_num].egn); getchar();
		printf("F. Number: "); scanf("%s", students[stud_num].faculty_number); getchar();
		printf("Grades:\n");
		float grade = 0;
		for (int grade_num = 0; grade_num < 10; grade_num++) {
			scanf("%f", &grade);
			students[stud_num].grades[grade_num] = grade;
		}
		getchar();
	}
	int menu_num;

	do {
		printf("\tMENU\n");
		printf("1.Create file with information.\n");
		printf("2.calc. avg. grade for each student.\n");
		printf("3. show women's num with less than 4.50 grades, born in winter.\n");
		printf("0.---EXIT\n");

		printf("1-3 functions, 0 for exit.\n"); 
		menu_num = -1;

		scanf("%d", &menu_num);
		getchar();

		switch (menu_num) {
		case 0: printf("Exiting"); break;
		case 1: file_to_create(); break;
		case 2: average_grades(students, student_num); break;
		case 3: show_women_born_in_winter(students, student_num); break;
		default: printf("Try Again!\n");
		} 

	} while (menu_num != 0);

	return 0;
}


int file_to_create() {
	printf("To do.\n");
	return 0;
}

int average_grades(struct student* students, int stud_num) {
	struct student student;
	float grade_average;

	for (int stud_in_arr = 0; stud_in_arr < stud_num; stud_in_arr++) {

		float total = 0;
		student = students[stud_in_arr];

		for (int stud_grade = 0; stud_grade < 10; stud_grade++) {
			total += student.grades[stud_grade];
		}

		grade_average = total / 10;

		printf("Name: %s. avg. grade: %.2f\n", student.name, grade_average);
	}
	return 0;
}

int show_women_born_in_winter(struct student* students, int stud_num) {
	struct student student;
	int girls_num = 0;

	for (int stud_in_arr = 0; stud_in_arr < stud_num; stud_in_arr++) {
		student = students[stud_in_arr];
			if (student.egn[8] % 2 == 1) {
				char month[3];
				month[0] = student.egn[2];
				month[1] = student.egn[3];
				month[2] = '\0';

				if (strcmp("12", month) == 0 || strcmp("01", month) == 0 || strcmp("02", month) == 0) {
					float total = 0;
					float grade_average;

					for (int stud_grade = 0; stud_grade < 10; stud_grade++) {
						total += student.grades[stud_grade];
					}

					grade_average = total / 10;

					if (grade_average < 4.50) {
						girls_num++;
					}
				}
			}
	}
	printf("num of girls with less than 4.50 born in winter: %d\n", girls_num);
	return 0;
}