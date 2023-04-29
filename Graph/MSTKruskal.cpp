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

struct aresta{
        int x, y;
        ll w;
};

bool comp(aresta a,aresta b){
    return a.w<b.w;
}

namespace Kruskal{
    int n, pai[200005], qtd[200005];
    vector< aresta > e;

    void build(int n1){
        n=n1; for(int i=0;i<=n+1;i++) pai[i]=i, qtd[i]=1;
    }

    void add(aresta a){
        e.pb(a);
    }

    int acha(int x){
        return (x==pai[x] ? x : pai[x]=acha(pai[x]));
    }

    void join(int a,int b){
        a=acha(a); b=acha(b);
        if(a==b) return;
        if(qtd[a]<qtd[b]) swap(a,b);
        qtd[a]+=qtd[b]; pai[b]=a;
    }

    ll solve(){
        ll ans=0; sort(all(e),comp);
        for(auto a : e)
            if(acha(a.x)!=acha(a.y)){
                join(a.x,a.y); ans+=a.w;
            }
        

        return ans;
    }
};

int main(){_


    return 0;
}