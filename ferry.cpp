#include <bits/stdc++.h>

using namespace std;

int main() {
	int c; string side; int n,t,m, time_, qcars;
	scanf("%d", &c);

	while (c--) {
		scanf("%d %d %d", &n, &t, &m);
		std::queue<int> left, right;
		while(m--) {
			cin >> time_ >> side;
			if (side == "left") left.push(time_);
			else right.push(time_);
		}

		side = "left"; time_ = 0; qcars = 0;
		while(!left.empty() || !right.empty()) {
			qcars = 0;
			if(side == "left"){
				while(!left.empty() && left.front() <= time_ && qcars <= n) {
					left.pop();
					qcars++;
				}

				if(qcars == 0) {
					if(!right.empty() && left.front() > right.front() && right.front() > time_)
						time_ += right.front();
					else if(!left.empty()) {
						time_ = left.front();
						left.pop();
						qcars++;
					}
				}

				time_ += t;
				side = "right";
			}

			else {
				while(!right.empty() && right.front() <= time_ && qcars <= n) {
					right.pop();
					qcars++;
				}

				if(qcars == 0) {
					if(!left.empty() && right.front() > left.front() && left.front() > time_)
						time_ += left.front();
					else if (!right.empty()) {
						time_ = right.front();
						right.pop();
						qcars++;
					}
				}

				time_ += t;
				side = "left";
			}

			while(qcars--) {
				cout << time_ << endl;
			}

		}

		if(c > 0)
			cout << endl;
	}

	return 0;
}
