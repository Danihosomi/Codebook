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
    int X, Y;
    ll W;
};
 
int N, M, pai[200005], qtd[200005];
ll ans;
vector< aresta > V;

bool comp(aresta A,aresta B){
    return A.W<B.W;
}

int func(int A){
    if(A==pai[A])
        return A;
    return pai[A]=func(pai[A]);
}
 
void join(int A,int B){
    A=func(A);
    B=func(B);
    if(A==B)
        return;
 
    if(qtd[A]<qtd[B]) swap (A,B);
 
    qtd[A]+=qtd[B];
    pai[B]=A;
    return;
}
 
int main(){_
    cin>>N>>M;

    for(int i=1;i<=N;i++){
        qtd[i]=1; pai[i]=i;
    }

    while(M--){
        int A, B, C;
        cin>>A>>B>>C;
        V.push_back({A,B,C});
    }
    
    sort(V.begin(),V.end(),comp);

    for(auto v : V){
        if(func(v.X)!=func(v.Y)){
            join(v.X,v.Y);
            ans+=v.W;
        }
    }
    
    cout<<ans<<'\n';

    return 0;
}