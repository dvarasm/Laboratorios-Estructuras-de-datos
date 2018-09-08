#include "MapHash2.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

MapHash2::MapHash2(){
	for(int i=0; i<100;i++){
		map[i]=0;	
	}
	count=0;
}

bool MapHash2::empty(){
	if(count==0)return true;
	else return false;
}
int MapHash2::size(){
	return count;
}
void MapHash2::insert(string k,int v){
if(count!=100){
	int suma=0;
	int key,z=33;
	for(int i=0; i<k.size();i++){
		suma = suma + ((int)k[i])*(z^i);
	}
	key= suma%100;
	if(map[key]==0){
		map[key]=v;
		s[key]=k;
		count++;
	}
	else{
		for(int i=key;;i++){
			if(i>=100 && map[i-100]==0){
				map[i-100]=v;
				s[i-100]=k;
				count++;
				break;
			}
			if(i<=100 && map[i]==0) {
				map[i]=v;
				s[i]=k;
				count++;
				break;
			}
		}
	}
}

else cout<<"Tabla LLena!!!"<<endl;
}
int MapHash2::at(string k){
if(count!=0){
	for(int i=0;i<100;i++){
		if(s[i].compare(k)==0){
			int suma=0;
			int key,z=33;
			for(int i=0; i<k.size();i++){
				suma = suma + ((int)k[i])*(z^i);
			}
			key= suma%100;
			for(int i=key;;i++){
				if(i>100 && s[i-100].compare(k)==0){
					return map[i-100];
				}
				else if(s[i].compare(k)==0) {
					return map[i];
				}
			}
		}else cout << "Key no Existe" << endl;
	}
}
else cout<<"Tabla Vacia!!!"<<endl;
}
void MapHash2::erase(string k){
if(count!=0){
	for(int i=0;i<100;i++){
		if(s[i].compare(k)==0){
			int suma=0;
			int key,z=33;
			for(int i=0; i<k.size();i++){
				suma = suma + ((int)k[i])*(z^i);
			}
			key= suma%100;
			for(int i=key;;i++){
				if(i>100 && s[i-100].compare(k)==0){
					map[i-100]=0;
					count--;
					break;
				}
				else if(s[i].compare(k)==0) {
					map[i]=0;
					count--;
					break;
				}
			}
		}else cout << "Key no Existe" << endl;
	}
}
else cout<<"Tabla Vacia!!!"<<endl;
}
