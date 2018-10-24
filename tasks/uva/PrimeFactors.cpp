#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forx(i, n) for(int i = 1 ; (i) <= (n) ; ++i)
#define ll long long
#define all(x) (x).begin(),(x).end()
#define sqr(x) (x) * (x)
#define debug(x) cout << #x <<" = " << x << endl
#define printvpair(v) for(auto x : v) cout << x.first  <<" " << x.second << endl;
#define printv(v) if (v.size()> 0) {for(int i = 0; i < v.size() - 1; i++) printf("%d x ", v[i]); printf("%d\n", v.back());}
#define MINUS(a) memset(a,0xff,sizeof(a))

const int N = 1e5;

const int dx[4] = {0,  0, 1, -1};
const int dy[4] = {1, -1, 0,  0};


bool primes[N + 5];

void gen_primes() {
	int i, j;
	for(i = 2; i <= (int)sqrt(1.0*N); i++)
		if (primes[i])
			for(j = i * i; j < N; j += i) primes[j] = 0;
}

bool isPrime(int n){
	return !primes[n];
}
vector<int> primeList;
int main() {
	int n;
	gen_primes();
	for(int i = 2; i <= N; i++)
		if (isPrime(i)){
			primeList.push_back(i);
		}
	while (scanf("%d", &n), n != 0) {
		int t = n;
		if (n == 0) {
			break;
		}
		int i = 0;
		vector<int> ans;

		bool minus = false;
		if (n < 0){
			n = n * -1;
			minus = true;
		}

		if (minus){
			printf("%d = -1 x ",t);
		}
		else {
			printf("%d = ",t);
		}
		while (primeList[i] * primeList[i] <= n && i < primeList.size()) {

			while (n % primeList[i]  == 0) {
				n /= primeList[i] ;
				if (n > 1){
					printf("%d x ", primeList[i] );
				}
				else {
					printf("%d\n", primeList[i] );
				}
			}
			i++;
		}

		if (n > 1) {
			printf("%d\n", n);
		}
	}
}

