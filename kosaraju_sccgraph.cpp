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
typedef long long int ll;
const ll mod=1e9+7;
//freopen("1.in", "r", stdin);

struct aresta{
    int X, Y;
};

int N, M, ini, fim, vis[1000001], cont;
ll fun[1000001], qtd[1000001];
vector<int> V[1000001], R[1000001], O;
vector< aresta > T;

void dfs(int A){
    vis[A]=1;
    for(auto v : V[A]){
        if(vis[v]) continue;
        dfs(v);
    }
    O.emplace_back(A);
}

void dfs1(int A,int B){
    vis[A]=B;
    fun[B]+=qtd[A];
    for(auto v : R[A]){
        if(vis[v]) continue;
        dfs1(v,B);
    }
}

ll ans(int A){
    if(A==vis[fim])
        return fun[A];

    if(qtd[A]!=-1)
        return qtd[A];
    
    ll resp=0;
    for(auto v : V[A])
        resp=max(resp,fun[A]+ans(v));

    return qtd[A]=resp;
}

int main(){_
    cin>>N>>M>>ini>>fim;

    for(int i=1;i<=N;i++)
        cin>>qtd[i];

    while(M--){
        int A, B;
        cin>>A>>B;
        V[A].emplace_back(B);
        R[B].emplace_back(A);
        T.push_back({A,B});
    }

    for(int i=1;i<=N;i++)
        if(!vis[i])
            dfs(i);
    
    for(int i=1;i<=N;i++){
        vis[i]=0;
        V[i].clear();
    }

    for(int i=O.size()-1;i>=0;i--){
        if(!vis[O[i]]){
            cont++;
            dfs1(O[i],cont);
        }
    }

    for(int i=0;i<T.size();i++){
        int A, B;
        A=T[i].X;
        B=T[i].Y;
        if(vis[A]!=vis[B])
            V[vis[A]].emplace_back(vis[B]);
    }
    
    for(int i=1;i<=N;i++)
        qtd[i]=-1;

    cout<<ans(vis[ini])<<'\n';

	return 0;
}