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

const int N = 1e5 + 7;

const int dx[4] = {0,  0, 1, -1};
const int dy[4] = {1, -1, 0,  0};



class CodeRefactoring {
public:
	void solve(std::istream& cin, std::ostream& cout) {
		int t;
		cin >> t;
		int c = 0;
		while (t--){
			int n;
			cin >> n;

			vector<pair<int,int> > ans;
			for (int i = 2; i <= sqrt(n) && ans.size() < 2; ++i) {
				if (n % i == 0){
					ans.emplace_back(i, n / i);
				}
			}
			cout << "Case #" << ++c << ": " << n << " = ";

			cout << ans[0].first << " * " << ans[0].second << " = " << ans[1].first << " * " << ans[1].second << endl;

		}

	}
};
