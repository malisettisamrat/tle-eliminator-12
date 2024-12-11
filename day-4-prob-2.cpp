#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

void solve() {
	int n, k, l, r;
	cin >> n >> k;
	
	vector<int>v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	
	vector<int>pref(n + 1, 0);
	for(int query = 0; query < k; ++query) {
		cin >> l >> r;
		pref[l] += 1;
		if(r + 1 > 0) pref[r + 1] -= 1;
	}
	
	for(int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + pref[i];
	}
	
	sort(pref.begin(), pref.end());
	sort(v.begin(), v.end());
	
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += (pref[i] * v[i - 1]);
	
	cout << ans << endl;
	
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
