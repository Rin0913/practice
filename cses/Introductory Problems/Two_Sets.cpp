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
    if(n % 2) {
        if((1 + n) / 2 % 2) cout << "NO";
        else if(n == 3) {
            cout << "YES" << endl;
            cout << "1" << endl; cout << "3" << endl;
            cout << "2" << endl; cout << "1 2";
        }
        else {
            cout << "YES" << endl;
            cout << 4 + (n - 7) / 2 << endl;
            cout << "1 2 4 7 ";
            for(int i = 8; i + 3 <= n; i += 4) 
                cout << i << " " << i + 3 << " ";
            cout << endl;
            cout << 3 + (n - 7) / 2 << endl;
            cout << "3 5 6 ";
            for(int i = 9; i + 1 <= n; i += 4)
                cout << i << " " << i + 1 << " ";
        }       
    } else {
        if(n / 2 % 2) {
            cout << "NO";
        } else if(n == 4) {
            cout << "YES" << endl;
            cout << "2" << endl; cout << "1 4" << endl;
            cout << "2" << endl; cout << "2 3";
        } else if(n >= 8) {
            cout << "YES" << endl;
            cout << n / 2 << endl;
            for(int i = 1, j = 0, k = 0; i + k <= n; i += 2, k = !k)
                cout << i + k << " ";
            cout << endl;
            cout << n/2 << endl;
            for(int i = 1, j = 0, k = 1; i + k <= n; i += 2, k = !k)
                cout << i + k << " ";
        } else cout << "NO";
    }
    return 0;
}

