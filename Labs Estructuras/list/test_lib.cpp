#include <iostream>
#include <cstdio>
#include "ArrayList.h"
#include "LinkedList.h"
#include "Stack.h"

using namespace std;

int main(){
 
	ArrayList *ar = new ArrayList();
	LinkedList *ll = new LinkedList();
	Stack *st = new Stack();

	if(ll->isEmpty() && st->isEmpty())printf("LinkedList y Stack vacios..\n");	
	printf("Llenar!!\n");
	for(int i=0;i<10;i++){
		ar->push_back(i);
		ll->push_back(i);
		st->push(i);
	}
	printf("ArrayList, LinkedList y Stack con 10 elementos\n");
	
	printf("ArrayList: ");	
	for(int i=0;i<10;i++){	
		printf("%d ",ar->at(i));
	}
	printf("\n");
	printf("LinkedList: ");	
	for(int i=0;i<10;i++){	
		printf("%d ",ll->at(i));
	}
	printf("\n");
	printf("Stack: %d\n",st->top());
	printf("Eliminar 3 elementos de LinkedList y Stack\n");
	ll->pop_front();
	ll->pop_front();
	ll->pop_front();	
	printf("LinkedList: ");	
	for(int i=0;i<7;i++){	
		printf("%d ",ll->at(i));
	}
	printf("\n");
	st->pop();
	st->pop();
	st->pop();
	printf("Stack: %d\n",st->top());
	printf("Agregar el 1 al comienzo de LinkedList\n");
	ll->push_front(1);
	printf("LinkedList: ");	
	for(int i=0;i<10;i++){	
		printf("%d ",ll->at(i));
	}
	printf("\n");
	printf("Size ArrayList: %d\n",ar->size());
 	printf("Size LinkedList: %d\n",ll->size());
	printf("Size Stack: %d\n",st->size());
 return 0;
}
