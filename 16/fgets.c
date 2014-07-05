/**
 * キーボードから１行入力を受け取って表示するだけのコマンド
 */
#include <stdio.h>

#define BUF_MAX_LEN 1024

int main()
{
    FILE *fin;
    char buf[BUF_MAX_LEN];

    fin = stdin;

    if (fgets(buf, BUF_MAX_LEN, fin) == NULL) {
	perror("fgets");
	return 1;
    }

    printf(buf);
    return 0;
}
