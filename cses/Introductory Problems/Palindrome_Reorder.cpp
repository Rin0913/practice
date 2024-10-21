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
    string s; cin >> s;
    int odd = -1, cnt[26] = {};
    for(char c: s) cnt[c - 'A']++;
    REP(i, 26) 
        if(cnt[i] % 2) {
            if(odd == -1) odd = i;
            else {
                cout << "NO SOLUTION";
                return 0;
            }
        }
    s[s.size() / 2] = 'A' + odd;
    int l = 0, r = s.size() - 1;
    REP(i, 26)
        while(cnt[i] > 1)
            s[l] = s[r] = 'A' + i, l++, r--, cnt[i] -= 2;
    cout << s;
    return 0;
}

