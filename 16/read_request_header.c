/**
 * 標準入力からHTTP Request Headerを受け取って
 * １行目をパーズするプログラム
 * Usage: ./read_request_header < request_header.txt
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_MAX_LEN 1024

struct http_request_header {
    char *method;
    char *path;
    char *proto;
};

struct http_request_header * read_request_line(char *buf, struct http_request_header *req)
{
    char *p;

    //get method
    p = strchr(buf, ' ');
    *p = '\0';

    req->method = malloc(strlen(buf) + 1);
    strcpy(req->method, buf);

    //get path
    p++;
    char *tmp_path;
    tmp_path = p;
    p = strchr(p, ' ');
    *p = '\0';

    req->path = malloc(strlen(tmp_path) + 1);
    strcpy(req->path, tmp_path);

    //get proto
    p++;
    req->proto = malloc(strlen(p) + 1);
    strcpy(req->proto, p);
    return req;
}

int main()
{
    FILE *fin;
    char buf[BUF_MAX_LEN];

    fin = stdin;

    if (fgets(buf, BUF_MAX_LEN, fin) == NULL) {
	perror("fgets");
	return 1;
    }

    struct http_request_header s_req;
    struct http_request_header *req;

    req = read_request_line(buf, &s_req);

    printf("=== result ===\n");
    printf("method:%s\n", req->method);
    printf("path:%s\n", req->path);
    printf("proto:%s\n", req->proto);
    return 0;
}
