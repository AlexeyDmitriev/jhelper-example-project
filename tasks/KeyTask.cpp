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
#define vertex pair<int,pair<int,string> >
const int N = (int)1e5 + 7;

const int dx[4] = {0,  0, 1, -1};
const int dy[4] = {1, -1, 0,  0};


class KeyTask {
public:
	void run(int n,int m,std::istream& cin, std::ostream& cout){
		vector<vector<char> > a(n,vector<char >(m));
		int x,y, endX = 0, endY = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
				if (a[i][j] == '*'){
					x = i;
					y = j;
				}
				if (a[i][j] == 'X'){
					endX = i;
					endY = j;
				}
			}
		}
		queue<vertex> queue1;
		map<vertex ,bool > used;
		map<vertex,int> d;
		vertex temp;
		temp.first = x;
		temp.second.first = y;
		temp.second.second = "";
		queue1.emplace(temp);
		used[queue1.back()] = true;
		d[queue1.back()] = 1;
		int ans = 0;
		while (!queue1.empty()){
			vertex cur = queue1.front();
			queue1.pop();

			for (int i = 0; i < 4; ++i) {
				int x1 = cur.first + dx[i];
				int y1 = cur.second.first + dy[i];
				string keys = cur.second.second;

				if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && a[x1][y1] != '#'){
					if (x1 == endX && y1 == endY){
						ans = d[cur];
						cout << "Escape possible in "<< ans <<" steps." << endl;
						return;
					}
					vertex v;
					v.first = x1;
					v.second.first = y1;
					v.second.second = keys;
					if (a[x1][y1] == '.' || a[x1][y1] == '*'){
						if (!used[v]){
							queue1.push(v);
							used[v] = true;
							d[v] = d[cur] + 1;
						}
					} else if (islower(a[x1][y1])){
						if (keys.find(a[x1][y1]) == -1){
							keys = keys + a[x1][y1];
						}
						sort(all(keys));
						v.second.second = keys;
						if (!used[v]){
							queue1.push(v);
							used[v] = true;
							d[v] = d[cur] + 1;
						}
					} else {
						char key = (char)tolower(a[x1][y1]);
						if (keys.find(key) != -1){
							used[v] = true;
							queue1.push(v);
							d[v] = d[cur] + 1;
						}
					}
				}
			}
		}
		if (queue1.empty()){
			cout << "The poor student is trapped!" << endl;
		}
	}
	void solve(std::istream& cin, std::ostream& cout) {
		ios::sync_with_stdio(false);
		cin.tie(0);
		int n,m;
		while (cin >> n >> m){
			if (n == 0 && m == 0){
				break;
			}
			run(n,m,cin,cout);
		}
	}
};
