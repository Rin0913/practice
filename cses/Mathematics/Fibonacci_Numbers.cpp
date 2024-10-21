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

const int MOD = 1e9 + 7;

struct Matrix {
    int mat[2][2];

    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                result.mat[i][j] = 0;
                for(int k = 0; k < 2; k++) {
                    result.mat[i][j] = (result.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return result;
    }
};

Matrix mpow(Matrix b, long long e) {
    Matrix ans = {{{1, 0}, {0, 1}}};
    while(e) {
        if(e & 1)
            ans = ans * b;
        b = b * b;
        e >>= 1;
    }
    return ans;
}


int32_t main(){
    io_o();
    int n; cin >> n;
    Matrix transition = {{{1, 1}, {1, 0}}};
    Matrix initial = {{{1, 0}, {0, 0}}};
    transition = mpow(transition, n);
    initial = transition * initial;
    cout << initial.mat[1][0];
    return 0;
}

