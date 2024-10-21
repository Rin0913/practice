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
 
int32_t main(){
    io_o(); 
    int n, ans = 0; cin >> n;
    map<int, int> cnt;
    queue<int> q;
    while(n --){
        int x; cin >> x;
        while(cnt[x]) {
            cnt[q.front()] --;
            q.pop();
        }
        q.push(x);
        cnt[x] ++;
        ans = max((ll)q.size(), ans);
    }
    cout << ans << endl;
    return 0;
}

