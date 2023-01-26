#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
	int sockfd, portno = 6365;
	struct sockaddr_in serv_addr;
	int n;
	int rand_num;

	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
memset((char *) &serv_addr, 0, sizeof(serv_addr));

	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("10.0.2.15");
	serv_addr.sin_port = htons(6365);

	
	connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

	
	n = read(sockfd, &rand_num, sizeof(rand_num));
	printf("Random number is: %d\n", rand_num);
	close(sockfd);

	return 0;
}
