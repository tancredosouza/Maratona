#include <bits/stdc++.h>
#define rp(i,n) for(int i = 0; i < (int) n; i++)
#define fr(i,a,b) for(int i = (int) a; i < b; i++)
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define scs(c) scanf("%s", c)
#define go(T) while(T--)
#define cl(v) memset (v,0,sizeof(v))
using namespace std;
int L;
char axis;
int sinal;
string c;
void bend() {
	if (axis == 'x' && sinal && c[0] == '-') { sinal = 0; axis = c[1];}
	else if (axis == 'x' && sinal && c[0] == '+') axis = c[1];
	else if (axis == 'x' && !sinal && c[0] == '+') {sinal = 0; axis = c[1];}
	else if (axis == 'x' && !sinal && c[0] == '-') {sinal = 1; axis = c[1];}
	
	else if (axis == c[1] && sinal && c[0] == '-') { sinal = 1; axis = 'x';}
	else if (axis == c[1] && sinal && c[0] == '+') { sinal = 0; axis = 'x';}
	else if (axis == c[1] && !sinal && c[0] == '+') {sinal = 1; axis = 'x';}
	else if (axis == c[1] && !sinal && c[0] == '-') {sinal = 0; axis = 'x';}
	
	return;
}

int main() {
	while (sc(L) && L) {
		sinal = 1; 
		axis = 'x';
		rp(i,L-1) {
			cin >> c;
			bend();
		}
		if (sinal) printf("+");
		else printf("-");
		printf("%c\n", axis);
	}
	return 0;
}
