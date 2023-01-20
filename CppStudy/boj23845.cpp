#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long int

using namespace std;

priority_queue<int> pq[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<ll> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < N; i++) {
		if (pq[v[i] + 1].empty())
			pq[v[i]].push(v[i]);
		else {
			int num = pq[v[i] + 1].top();
			pq[v[i] + 1].pop();
			pq[v[i]].push(num);
		}
	}

	ll ans = 0;
	for (int i = 1; i <= 100000; i++) {
		while (!pq[i].empty()) {
			ll num = pq[i].top();
			pq[i].pop();
			ans += num * (num - i + 1);
		}
	}
	cout << ans;
}