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
    int n, m; cin >> n >> m;
    multiset<int> h;
    vi ans(m);
    REP(i, n) {int x; cin >> x; h.insert(x);}
    REP(i, m) {
        int x; cin >> x;
        auto t = h.lower_bound(x);
        while(t != h.begin() and (t == h.end() or *t > x)) t = prev(t);
        if(t == h.begin() and (t == h.end() or *t > x)) ans[i] = -1;
        else ans[i] = *t, h.erase(t);
    }
    REP(i, m) cout << ans[i] << "\n "[i == m - 1];
    return 0;
}

