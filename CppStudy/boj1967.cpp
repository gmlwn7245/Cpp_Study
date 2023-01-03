#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<int, vector<int>> m;
int weight[10001][10001];

priority_queue<int> pq;
vector<int> number;

int N, maxNum;
void dfs(int n, int w);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	cin >> N;


	for (int i = 1; i < N; i++) {
		int na, nb, w;
		cin >> na >> nb >> w;
		if (m.find(na) == m.end()) {
			vector<int> v;
			m.insert({ na, v });
		}

		if (m.find(nb) == m.end()) {
			vector<int> v;
			m.insert({ nb, v });
		}

		m[na].push_back(nb);
		m[nb].push_back(na);
		weight[na][nb] = w;
		weight[nb][na] = w;

		if (m[na].size() > 1)
			number.push_back(na);
		if (m[nb].size() > 1)
			number.push_back(nb);
	}
	
	sort(number.begin(), number.end());
	number.erase(unique(number.begin(), number.end()), number.end());
	
	for (int i = 0; i < number.size(); i++) {
		int n = number[i];
		vector<int> v = m[n];
		maxNum = 0;
		
		for (int j = 0; j < v.size(); j++) {
			dfs(n, v[j]);
		}
	}

}

void dfs(int n, int w) {
	bool hasChild = false;

	for (int i = 2; i < N; i++) {
		if (i == n)
			continue;

		if (weight[n][i] > 0) {
			hasChild = true;
			dfs(i, w+ weight[n][i]);
		}
	}

	if (hasChild == false) {
		maxNum = max(maxNum, w);
	}
}