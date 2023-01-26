#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <time.h>

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
	char name[31];
	float retailPrice; // na drebno
	float tradePrice; // edro
	date manufactureDate;
	date expiryDate;
} product;

int checkCheapestProduct(product* products, int numberOfProducts) {
	product cheapestProduct;
	float cheapestProductPrice = FLT_MAX;
	for (int num = 0; num < numberOfProducts; num++) {
		product product = products[num];
		float currentProductPrice = (product.retailPrice + product.tradePrice) / 2;
		if (currentProductPrice < cheapestProductPrice) {
			cheapestProductPrice = currentProductPrice;
			cheapestProduct = product;
		}
	}
	printf("Cheapest product at the moment is: %s. Price: %.2f", cheapestProduct.name, cheapestProductPrice);
	return 0;
}

int checkExpiriedProducts(product* products, int numberOfProducts) {
	for (int num = 0; num < numberOfProducts; num++) {
		product product = products[num];

		time_t rawtime;
		struct tm* timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		int currentYear = timeinfo->tm_year + 1900, currentMonth = timeinfo->tm_mon + 1, currentDay = timeinfo->tm_mday;

		// printf("Current local time and date: %s", asctime(timeinfo));
		int expired = 0; // not expired at start.
		int today = 0;
		if (product.expiryDate.year < currentYear) {
			expired = 1;
		}
		else if (product.expiryDate.year == currentYear) {
			if (product.expiryDate.month < currentMonth) {
				expired = 1;
			}
			else if (product.expiryDate.month == currentMonth) {
				if (product.expiryDate.day < currentDay) {
					expired = 1;
				}
				else if (product.expiryDate.day == currentDay) {
					printf("Product %s is expiring today.\n", product.name);
					today = 1;
				}
			}
		}

		if (expired && !today) {
			printf("Product %s has expiried.\n", product.name);

		}
	}

	return 0;
}

int main() {
	int numberOfProducts;
	printf("How many products will you insert? ");
	int returnedValue = scanf("%d", &numberOfProducts);
	
	if (numberOfProducts <= 0) { // <= 0, NOT ONLY < 0. SOLVED THE BUFFER OVERRUN PROBLEM.
		return -1;
	}

	if (!returnedValue) {
		return -1;
	}

	product* products = malloc(sizeof(product) * numberOfProducts);

	if (products == NULL) {
		return -1;
	}

	for (int num = 0; num < numberOfProducts; num++) {
		product product;
		printf("Product name? ");
		if (scanf("%s", product.name) == 0) {
			return -1;
		};
		printf("Product retail price? ");
		if (scanf("%f", &product.retailPrice) == 0) {
			return -1;
		};
		printf("Product trade price? ");
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
			
		
		products[num] = product;
	}


	checkCheapestProduct(products, numberOfProducts);
	checkExpiriedProducts(products, numberOfProducts);
	free(products);
	return 0;
}