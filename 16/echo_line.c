/**
 * キーボードから１行入力を受け取って表示するだけのコマンド
 */
#include <stdio.h>

#define LINE_BUF_SIZE 1024

int main()
{
    char buf[LINE_BUF_SIZE];
    FILE *in = stdin;
    fgets(buf, LINE_BUF_SIZE, in);
    printf(buf);
    return 0;
}
