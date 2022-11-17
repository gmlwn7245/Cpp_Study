#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(vector<int> v);

int N, M;
int main() {
	cin >> N >> M;
	vector<int> newV;
	dfs(newV);
}

void dfs(vector<int> v) {
	if (v.size() == M) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << "\n";
		return ;
	}

	for (int i = 1; i <= N; i++) {
		if (find(v.begin(), v.end(), i) != v.end())
			continue;

		v.push_back(i);
		dfs(v);
		v.pop_back();
	}
}