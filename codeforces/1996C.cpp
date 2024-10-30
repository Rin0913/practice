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

int32_t main(){
    io_o(); 
    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;
        vector<vi> c1(n + 1, vi(26));
        vector<vi> c2(n + 1, vi(26));
        string a, b; cin >> a >> b;
        REP(i, n) c1[i + 1] = c1[i], c1[i + 1][a[i] - 'a']++;
        REP(i, n) c2[i + 1] = c2[i], c2[i + 1][b[i] - 'a']++;
        while(q--) {
            int l, r; cin >> l >> r;
            int ans = 0;
            REP(i, 26) ans += abs(c1[r][i] - c2[r][i] - c1[l - 1][i] + c2[l - 1][i]);
            cout << ans / 2 << endl;
        }
    }
    return 0;
}

