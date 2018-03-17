#include <bits/stdc++.h> 

using namespace std;
int main() {
	map<pair<double, double>, int> m;
	int t = 5;

	while(t--) {
			double x, y;
			cin >> x >> y;
			m[{x, y}]++;
		
	
		for(auto x: m) {
			cout << x.first.first << " " << x.first.second << " " << x.second << endl;
		} 
	}
	return 0;
}