#include <cstdio>
#include <stack>
 
using namespace std;
void m(int);
 
int main() {
	int n;
	while(1) {
		scanf("%d", &n);
		if(n == 0) break;
		m(n);
		printf("\n");
	}
}

void m(int n) {
	stack<int> st;
	int c;	
	while(1) {
		while(st.size() > 0) st.pop();
		int j = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &c);
			if(c == 0) return;
			while(j < n && j != c) {
				if(st.size() > 0 && st.top() == c) break;
				j++;
				st.push(j);
			}
			if(st.top() == c) st.pop();
		}
		if(st.size() == 0){ 
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
}
