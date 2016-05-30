#include <bits/stdc++.h>
#define rp(i,n) for(int i = 0; i < (int) n; i++)
#define fr(i,a,b) for(int i = (int) a; i < b; i++)
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define go(T) while(T--)

using namespace std;
int T,v,c,maxi,n;
int main () {
	sc(T);
	while(T--) {
		sc(n);
		maxi = 0;
		rp(i,n) {
			sc(v);
			if (v > maxi) maxi = v;
		}
		
		printf("Case %d: %d\n", ++c, maxi);
	}
	return 0;
}
