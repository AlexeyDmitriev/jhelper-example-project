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

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};


class FractionsAgain {
public:
    void solve(std::istream &cin, std::ostream &cout) {
        int n;
        while (cin >> n) {
            int ans = 0;
            for (int i = n + 1; i <= 2 * n; ++i) {
                int up = i - n;
                int down = i * n;
                int k = __gcd(up, down);
                up /= k;
                down /= k;
                if (up == 1) {
                    ans++;
                }
            }
            cout << ans << endl;
            for (int i = n + 1; i <= 2 * n; ++i) {
                int up = i - n;
                int down = i * n;
                int k = __gcd(up, down);
                up /= k;
                down /= k;
                if (up == 1) {
                    cout << 1 << "/" << n << " = " << up << "/" << down << " + " << 1 << "/" << i << endl;
                }
            }
          
        }
    }
};
