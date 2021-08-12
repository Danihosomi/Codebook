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

int N, M, vis[100005], K, pai[100005];
vi V[100005];
queue<int>Q;

int bfs(int A){
    for(int i=0;i<=N;i++)
        vis[i]=pai[i]=-1;
    
    Q.push(A);
    vis[A]=0;
    while(!Q.empty()){
        A=Q.front(); Q.pop();
        for(auto v : V[A]){
            if(vis[v]!=-1)  continue;
            vis[v]=1+vis[A];
            pai[v]=A;
            Q.push(v);
        }
    }
  
    return A;
}

int centro(){
    int ans, X;
    X=ans=bfs(bfs(1));

    while(vis[ans]>vis[X]/2)
        ans=pai[ans];

    return ans;
}

int main(){_
    cin>>N;

    K=N-1;

    while(K--){
        int A, B;
        cin>>A>>B;
        V[A].eb(B);
        V[B].eb(A);
    }
    
    cout<<centro()<<'\n';

    return 0;
}