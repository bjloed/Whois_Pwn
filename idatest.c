#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void win() {
	char *str[3];
	str[0] = "/bin/cat";
	str[1] = "/home/idatest/flag";
	str[2] = NULL;
	execve(str[0], str, NULL);
}

void vuln() {
	char buf[16];
	gets(buf);
}

void init() {
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

int main() {
	init();
	printf("HI! This is for you %p\n", win);
	vuln();
}
