#include <stdio.h>
int main() {
	char arr[8] = "Hello";

	printf("%s", arr); //Correct!
	printf(arr); //Nah..
}
