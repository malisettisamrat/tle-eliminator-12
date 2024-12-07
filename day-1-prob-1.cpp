#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

void solve() {
	int n, q;
	cin >> n >> q;
	
	vector<ll>v(n);
	
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	
	vector<ll>pref(n);

	pref[0] = v[0];
	for(int i = 1; i < n; ++i)
		pref[i] = pref[i - 1] + v[i];
	
	int a, b;
	for(int query = 0; query < q; ++query) {
		cin >> a >> b;
		a--, b--;
		cout << pref[b] - (a == 0 ? 0 : pref[a - 1]) << endl;
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
