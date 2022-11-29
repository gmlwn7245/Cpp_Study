#include <iostream>

using namespace std;


char ch[15][15];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i < 5; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < str.length(); j++) {
			ch[i][j] = str.at(j);
		}
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (ch[j][i] == NULL)
				continue;

			cout << ch[j][i];
		}
	}
}