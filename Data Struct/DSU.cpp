#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
#define inf (int)1e9
#define linf (ll)1e17
typedef pair<int,int> ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

// Com roll-back
// ans representa quantas componentes formam o grafo geral
// Complexidade (log(n))
namespace DSU{
    int n, ans, pai[200005], qtd[200005];
    stack<int> p;

    void build(int n1){
        ans=n=n1;
        for(int i=0;i<=n+1;i++) pai[i]=i, qtd[i]=1;
    }

    int acha(int x){
        while(x!=pai[x]) x=pai[x];
        return x;
    }

    void join(int a,int b){
        a=acha(a); b=acha(b);
        if(a==b) return p.push(-1);
        ans--; if(qtd[a]<qtd[b]) swap(a,b);
        p.push(a); qtd[a]+=qtd[b]; pai[b]=a;
    }

    void rollback(){
        int a=p.top(); p.pop();
        if(a==-1) return ;
        qtd[pai[a]]-=qtd[a];
        pai[a]=a, ans++;
    }
};

// Sem rollback
// Complexidade de ackerman
namespace DSU{
    int n, pai[200005], qtd[200005];

    void build(int n1){
        n=n1; for(int i=0;i<=n+1;i++) pai[i]=i, qtd[i]=1;
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
};


int main(){_


    return 0;
}