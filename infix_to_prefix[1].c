#include <stdio.h>
#include <string.h>
#define MAX 100

char st[MAX];
int top = -1;

void push(char c, int *t) {
    st[++(*t)] = c;
}

char pop(int *t) {
    return st[(*t)--];
}

char peek(int *t) {
    if (*t == -1) return '\0';
    return st[*t];
}

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int isOp(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void revStr(char *s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++; j--;
    }
}

int main() {
    char inf[MAX], pre[MAX], c;
    int i, j = 0;
    int *t = &top;

    printf("Enter infix no space: ");
    scanf("%s", inf);

    revStr(inf);

    for (i = 0; inf[i]; i++) {
        c = inf[i];
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    for (i = 0; inf[i]; i++) {
        c = inf[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            pre[j++] = c;
        }
        else if (c == '(') {
            push(c, t);
        }
        else if (c == ')') {
            while (peek(t) != '(') {
                pre[j++] = pop(t);
            }
            pop(t);
        }
        else if (isOp(c)) {
            while (*t != -1 && isOp(peek(t)) && prec(peek(t)) > prec(c)) {
                pre[j++] = pop(t);
            }
            push(c, t);
        }
    }

    while (*t != -1) {
        pre[j++] = pop(t);
    }

    pre[j] = '\0';
    revStr(pre);

    printf("Prefix: %s\n", pre);
    return 0;
}
