#include <bits/stdc++.h>
int package[10100], t,m,dif,aux;

int main() {
	while (1) {
		scanf("%d", &t);
		if (t == -1)
			break;
		m = 0;
		dif = 0;
		for (int i = 0; i < t; i++) {
			scanf("%d", &package[i]);
			m += package[i];
		}
		if (m%t != 0)
			printf("-1\n");
			
		else {
			m /= t;
			for (int i = 0; i < t; i++) {
				if (package[i] < m) {
					while (package[i] < m) {
						package[i]++;
						dif++;
					}
				}
			}
			printf("%d\n", dif);
		}
	}
	return 0;
}
