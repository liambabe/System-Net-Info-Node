#include "Main.h"

int socket_desc;
struct sockaddr_in server_addr;

const char process[7] = "/proc/\0";

FILE *memInfo;
struct Node *memHead = NULL;

FILE *cpuInfo;
struct Node *cpuHead = NULL;

int main (int argc, char *argv[])
{
	initDataLists();
	initSocket();

	OpenFiles();

	ReadFile(&memInfo, memHead, 5);
	ReadFile(&cpuInfo, cpuHead, 7);

	PrintList(memHead);
	PrintList(cpuHead);

	CloseFiles();
}


void initDataLists ()
{ 
	memHead = (struct Node*) malloc(sizeof(struct Node));
	strcpy(memHead->data, "Memory List");

	cpuHead = (struct Node*) malloc(sizeof(struct Node));
	strcpy(cpuHead->data, "CPU List");
}

void initSocket () 
{
	socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = inet_addr(SERVERIP);
	int server_struct_length = sizeof(server_addr);

	if(socket_desc < 0){
		printf("Error while creating socket\n");
	}
	
	// Send the message to server:
	if(sendto(socket_desc, "UDP Message\0", BUFLEN, 0,
			(struct sockaddr*)&server_addr, server_struct_length) < 0){
		printf("Unable to send message\n");
	}


	close(socket_desc);
}