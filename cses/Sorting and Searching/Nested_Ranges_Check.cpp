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
    int n; cin >> n;
    vector<pii> intervals;
    map<pii, int> mapping;
    REP(i, n) {
        int x, y; cin >> x >> y;
        intervals.push_back({x, -y});
        mapping[{x, y}] = i;
    }
    sort(ALL(intervals));
    REP(i, n) intervals[i].scd *= -1;
    // REP(i, n) cout << intervals[i].fst << ", " << intervals[i].scd << endl;
    
    vi A(n), B(n);
    vi AA(n), BB(n);
    vi prefix_max(n), suffix_min(n);
    prefix_max[0] = intervals[0].scd;
    suffix_min[n - 1] = intervals[n - 1].scd;
    REP(i, n - 1){
        prefix_max[i + 1] = max(prefix_max[i], intervals[i + 1].scd);
        suffix_min[n - 2 - i] = min(suffix_min[n - 1 - i], intervals[n - 2 - i].scd);
    }
 
    for(int i = 1; i < n; i++){
        if(prefix_max[i - 1] >= intervals[i].scd) B[i] = 1;
        // cout << mapping[intervals[i]] << " - " << intervals[i].fst << ". current: " << intervals[i].scd << " ? " << prefix_max[i - 1] << " = " << B[i] << endl;
    }
    for(int i = 0; i < n - 1; i++){
        if(suffix_min[i + 1] <= intervals[i].scd) A[i] = 1;
    }
 
    if(n > 1 and intervals[0] == intervals[1]) B[0] = 1;
    if(n > 1 and intervals[n - 1] == intervals[n - 2]) A[n - 1] = 1;
 
    REP(i, n) AA[mapping[intervals[i]]] = A[i], BB[mapping[intervals[i]]] = B[i];
    print1d(AA);
    print1d(BB);
 
    return 0;
}

