#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct Person {
	int h, w;

	Person(int height, int weight) : h(height), w(weight){}

};

bool isSame(Person p1, Person p2) {
	return p1.h >= p2.h && p1.w <= p2.w || p1.h <= p2.h && p1.w >= p2.w ;
}

bool isBigger(Person p1, Person p2) {
	return p1.h > p2.h && p1.w > p2.w;
}

int main(void) {
	int n;
	cin >> n;

	vector<Person> v;
	int answer[50] = {};

	for (int i = 0; i < n; i++) {
		int w, h;
		cin >> w >> h;
		
		v.push_back(Person(w, h));
		answer[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		Person p1 = v.at(i);
		for (int j = i + 1; j < n; j++) {
			if (i == j)
				continue;

			Person p2 = v.at(j);
			if (isSame(p1, p2))
				continue;
			
			if (isBigger(p1, p2))
				answer[j]++;
			else
				answer[i]++;
		}
	}

	for (int i = 0; i <n-1; i++) {
		cout << answer[i] << " ";
	}
	cout << answer[n - 1];
	return 0;
}
