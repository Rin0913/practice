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

int n, sum, ans = 1e18;
vi a;

void solv(int i = 0, int total = 0) {
    if(i == n) {
        ans = min(ans, abs(sum - 2 * total));
        return;
    }
    solv(i + 1, total + a[i]);
    solv(i + 1, total);
}

int32_t main(){
    io_o(); 
    cin >> n; a.resize(n);
    REP(i, n) cin >> a[i], sum += a[i];
    solv();
    cout << ans;
    return 0;
}

