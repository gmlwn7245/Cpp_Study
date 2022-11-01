#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main() {
	int n, res, cnt;
	string str, copy;
	char ch;
	cin >> n;

	res = 0;
	for (int i = 0; i < n; i++) {
		cin >> str;

		copy = "";
		ch = ' ';
		cnt = 1;

		for (int j = 0; j < str.size(); j++) {
			if (ch == str.at(j))
				continue;
			if (copy.find(str.at(j))!=string::npos) {
				cnt = 0;
				break;
			}

			ch = str.at(j);
			copy += ch;
		}

		res += cnt;
	}
	cout << res << endl;
}