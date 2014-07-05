/**
 * 標準入力からHTTP Request Headerを受け取って
 * １行目をパーズするプログラム
 * Usage: ./read_request_header < request_header.txt
 */
#include <stdio.h>
#include <string.h>

#define BUF_MAX_LEN 1024

int main()
{
    FILE *fin;
    char buf[BUF_MAX_LEN];
    char *p;

    char method[BUF_MAX_LEN];
    char path[BUF_MAX_LEN];
    char proto[BUF_MAX_LEN];

    fin = stdin;

    if (fgets(buf, BUF_MAX_LEN, fin) == NULL) {
	perror("fgets");
	return 1;
    }

    //get method
    p = strchr(buf, ' ');
    *p = '\0';
    strcpy(method, buf);

    //get path
    p++;
    char *tmp_path;
    tmp_path = p;
    p = strchr(p, ' ');
    *p = '\0';
    strcpy(path, tmp_path);

    //get proto
    p++;
    strcpy(proto, p);

    printf("=== result ===\n");
    printf("method:%s\n", method);
    printf("path:%s\n", path);
    printf("proto:%s\n", proto);
    return 0;
}
