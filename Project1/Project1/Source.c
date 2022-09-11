#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
	float a, b, c, S, P;
	printf("Insert a: ");
	scanf_s("%f", &a); 
	printf("Insert b: ");
	scanf_s("%f", &b); 
	c = sqrt(a * a + b * b);
	S = (a * b) / 2;
	P = a + b + c;
	printf("S = %f\nP = %f", S, P);
	return 0;
}