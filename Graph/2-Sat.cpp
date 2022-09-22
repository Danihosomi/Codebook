#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define s second
#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define inf 1e9
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

int n, used[100005], vis[50005], comp[100005];
vi v[100005], rv[100005], ord;

void dfs1(int a){
    used[a]=1;
    for(auto x : v[a]) if(!used[x]) dfs1(x);
    ord.pb(a);
}

void dfs2(int a,int c){
    comp[a]=c;
    for(auto x : rv[a]) if(!comp[a]) dfs2(x,c);
}

int ans2Sat(){
    ord.clear();
    for(int i=1;i<=n;i++) if(!used[i]) dfs1(i);

    for(int i=0,j=1;i<n;i++){
        int x=ord[n-i-1];
        if(!comp[x]) dfs2(x,j), j++;
    }

    for(int i=1;i<=n;i+=2){
        if(comp[i]==comp[i+1]) return 0;
        vis[i/2]=(comp[i]>comp[i+1]);
    }

    return 1;
}

int main(){_

    return 0;

}