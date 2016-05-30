#include <bits/stdc++.h>
#define rp(i,n) for(int i = 0; i < (int) n; i++)
#define fr(i,a,b) for(int i = (int) a; i < b; i++)
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define go(T) while(T--)

using namespace std;
int N, B, H, W, p, a, min_B;
bool beds, budget, stay_home;
int main() {
	while(scanf("%d%d%d%d", &N,&B,&H,&W) != EOF) {
		stay_home = true;
		min_B = (B+1);
		rp(i, H) {
			scanf("%d", &p); //price per person
			rp(i, W) {
				scanf("%d", &a); // number of beds
				if (a >= N) {
					if(N*p < B && min_B > N*p) {
						min_B = N*p;
						stay_home = false;
					}
				}
			}
		}
		if(stay_home) { 
			puts("stay home");
		}
		else printf("%d\n", min_B);
	}
	return 0;
}
