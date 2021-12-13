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

int N, M, low[10001], tin[10001], timer, ans;
vector<int> V[10001], resp;

void dfs(int A,int pai){
    timer++;
    tin[A]=low[A]=timer;
    int qtd=0;
    for(auto v : V[A]){
        if(v==pai) continue;
        if(tin[v])
            low[A]=min(low[A],tin[v]);
        else{
            dfs(v,A);
            qtd++;
            low[A]=min(low[A],low[v]);
            if(low[v]>=tin[A] && A!=pai)
                ans++;
        }
    }
    if(A==pai && qtd>1)
        ans++;
}

int main(){_
    
    while(cin>>N>>M){
    
        while(M--){
            int A, B; cin>>A>>B;
            V[A].emplace_back(B);
            V[B].emplace_back(A);
        }

        for(int i=1;i<=N;i++){
            if(!tin[i])
                dfs(i,i);
        }

        cout<<ans<<'\n';
    }    
    
    return 0;
}
