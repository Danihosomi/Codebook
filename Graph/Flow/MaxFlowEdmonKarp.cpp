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
#define INF (int)1e9+1
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int N, S, T, pai[1000];
ll capacity[1000][1000];
vi V[1000];

ll bfs(){
    memset(pai,-1,sizeof(pai));
    pai[S]=-2;
    queue<pair<int,ll>> Q;
    Q.push({S,INF});

    while(!Q.empty()){
        ll atual, flow, new_flow;
        atual=Q.front().f; flow=Q.front().s;
        Q.pop();
        for(auto v : V[atual]){
            if(pai[v]==-1 && capacity[atual][v]>0){
                pai[v]=atual;
                new_flow=min(flow,capacity[atual][v]);
                if(v==T)
                    return new_flow;
                Q.push({v,new_flow});
            }
        }
    }

    return 0;
}

ll edmonkarp(){
    ll ans=0, new_flow;
    while(new_flow=bfs()){
        int atual=T, ant;
        ans+=new_flow;
        while(atual!=S){
            ant=pai[atual];
            capacity[ant][atual]-=new_flow;
            capacity[atual][ant]+=new_flow;
            atual=ant;
        }
    }
    return ans;
}

int main(){_

    return 0;
}