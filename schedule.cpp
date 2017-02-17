#include <bits/stdc++.h>

using namespace std;

int main() {
	bitset<1000200> calendar;
	int n, m;
	int s, e, r;
	bool CONFLICT;
	while (scanf("%d %d", &n, &m) && (n || m)) {
		calendar.set();
		CONFLICT = false;

		// scan single tasks
		for (int c = 0; c < n; ++c) {
			scanf("%d %d", &s, &e);

			if (!calendar.test(s) && !calendar.test(e)) {
				CONFLICT = true;
			}
			
			else {
				calendar.set(s,0);
			}

			for(int i = s + 1; i < e && !CONFLICT; ++i) {
				if (!calendar.test(i))
					CONFLICT = true;
				else
					calendar.set(i, 0);
			}
		}

		// scan repeated tasks
		for (int c = 0; c < m; ++c) {
			scanf("%d %d %d", &s, &e, &r);
			while (s <= 1000000){
				calendar.set(s,0);
				for(int i = s + 1; i < e && !CONFLICT; ++i) {
					if (!calendar.test(i))
						CONFLICT = true;
					else
						calendar.set(i, 0);
				}

				if (CONFLICT)
					break;
				s = s + r;
				e = max(1000000,e + r);
			}
		}

		if(CONFLICT)
			cout << "CONFLICT" << endl;
		else
			cout << "NO CONFLICT" << endl;
	}

	return 0;
}