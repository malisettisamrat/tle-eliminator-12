#include <bits/stdc++.h>
using namespace std;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;

#define int long long int

void solve() {
	int n, x;
	cin >> n >> x;
	
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	
	safe_map<int, int> mark;
	int ans = 0, sum = 0;	
	mark[0] = 1;
	
	for(int i = 0; i < n; ++i) {
		sum += v[i];
		ans += mark[sum - x];
		mark[sum] += 1;
	}
	
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
