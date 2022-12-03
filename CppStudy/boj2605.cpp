#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int idx;
		cin >> idx;

		if (idx == 0) {
			v.push_back(i + 1);
			continue;
		}
		
		if (v.size() - 1 - idx < 0) {
			v.insert(v.begin(), i + 1);
		}
		else {
			v.insert(v.end() -idx, i + 1);
		}
	}

	for (int i : v) {
		cout << i <<" ";
	}

	
}