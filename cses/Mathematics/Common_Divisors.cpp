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

const int MAXN = 1e6 + 5;

int cnt[MAXN];

int32_t main(){
    io_o();
    int n; cin >> n;
    REP(i, n) {
        int x; cin >> x;
        cnt[x]++;
    }
    
    for(int ans = MAXN; ans >= 1; ans--) {
        int mul = 0;
        for(int i = ans; i <= MAXN; i += ans) 
            mul += cnt[i];
        if(mul >= 2) {
            cout << ans;
            break;
        }
    }
    return 0;
}

