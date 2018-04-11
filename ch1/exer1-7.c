#include <stdio.h>

int main() {
    int a;
    while(a = getchar()) {
        if (a == EOF) {
            printf("%d\n", a);
            break;
        }
    }
}
