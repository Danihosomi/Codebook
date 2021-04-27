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

int Q, N, M, vis[2005], ok, timer;
vector<int> V[2005];

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
    cin>>Q;
    while(Q--){
        timer++;
        cin>>N>>M;
        ok=1;
        for(int i=1;i<=N;i++){
            V[i].clear();
            vis[i]=0;
        }
        while(M--){
            int A, B;
            cin>>A>>B;
            V[A].emplace_back(B);
            V[B].emplace_back(A);
        }

        for(int i=1;i<=N;i++){
            if(!vis[i])
                dfs(i,1);
        }
        cout<<"Scenario #"<<timer<<':'<<'\n';
        if(ok)
            cout<<"No suspicious bugs found!"<<'\n';
        else
            cout<<"Suspicious bugs found!"<<'\n';
    }
 
    return 0;
}