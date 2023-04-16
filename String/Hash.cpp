#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define f first
#define s second
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define ii pair<int,int>
#define INF 1e9+1
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

string S1;
ll H1[200005], P[200005];

void pre(){
    memset(H1,0,sizeof(H1)); memset(P,0,sizeof(P));
    ll A=33; P[0]=1; 
    for(int i=1;i<=sz(S1);i++)
        P[i]=(A*P[i-1])%mod;
    
    for(int i=1;i<=sz(S1);i++)
        H1[i]=(A*H1[i-1]+(S1[i-1]-'a')+1)%mod;
}

ll hash1(int l,int r){
    return (H1[r]-(H1[l-1]*P[r-l+1])%mod+mod)%mod;
}

int main(){_

    return 0;
}