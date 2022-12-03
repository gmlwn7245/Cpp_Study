#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	cin >> str;

	if (str.size() <= 1)
		cout << str;
	else {
		int adds = 0;
		for (int i = str.size() - 1; i > 0; i--) {
			int num = str.at(i) - '0' + adds;
			if (num >= 5) {
				adds = 1;
			}
			else {
				adds = 0;
			}
		}
		cout << str.at(0) - '0' + adds;
		for (int i = 0; i < str.size() - 1; i++) {
			cout << "0";
		}
	}


}