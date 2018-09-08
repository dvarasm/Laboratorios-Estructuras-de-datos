#include "grafo.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

grafo::grafo(){
	first = true;
	for (int i=0; i<500; i++){
		visitadodfs[i]=false;
		visitadobfs[i]=false;
	}
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
void grafo::databfs(){
	Tnodo ptr;
	Tarista ar;
	ptr=p;
	while(ptr!=NULL){
		if(ptr->ady!=NULL){
			ar=ptr->ady;
			while(ar!=NULL){
				adybfs[ptr->ID].push_back(ar->destino->ID);
				adybfs[ar->destino->ID].push_back(ptr->ID);
				ar=ar->sgte;
			} 
		}
		ptr=ptr->sgte;
	}
}
void grafo::datadfs(){
	Tnodo ptr;
	Tarista ar;
	ptr=p;
	while(ptr!=NULL){
		if(ptr->ady!=NULL){
			ar=ptr->ady;
			while(ar!=NULL){
				adydfs[ptr->ID].push_back(ar->destino->ID);
				adydfs[ar->destino->ID].push_back(ptr->ID);
				ar=ar->sgte;
			} 
		}
		ptr=ptr->sgte;
	}
}

void grafo::dfs(int ini){
	cout << "hola ";
	if(first ==true ){
		datadfs();
		cout<< "DFS" << endl;		
		cout<< ini;
	}
	else cout <<" -> "<<ini;
	first = false;
	visitadodfs[ini] = true;
	for( int v = 0 ; v < adydfs[ini].size(); v++ ){
		cout <<"&&"<<ini<<" "<< adydfs[ini].size();
		if(visitadodfs[adydfs[ini].at(v)]==false){
			cout << "##"<<ini;
			dfs(adydfs[ini].at(v));
		}
	}
	//for( int v = 0 ; v < adydfs[ 7 ].size(); v++ ){
	//		cout << adydfs[ 7 ].at( v )<<endl;
	//}
}


void grafo::bfs(int ini,int fin){
	databfs();
	queue<int> Q;
	Q.push(ini);
	cout << "BFS Nodo: "<<ini<<" al Nodo: "<<fin <<endl;
	while(!Q.empty()){ 
		int actual=Q.front();
		Q.pop();
		if(actual==fin)break;
		visitadobfs[actual]=true;
		for(int i=0;i<adybfs[actual].size();i++){
			if(!visitadobfs[adybfs[actual][i]]){
				cout<<actual<<" -> "<< adybfs[actual][i]<<endl;
				Q.push(adybfs[actual][i]);
			}
		}
	}	
}


void grafo::mostrar_grafo(){
	Tnodo ptr;
	Tarista ar;
	ptr=p;
	cout<<"Nodo|| Adyacencia\n"; 	
	while(ptr!=NULL){
		cout<<" "<<ptr->ID<<"  ||";
		if(ptr->ady!=NULL){
			ar=ptr->ady;
			while(ar!=NULL){
				cout<<" -> "<<ar->destino->ID;
				ar=ar->sgte;
			} 
		}
		ptr=ptr->sgte;
		cout<<endl;
	}
}
