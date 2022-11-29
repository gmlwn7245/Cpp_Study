#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int N, M;
// 들어온 시점
map<int, int> time;

// 개수
map<int, int> cnt;
int student[];

struct Person {
	int reCnt;
	int time;

	Person(int reCnt, int time) : reCnt(reCnt), time(time) {};

	bool operator<(const Person p) const {
		if (this->reCnt == p.reCnt)
			return this->time < p.time;		// 게시된 지 오래된 순
		return this->reCnt < p.reCnt;		// 추천 수가 적은 순
	}
};

struct cmp {
	bool operator()(int idx1, int idx2) {
		if (cnt.find(idx1) == cnt.find(idx2))
			return time.find(idx1) < time.find(idx2);
		return cnt.find(idx1) < cnt.find(idx2);
	}
};


int main() {
	cin >> N >> M;

	vector<Person> priorV;
	vector<int> conV;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;


	}
}