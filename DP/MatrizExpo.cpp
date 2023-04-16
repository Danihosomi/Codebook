#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
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
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;
const int tam =105;

struct matrix{
    ll m[tam][tam];
    matrix(){
        for (int i=0;i<tam;i++)
            for (int j=0;j<tam;j++)
                m[i][j]=(i==j ? 1 : 0);
    }
    matrix(int x){
        for (int i=0;i<x;i++)
            for (int j=0;j<x;j++)
                    m[i][j]=0;
    }
};

matrix mult(matrix a,matrix b){
    matrix ans(tam);
    for (int i=0;i<tam;i++)
        for (int j=0;j<tam;j++)
            for (int k=0;k<tam;k++) 
                ans.m[i][j]=(ans.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
    return ans;
}
 
matrix fexpo(matrix b,ll e){
    matrix ans;
        
    while(e){
        if(e&1) ans=mult(ans,b);
        b=mult(b,b); e>>=1;
    }
 
    return ans;
}
 
int main(){_
    
    
	return 0;
}