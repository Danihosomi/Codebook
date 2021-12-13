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

ll A, B;
ll dp[12][110][2], ans1, ans2;
vector<int> V;

void digit(ll X){
    if(X==0)
        V.emplace_back(0);
    while(X){
        V.emplace_back(X%10);
        X/=10;
    }
}

ll ans(int id,int sum,int t){
    if(id==-1)
        return sum;

    if(dp[id][sum][t]!=-1)
        return dp[id][sum][t];

    ll resp=0;
    if(t){
        for(int i=0;i<=9;i++)
            resp=(resp+ans(id-1,sum+i,1))%mod;
    }
    else{
        resp=(resp+ans(id-1,sum+V[id],0))%mod;
        for(int i=0;i<V[id];i++)
            resp=(resp+ans(id-1,sum+i,1))%mod;
    }

    return dp[id][sum][t]=resp;
} 

int main(){_
    while(cin>>A>>B){
        A--;
        memset(dp,-1,sizeof(dp));
        V.clear();

        digit(A);
        ans1=ans(V.size()-1,0,0);
        ans1%=mod;
       

        V.clear();
        memset(dp,-1,sizeof(dp));

        digit(B);
        ans2=ans(V.size()-1,0,0);
        ans2%=mod;

        cout<<(ans2-ans1)%mod<<'\n';
    }

    return 0;
}