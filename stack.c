#include <stdio.h>
typedef unsigned long long QWORD;
char temp[40] = "| aaaaaaaaaaaaaaaa  |\n";

void hexreturn(QWORD num) {
	sprintf(temp + 2, "%016lx", num);
}

void stackview(char *name) {
	puts("[STACK]");
	printf("Name size: %d\n", 40);
	printf("Address: %p\n\n", name);
	printf("Input 'hex' to change mode\n");
	printf("Input 'exit' to exit\n\n");
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
	printf("name => %s\n\n", name);
}

void hexinput(unsigned char *name) {
	unsigned char hextemp[513] = "";
	unsigned char newhextemp[256] = "";
	unsigned char temptemp[8] = "";

	int cnt = 0;
	puts("Example) 01020304 -> '\\x01\\x02\\x03\\x04'");
	read(0, hextemp, 512);

	for (int i = 0; i < strlen(hextemp); i += 4) {
		newhextemp[cnt++] = *(hextemp + i + 2);
		newhextemp[cnt++] = *(hextemp + i + 3);
	}
	for (int i = 0; i < strlen(newhextemp); i += 2) {
		int num;
		temptemp[0] = newhextemp[i];
		temptemp[1] = newhextemp[i + 1];

		num = (int)strtol(temptemp, NULL, 16);
		name[i / 2] = num & 0xff;
	}
}

int main() {
	unsigned char name[40] = "";
	unsigned char command[6] = "";
	while (1) {
		stackview(name);
		puts("Input Command.");
		read(0, command, 6);
		if (!strncmp("exit", command, 4))
			break;
		else if (!strncmp("hex", command, 3))
			hexinput(name);
		else if (!strncmp("ASCII", command, 5)) {
			puts("What is your name?");
			read(0, name, 256);
		}
	}
}