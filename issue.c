#include <stdio.h>
int main() {
	unsigned int num1 = 0;
	unsigned int num2 = 4294967295;

	int num3 = 2147483647;

	printf("%u\n%u\n%d\n", num1 - 1, num2 + 1, num3 + 1);
}