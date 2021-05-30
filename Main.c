#include "Main.h"

//socket variables
int socket_desc;
struct sockaddr_in server_addr;
char msgBuffer[BUFLEN];

int main (int argc, char *argv[])
{
	initDataLists();
	initSocket();

	char *data;
	data = malloc(sizeof(char) * 255);
	int server_struct_length = sizeof(server_addr);


	while (1) {
		ProcessData(data);
		strcpy(msgBuffer, "hello world\0");

		// Send the message to server:
		if(sendto(socket_desc, msgBuffer, BUFLEN, 0,
			(struct sockaddr*)&server_addr, server_struct_length) < 0){
			printf("Unable to send message\n");
		}

		memset(data, 0, (sizeof(char) * 255));
		sleep(6);
	}

	free(data);
	close(socket_desc);
}

void initSocket () 
{
	socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = inet_addr(SERVERIP);

	if(socket_desc < 0){
		printf("Error while creating socket\n");
	}



}