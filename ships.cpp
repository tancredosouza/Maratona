#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	int num_c = 1;
	while(cin >> s && s != "end") {
		vector<stack<char> > terminal(1000);
		int term_size = 0, min_pos, min_val;

		for(int i = 0; i < s.size(); i++) {
			//for each char
			min_pos = -1;
			for(int k = 0; k < term_size; k++) {
				if (s[i] - s[k] < min_val) {
					min_val = s[i] - s[k];
					min_pos = k;
				}
			}

			if(min_pos == -1) {
				min_pos = term_size;
				term_size++;
			}

			terminal[min_pos].push(s[i]);
		}

		printf("Case %d: %d\n", num_c++, term_size);
		terminal.clear();
	}

	return 0;
}