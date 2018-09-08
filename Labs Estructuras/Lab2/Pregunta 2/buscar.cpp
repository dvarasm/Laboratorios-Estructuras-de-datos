#include "buscar.h"
#include <cstdio>
#include <algorithm>

using namespace std;

buscar::buscar(){
	count =0;
}

void buscar::llenar(int n){
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		vec.push_back(tmp);
	}
	 sort(vec.begin(), vec.end());
}

int buscar::rec(int min,int max,int x) {
	int centro;
	centro = (min+max)/2;
	if(vec[centro] == x){
		count++;
		return count;
	}
	if(vec[centro] < x){
		count++;
		rec(centro+1,max,x);
	}
	if(vec[centro] > x){
		count++;
		rec(min,centro-1,x);
	}
	return count;
}
int buscar::ite(int n,int x){
	count=0;
	int max = n-1;
	int min = 0;
	int centro;
	while (min <= max){
		centro = (min+max)/2;
		if (vec[centro] == x){
			count ++;
			return count;
		}
		if(vec[centro] < x){
			count++;
			min=centro+1;
		}
		if (vec[centro] > x){
			count++;
			max=centro-1;
		}
	}
	return count;
}
