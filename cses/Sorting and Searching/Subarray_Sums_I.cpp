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
    int n, t, sum = 0, ans = 0; cin >> n >> t;
    map<int, int> cnt; cnt[0] = 1;
    REP(i, n) {
        int x; cin >> x; sum += x;
        ans += cnt[sum - t], cnt[sum] ++;
    }
    cout << ans;
    return 0;
}

