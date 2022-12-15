#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;

	int p[201];
	int d[201];

	cin >> p[1];
	d[1] = 1;

	int maxN = 0;
	for (int i = 2; i <= N; i++) {
		cin >> p[i];
		d[i] = 1;

		for (int j = i - 1; j >= 1; j--) {
			if (p[i] > p[j]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
		maxN = max(maxN, d[i]);
		//cout << p[i] << "==>" << d[i] << endl;
	}

	int ans = N - maxN;
	cout << ans;
}