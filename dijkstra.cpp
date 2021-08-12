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
#define MAXN (int)2e5
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int N, M, ini;
ll dist[MAXN];
vector< ii > V[MAXN];
priority_queue<ii, vector<ii>, greater<ii> > P;

void dijkstra(){
    for(int i=0;i<=N;i++)
        dist[i]=INF;
    dist[ini]=0;
    P.push({0,ini});
    while(!P.empty()){
        int A; ll D;
        A=P.top().s;
        D=P.top().f;
        if(D>dist[A]) continue;
        for(auto v : V[A]){
            if(dist[v.f]>v.s+dist[A]){
                dist[v.f]=v.s+dist[A];
                P.push({dist[v.f],v.f});
            }
        }
    }
}

int main(){_
    cin>>N>>M>>ini;

    while(M--){
        int A, B, C; cin>>A>>B>>C;
        V[A].push_back({B,C});
        V[B].push_back({A,C});
    }

    dijkstra();

    return 0;
}