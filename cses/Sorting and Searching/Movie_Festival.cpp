#include<bits/stdc++.h>
#define io_o() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fst first
#define scd second
#define endl "\n"
 
using namespace std;
 
typedef long long int ll;
typedef pair<ll, ll> pii;
 
 
int main(){
    io_o(); 
    int n; cin >> n;
    vector<pii> movies;
    
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        movies.push_back({a, b});
    }
    
    sort(movies.begin(),movies.end(), [](auto a, auto b){
       return (a.scd < b.scd) or (a.scd == b.scd and a.fst < b.fst);
    });
 
    int ans = 0, lastest = 0;
 
    for(int i = 0; i < n; i++){
        if(movies[i].fst < lastest){
            continue;
        } else {
            lastest = movies[i].scd;
            ans ++;
        }
    }
    
    cout << ans;
    return 0;
}

