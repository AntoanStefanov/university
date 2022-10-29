#include <stdlib.h>

// returned string has to be dynamically allocated and will be freed by the caller
char* alphabet_position(const char* text) {

	return NULL;
}


#include <criterion/criterion.h>
#include <stdlib.h>

char* alphabet_position(const char* text);

static void tester(const char* input, const char* expected) {
	char* ptr = alphabet_position(input);
	cr_assert_str_eq(ptr, expected, "Incorrect answer for input: \"%s\"\nActual: \"%s\"\nExpected: \"%s\"", input, ptr, expected);
	free(ptr);
}

Test(sample_cases, should_pass_all_the_tests_provided) {
	tester("The sunset sets at twelve o' clock.", "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11");
	tester("The narwhal bacons at midnight.", "20 8 5 14 1 18 23 8 1 12 2 1 3 15 14 19 1 20 13 9 4 14 9 7 8 20");
}

Test(number_tests, should_pass) {
	tester("0", "");
	tester("123456789", "");
}