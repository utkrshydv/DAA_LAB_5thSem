// lab2q1.c
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int num, char *binary, int pos) {
    if (pos == 0) return;
    decimalToBinary(num / 2, binary, pos - 1);
    binary[16 - pos] = (num % 2) + '0';
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <source file> <destination file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    FILE *src = fopen(argv[2], "r");
    FILE *dest = fopen(argv[3], "w");

    int number;
    for (int i = 0; i < n && fscanf(src, "%d", &number) == 1; i++) {
        char binary[17] = {0};
        decimalToBinary(number, binary, 16);
        fprintf(dest, "The binary equivalent of %d is %s\n", number, binary);
    }

    fclose(src);
    fclose(dest);

    FILE *output = fopen(argv[3], "r");
    char line[100];
    while (fgets(line, sizeof(line), output)) {
        printf("%s", line);
    }
    fclose(output);

    return 0;
}
