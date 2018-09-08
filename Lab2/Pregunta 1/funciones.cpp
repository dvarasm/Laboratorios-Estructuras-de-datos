#include "funciones.h"

funciones::funciones() {
	count = 0;
}

int funciones::rec(int n) {
	if(n==1){
		count++;
		return count;
	}
	if(n%2==0){
		rec(n/2);
		count++;	
	}
	else {
		rec(3*n+1);
		count++;
	}
	return count;
}
int funciones::ite(int n){
	count=0;	

	while(n>1){
		if(n%2==0){
			n=n/2;
			count++;			
		}
		else {
			n=3*n+1;
			count++;
		}
	}
	if(n==1){
		count++;
		return count;
	}
	return count;
}
