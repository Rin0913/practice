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

int qpow(int b, int e, int m) {
    int ans = 1;
    while(e) {
        if(e & 1)
            ans = ans * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return ans;
}

int32_t main(){
    io_o(); 
    int n; cin >> n;
    cout << qpow(2, n, 1e9 + 7);
    return 0;
}

