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
    while(t --) {
        int n, x; cin >> n >> x;
        map<int, int> cnt;
        REP(i, n) {
            int a; cin >> a;
            cnt[a] ++;
        }
        REP(ans, n + 1) {
            if(!cnt[ans]) {
                cout << ans << endl;
                break;
            }
            cnt[ans + x] += cnt[ans] - 1;
        }
    }
    return 0;
}

