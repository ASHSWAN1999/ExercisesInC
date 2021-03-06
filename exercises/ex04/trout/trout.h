#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>
#include <unistd.h>

#define MAXLINE 4096
#define BUFSIZE 1500

typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;

typedef struct timeval Timeval;
typedef struct sockaddr Sockaddr;

/* the following are a few definitions from Stevens' unp.h */

typedef	void Sigfunc(int);        /* for signal handlers */

#define max(a,b) ((a) > (b) ? (a) : (b))

//function declarations from trout.c
void sig_alrm (int signo);
int process_ip (struct ip *ip, int len);
int recv_dgram ();
double time_to_double (Timeval *time);
void send_dgram (int ttl);
int send_probes (int ttl);
void loop_ttl ();

//global variables used by main and trout
extern int max_ttl;
extern int nprobes;
extern int datalen;

extern Sockaddr *sasend; /* socket addresses for various purposes */
extern Sockaddr *sarecv;
extern Sockaddr *salast;
extern Sockaddr *sabind;

extern socklen_t salen; /* length of a socket address */
