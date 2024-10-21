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
 
int queens[8];
int ans = 0;
int graph[8][8];
 
void dfs(int x) {
    if(x == 8) {
        ans ++;
        return;
    }
    for(int i = 0; i < 8; i++){
        if(graph[x][i] == 0) continue;
        int flag = 1;
        for(int j = 0; j < x; j++){
            if(abs(x - j) == abs(queens[j] - i)) flag = 0;
            if(queens[j] == i) flag = 0;
            if(!flag) break;
        }
        if(flag) {
            queens[x] = i;
            dfs(x + 1);
        }
    }
}
 
int32_t main(){
    io_o(); 
    REP(i, 8) {
        string x; cin >> x;
        REP(j, 8)
            graph[i][j] = x[j] == '.';
    }
    dfs(0);
    cout << ans;
    return 0;
}

