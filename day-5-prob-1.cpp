#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

void solve() {
	int n, k, q;
	cin >> n >> k >> q;
	
	vector<int>cnt(200002, 0);
	
	int l, r;
	for(int i = 0; i < n; ++i) {
		cin >> l >> r;
		cnt[l] += 1;
		cnt[r + 1] -= 1;
	}
	
	for(int i = 1; i < 200002; ++i)
		cnt[i] += cnt[i - 1];
	
	vector<int>valid(200002, 0);
	for(int i = 1; i < 200002; ++i)
		if(cnt[i] >= k)
			valid[i] = 1;
	
	for(int i = 1; i < 200002; ++i)
		valid[i] += valid[i - 1];
		
	while(q--) {
		cin >> l >> r;
		cout << valid[r] - valid[l - 1] << endl;
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
