#include <iostream>
#include <cstdlib>
#include <stack>
#include "Queue.h"

using namespace std;

Queue::Queue(){
}

bool Queue::empty(){
	if(s1.empty()==1 && s2.empty()==1)return true;
	else return false;
}

int Queue::size(){
	if(s1.size() != 0) return s1.size();
	if(s2.size() != 0) return s2.size();
	else return s1.size();
}

int Queue::front(){

		if(s1.empty()==1)return s2.top();
		else{
			while(1){
				s2.push(s1.top());
				s1.pop();
				if(s1.empty()==1)return s2.top();
			}
		}

}

int Queue::back(){

		if(s2.empty()==1)return s1.top();
		else{
			while(1){
				s1.push(s2.top());
				s2.pop();
				if(s2.empty()==1)return s1.top();
			}
		}	
}

void Queue::push(int n){
	s1.push(n);
}

void Queue::pop(){
	while(1){
		if(s1.empty()==1){
			if(s2.empty()==1)break;
			s2.pop();
			break;
		}
		s2.push(s1.top());
		s1.pop();	
	}
}

void Queue::swap(Fila *q){
	int tmp;
	stack<int> s3,s4;
	while(1){
		tmp = q->front();
		s3.push(tmp);
		q->pop();
		if(q->empty()==1)break;
	}
	while(1){
		tmp = s3.top();
		s4.push(tmp);
		s3.pop();
		if(s3.empty()==1)break;
	}
	while(1){
		if(s1.empty()==1){
			while(1){
				q->push(s2.top());
				s2.pop();
				if(s2.empty()==1)break;
			}
			while(1){
				tmp = s4.top();
				s1.push(tmp);
				s4.pop();
				if(s4.empty()==1)break;
			}	
		}
		if(s2.empty()==1){
			while(1){
				s2.push(s1.top());
				s1.pop();
				if(s1.empty()==1)break;
			}
			while(1){
				q->push(s2.top());
				s2.pop();
				if(s2.empty()==1)break;
			}
			while(1){
				tmp = s4.top();
				s1.push(tmp);
				s4.pop();
				if(s4.empty()==1)break;
			}	
		}
		if(s4.empty()==1)break;
	}
}
