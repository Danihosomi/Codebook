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


int N, tin[100005], tout[100005], timer, Q, up[100005][22], dist[100005];
vi V[100005];

void dfs(int A,int pai){
    tin[A]=timer;
    dist[A]=dist[pai]+1;
    timer++;
    up[A][0]=pai;
    for(int i=1;i<=21;i++)
        up[A][i]=up[up[A][i-1]][i-1];

    for(auto v : V[A]){
        if(v==pai) continue;
        dfs(v,A);
    }
    tout[A]=timer;
    timer++;
}

bool anc(int A,int B){
    return (tin[A]<=tin[B] && tout[B]<=tout[A]);
}

int LCA(int A,int B){
    if(anc(A,B)) return A;
    if(anc(B,A)) return B;

    for(int i=20;i>=0;i--){
        if(!anc(up[A][i],B))
            A=up[A][i];
    }

    return up[A][0];
}

int main(){_
    cin>>N>>Q;

    for(int i=0;i<N;i++){
        int A, B; cin>>A>>B;
        V[A].eb(B);
        V[B].eb(A);
    }

    dfs(0,0);

    while(Q--){
        int A, B;
        cin>>A>>B;
        cout<<LCA(A,B)<<'\n';
    }

    return 0;
}