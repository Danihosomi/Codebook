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
// Heavy-Light Decomposition - aresta
//
// SegTree de soma
// query / update de soma das arestas
//
// Complexidades:
// build - O(n)
// query_path - O(log^2 (n))
// update_path - O(log^2 (n))
// query_subtree - O(log(n))
// update_subtree - O(log(n))
// 3e2b4b

struct node{
    ll sum, lazy;
};

int n;
node seg3[4*10005];
vector< ii > v[10005], arestas;
int pos[10005], tam[10005];
int sobe[10005], pai[10005];
int h[10005], valor[10005], t;

void build_hld(int k, int p = -1, int cor = 1) {
    t++; valor[pos[k] = t] = sobe[k]; tam[k] = 1;
    for (auto& i : v[k]) if (i.first != p) {
        int &u = i.f, &w=i.s;
        sobe[u] = w; pai[u] = k;
        h[u] = (i == v[k][0] ? h[k] : u);
        build_hld(u, k, cor); tam[k] += tam[u];

        if (tam[u] > tam[v[k][0].first] or v[k][0].first == p)
            swap(i, v[k][0]);
    }
    if (p*cor == -1) build_hld(h[k] = k, -1, t = 0);
}


ll join(ll a,ll b){
    return max(a,b);
}

void build(int id,int l,int r){
    if(l==r){
        seg3[id].sum=valor[l];
        seg3[id].lazy=1e9;
        return ;
    }
    int meio=(l+r)>>1;
    build(L(id),l,meio);
    build(R(id),meio+1,r);
    seg3[id].sum=join(seg3[L(id)].sum,seg3[R(id)].sum); seg3[id].lazy=1e9;
}

void refresh(int id,int l,int r){
    if(seg3[id].lazy==1e9) return;

    ll num=seg3[id].lazy; seg3[id].lazy=1e9;
    seg3[id].sum=(r-l+1)*num;
    
    if(l==r) return ;
    seg3[L(id)].lazy=num; seg3[R(id)].lazy=num;
}

void update(int id,int l,int r,int i,int j,int val){
    refresh(id,l,r);
    if(j<l || r<i) return;
    if(i<=l && r<=j){
        seg3[id].lazy=val;
        refresh(id,l,r);
        return ;
    }
    
    int meio=(l+r)>>1;
    update(L(id),l,meio,i,j,val); update(R(id),meio+1,r,i,j,val);
    seg3[id].sum=join(seg3[L(id)].sum,seg3[R(id)].sum);    
}

ll query(int id,int l,int r,int i,int j){
    refresh(id,l,r);
    if(r<i || j<l) return -1e9;
    if(i<=l && r<=j) return seg3[id].sum;
    int meio=(l+r)>>1;
    return join(query(L(id),l,meio,i,j),query(R(id),meio+1,r,i,j));
}

ll query_path(int a, int b) {
    if (a == b) return 0;
    if (pos[a] < pos[b]) swap(a, b);

    if (h[a] == h[b]) return query(1,1,t,pos[b]+1, pos[a]);
    return join(query(1,1,t,pos[h[a]], pos[a]),query_path(pai[h[a]], b));
}

void update_path(int a, int b, int x) {
    if (a == b) return;
    if (pos[a] < pos[b]) swap(a, b);

    if (h[a] == h[b]) return (void)update(1,1,t,pos[b]+1, pos[a], x);
    update(1,1,t,pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
}

ll query_subtree(int a) {
    if (tam[a] == 1) return 0;
    return query(1,1,t,pos[a]+1, pos[a]+tam[a]-1);
}

void update_subtree(int a, int x) {
    if (tam[a] == 1) return;
    update(1,1,t,pos[a]+1, pos[a]+tam[a]-1, x);
}

int lca(int a, int b) {
    if (pos[a] < pos[b]) swap(a, b);
    return h[a] == h[b] ? b : lca(pai[h[a]], b);
}

int main(){_


    return 0;

}