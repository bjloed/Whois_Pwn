#include <stdio.h>
int main() {
	int a, b;

	printf("whoiswing%n", &a);
	printf("%44c%n", 'q', &b);

	printf("\n%d %d\n", a, b);
}
