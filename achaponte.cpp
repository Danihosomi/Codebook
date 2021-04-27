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

int N, M, low[701], tin[701], timer, T, id;
vector<int> V[701];
vector< ii > resp;

void dfs(int A,int pai){
    timer++;
    tin[A]=low[A]=timer;
    
    for(auto v : V[A]){
        if(v==pai) continue;
        if(tin[v])
            low[A]=min(low[A],tin[v]);
        else{
            dfs(v,A);
            low[A]=min(low[A],low[v]);
            if(low[v]>tin[A])
                resp.push_back({min(A,v),max(A,v)});
        }
    }
}

int main(){_
    cin>>T;
    while(T--){
        id++;
        resp.clear();
        timer=0;
    
        cin>>N>>M;

        while(M--){
            int A, B;
            cin>>A>>B;
            V[A].emplace_back(B);
            V[B].emplace_back(A);
        }

      for(int i=1;i<=N;i++){
            if(!tin[i])
                dfs(i,i);
        }
        cout<<"Caso #"<<id<<'\n';
        if(resp.size()){
            sort(resp.begin(),resp.end());
            cout<<resp.size()<<'\n';
            for(auto r : resp)
                cout<<r.first<<' '<<r.second<<'\n';
        }
        else
            cout<<"Sin bloqueos"<<'\n';

        for(int i=1;i<=N;i++){
            tin[i]=low[i]=0;
            V[i].clear();
        }
    }
    return 0;
}
