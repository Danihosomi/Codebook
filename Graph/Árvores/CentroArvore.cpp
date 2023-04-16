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

int n, vis[100005], pai[100005];
vi v[100005];
queue<int>q;

int bfs(int ini){
    for(int i=0;i<=n;i++) vis[i]=pai[i]=-1;
    
    q.push(ini); vis[ini]=0;
    while(!q.empty()){
        int a=q.front(); q.pop();
        for(auto x : v[a]){
            if(vis[x]!=-1)  continue;
            vis[x]=1+vis[a]; pai[x]=a;
            q.push(x);
        }
    }

    int maior=0, id=0;
    for(int i=1;i<=n;i++)
        if(maior<vis[i]) maior=vis[i], id=i;

    return id;
}

int centro(){
    int ans, x;
    x=ans=bfs(bfs(1));

    while(vis[ans]>vis[x]/2) ans=pai[ans];

    return ans;
}

int main(){_


    return 0;
}