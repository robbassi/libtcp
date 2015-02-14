#include <stdio.h>
#include <string.h>
#include "tcp.h"

#define BUFSIZE 1000

int
main(int argc, char ** argv) {
    struct tcpConnection* conn = tcp_connect("www.google.ca", "80");
    char* buf = "GET http://www.google.ca/search?q=asd HTTP/1.1\r\n\r\n";
    tcp_write(conn, buf, strlen(buf));
    char res_buf[BUFSIZE];
    while (tcp_read(conn, res_buf, BUFSIZE) != -1) {
        puts(res_buf);
        memset(res_buf, 0, BUFSIZE);
    }
    tcp_close(conn);
    return 0;
}