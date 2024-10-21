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
    while(n --) {
        int x, y; cin >> x >> y;
        int d = max(x, y);
        cout << d * (d - 1) + 1 + (2 * (d % 2) - 1) * (y - x) << endl;
        // d * (d - 1) + 1 -> the value of (d, d)
        // (2 * (d % 2) - 1) -> convert 0 to -1 and keep 1 still 1
    }
    return 0;
}

