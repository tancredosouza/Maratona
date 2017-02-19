#include <bits/stdc++.h>

using namespace std;
string in, res;
int pos_in, pos_res;

void func(stack<char> stk, int c, int pos, string str) {

	if(stk.empty() && pos == res.size()) {
		if(!str.empty())
			str.erase(str.end() - 1);
		cout << str << endl;
	}

	else if((!stk.empty() && c > in.size()))
		return;

	else if (stk.empty() || stk.top() != res[pos]) {
		stk.push(in[c]);
		str.push_back('i');
		str.push_back(' ');

		func(stk, c + 1, pos, str);
	}

	else if (!stk.empty() && stk.top() == res[pos]) {
		string res;
		if(c < in.size()) {// in
			res = str;
			stk.push(in[c]);
			str.push_back('i');
			str.push_back(' ');
		
			func(stk, c + 1, pos, str);
			stk.pop();
			str = res;
		}

		//out
		if(!stk.empty()) {
			stk.pop();
			str.push_back('o');
			str.push_back(' ');

			func(stk, c, pos + 1, str);
		}
	}

	else
		return;
}

int main() {
	char c;
	string s;
	while (cin >> in >> res) {
		stack<char> anag;
		printf("[\n");
		func(anag, 0, 0, s);
		printf("]\n");
	}
	return 0;
}