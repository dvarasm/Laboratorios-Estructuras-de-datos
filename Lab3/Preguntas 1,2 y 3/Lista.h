#ifndef __LISTA_h
#define __LISTA_h

class Lista {
	public:
		virtual void push_back(int) = 0;
		virtual int at(int) = 0;
		virtual int size() = 0;
};
#endif
