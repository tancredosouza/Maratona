#include <bits/stdc++.h>
#define rp(i,n) for(int i = 0; i < (int) n; i++)
#define fr(i,a,b) for(int i = (int) a; i < b; i++)
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define go(T) while(T--)
#define cl(v) memset (v,0,sizeof(v));

using namespace std;

int main() {
	double ha,U,D,F;
	double fatigue,H;
	while(scanf("%lf%lf%lf%lf", &ha,&U,&D,&F) && ha) 
	{
		H = U;
		fatigue = H*(F/100.0);
		int day = 1;
		if (H > ha) printf("success on day 1\n");
		else {
			U -= fatigue;
			if (U < 0) U = 0;
			H -= D;
			if (H < 0) printf("failure on day 1\n");
			else {
				day++;
				while (1) {
					// climbs on day
					H += U;
					if (H > ha) break;
					// loses U
					U -= fatigue;
					if (U < 0) U = 0;
					// slides at night	
					H -= D;
					if(H < 0) break;
					day++;
				}
				if(H < 0) printf("failure on day ");
				else printf("success on day ");
				printf("%d\n", day);
			}
		}			
	}
	return 0;
}
