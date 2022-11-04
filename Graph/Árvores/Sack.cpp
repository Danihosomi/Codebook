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

// O(n*log(n))
// responde query offline
// DSU on tree - maluquisse

int n, tam[200005], cor[200005], cnt[200005];
vi v[200005];

void build(int a,int p=1){
    tam[a]=1;
    for(auto &x : v[a]){
        if(x==p) continue;
        build(x,a); tam[a]+=tam[x];
        if(tam[x]>tam[v[a][0]]) swap(x,v[a][0]);
    }
}

void join(int a,int p,int num,int dont){
    cnt[cor[a]]+=num;
    
    for(int i=dont;i<sz(v[a]);i++)
        if(v[a][i]!=p) join(v[a][i],a,num,0);
}

void solve(int a,int p,int keep=0){
    for(int i=sz(v[a])-1;i>=0;i--) if(v[a][i]!=p) solve(v[a][i],a,!i);
    join(a,p,1,1);
    
    // Nesse ponto o vetor cnt conta quantas vértices de cada cor existem na subtree de a

    if(!keep) join(a,p,-1,0);
}


int main(){_


    return 0;

}