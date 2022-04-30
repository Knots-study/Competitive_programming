#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<endl

int main(){
    int a[4][4];
    REP(i,4){
        REP(j,4){
            cin >> a[i][j];
        }
    }
    const int dx[4] = {1,0,-1,0};
    const int dy[4] = {0,1,0,-1};
    
    bool flag = false;
    REP(i,4){
        REP(j,4){
            REP(k,4){
                const int ny = i + dy[k];
                const int nx = j + dx[k];
                if(nx<0||4<=nx||ny<0||4<=ny)continue;
                if(a[i][j]==a[ny][nx])flag = true;
            }
        }
    }
    if(flag)COUT("CONTINUE");
    else COUT("GAMEOVER");
    return 0;
}