#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#define io_o() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fst first
#define scd second
#define endl "\n"
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define REP(i,n) for(int i = 0; i < n; i++)
#define print1d(a) {for(auto v: a) cout << v << " "; cout << endl;}
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int p2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 13107};
const int p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000};

int n;

unordered_set<int> history;
vector<int> stk;

inline int count(int x) {
    int c = 0;
    while(x) x /= 10, c++;
    return max(1ll, c);
}

inline void print(int x, bool endline = true) {
    REP(i, n - count(x)) cout << '0'; cout << x << " \n"[endline];
}

int gen4(int seed, int c = 1) {
    if(history.count(seed)) return 0;
    history.insert(seed);
    stk.pb(seed);
    if(c == p2[n]) return 1;
    for(int i = 0; i < n; i ++) {
        if(seed / p10[i] % 10 == 0) {
            if(gen4(seed + p10[i], c + 1)) return 1;
        } else {
            if(gen4(seed - p10[i], c + 1)) return 1;
        }
    }
    stk.pop_back();
    history.erase(seed);
    return 0;
}

int32_t main(){
    io_o(); 

    cin >> n;

    if(n <= 8) gen4(0);
    else gen4(10101101);

    for(int i = 0; i < stk.size(); i++)
        print(stk[i], i != stk.size() - 1);
    
    return 0;
}

