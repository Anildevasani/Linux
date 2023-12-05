Write a C Program that makes a copy of a file using standard I/O and system calls
#include <stdio.h>

int main() {
	const char* src = "w.txt";
	const char* dest = "ww.txt";
	if (rename(src, dest) == 0) {
		printf("file moved succesfully");
	} else {
		printf("Error");
	}
}
