#include <bits/stdc++.h>
#define rp(i,n) for(int i = 0; i < (int) n; i++)
#define fr(i,a,b) for(int i = (int) a; i < b; i++)
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define go(T) while(T--)

int K;
int xd,yd,x,y;
int main () {
	while(sc(K) && K) {
		sc2(xd,yd);
		go(K) {
			sc2(x,y);
			if (x == xd || y == yd)
				puts("divisa");
			
			else {
				if (y > yd) 
					printf("N");
				else
					printf("S");
				
				if (x < xd)
					puts("O");
				else
					puts("E");
			}
		}
	}
	return 0;
}
