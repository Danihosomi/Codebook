#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define ii pair<int,int>
#define INF 1e9+1
#define NEG -1e9+1
#define BUG(x) cout<<x<<endl;
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;

ll mdc(ll A,ll B){
    if(B==0)
        return A;
    return mdc(B,A%B);
}

ll X, Y;

int main(){_
    cin>>X>>Y;

    cout<<mdc(X,Y)<<'\n';
    
    return 0;
}