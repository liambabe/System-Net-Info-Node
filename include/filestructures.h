#ifndef FILESTRUCTURES_H_INCLUDED
#define FILESTRUCTURES_H_INCLUDED

/* Linked list for storing file information */
struct Node {
    char data[255];
    struct Node* next;
};

#endif