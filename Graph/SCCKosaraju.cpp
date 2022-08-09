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

struct aresta{
    int X, Y;
};

int N, M, vis[1000001], cont, qtd[1000001];
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
    qtd[B]++;
    for(auto v : R[A]){
        if(vis[v]) continue;
        dfs1(v,B);
    }
}

int main(){_
    cin>>N>>M;

    while(M--){
        int A, B;
        cin>>A>>B;
        V[A].eb(B);
        R[B].eb(A);
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

    for(auto t : T){
        if(vis[t.X]!=vis[t.Y])
            V[vis[t.X]].emplace_back(vis[t.Y]);
    }
    
    cout<<cont<<'\n';

	return 0;
}