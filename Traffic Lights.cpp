#include <bits/stdc++.h>

using namespace std;
vector <int> lights;
int x,y,z,tempo;
bool answer;
bool Tatlo(vector<int> str, int period) {
	int turned_on, changed_orange;
	turned_on = changed_orange = 0;
	for (int i = 0; i < str.size(); i++) {
		if (period % (2*str[i]) < str[i]-5) {
			++turned_on;
		}
		if (period >= str[i]-5)
			++changed_orange;
	}
	
	if (turned_on == str.size() && changed_orange > 0)
		return true;
	
	return false;
}

int main() {
	while (scanf("%d%d%d",&x,&y,&z),(x||y||z)) {
		int hours,minutes,seconds;
		hours = minutes = seconds = 0;
		lights.push_back(x);
		lights.push_back(y);
		answer = false;
		while (z != 0) {
			lights.push_back(z);
			scanf("%d", &z);
		}
		
		for (tempo = 1; tempo <= 18000; tempo++) {
			if (Tatlo(lights, tempo)) {
				answer = true;
				break;
			}
		}
		
		if (!answer)
			printf("Signals fail to synchronise in 5 hours\n");
		else {
			hours = tempo/3600;
			tempo%=3600;
			minutes = tempo/60;
			tempo%=60;
			seconds = tempo;
			
			printf("%02d:%02d:%02d\n",hours,minutes,seconds);
		}
		lights.erase(lights.begin(),lights.end());	
	}
	return 0;
}
