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

const int p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000};

int32_t main(){
    io_o(); 
    int k; cin >> k;
    while(k--) {
        int d = 1, q; cin >> q;

        for(int i = 2, n = 9; n * (i - 1) < q; i ++, n = n * 10)
            q -= n * (i - 1), d = i;

        int o = p10[d - 1] + (q - 1) / d;
        q = (q - 1) % d;
        d -= q + 1;
        while(d--) o /= 10;
        cout << o % 10 << "\n "[!k];
    }
    return 0;
}

