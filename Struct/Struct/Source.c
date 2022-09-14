#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* TRAINING
* 
* 
typedef struct {
	int length;
	int width;
} rectangle;


typedef struct {
	int x;
	int y;
} position;


typedef struct {

	char owner[30];
	rectangle rectangle;
	position position;

} buildingPlan;

int main() {

	rectangle myRectangle = {5, 10};
	printf("Length: %d\nWidth: %d\n", myRectangle.length, myRectangle.width);

	buildingPlan myHouse = { "Antoan Stefanov", {5, 10}, {32, 48} };

	printf("The house at %d %d (size %d %d) is owned by %s\n",
		myHouse.position.x,
		myHouse.position.y,
		myHouse.rectangle.length,
		myHouse.rectangle.width,
		myHouse.owner);

	int size = 3;
	position arr[] = { {0, 1}, {1, 2}, {2, 3} };

	for (int i = 0; i < size; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}

	buildingPlan* structPointer = &myHouse;
	printf("Position x: %d\n", structPointer->position.x);
	
	return 0;
}
*/


typedef struct {
	int day;
	int month;
	int year;
} date;

typedef struct {
	char name[30];
	float retailPrice; // na drebno
	float tradePrice; // edro
	date manufactureDate;
	date expiryDate;
} product;

int main() {
	int numberOfProducts;
	printf("How many products will you insert? ");
	int returnedValue = scanf("%d", &numberOfProducts);
	if (returnedValue) {
		for (int i = 0; i < numberOfProducts; i++) {
			product product;
			printf("Product name ?");
			if (scanf("%s", product.name) == 0) {
				return -1;
			};
			printf("Product retail price ?");
			if (scanf("%f", &product.retailPrice) == 0) {
				return -1;
			};
			printf("Product trade price ?");
			if (scanf("%f", &product.tradePrice) == 0) {
				return -1;
			};
			printf("Product Manufacture date (day-month-year)? ");
			char date[11]; // +1 -> \0
			if (scanf("%s", date) == 0) {
				return -1;
			}
			int arr[3] = {-1, -1, -1};
			int i = 0;

			// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			char* next_token = NULL;
			char* token;
			token = strtok_s(date, "-", &next_token);
			while (token) {
				puts(token);
				arr[i] = atoi(token);
				i++;
				token = strtok_s(NULL, "-", &next_token);
			}
			// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!SPLIT

			product.manufactureDate.day = arr[0];
			product.manufactureDate.month = arr[1];
			product.manufactureDate.year = arr[2];

			printf("Product Expiry date (day-month-year)? ");
			char expiryDate[11]; // +1 -> \0
			if (scanf("%s", expiryDate) == 0) {
				return -1;
			}
			int expiry_date_arr[3] = { -1, -1, -1 };
			int j = 0;
			// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			char* next_expiry_token = NULL;
			char* expiryToken;
			expiryToken = strtok_s(expiryDate, "-", &next_expiry_token);
			while (expiryToken) {
				puts(expiryToken);
				expiry_date_arr[j] = atoi(expiryToken);
				j++;
				expiryToken = strtok_s(NULL, "-", &next_expiry_token);
			}
			// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!SPLIT

			product.expiryDate.day = expiry_date_arr[0];
			product.expiryDate.month = expiry_date_arr[1];
			product.expiryDate.year = expiry_date_arr[2];
			

			printf("%s", date);


	
			printf("asdas");

		}
	}

	product firstProduct = { "Bread", 1.90, 0.90, {14, 9, 2022}, {15, 9, 2022} };
	printf("Product: %s. Price: %f", firstProduct.name, firstProduct.retailPrice);
	return 0;
}