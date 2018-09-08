#include "Control.h"
#include "Corrector.h"
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

Control::Control(){
	co = Corrector();
}

void Control::cerrar_archivo(){
	fclose(file);
	fclose(file1);
}

void Control::leer_dic(string nom){
	nom_dic = nom;
	file = fopen (nom.c_str(), "r" );        
	if (file==NULL){
		fputs ("File error\n",stderr);
		exit(1);
	}
	char linea[1000];
	char *t;
	while(fgets(linea,1000,file)){
		t = strtok (linea," %");
		dic.push_back(co.mayu_min(co.sololetras(co.sin_tildes(t))));
		t = strtok (NULL, " %");
	}
	co.add_dic(dic);
}
void Control::leer_arr(string nom){
	nom_tex=nom;
	file1 = fopen (nom.c_str(), "r" );        
	if (file1==NULL){
		fputs ("File error\n",stderr);
		exit(1);
	}
	char linea[1000];
	char *t;
	while(fgets(linea,1000,file1)){
		t = strtok (linea," ");
		while (t != NULL){
			arr.push_back(co.mayu_min(co.sololetras(co.sin_tildes(t))));
			t = strtok (NULL, " ");
		}
	}
	co.exis_dic(arr);
}
void Control::leer_vac(string nom){
	ofstream file2(nom.c_str(),ios::out);
	
	file2 << "Jeremias Torres/Diego Varas  Revision de archivo: " << nom_tex << " Diccionario: "<< nom_dic << " URL Diccionario: http://www.winedt.org/dict/es.zip"<<endl;
	file2 <<"Palabras en el Diccionario: "<< dic.size()<<endl;
	file2 << "Palabras en el texto: " << arr.size()<<endl;
	file2 <<"Palabras Bien Escritas: "<< (arr.size()-co.size_pa_malas()) <<endl;
	file2 <<"Palabras Mal Escritas: "<< co.size_pa_malas() <<endl; 

	for(int i=0; i<co.size_pa_malas(); i++){
		vector<string> sugerencias = co.sug(i);
		file2 <<"Correccion para: " <<co.pa_malas()[i] <<endl;
		if(sugerencias.size()==0)file2 << "No hay sugerencias!!" << endl;
		for(int j = 0; j < sugerencias.size(); j++){
			file2 << sugerencias[j] << endl;
		} 
	}

	

	file2.close();

}
