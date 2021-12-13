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

ll N, Q, seg3[4*200005], lazy[4*200005], V[200005];

ll join(ll A,ll B){
    return A+B;
}

void build(int node,int l,int r){
    if(l==r){
        seg3[node]=V[l];
        return ;
    }
    int meio;
    meio=(l+r)>>1;
    build(L(node),l,meio);
    build(R(node),meio+1,r);
    seg3[node]=join(seg3[L(node)],seg3[R(node)]);
}

void update(int node,int l,int r,int i,int j,int val){
    if(lazy[node]){
        seg3[node]=lazy[node]*(r-l+1);
        if(r!=l){
            lazy[R(node)]=lazy[node];
            lazy[L(node)]=lazy[node];
        }
        lazy[node]=0;
    }
    if(j<l || r<i) return;
    if(i<=l && r<=j){
        seg3[node]=val*(r-l+1);
        if(r!=l){
            lazy[R(node)]=val;
            lazy[L(node)]=val;
        }
    }
    else{
        int meio;
        meio=(l+r)>>1;
        update(L(node),l,meio,i,j,val);
        update(R(node),meio+1,r,i,j,val);
        seg3[node]=join(seg3[L(node)],seg3[R(node)]);
    }
}

ll query(int node,int l,int r,int i,int j){
    if(lazy[node]){
        seg3[node]=lazy[node]*(r-l+1);
        if(l!=r){
            lazy[R(node)]=lazy[node];
            lazy[L(node)]=lazy[node];
        }
        lazy[node]=0;
    }

    if(r<i || j<l) return 0;

    if(i<=l && r<=j) return seg3[node];
    int meio;
    meio=(l+r)>>1;
    return join(query(L(node),l,meio,i,j),query(R(node),meio+1,r,i,j));
}

int main(){_
    cin>>N>>Q;

    for(int i=1;i<=N;i++)
        cin>>V[i];

    build(1,1,N);

    while(Q--){
        int A;
        cin>>A;
        if(A==1){
            int B, C, K;
            cin>>B>>C>>K;
            update(1,1,N,B,C,K);
        }
        else{
            int B, C;
            cin>>B>>C;
            cout<<query(1,1,N,B,C)<<'\n';
        }
    }

    return 0;
}
