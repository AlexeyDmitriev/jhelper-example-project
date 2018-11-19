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


int dp[N][6];
pair<int,int> restoreAns[N][6];
class CIgraNaFortepiano {
public:
	vector<int> a;
	int n;
    vector<int> res;
	int go(int pos,int last){
		int &memo = dp[pos][last];
		if (memo != -1){
			return memo;
		}
		if (pos == n - 1){
			return memo = 1;
		}
		if (pos < n - 1){
			int ans = INT_MIN;
			int p1,p2;
			if (last == 0){
				for (int i = 1; i <= 5; ++i) {
				    int x = go(pos,i) + 1;
				    if (x > ans){
				        ans = x;
				        p1 = pos;
				        p2 = i;
				    }
				}
			}else {
				if (a[pos] < a[pos + 1]){
					for (int i = last + 1; i <= 5; ++i) {
                        int x = go(pos + 1,i) + 1;
                        if (x > ans){
                            ans = x;
                            p1 = pos + 1;
                            p2 = i;
                        }
					}
				}
				if (a[pos] > a[pos + 1]){
					for (int i = last - 1; i >= 1; --i) {
                        int x = go(pos + 1,i) + 1;
                        if (x > ans){
                            ans = x;
                            p1 = pos + 1;
                            p2 = i;
                        };
					}
				}

				if (a[pos] == a[pos + 1]){
					for (int i = 1; i <= 5; ++i) {
						if(i != last) {
                            int x = go(pos + 1,i) + 1;
                            if (x > ans){
                                ans = x;
                                p1 = pos + 1;
                                p2 = i;
                            }
						}
					}
				}
			}
			restoreAns[pos][last] = {p1,p2};
			return memo = ans;
		}
	}

	void findAns(int pos,int last){
	    int x = restoreAns[pos][last].first;
	    int y = restoreAns[pos][last].second;
	    if (res.size() < a.size()) {
            res.push_back(y);
            findAns(x,y);
        }
	}
	void solve(std::istream& cin, std::ostream& cout) {
		ios::sync_with_stdio(false);
		cin.tie(0);

		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		if (n == 1){
		    cout << 1 << endl;
            return;
		}
		MINUS(dp);
		if (go(0,0) > 0){
			findAns(0,0);
		    printv(res);
		}else {
            cout << -1 << endl;
        }
	}
};
