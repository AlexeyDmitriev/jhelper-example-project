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

const int N = (int)5e5 + 7;

const int dx[4] = {0,  0, 1, -1};
const int dy[4] = {1, -1, 0,  0};


int dp[101][N];
class DividingCoins {
public:
	vector<int> a;
	int total;
	int best;
	int go(int pos,int sum){
		int &memo = dp[pos][sum];
		if (memo != -1){
			return memo;
		}
		if (a.size() == pos && sum != total){
			int second = abs(sum - total);
			best = min(best,abs(sum - second));
			return memo = best;
		}
		if (pos < a.size()){
			return memo = min(go(pos + 1, sum + a[pos]),go(pos + 1, sum));
		}
	}
	void run(std::istream& cin,std::ostream& cout){
		int n;
		cin >> n;
		a.resize(n);
		total = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			total += a[i];
		}
		best = INT_MAX;
		MINUS(dp);
		go(0,0);

		cout << best << endl;
	}
	void solve(std::istream& cin, std::ostream& cout) {
		int t;
		cin >> t;
		while (t--) run(cin,cout);
	}
};
