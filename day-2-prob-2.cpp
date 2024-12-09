#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
	int n;
	cin >> n;
	
	vector<int>v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	
	vector<int>pref(n), sort_pref(n);
	pref[0] = v[0];
	
	for(int i = 1; i < n; ++i)
		pref[i] = pref[i - 1] + v[i];
	
	sort(v.begin(), v.end());
	
	sort_pref[0] = v[0];
	for(int i = 1; i < n; ++i)
		sort_pref[i] = sort_pref[i - 1] + v[i];
	
	// for(int x: sort_pref)
		// cout << x << ' ';
	// cout << endl;
	
	int m, type, l, r;
	cin >> m;
	
	for(int q = 0; q < m; ++q) {
		cin >> type >> l >> r;
		l--, r--;
		if(type == 1) {
			cout << pref[r] - (l > 0 ? pref[l - 1] : 0) << endl;
		} else {
			cout << sort_pref[r] - (l > 0 ? sort_pref[l - 1] : 0) << endl;
		}
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
