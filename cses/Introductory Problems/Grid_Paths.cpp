#include<bits/stdc++.h>
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
 
int used[7][7];
int cnt = 49;
int ans = 0;
string path;
 
void walk(int x, int y, char lastMove = '\0'){
    if(x == 0 and y == 6 and cnt == 1) {
        ans ++;
        return;
    } else if(x == 0 and y == 6) return;
    if(x < 0 or y < 0 or x > 6 or y > 6) return;
    if(used[x][y]) return;
    if(lastMove == 'L' and (x == 0 or used[x - 1][y]) and y > 0 and y < 6 and !used[x][y - 1] and !used[x][y + 1]) return;
    if(lastMove == 'R' and (x == 6 or used[x + 1][y]) and y > 0 and y < 6 and !used[x][y - 1] and !used[x][y + 1]) return;
    if(lastMove == 'U' and (y == 0 or used[x][y - 1]) and x > 0 and x < 6 and !used[x - 1][y] and !used[x + 1][y]) return;;
    if(lastMove == 'D' and (y == 6 or used[x][y + 1]) and x > 0 and x < 6 and !used[x - 1][y] and !used[x + 1][y]) return;
    used[x][y] = 1;
    cnt --;
    int step = 48 - cnt;
    if(path[step] == 'L') walk(x - 1, y, 'L');
    if(path[step] == 'R') walk(x + 1, y, 'R');
    if(path[step] == 'U') walk(x, y - 1, 'U');
    if(path[step] == 'D') walk(x, y + 1, 'D');
    if(path[step] == '?') {
        walk(x - 1, y, 'L');
        walk(x + 1, y, 'R');
        walk(x, y - 1, 'U');
        walk(x, y + 1, 'D');
    }
    cnt ++;
    used[x][y] = 0;
}
 
int32_t main(){
    io_o(); 
    cin >> path;
    walk(0, 0);
    cout << ans;
    return 0;
}

