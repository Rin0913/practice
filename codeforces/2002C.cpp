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

inline int dis(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int32_t main(){
    io_o(); 
    int t; cin >> t;
    while(t--) {
        int n ; cin >> n;
        vector<pii> pts(n);
        pii st, ed;
        REP(i, n) cin >> pts[i].fst >> pts[i].scd;
        cin >> st.fst >> st.scd >> ed.fst >> ed.scd;
        int flag = 1;
        int distance = dis(st.fst, st.scd, ed.fst, ed.scd);
        REP(i, n) {
            if(dis(ed.fst, ed.scd, pts[i].fst, pts[i].scd) <= distance) {
                flag = 0;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

