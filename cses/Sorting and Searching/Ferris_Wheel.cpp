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
    int n, x; cin >> n >> x;
    multiset<int> w;
    REP(i, n) {
        int a; cin >> a;
        w.insert(a);
    }

    int ans = 0;
    while(w.size() > 1) {
        auto a = w.begin();
        auto b = w.lower_bound(x - *a);
        if(a == b) b = next(b);
        if(b == w.end()) b = prev(b);
        while(a != prev(b) and *a + *b > x) 
            b = prev(b);
        if(*a + *b > x) break;
        w.erase(a), w.erase(b), ans++;
    }
    cout << ans + w.size();
    return 0;
}

