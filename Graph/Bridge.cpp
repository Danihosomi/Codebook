#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define f first
#define s second
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb push_back
#define ii pair<int,int>
#define INF 1e9+1
#define all(x) x.begin(),x.end()
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int n, m, low[100005], tin[100005], timer;
vector<int> v[100005];
vector<ii> ans;

void dfs(int a,int pai){
    timer++; tin[a]=low[a]=timer;
    
    for(auto x : v[a]){
        if(x==pai) continue;
        if(tin[x]) low[a]=min(low[a],tin[x]);
        else{ 
            dfs(x,a); low[a]=min(low[a],low[x]);
            if(low[x]>tin[a]) ans.pb({min(a,x),max(a,x)});
        }
    }
}

void bridge(){
    for(int i=1;i<=n;i++)
        if(!tin[i]) dfs(i,i);
}

int main(){_
        

    return 0;
}
