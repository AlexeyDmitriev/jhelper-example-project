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



class OutOf5 {
public:
	vector<int> a;
	string operations = "+-*";
	bool ok;
	void go(int pos,int sum){
		if (pos == 5 && sum == 23){
			ok = true;
			return;
		}
		if (pos < 5) {
			for(char cmd : operations) {
				if (cmd == '+')
					go(pos + 1, sum + a[pos]);
				if (cmd == '-')
					go(pos + 1, sum - a[pos]);
				if (cmd == '*')
					go(pos + 1, sum * a[pos]);
			}
		}
	}
	void solve(std::istream& cin, std::ostream& cout) {
		while (true) {
			a.resize(5);
			ok = false;
			int sum = 0;
			for (int i = 0; i < 5; ++i) {
				cin >> a[i];
				sum  += a[i];
			}
			if (sum == 0){
				break;
			}

			sort(all(a));
			
			do {
				go(1,a[0]);	
			} while (next_permutation(all(a)));
			
			if (ok){
				cout << "Possible" << endl;
			} else {
				cout << "Impossible" << endl;
			}
		}
	}
};
