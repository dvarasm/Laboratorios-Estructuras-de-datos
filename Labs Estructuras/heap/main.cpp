#include "heap.h"
#include <iostream>

int main(){

	heap h = heap();
	int c;
	cout << "Ingrese Tamano del Heap" << endl;
	cin >> c;
	for(int i; i<c; i++){ 
		//h.insert(i);
	}
	h.insert(4);
	if(h.empty()==true)cout << "Esta vacio" <<endl;
	else cout << "Tiene " << h.size() << " elementos" << endl;
	cout << "Minimo elemento del heap " << h.min() << endl;
	h.removeMin();
	if(h.empty()==true)cout << "Esta vacio" <<endl;
	else cout << "Tiene " << h.size() << " elementos" << endl;
	cout << "Minimo elemento del heap " << h.min() << endl;
	h.insert(1);
	if(h.empty()==true)cout << "Esta vacio" <<endl;
	else cout << "Tiene " << h.size() << " elementos" << endl;
	cout << "Minimo elemento del heap " << h.min() << endl;
	h.removeMin();
	if(h.empty()==true)cout << "Esta vacio" <<endl;
	else cout << "Tiene " << h.size() << " elementos" << endl;
	cout << "Minimo elemento del heap " << h.min() << endl;
	return 0;
}
