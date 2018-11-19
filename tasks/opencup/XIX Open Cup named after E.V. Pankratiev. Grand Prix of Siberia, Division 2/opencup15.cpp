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

const int N = (int)1e5 + 7;

const int dx[4] = {0,  0, 1, -1};
const int dy[4] = {1, -1, 0,  0};



class opencup15 {
public:
	void solve(std::istream& cin, std::ostream& cout) {
		ios::sync_with_stdio(false);
		cin.tie(0);

		int t;
		cin >> t;

		vector<int> total(30);

		for (int i = 0; i < t; ++i) {
			string s;
			int k;
			cin >> s >> k;
			vector<int> a(30);

			for (int j = 0; j < s.length(); ++j) {
				a[s[j] - 'a']++;
			}

			for (int j = 0; j < 30; ++j) {
				a[j] *= k;
				total[j] += a[j];
			}
		}

		int ans = INT_MIN;
		for (int j = 0; j < 30; ++j) {
			ans = max(ans,total[j]);
		}
		cout << ans << endl;
	}
};
