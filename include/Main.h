#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "filemanager.h"
#include "linkedlist.h"
#include "fileprocessors.h"


//socket constants
#define SERVERIP "127.0.0.1"
#define BUFLEN 512
#define PORT 2115

//socket variables
extern char msgBuffer[BUFLEN];

void initSocket ();


#endif