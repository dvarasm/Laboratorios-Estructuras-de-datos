#ifndef __DEQUEADT_H
#define __DEQUEADT_H


class DequeADT{

	public:
		virtual bool empty() = 0;
		virtual int size() = 0;
		virtual int front() = 0;
		virtual int back() = 0;
		virtual void push_front(int) = 0;
		virtual void push_back(int) = 0;
		virtual void pop_front() = 0;
		virtual void pop_back() = 0;
};
#endif
