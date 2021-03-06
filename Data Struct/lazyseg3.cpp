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

struct node{
    ll sum, lazy;
};

int N, Q, V[200005];
node seg3[4*200005];

ll join(ll A,ll B){
    return A+B;
}

void build(int id,int l,int r){
    if(l==r){
        seg3[id].sum=V[l];
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
    seg3[L(id)].lazy+=num;
    seg3[R(id)].lazy+=num;
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
    update(L(id),l,meio,i,j,val);
    update(R(id),meio+1,r,i,j,val);
    seg3[id].sum=join(seg3[L(id)].sum,seg3[R(id)].sum);    
}

ll query(int id,int l,int r,int i,int j){
    refresh(id,l,r);
    if(r<i || j<l) return 0;
    if(i<=l && r<=j) return seg3[id].sum;
    int meio=(l+r)>>1;
    return join(query(L(id),l,meio,i,j),query(R(id),meio+1,r,i,j));
}

int main(){_
    cin>>N>>Q;
    for(int i=1;i<=N;i++)
        cin>>V[i];

    build(1,1,N);

    while(Q--){
        int A;
        cin>>A;
        if(!A){
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
