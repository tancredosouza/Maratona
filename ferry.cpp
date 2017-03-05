#include <bits/stdc++.h>

using namespace std;

int main() {
	int c; string side; int n,t,m, time_, qcars;
	scanf("%d", &c);

	while (c--) {
		scanf("%d %d %d", &n, &t, &m);
		std::queue<int> left, right, ans_left, ans_right;
		vector<string> ans;
		while(m--) {
			cin >> time_ >> side;
			if (side == "left") left.push(time_);
			else right.push(time_);

			ans.push_back(side);
		}

		side = "left"; time_ = 0; qcars = 0;
		while(!left.empty() || !right.empty()) {
			qcars = 0;
			if(side == "left"){
				while(!left.empty() && left.front() <= time_ && qcars < n) {
					left.pop();
					qcars++;
				}

				if(qcars == 0) {
					if((right.empty()&& !left.empty()) || (!left.empty() && left.front() < right.front())) {
						time_ = left.front();
						left.pop();
						qcars++;
					}
					else if(!right.empty() && right.front() > time_) {
						time_ = right.front();
						continue;
					}
				}

				time_ += t;
				side = "right";

				while(qcars--) {
					ans_left.push(time_);
				}
			}
			else {
				while(!right.empty() && right.front() <= time_ && qcars < n) {
					right.pop();
					qcars++;
				}

				if(qcars == 0) {
					if((left.empty() && !right.empty())|| (!right.empty() && right.front() < left.front())) {
						time_ = right.front();
						right.pop();
						qcars++;
					}
					else if(!left.empty() && left.front() > time_) {
						time_ = left.front();
						continue;
					}
				}

				time_ += t;
				side = "left";

				while(qcars--) {
					ans_right.push(time_);
				}
			}
		}

		for(int i = 0; i < ans.size(); i++) {
			if(ans[i] == "left") {
				cout << ans_left.front() << endl;
				ans_left.pop();
			}

			else {
				cout << ans_right.front() << endl;
				ans_right.pop();
			}
		}

		if(c > 0)
			cout << endl;
	}

	return 0;
}
