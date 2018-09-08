#ifndef __FILA_H
#define __FILA_H

class Fila {
	public:
		virtual bool empty() = 0;
		virtual int size() = 0;
		virtual int front() = 0;
		virtual int back() = 0;
		virtual void push(int) = 0;
		virtual void pop() = 0;
		virtual void swap(Fila *f)=0;
};
#endif
