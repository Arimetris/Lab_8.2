#ifndef _HEAD_H_
#define _HEAD_H_

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define SIZE 100

struct Node {
    char word[SIZE];
    int count;
    struct Node* prev;
    struct Node* next;
};

struct Node* get_list(char*);
void put_list(struct Node*);
void clear_list(struct Node**);
int Len_longest_word(struct Node*);
void del_Node(struct Node**, int);

#endif