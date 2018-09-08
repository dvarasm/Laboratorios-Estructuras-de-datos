#include "grafo.h"
#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <utility>
using namespace std;

grafo::grafo(){
	first = true;
}

void grafo::insertar_nodo(int value){
	Tnodo t,nuevo=new struct nodo;
	nuevo->ID = value;
	nuevo->sgte = NULL;
	nuevo->ady=NULL;
	if(p==NULL){
		p = nuevo;
	}
	else{
		t = p;
		while(t->sgte!=NULL){
			t = t->sgte;
		}
		t->sgte = nuevo;
	}
}


void grafo::insertar_arista(int ini,int fin){
	Tarista nuevo=new struct arista;
	Tnodo aux, aux2;
	if(p==NULL){
         cout<<"Grafo vacio!";
         return;
	}
	nuevo->sgte=NULL;
	aux=p;
	aux2=p;
	while(aux2!=NULL){
		if(aux2->ID==fin){
			break;
		} 
		aux2=aux2->sgte;
	}
	while(aux!=NULL){
		if(aux->ID==ini){
			Tarista q;
			if(aux->ady==NULL){
				aux->ady=nuevo;
				nuevo->destino=aux2;
			}
			else{
				q=aux->ady;
				while(q->sgte!=NULL){
					q=q->sgte;
				}
				nuevo->destino=aux2;
				q->sgte=nuevo;
			}
			return;
		}
		aux = aux->sgte;
	}
}

vector<int> grafo::mostrar_grafo(int nodo){
	Tnodo ptr;
	vector <int> ad;
	Tarista ar;
	ptr=p;
	while(ptr!=NULL){
		ptr->ID;
		if(ptr->ID==nodo){
			if(ptr->ady!=NULL){
				ar=ptr->ady;
				while(ar!=NULL){
					ar->destino->ID;
					ad.push_back(ar->destino->ID);
					ar=ar->sgte;
				} 
			}
		}
		ptr=ptr->sgte;
	}
	return ad;
}

int grafo::grado_salida(int nodo){
	Tnodo ptr;
	Tarista ar;
	ptr=p; 	
	int count=0;
	while(ptr!=NULL){
		ptr->ID;
		if(ptr->ID==nodo){
			if(ptr->ady!=NULL){
				ar=ptr->ady;
				while(ar!=NULL){
					ar->destino->ID;
					count++;
					ar=ar->sgte;
				} 
			}
		}
		ptr=ptr->sgte;
	}
	return count;
}

int grafo::grado_entrada(int nodo){
	Tnodo ptr;
	Tarista ar;
	ptr=p; 	
	int count=0;
	while(ptr!=NULL){
		ptr->ID;
		if(ptr->ady!=NULL){
			ar=ptr->ady;
			while(ar!=NULL){
				if(ar->destino->ID==nodo){
					count++;
				}
				ar=ar->sgte;
			} 
		}
		ptr=ptr->sgte;
	}
	return count;
}
