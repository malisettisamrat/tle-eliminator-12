#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>>grid(n + 1, vector<char>(n + 1));
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> grid[i][j];
	
	
	vector<vector<int>>pref(n + 1, vector<int>(n + 1, 0));
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) 
			if(grid[i][j] == '*')
				pref[i][j] = 1;
	}
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i > 0 and j > 0)
				pref[i][j] = pref[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
			else if(i > 0)
				pref[i][j] = pref[i][j] + pref[i - 1][j];
			else if(j > 0)
				pref[i][j] = pref[i][j] + pref[i][j - 1];
		}
	}
	
	// for(int i = 0; i < n; ++i) {
		// for(int j = 0; j < n; ++j)
			// cout << pref[i][j] << ' ';
		// cout << endl;
	// }
	
	int l1, r1, l2, r2;
	
	for(int query = 0; query < m; ++query) {
		cin >> l1 >> r1 >> l2 >> r2;
		
		l1--, r1--, l2--, r2--;
		
		if(l1 > 0 and r1 > 0)
			cout << pref[l2][r2] - pref[l1 - 1][r2] - pref[l2][r1 - 1] + pref[l1 - 1][r1 - 1] << endl;
		else if(l1 > 0)
			cout << pref[l2][r2] - pref[l1 - 1][r2] << endl;
		else if(r1 > 0)
			cout << pref[l2][r2] - pref[l2][r1 - 1] << endl;
		else
			cout << pref[l2][r2] << endl;
		
	}
	
}

void TC(bool f) {
	if(f) {
		int T;
		cin >> T;

		while(T--) {
			solve();
		}
	} else {
		solve();
	}
}

int32_t main() {

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		
		TC(0);
	
}
