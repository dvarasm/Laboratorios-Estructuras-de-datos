#include "Deque.h"
#include<cstdlib>
#include<cstdio>
#include<iostream>

Deque::Deque(){
	count=0;
	q1=NULL;
}

bool Deque::empty(){
	if(q1== NULL)return true;
	else return false;
}
int Deque::size(){
return count;
}
int Deque::front(){
	struct nodo *q =q1;
	while (q!=NULL){
		if(q->ante==NULL)return q->n;
		q= q->ante;
	}
}
int Deque::back(){
	struct nodo *q =q1;
	while (q!=NULL){
		if(q->sgte==NULL)return q->n;
		q= q->sgte;
	}
}
void Deque::push_front(int f){

	if (q1 == NULL){
		push_back(f);
 	}
	else{
		struct nodo *temp;
		temp = new(struct nodo);
		temp->ante = NULL;
		temp->n = f;
		temp->sgte = q1;
		q1->ante = temp;
		q1 = temp;
		count++;
	}

}
void Deque::push_back(int b){

	struct nodo *s, *temp;
	temp = new(struct nodo); 
	temp->n = b;
	temp->sgte = NULL;
	count++;

	if (q1 == NULL){
		temp->ante = NULL;
		q1 = temp;
	}
	else{
		s = q1;
		while (s->sgte != NULL) s = s->sgte;
		s->sgte = temp;
		temp->ante = s;
	}

}
void Deque::pop_front(){
	if(q1!=NULL){
		q1 = q1->sgte;  
		q1->ante = NULL;
		count--;
	}
}
void Deque::pop_back(){
	struct nodo *tmp;
	while(1){
		if (q1->sgte == NULL){ 	
			q1 = q1->ante;
			q1->sgte = NULL;
			count--;
			break;
		}
		q1=q1->sgte;
	}
}






