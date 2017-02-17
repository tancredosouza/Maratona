#include <bits/stdc++.h>

using namespace std;
string in, res;
int pos_in, pos_res;

void func(stack<char> stk, int c, int pos, string str) {

	if(c == in.size()) {
		if (res.size() == pos)
			cout << str << endl;

		else 
			return;
	}

	else if (stk.empty() || stk.top() != res[pos]) {
		stk.push(in[++c]);
		str.push_back('i');
		str.push_back(' ');
		func(stk, c, pos, str);
	}

	else {
		str.push_back('o');
		str.push_back(' ');
		stk.pop();
		func(stk, c + 1, pos + 1, str);
	}

}

int main() {
	char c;
	string s;
	while (cin >> in >> res) {
		stack<char> anag;
		printf("[\n");
		func(anag, 0, 0, s);
		printf("\n]\n");
	}
	return 0;
}