#include <iostream>
#include <string>
using namespace std;

int N;
int alpha[26];
string s = "abcdefghijklmnopqrstuvwxyz";

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		alpha[input[0] - 'a']++;
	}
	bool makePlayer = true;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] >= 5) {
			cout << s[i];
			makePlayer = false;
		}
	}
	if (makePlayer)
		cout << "PREDAJA";
}