#include "LinkedList.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

LinkedList::LinkedList(){
	list = NULL;
	head = NULL;
	element=0;
}

void LinkedList::pop_front(){
	if(element!=0){	
		element--;
		nodo *aux;
		aux=list;
		list=list->sgte;
	}
}


bool LinkedList::isEmpty(){
	if(list == NULL && head == NULL)return true;
	else return false;
}

void LinkedList::push_front(int valor){
	element++;
	Llista tmp = head;
	head = new nodo;
	head->n = valor;
	head->sgte = tmp;
	list = head;
}



void LinkedList::push_back(int valor){
	element++;
	Llista t, q = new nodo;
	q->n  = valor;
	q->sgte = NULL;
	if(list == NULL){
        	list = q;
	}
	else{
		t = list;
        	while(t->sgte!=NULL){
        		t = t->sgte;
        	}
        	t->sgte = q;
	}
}

int LinkedList::at(int valor){
	Llista q = list;
	int i = 0;
	while(q!=NULL){
	        if(i==valor){
			return q->n;
		}
		q = q->sgte;
		i++;
	}	
	return -1;
}

int LinkedList::size(){
	return element;
}
