#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x <<" = " << x << endl
#define MINUS(a) memset(a,0xff,sizeof(a))

const int N = (int) 1e5 + 7;

class CDivideByThree {
    string s;
    int len;
public:
    int dp[N][3][2];
    pair<int, pair<int, int> > restoreAns[N][3][2];

    int go(int pos, int mod, bool begin) {
        int &memo = dp[pos][mod][begin];
        pair<int, pair<int, int> > &way = restoreAns[pos][mod][begin];

        if (memo != -1) {
            return memo;
        }
        if (pos == len && mod == 0) {
            return memo = 0;
        }
        int ans = INT_MIN;
        if (pos < len) {
            if (!begin && s[pos] != '0') {
                int x = go(pos + 1, (mod + (s[pos] - '0')) % 3, true) + 1;
                if (x > ans) {
                    ans = x;
                    way = {pos + 1, {(mod + (s[pos] - '0')) % 3, true}};
                }
            }
            if (begin) {
                int x = go(pos + 1, (mod + (s[pos] - '0')) % 3, true) + 1;
                if (x > ans) {
                    ans = x;
                    way = {pos + 1, {(mod + (s[pos] - '0')) % 3, true}};
                }
            }
            int x = go(pos + 1, mod, begin);
            if (x > ans) {
                ans = x;
                way = {pos + 1, {mod, begin}};
            }
        }
        return memo = ans;
    }

    vector<char> res;
    void findAns(int pos, int mod, bool begin){
        if (pos == len && mod == 0) {
            return;
        }
        if (pos < len) {
            int x = restoreAns[pos][mod][begin].first;
            int y = restoreAns[pos][mod][begin].second.first;
            int z = restoreAns[pos][mod][begin].second.second;

            if (dp[pos][mod][begin] > dp[x][y][z]){
                res.push_back(s[pos]);
            }
            findAns(x,y,z);
        }
    }

    void solve(std::istream &cin, std::ostream &cout) {
        cin >> s;
        len = s.length();
        MINUS(dp);
        go(0, 0, false);
        findAns(0,0,false);
        if (res.empty() && s.find('0') != -1) {
            cout << 0 << endl;
        } else if (res.empty()) {
            cout << -1 << endl;
        } else {
            for(char x : res){
                cout << x;
            }
        }
    }
};
