#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forx(i, n) for(int i = 1 ; (i) <= (n) ; ++i)
#define ll long long
#define all(x) (x).begin(),(x).end()
#define sqr(x) (x) * (x)
#define debug(x) cout << #x <<" = " << x << endl
#define printvpair(v) for(auto x : v) cout << x.first  <<" " << x.second << endl;
#define printv(v) if (v.size()> 0) {for(auto x : v) cout << x << " "; cout << endl;}
#define MINUS(a) memset(a,0xff,sizeof(a))

const int N = (int)1e4 + 7;

const int dx[4] = {0,  0, 1, -1};
const int dy[4] = {1, -1, 0,  0};



int dp[N][207];
class Divisibility {
public:
	int n,k;
	vector<int> a;
	int go(int pos,int mod){
		int &memo = dp[pos][mod];
		if (memo != -1){
			return memo;
		}
		if (pos == n){
			return memo = (mod == 0);
		}
		if (pos < n){
			return memo = (go(pos + 1, abs((mod - a[pos]) % k)) || go(pos + 1, abs((mod + a[pos]) % k)));
		}
	}
	void run(std::istream& cin, std::ostream& cout){
		cin >> n >> k;
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		MINUS(dp);
		if (go(0,0)){
			cout << "Divisible" << endl;
		} else {
			cout << "Not divisible" << endl;
		}
	}
	void solve(std::istream& cin, std::ostream& cout) {
		int t;
		ios::sync_with_stdio(false);
		cin.tie(0);
		cin >> t;
		while (t--) run(cin,cout);
	}
};