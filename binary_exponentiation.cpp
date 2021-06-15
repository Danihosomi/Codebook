#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define ii pair<int,int>
#define INF 1e9+1
#define BUG(x) cout<<x<<endl;
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

ll A, B;

ll binpow(ll A,ll E){
    ll ans = 1;
    while(E){
        if(E&1) 
			ans=(ans*A)%mod;
        
		A=(A*A)%mod;
        E>>=1;
    }
    return ans;
}

int main(){_
	cin>>A>>B;

	cout<<binpow(A,B)<<'\n';

    return 0;
}