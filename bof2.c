#include <stdio.h>

void trash() {
	printf("How did you call me?\n");
}

int main() {
	char buffer[16] = "";
	scanf("%s", buffer);
}