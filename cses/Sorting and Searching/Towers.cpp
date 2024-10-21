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
    int n; cin >> n;
	vector<vi> t;
    set<pii> s;
    REP(i, n) {
        int x, idx; cin >> x;
        auto p = s.lower_bound({x + 1, 0});
        if(p == s.end())
            t.pb({x}), s.insert({x, t.size() - 1});
        else
            idx = p->scd, t[idx].pb(x), s.erase(p), s.insert({x, idx});
    }
    cout << s.size();
    return 0;
}

