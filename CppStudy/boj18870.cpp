#include <iostream>
#include <queue>

using namespace std;

struct xNode {
	int xNum, xIdx = 0;
	xNode(int num, int idx) : xNum(num), xIdx(idx) {};
	bool operator<(const xNode &x) const {
		return xNum > x.xNum;
	}
};
int ans[1000001];
priority_queue<xNode> pq;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x;

		cin >> x;
		pq.push(xNode(x, i));
	}

	
	xNode n = pq.top();
	int cnt = 0;
	int num = n.xNum;
	ans[n.xIdx] = cnt;
	pq.pop();
	
	while (!pq.empty()) {
		n = pq.top();
		pq.pop();

		if (n.xNum != num) {
			cnt++;
		}
		ans[n.xIdx] = cnt;
		num = n.xNum;
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
	

	return 0;
}