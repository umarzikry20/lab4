#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[])
{

	int socket_desc;
	struct sockaddr_in server;
	char *message;

	socket_desc = socket(AF_INET, SOCK_STREAM,0);
	if(socket_desc == -1)
	{
	
		printf("could not create socket");
	}

	server.sin_addr.s_addr = inet_addr("192.168.56.107");
	server.sin_family = AF_INET;
	server.sin_port = htons(22);

	if(connect(socket_desc,(struct sockaddr*)&server , sizeof(server))<0)
	{
		puts("connect error");
		return 1;
	}

	puts("Connected");
	message = "connect";
	if(send(socket_desc, message, strlen(message),0)<0)
	{
		puts("Send Failed");
		return 1;
	}
	puts("Data Send\n");
	return 0;
}

