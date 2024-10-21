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
    cout << 0 << endl;
    if(n >= 2) cout << 6 << endl;
    if(n >= 3) cout << 28 << endl;
    for(int k = 4; k <= n; k++) {
        int type1 = 4; // 2 choices
        int type2 = 8; // 3 choices
        int type3 = 4 * (k - 4) + 4; // 4 choices
        int type4 = 4 * (k - 4) ; // 6 choices
        int type5 = (k - 4) * (k - 4); // 8 choices
        int all = k * k;
        int ans = type1 * (all - 3) +
                  type2 * (all - 4) +
                  type3 * (all - 5) +
                  type4 * (all - 7) +
                  type5 * (all - 9);
        cout << ans / 2 << endl;
    }
    return 0;
}

