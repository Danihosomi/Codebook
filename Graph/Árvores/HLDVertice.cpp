#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define x(x) (int)x.size() 
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

struct node{
    ll sum, lazy;
};

node seg3[4*200005];
vector<int> v[200005];
int pos[200005], tam[200005], n, q;
int peso[200005], pai[200005];
int h[200005], valor[200005], t;

void build_hld(int k, int p = -1, int cor = 1) {
    t++;
    valor[pos[k] = t] = peso[k]; tam[k] = 1;
    
    for (auto& i : v[k]) if (i != p) {
        pai[i] = k; h[i] = (i == v[k][0] ? h[k] : i);
        build_hld(i, k, cor); tam[k] += tam[i];
        if (tam[i] > tam[v[k][0]] || v[k][0] == p) swap(i, v[k][0]);
    }

    if (p*cor == -1) build_hld(h[k] = k, -1, t = 0);
}

ll join(ll a,ll b){
    return max(a,b);
}

void build(int id,int l,int r){
    if(l==r){
        seg3[id].sum=valor[l];
        seg3[id].lazy=0;
        return ;
    }
    int meio=(l+r)>>1;
    build(L(id),l,meio);
    build(R(id),meio+1,r);
    seg3[id].sum=join(seg3[L(id)].sum,seg3[R(id)].sum);
}

void refresh(int id,int l,int r){
    if(!seg3[id].lazy) return;

    ll num=seg3[id].lazy; seg3[id].lazy=0;
    seg3[id].sum=(r-l+1)*num;
    
    if(l==r) return ;
    seg3[L(id)].lazy+=num; seg3[R(id)].lazy+=num;
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
    if(r<i || j<l) return 0;
    if(i<=l && r<=j) return seg3[id].sum;
    int meio=(l+r)>>1;
    return join(query(L(id),l,meio,i,j),query(R(id),meio+1,r,i,j));
}

ll query_path(int a, int b) {
    if (pos[a] < pos[b]) swap(a, b);
    if (h[a] == h[b]) return query(1,1,t,pos[b], pos[a]);
    return join(query(1,1,t,pos[h[a]], pos[a]),query_path(pai[h[a]], b));
}

void update_path(int a, int b, int x) {
    if (pos[a] < pos[b]) swap(a, b);

    if (h[a] == h[b]) return (void)update(1,1,t,pos[b], pos[a], x);
    update(1,1,t,pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
}

ll query_subtree(int a) {
    return query(1,1,t,pos[a], pos[a]+tam[a]-1);
}

void update_subtree(int a, int x) {
    update(1,1,t,pos[a], pos[a]+tam[a]-1, x);
}

int lca(int a, int b) {
    if (pos[a] < pos[b]) swap(a, b);
    return h[a] == h[b] ? b : lca(pai[h[a]], b);
}

int main(){_

    return 0;
}