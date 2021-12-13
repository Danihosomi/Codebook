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

int N, M, vis[100005], ok;
vi V[100005];

void dfs(int A,int cor){
    vis[A]=cor;
    for(auto v : V[A]){
        if(vis[v]){
            if(vis[v]==cor)
                ok=0;
            continue;
        }
        if(cor==1)
            dfs(v,2);
        else
            dfs(v,1);
    }
}

int main(){_
    cin>>N>>M;
    
    while(M--){
        int A, B;
        cin>>A>>B;
        V[A].eb(B);
        V[B].eb(A);
    }

    for(int i=1;i<=N;i++){
        if(!vis[i])
            dfs(i,1);
    }

    if(ok)
        cout<<"NAO BIPARTIDO"<<'\n';
    else
        cout<<"BIPARTIDO"<<'\n';
    
 
    return 0;
}