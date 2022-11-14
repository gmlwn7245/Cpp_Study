#include <iostream>
#include <queue>
#include <functional>
using namespace std;

struct Person {
	int h, w, idx;

	Person(int height, int weight, int index) : h(height), w(weight), idx(index) {}

	bool operator<(const Person p) const {
		if (this->h < p.h && this->w < p.w)
			return true;
		return false;
	}
};

bool isSame(Person p1, Person p2) {
	return p1.h > p2.h && p1.w < p2.w || p1.h < p2.h&& p1.w > p2.w;
}

int main(void) {
	int n;
	cin >> n;

	priority_queue<Person> pq;
	int answer[50];

	for (int i = 0; i < n; i++) {
		int w, h;
		cin >> w >> h;

		pq.push(Person(w, h, i));
	}

	answer[pq.top().idx] = 1;
	pq.pop();

	int cnt = 1;
	int realCnt = 2;
	Person prev = pq.top();

	while (!pq.empty()) {
		Person p = pq.top();
		pq.pop();

		if (isSame(prev, p)) {
			answer[p.idx] = cnt;
		}
		else {
			cnt = realCnt;
			answer[p.idx] = cnt;
		}

		realCnt++;
	}

	for (int i = 0; i < n - 1; i++) {
		cout << answer[i] << " ";
	}
	cout << answer[n - 1];
	return 0;
}
