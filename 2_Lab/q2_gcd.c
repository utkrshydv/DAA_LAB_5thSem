// lab2q2.c
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    
    FILE *src = fopen(argv[1], "r");
    FILE *dest = fopen(argv[2], "w");

    int a, b;
    while (fscanf(src, "%d %d", &a, &b) == 2) {
        fprintf(dest, "The GCD of %d and %d is %d\n", a, b, gcd(a, b));
    }

    fclose(src);
    fclose(dest);

    FILE *out = fopen(argv[2], "r");
    char line[100];
    while (fgets(line, sizeof(line), out)) {
        printf("%s", line);
    }
    fclose(out);

    return 0;
}
