#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, s, t;
	cin >> n >> s >> t;
	s--;
	t--;

	vector<int> v(n);

	for (int &e : v) { cin >> e; e--; }

	int slow = v[s];
	int fast = v[v[s]];
	while (slow != fast) {
		slow = v[slow];
		fast = v[v[fast]];
	}

	int moves = 0;
	slow = s;
	while (slow != fast && slow != t) {
		slow = v[slow];
		fast = v[fast];
		moves++;
	}

	if (slow == t) {
		cout << moves;
		return 0;
	}

	moves++;
	fast = v[slow];
	while (fast != slow && fast != t) {
		fast = v[fast];
		moves++;
	}

	if (fast == t) {
		cout << moves;
		return 0;
	}

	cout << -1;
	
}
