#include <bits/stdc++.h>
 
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
 	int n, m;
 	cin >> n >> m;
 	set<pair<string, string>> s;
 	map<string, string> mp1;
 	map<string, string> mp2;
 	for (int i = 0; i < m; i++) {
 		string a, b;
 		cin >> a >> b;
		s.emplace(a, b);
		mp1[a] = b; // map the two elements (original) (map 1)
		mp2[b] = a; // reverse before mapping the two elements (map 2)
 	}
 	vector<string> res;
 	for (int i = 0; i < n; i++) {
 		string lecture;
 		cin >> lecture;
		pair<string, string> p;
		if (!mp1[lecture].empty()) { // check if the word is in map 1
			p = make_pair(lecture, mp1[lecture]);			
		} else { // otherwise, it can be found on map 2
			p = make_pair(mp2[lecture], lecture); // don't forget to switch the position here
		}
		int x = p.first.size();
		int y = p.second.size();
		if (x == y || x < y) { // choose the first language if it's size if less than or equal to the second
		 res.push_back(p.first);
		} else { // otherwise, choose the second language
			res.push_back(p.second);
		}
 	}
 	for (auto& e : res) {
 		cout << e << " ";
 	}
 	cout << '\n';
	return 0;
}