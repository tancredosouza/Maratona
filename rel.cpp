#include <bits/stdc++.h>
#define rp(i,n) for(int i = 0; i < (int) n; i++)
#define fr(i,a,b) for(int i = (int) a; i < b; i++)
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define go(T) while(T--)
int T,a,b;
int main() {
	sc(T);
	go(T) {
		sc2(a,b);
		if(a>b)
			puts(">");
		else if(a == b)
			puts("=");
		else
			puts("<");
	}
	return 0;
}
