#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define ii pair<int,int>
#define INF 1e9+1
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define f first
#define s second
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int t;

struct matrix{
    ll m[10][10];
};
 
matrix mult(matrix A,matrix B){
    matrix ans;
    for (int i=0;i<t;i++){
        for (int j=0;j<t;j++){
            ans.m[i][j]=0;
            for (int k=0;k<t;k++){
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
            }
        }
    }
    return ans;
}
 
matrix fexpo(matrix B,ll E){
    matrix ans;
    for (int i=0;i<t;i++){
        for (int j=0;j<t;j++){
            ans.m[i][j]=(i==j ? 1 : 0);
        }
    }
    while (E){
        if(E&1) 
            ans=mult(ans,B);
        B=mult(B,B);
        E>>=1;
    }
 
    return ans;
}
 
int main(){_
    
    
	return 0;
}