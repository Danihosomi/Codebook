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

int n, m, vis[500005];
vector<unordered_map<int,int>> v;
stack<int> p;
 
 
void dfs(int a){
    vis[a]=1;
    for(auto x : v[a]){
        if(vis[x.f]) continue;
        dfs(x.f);
    }
}
 
vi UndirectEulerCircuit(){
    vi ans; dfs(1);
 
    for(int i=1;i<=n;i++) if(sz(v[i])%2 || (!vis[i] && sz(v[i]))) return ans;
 
    p.push(1);
    
    while(!p.empty()){
        int atual = p.top();
        if(sz(v[atual])){
            int prox = v[atual].begin()->first;
            v[atual].erase(prox);
            v[prox].erase(atual); // this part makes the for undirected graph
            p.push(prox);
        }
        else{
            ans.pb(atual);
            p.pop();
        }
    }
 
    return ans;
}


int main(){_

    return 0;
}