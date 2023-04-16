#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
#define inf (int)1e9
#define linf (ll)1e17
typedef pair<int,int> ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

// Divide and Conquer - DP
// O(k*n^2) -> O(k*n*log(n))
//  
// Serve para dp[i][j] = min(dp[i-1][k]+C[k][j])
// dp[i][j] = 0 para j<0
// C[k][j] é uma função de custo 
// 


int n, k;
ll dp[2][50005], C[5005][5005];

void solve(int l,int r,int optl,int optr){
    if(l>r) return;

    int mid = (l+r)>>1;
    pair<ll,ll> best = {linf,-1};
    for(int i=optl;i<=min(mid,optr);i++) best = min(best,{(i ? dp[0][i-1] : 0) + C[i-1][mid], i});

    dp[1][mid]=best.f;
    solve(l,mid-1,optl,best.s);
    solve(mid+1,r,best.s,optr);
}

ll ans(){
    // Inicialization
    for(int i=0;i<2;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=linf;
    dp[0][0] = 0;  
 
    // Compute Cost-Function    
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            if(i>j) C[i][j] = linf;
            else C[i][j] = inf; // Resolve aqui oq vai usar
 
    // Solve Function
    for(int i=1;i<=k;i++){
        solve(0,n,0,n);
        for(int j=0;j<=n;j++) dp[0][j] = dp[1][j];
    }

    return dp[0][n];
}

int main(){_

    int t = 1;
    //cin>>t;
    while(t--){

    }

    return 0;
}
