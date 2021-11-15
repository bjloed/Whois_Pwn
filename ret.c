#include <stdio.h>

void hello() {
	char hello[16] = "Hello_World!\n";
	printf("%s", hello);
}

void bye() {
	char bye[16] = "Bye_Bye!\n";
	printf("%s", bye);
}

int main() {
	hello();
	bye();
}