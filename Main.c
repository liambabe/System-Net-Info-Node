#include "Main.h"

//socket variables
int socket_desc;
struct sockaddr_in server_addr;
char msgBuffer[BUFLEN];

const char process[7] = "/proc/\0";

FILE *memInfo;
struct Node *memHead = NULL;

FILE *cpuInfo;
struct Node *cpuHead = NULL;

int main (int argc, char *argv[])
{
	initDataLists();
	initSocket();


	for (int i = 0; i < 5; i++) {
		OpenFiles();

		ReadFile(&memInfo, memHead, 5);
		ReadFile(&cpuInfo, cpuHead, 7);

		PrintList(memHead);
		PrintList(cpuHead);

		CloseFiles();

		CleanList(memHead);
		CleanList(cpuHead);

		sleep(1);
	}

		strcpy(msgBuffer, "hello world\0");
		int server_struct_length = sizeof(server_addr);

	// Send the message to server:
	if(sendto(socket_desc, msgBuffer, BUFLEN, 0,
			(struct sockaddr*)&server_addr, server_struct_length) < 0){
		printf("Unable to send message\n");
	}

	close(socket_desc);
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

	if(socket_desc < 0){
		printf("Error while creating socket\n");
	}



}