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

int isqrt(int n) {
    int l = 1, r = n;
    while(l < r) {
        int mid = (l + r) / 2;
        if(mid <= n / mid) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return max(1, l - 1);
}

int32_t main(){
    io_o(); 
    int t; cin >> t;
    while(t --) {
        int n; cin >> n;
        int prev = 0;
        while(n != prev) {
            int m = n;
            n = n + isqrt(n) - isqrt(prev);
            // cout << isqrt(n) << " " << isqrt(prev) << endl;
            prev = m;
        }
        cout << n << endl;
    }
    return 0;
}

