#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define ii pair<int,int>
#define INF 1e9+1
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
 
struct aresta{
    int X, Y;
    ll W;
};
 
int Q, N, K, pai[200005], qtd[200005];
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
    cin>>Q;
 
    while(Q--){
        V.clear();
        ans=0;
        cin>>N>>K;

        for(int i=1;i<=N;i++){
            int A, B;
            ll C;
            cin>>A>>B>>C;
            V.push_back({A,B,C});
            pai[i]=i;
            qtd[i]=1;
        }
 
        sort(V.begin(),V.end(),comp);

        for(int i=0;i<V.size();i++){
            int A, B;
            ll P;
            A=V[i].X;
            B=V[i].Y;
            P=V[i].W;
            if(func(A)!=func(B)){
                join(A,B);
                ans+=P;
            }
        }
     
        cout<<ans<<'\n';
    }
 
    return 0;
}