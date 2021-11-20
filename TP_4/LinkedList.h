#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include<stdio.h>
#include<stdlib.h>

#define ERROR -1

typedef struct{
	void* pElemento;
	Node* pNetxNode;
}Node;

typedef struct{
	Node* pFirstNode;
	int size;
}eLinkedList;

eLinkedList* Ll_newLinkedList(void);

int Ll_len(eLinkedList* this);

static Node* GetNode(eLinkedList* this, int nodeIndex);

static int AddNode(eLinkedList* this, int nodeIndex, void* pDato);

int Ll_add(eLinkedList* this, void* pDato);

void* Ll_get(eLinkedList* this, int index);

int Ll_set(eLinkedList* this, int index, void* pDato);

int Ll_remove(eLinkedList* this, int index);

int Ll_clear(eLinkedList* this);

int Ll_deleteLinkedList(eLinkedList* this);

int Ll_indexOf(eLinkedList* this, void* pDato);

int Ll_isEmty(eLinkedList* this);

int Ll_push(eLinkedList* this, int index, void* pDato);

void* Ll_pop(eLinkedList* this, int index);

int Ll_contain(eLinkedList* this, void* pDato);

int Ll_containsAll(eLinkedList* this, eLinkedList* this2);

eLinkedList* Ll_subList(eLinkedList* this, int from, int to);

eLinkedList* Ll_clone(eLinkedList* this);

int Ll_sort(eLinkedList* this, int (*pFunc)(void*,void*), int order);

#endif /* LINKEDLIST_H_ */
