#include <bits/stdc++.h>

#define ST_ID pos + 1

using namespace std;

int SET, N, S, Q, Q_i, pos, time_, v;

int main() {
	scanf("%d", &SET);
	while(SET--) {
		std::stack<int> carrier;
		cin >> N >> S >> Q;
		std::vector<std::queue<int> > B(N);
		pos = 0; time_ = 0;

		//read input
		for(int i = 0; i < N; i++) {
			cin >> Q_i;
			for(int j = 0; j < Q_i; j++) {
				cin >> v;
				B[i].push(v);
			}
		}

		//while there is stations to visit or the carrier has cargo
		while (1) {
			//unload
			while(!carrier.empty() && (carrier.top() == ST_ID || B[pos].size() < Q)) {
				if(carrier.top() != ST_ID)
					B[pos].push(carrier.top());

				carrier.pop();
				time_ += 1; //successful unload
			}

			//load
			while(!carrier.size() < S && !B[pos].empty()) {
				carrier.push(B[pos].front());
				B[pos].pop();
				time_ += 1; //successful load
			}


			//check for end
			int c = 0;
			for(int i = 0; i < N && carrier.empty(); i++) {
				if(B[i].empty())
					c++;
			}

			if(c == N)
				break;

			//move
			pos = (pos + 1)%N;
			time_ += 2;
		}

		std::cout << time_ << std::endl;
	}
	return 0;
}
