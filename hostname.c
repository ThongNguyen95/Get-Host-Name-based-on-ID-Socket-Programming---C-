//Thong Nguyen - HW3 - Networking

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

int main(int argc, char * argv[]) {
	struct hostent *host = NULL;
	struct in_addr ipvAddr;

	if (argc != 2) {
		fprintf(stderr,"Invalid input!\n");
		return 1;		
	} else {
		ipvAddr.s_addr = inet_addr(argv[1]);
		host = gethostbyaddr(&ipvAddr, sizeof(ipvAddr), AF_INET);
		if (host == NULL) {
			herror("gethostbyaddr");
			return 2;
		}
		printf("Host name: %s\n", host->h_name);
		return 0;
	}
}
