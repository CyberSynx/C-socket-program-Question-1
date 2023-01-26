#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){
	int sockfd, newsockfd, portno = 6365;
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen;
	int n;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	memset((char*) &serv_addr, 0, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(6365);
 
	bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
	listen(sockfd, 5);
	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);





	int rand_num =rand() %900 + 100;
	n = write(newsockfd, &rand_num, sizeof(rand_num));
}

	close(newsockfd);
	close(sockfd);

	return 0;

}
