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

string gen4(string s) { 
    int n = s.size(), pivot = -1;
    
    for(int i = n - 2; i >= 0; i--) {
        if(s[i] < s[i + 1]) {
            pivot = i;
            break;
        }
    }
    
    if(pivot == -1) return "";

    for(int i = n - 1; i >= 0; i--) {
        if(s[i] > s[pivot]) {
            swap(s[i], s[pivot]);
            reverse(s.begin() + pivot + 1, s.end());
            break;
        }
    }
    
    return s;
}

int32_t main(){
    io_o(); 
    string s; cin >> s;
    vector<string> ans;

    sort(ALL(s));

    while(s != "") {
        ans.pb(s);
        s = gen4(s);
    }

    cout << ans.size() << endl;
    for(auto s: ans) cout << s << "\n "[s == " "];
    return 0;
}

