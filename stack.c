#include <stdio.h>
typedef unsigned long long QWORD;
char temp[40] = "| aaaaaaaaaaaaaaaa  |\n";

void hexreturn(QWORD num) {
	sprintf(temp + 2, "%016lx", num);
}

void stackview(char *name) {
	puts("[STACK]");
	printf("Name size: %d\n", 40);
	printf("Address: %p\n", name);
	printf("Press 'exit' to exit\n");
	printf("+------------------+ 0x0    <= name\n");
	hexreturn(*(QWORD *)name);
	write(1, temp, 22);
	printf("+------------------+ 0x8    <= name+0x8\n");
	hexreturn(*(QWORD *)(name + 8));
	write(1, temp, 22);
	printf("+------------------+ 0x10   <= name+0x10\n");
	hexreturn(*(QWORD *)(name + 16));
	write(1, temp, 22);
	printf("+------------------+ 0x18   <= name+0x18\n");
	hexreturn(*(QWORD *)(name + 24));
	write(1, temp, 22);
	printf("+------------------+ 0x20   <= name+0x20\n");
	hexreturn(*(QWORD *)(name + 32));
	write(1, temp, 22);
	printf("+------------------+ 0x28   <= canary\n");
	hexreturn(*(QWORD *)(name + 40));
	write(1, temp, 22);
	printf("+------------------+ 0x30   <= SFP\n");
	hexreturn(*(QWORD *)(name + 48));
	write(1, temp, 22);
	printf("+------------------+ 0x38   <= RET\n");
	hexreturn(*(QWORD *)(name + 56));
	write(1, temp, 22);
	printf("+------------------+\n");
}

int main() {
	char name[40] = "";

	while (1) {
		stackview(name);
		puts("What is your name?");
		gets(name);
		if (!strcmp("exit", name))
			break;
	}

}
