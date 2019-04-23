#include <stdio.h>

void scanAndPrint(FILE* in, FILE* out, unsigned char array[], int size) {
	for (int i = 0; i < size; i++) {
		array[i] = fscanf(in, "%X", &array[i]);
	}
}

int main() {
	FILE* in = fopen("file.in", "r");
	FILE* out = fopen("file.out", "w");
	int size = 512;
	unsigned char buffer[size];
	
	scanAndPrint(in,out,buffer,size);
	
	for (int i = 0; i < size; i++){
		printf("%X ", buffer[i]);
	}
	
	return 0;
}