#include <bits/stdc++.h>
#define rp(i,n) for(int i = 0; i < (int) n; i++)
#define fr(i,a,b) for(int i = (int) a; i < b; i++)
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define go(T) while(T--)
#define cl(v) memset (v,0,sizeof(v));
using namespace std;
double down,amnt,drop;
int dur,n;
int month;
int main() {
	while(scanf("%d %lf %lf %d", &dur,&down,&amnt,&n) && (dur >= 0)) {
		double m[dur+1];
		for(int i = 0; i < n; i++) {
			scanf("%d %lf", &month, &drop);
			for(int j = month; j <= dur; j++) m[j] = drop;
		}
		double val = (amnt + down)*(1.0-m[0]); //init value
		double tira = (amnt/dur);	
		//amnt -= tira;
		int res = 1;
		while((res <= dur && amnt >= val)) {
			val = val*(1.0-m[res]);
			amnt -= tira;
			res++;
		}
		res--;
		printf("%d %s",res, (res == 1)?"month\n":"months\n");
		
	}
	
	return 0;
}
