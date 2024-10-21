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
    int n, m, k, ans = 0; cin >> n >> m >> k;
    vi a(n), b(m);
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> b[i];
    sort(ALL(a)); sort(ALL(b));
    int i = 0, j = 0;
    while(i < n and j < m) {
        if(abs(a[i] - b[j]) <= k) i++, j++, ans++;
        else if(a[i] > b[j]) j++;
        else i++;
    }
    cout << ans;
    return 0;
}

