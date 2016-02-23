#include <bits/stdc++.h>
using namespace std;
char alex[21], mirror[21];
int palindrome, mirrored;
int main() {
	while (scanf("%s", alex) != EOF) {
		printf("%s -- is ", alex);
		palindrome = mirrored = 1;
		//1. Is not a palindrome
		//2. Is a regular palindrome
		//3. -- is a mirrored string.
		//4.  is a mirrored palindrome."
		mirror[0] = '\0';
		if (alex[0] == alex[strlen(alex)-1]) {
			int j = strlen(alex)-2;
			int i = 1; 
			for (;i <= j; i++,j--) {
				if (alex[i] != alex[j])
					palindrome = 0;
			}	
		}
		else
			palindrome = 0;
		int i,j;
		for (i = strlen(alex) - 1, j = 0; i >= 0; i--) {
			if (alex[i] == 'E')
				mirror[j] = '3';
			else if (alex[i] == '3')
				mirror[j] = 'E';
			else if (alex[i] == 'J')
				mirror[j] = 'L';
			else if (alex[i] == 'L')
				mirror[j] = 'J';
			else if (alex[i] == 'S')
				mirror[j] = '2';
			else if (alex[i] == '2')
				mirror[j] = 'S';
			else if (alex[i] == 'Z')
				mirror[j] = '5';
			else if (alex[i] == '5')
				mirror[j] = 'Z';
			else
				mirror[j] = alex[i];
				
			if (alex[i] == 'B' || alex[i] == 'C' || alex[i] == 'D' || alex[i] == 'F' || alex[i] == 'G' || alex[i] == 'K' || alex[i] == 'N' || alex[i] == 'P' || alex[i] == 'Q' || alex[i] == 'R' || alex[i] == '4' || alex[i] == '6' || alex[i] == '7' || alex[i] == '9')
				mirrored = 0;
			j++;
		}
		
		mirror[j] = '\0';
		if (strcmp(alex,mirror)) {
			mirrored = 0;
		}
			
		if (!mirrored && !palindrome)
			printf("not a palindrome.\n\n");
		
		else if (!mirrored && palindrome)
			printf("a regular palindrome.\n\n");
		else if(mirrored && !palindrome)
			printf("a mirrored string.\n\n");
		else if (mirrored && palindrome)
			printf("a mirrored palindrome.\n\n");
		
	}
	return 0;
}
