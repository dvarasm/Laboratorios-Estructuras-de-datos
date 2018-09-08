#include "Stack.h"


Stack::Stack(){
	ll = new LinkedList();
}

void Stack::pop(){
	ll->pop_front();
}

void Stack:: push(int n){
	ll->push_front(n);
}

int Stack::top(){
	return ll->at(0);
}

int Stack::size(){
	return ll->size();
}

bool Stack::isEmpty(){
	return ll->isEmpty();
}
