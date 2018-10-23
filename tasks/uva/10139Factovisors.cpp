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


class Factovisors {
public:
    void solve(std::istream &cin, std::ostream &cout) {
        int n,k;
        while (cin >> n >> k) {
            int k1 = k;
            vector<pair<int,int> > primes;
            int i = 2;

            while (i * i <= k) {
                int c = 0;
                while (k % i == 0) {
                    k /= i;
                    c++;
                }
                primes.emplace_back(i,c);
                i++;
            }

            if (k > 1)
                primes.emplace_back(k,1);

            bool ok = true;
            for (auto &prime : primes) {
                int c = 1;
                int total = 0;
                for (int j = 0; j < prime.second; ++j) {
                    c = c * prime.first;
                    total += n / c;
                }
                if (prime.second > total){
                    ok = false;
                }
            }
            if (ok){
                cout << k1 << " divides " << n << "!" << endl;
            }
            else {
                cout << k1 << " does not divide " << n << "!" << endl;
            }
        }

    }
};