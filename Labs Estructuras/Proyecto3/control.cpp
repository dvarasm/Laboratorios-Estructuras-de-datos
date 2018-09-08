#include "control.h"
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

control::control(){
	G = new grafo();
	num_nodos=0;
	num_aristas=0;
} 

void control::leer_archivo(string n,string a){
	file = fopen (n.c_str(),"r");
	if (file==NULL){
		cout<<"File error"<<endl;
		exit(1);
	}
	char linea[100];
	fgets(linea,100,file);
	char *t;
	int i,k=0;
	while(fgets(linea,100,file)){
		t = strtok (linea," ");
		i=0;
		while(t != NULL){
			if(i==0)datos[k].ID = atoi(t);
			if(i==1)datos[k].label = t;
			if(i==2)datos[k].friends = atoi(t);
			if(i==3)datos[k].followers = atoi(t);
			if(i==4)datos[k].tweets = atoi(t);
			i++;
			t = strtok(NULL, " ");
		}
		k++;
	}
	num_nodos=k;
	fclose(file);
	file1 = fopen (a.c_str(),"r");
	if (file1==NULL){
		cout<<"File error"<<endl;
		exit(1);
	}
	fgets(linea,100,file1);
	i=0;
	k=0;
	while(fgets(linea,100,file1)){
		t = strtok (linea," ");
		i=0;
		while(t != NULL){
			if(i==0)ari[k].first = atoi(t);
			if(i==1)ari[k].second = atoi(t);;
			i++;
			t = strtok(NULL, " ");
		}
		k++;
	}
	num_aristas=k;
	fclose(file1);
}
void control::adyacencia(){
	for(int i=0;i<num_nodos;i++){
		cout <<"ID: "<<datos[i].ID <<" - "<<datos[i].label << endl;
		for(int j=0;j<G->mostrar_grafo(datos[i].ID).size();j++){
				cout << G->mostrar_grafo(datos[i].ID)[j]<<" ";
		}
		cout<<endl;
	}
}

void control::generar_grafo(){
	for(int i =0; i<num_nodos; i++){
		G->insertar_nodo(datos[i].ID);
	}

	for(int i=0; i <num_aristas;i++){
		G->insertar_arista(ari[i].first,ari[i].second);	
	}
}

void control::analisis(){
	cout<<endl;
	cout <<"Estadisticas"<<endl;
	cout <<endl;
	cout <<"Nodos: "<<num_nodos<<endl;
	cout << "Aristas: "<<num_aristas<<endl;
	int mayor = 0; 
	int id;
	for(int i = 0; i<num_nodos ; i++){ 
		if (mayor < G->grado_salida(datos[i].ID)) { 
			mayor = G->grado_salida(datos[i].ID); 
			id = datos[i].ID; 
		} 
	}
	int nodo;
	for(int i=0;i<num_nodos; i++){
		if(datos[i].ID == id){
			nodo =i;	
		}
	}
	cout <<"Nodo que sigue a mas personas de mi red de amigos: " <<datos[nodo].label <<" siguiendo a "<< mayor << endl;
	mayor = 0; 
	id=0;
	for(int i = 0; i<num_nodos ; i++){ 
		if (mayor < G->grado_entrada(datos[i].ID)) { 
			mayor = G->grado_entrada(datos[i].ID); 
			id = datos[i].ID; 
		} 
	}
	nodo=0;
	for(int i=0;i<num_nodos; i++){
		if(datos[i].ID == id){
			nodo =i;	
		}
	}
	cout <<"Nodo al que siguen mas personas de mi red de amigos: " <<datos[nodo].label <<" seguido por "<< mayor << endl;
	mayor = 0; 
	id=0;
	for(int i = 0; i<num_nodos; i++){ 
		if (mayor < datos[i].friends) { 
			mayor = datos[i].friends; 
			id = datos[i].ID; 
		} 
	}
	nodo=0;
	for(int i=0;i<num_nodos; i++){
		if(datos[i].ID == id){
			nodo =i;	
		}
	}
	cout <<"Nodo que posee mas amigos: " <<datos[nodo].label <<endl;
	cout <<"Cantidad de amigos: "<< datos[nodo].friends << endl;
	mayor = 0; 
	id=0;
	for(int i = 0; i<num_nodos ; i++){ 
		if (mayor < datos[i].followers) { 
			mayor = datos[i].followers; 
			id = datos[i].ID; 
		} 
	}
	nodo=0;
	for(int i=0;i<num_nodos; i++){
		if(datos[i].ID == id){
			nodo =i;	
		}
	}
	cout <<"Nodo que posee mas seguidores: " <<datos[nodo].label <<endl;
	cout <<"Cantidad de seguidores: "<< datos[nodo].followers << endl;
	mayor = 0; 
	id=0;
	for(int i = 0; i<num_nodos; i++){ 
		if (mayor < datos[i].tweets) { 
			mayor = datos[i].tweets; 
			id = datos[i].ID; 
		} 
	}
	nodo=0;
	for(int i=0;i<num_nodos; i++){
		if(datos[i].ID == id){
			nodo =i;	
		}
	}
	cout <<"Nodo que posee mas tweets: " <<datos[nodo].label <<endl;
	cout <<"Cantidad de tweets: "<< datos[nodo].tweets << endl;
}

void control::nodo_aislado(){
	cout<<endl;
	vector<int> nodos_aislados;
	for(int i=0;i<num_nodos; i++){
		if(G->grado_entrada(datos[i].ID)==0 && G->grado_salida(datos[i].ID)==0){
			nodos_aislados.push_back(datos[i].ID);	
		}
	}
	cout <<"Nodos aislados "<<nodos_aislados.size()<<" :"<<endl;
	for(int i=0;i<nodos_aislados.size();i++){
		for(int j=0; j< num_nodos;j++){
			if(nodos_aislados.at(i)==datos[j].ID)cout <<"		"<<i+1<<" - "<<datos[j].label <<endl;
		}
	}
}


