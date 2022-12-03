#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;

	vector<int> v;
	for (int i = 0; i < M; i++) {
		int num;
		string str;

		cin >> str;
		if (str.compare("all") == 0) {
			v.clear();
			for (int j = 1; j <= 20; j++) {
				v.push_back(j);
			}
			continue;
		}
		else if (str.compare("empty") == 0) {
			v.clear();
			continue;
		}

		cin >> num;
		
		if (str.compare("add") == 0) {
			if (find(v.begin(), v.end(), num) == v.end()) {
				v.push_back(num);
			}
		}
		else if (str.compare("remove") == 0) {
			auto it = find(v.begin(), v.end(), num);
			if (it != v.end()) {
				v.erase(it);
			}
		}
		else if (str.compare("check") == 0){
			auto it = find(v.begin(), v.end(), num);
			if (it != v.end()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (str.compare("toggle") == 0) {
			auto it = find(v.begin(), v.end(), num);
			if (it != v.end()) {
				v.erase(it);
			}
			else {
				v.push_back(num);
			}
		}
		

	}
}