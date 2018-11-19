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



int lcm(int a,int b){
	if (__gcd(a,b) == 0){
		return INT_MAX;
	}
	return a  / __gcd(a,b) * b;
}
class Mint {
public:
	void solve(std::istream& cin, std::ostream& cout) {
		ios::sync_with_stdio(false);
		cin.tie(0);
		int n,q;
		while (cin >> n >> q) {
			if (n == 0 && q == 0){
				break;
			}
			vector<int> a(n);
			for (int i = 0; i < n; ++i) {
				cin >> a[i];
			}

			vector<int> queries(q);
			for (int i = 0; i < q; ++i) {
				cin >> queries[i];
			}

			int minLcm = INT_MAX;

			vector<int> possibleAnswer;

			for (int i = 0; i < n - 1; ++i) {
				for (int j = i + 1; j < n - 1; ++j) {
					for (int k = j + 1; k < n - 1; ++k) {
						for (int l = k + 1 ; l < n; ++l) {
							minLcm = (lcm(a[l],lcm(lcm(a[i],a[j]),a[k])));
							for (int m = 0; m < q; ++m) {
								int x = queries[m] / minLcm;
								possibleAnswer.emplace_back(x * minLcm);
								possibleAnswer.emplace_back((x + 1) * minLcm);
							}
						}
					}
				}
			}


			sort(all(possibleAnswer));
			for (int i = 0; i < q; ++i) {
				int l,r = -1;
				for (int j = 0; j < possibleAnswer.size(); ++j) {
					if (possibleAnswer[j] <= queries[i]){
						l = possibleAnswer[j];
					}
					if (possibleAnswer[j] >= queries[i] && r == -1){
						r = possibleAnswer[j];
					}
				}
				cout << l << " " << r << endl;
			}
		}
	}
};
