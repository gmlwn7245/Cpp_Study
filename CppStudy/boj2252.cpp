#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


bool visited[32001] = { false };


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N>>M;
	vector<vector<int>> p(N+1);
	vector<bool> visited(N + 1, false);

	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		if (p[n2].empty()) {
			p[n2].push_back(n1);
			continue;
		}

		bool isContain = false;

		for (int j = 0; j < p[n1].size(); j++) {
			for (int k = 0; k < p[n2].size(); k++) {
				if (p[n1].at(j) == p[n2].at(k)) {
					isContain = true;
					break;
				}
			}
		}

		if (isContain) {
			p[n2].clear();
		}
		
		p[n2].push_back(n1);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i]) {
			continue;
		}

		if (p[i].empty()) {
			cout << i << " " ;
			visited[i] = true;
			continue;
		}

		stack<int> s;
		s.push(i);

		vector<int> idx = p[i];
		
		while (!idx.empty()) {
			vector<int> tmp;
			for (int j = 0; j < idx.size(); j++) {
				int n = idx.at(j);

				if (!visited[n]) {
					s.push(n);
					tmp.insert(tmp.end(), p[n].begin(), p[n].end());
				}
			}
			idx = tmp;
		}

		while (!s.empty()) {
			int n = s.top();
			s.pop();
			visited[n] = true;
			cout << n << " ";
		}
	}
	return 0;
}