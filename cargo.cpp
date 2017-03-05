#include <bits/stdc++.h>

using namespace std;
int SET, N, S, Q;

int main() {
	scanf("%d", &SET);
	while(SET--) {
		scanf("%d %d %d", &N, &S, &Q);
		vector<queue<int> > B(N+1);
		stack<int> carrier;
		bitset<200> stat;

		stat.set();
		for(int i = N; i < 200; i++)
			stat.reset(i);
		int id, Q_i;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &Q_i);
			for(int k = 0; k < Q_i; k++) {
				scanf("%d", &id);
				B[i].push(id);
			}
		}

		int pos = 1, t = 0;
		while(1) {
			//unload in carrier stk
			while(!carrier.empty() && B[pos].size() < Q) {
				if (carrier.top() != pos)
 					B[pos].push(carrier.top());

 				carrier.pop();
				t = t + 1;
			}

			//load carrier stk
			while(carrier.size() < S && !B[pos].empty()) {
				carrier.push(B[pos].front());
				B[pos].pop();
				t = t + 1;
			}
			//check if station is clear
			if(B[pos].empty())
				stat.reset(pos - 1);
			else
				stat.set(pos - 1);

			//move
			if (carrier.empty() || stat.any()) {
				t = t + 2;
				pos = pos + 1;
			}

			else
				break;

			if(pos > N)
				pos = 1;


		}


		cout << t << endl;
	}
	return 0;
}