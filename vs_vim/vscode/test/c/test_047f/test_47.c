#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    char last_op = 0;

    while(n--) {
        char line[50];
        fgets(line, sizeof line, stdin);

        char op;
        int a, b;

        if (sscanf(line, " %c %d %d", &op, &a, &b) == 3 && isalpha(op)) {
            last_op = op;
        } else {
            sscanf(line, "%d %d", &a, &b);
            op = last_op;
        }

        int result;
        char symbol;

        if (op == 'a') {
            result = a + b;
            symbol ='+';
        }else if (op == 'b') {
            result = a - b;
            symbol = '-';
        } else{
            result = a * b;
            symbol = '*';
        }

        char expr[50];
        sprintf(expr, "%d%c%d=%d", a, symbol, b, result);

        printf("%s\n%d\n", expr, (int)strlen(expr));
    }
}