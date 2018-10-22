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

int n,a,b,c;
int dp[N];
class A {
public:
	void solve(std::istream& cin, std::ostream& cout) {
        cin >> n >> a >> b >> c;

        for (int i = 1; i <= n; ++i) {
            dp[i] = INT_MIN;
        }

        dp[a] = dp[b] = dp[c] = 1;


        for (int i = 1; i <= n; ++i) {
            if (i - a >= 0){
                dp[i] = max(dp[i],dp[i - a] + 1);
            }
            if (i - b >= 0){
                dp[i] = max(dp[i],dp[i - b] + 1);
            }
            if (i - c >= 0){
                dp[i] = max(dp[i],dp[i - c] + 1);
            }
        }
        cout << dp[n] << endl;
	}
};
