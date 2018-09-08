#include "Nomina.h"
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

Nomina::Nomina(int num){
	typedef struct Jugador ju[num];
	num_ju=0;
}
Nomina::~Nomina(){

}
void Nomina::Add(){
	printf("Nombre: \n");
	scanf("%s %s",ju[0].nombre,ju[0].apellido);
}
void Nomina::Delete(){}
void Nomina::Data(){
	
	//printf("nombre: %s %s \n",st[0].nombre,st[0].apellido);
}
