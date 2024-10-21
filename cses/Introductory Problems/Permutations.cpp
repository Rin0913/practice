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

vi a, used;


int32_t main(){
    io_o(); 
    int n; cin >> n;
    if(n == 1) cout << 1;
    else if(n == 2 or n == 3) cout << "NO SOLUTION";
    else if(n == 4) cout << "2 4 1 3";
    else if(n % 2){
        REP(i, n / 2) cout << i * 2 + 2 << " ";
        REP(i, n / 2) cout << i * 2 + 1 << " ";
        cout << n; 
    } else {
        REP(i, n / 2) cout << i * 2 + 1 << " ";
        REP(i, n / 2) cout << i * 2 + 2<< " ";
    }
    return 0;
}

