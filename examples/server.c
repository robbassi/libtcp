#include <stdio.h>
#include "tcp.h"

#define BUFSIZE 1000

int
main(int argc, char ** argv) {
    struct tcpConnection* conn = tcp_listen("localhost", "6666");
    struct tcpConnection* in_conn = tcp_accept(conn);
    char buf[BUFSIZE];

    while(tcp_read(in_conn, buf, BUFSIZE))
        printf("%s", buf);
    tcp_close(in_conn);
    tcp_close(conn);
    return 0;
}