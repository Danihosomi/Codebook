#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define ii pair<int,int>
#define INF 1e9+1
#define NEG -1e9+1
#define BUG(x) cout<<x<<endl;
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int N, id[100005], resp;
vector<int> V, P;
vector<int>::iterator it;

ll inv(vector<int> &V1){
    if(V1.size()==1)
        return 0;

    int ini1=0, ini2=0;
    ll cont=0;
    vector<int> A, B;
    
    for(int i=0;i<V1.size()/2;i++)
        A.push_back(V1[i]);
    
    for(int i=V1.size()/2;i<V1.size();i++)
        B.push_back(V1[i]);

    cont+=inv(A);
    cont+=inv(B);
    A.push_back(INF);
    B.push_back(INF);

    for(int i=0;i<V1.size();i++){
        if(A[ini1]>B[ini2]){
            V[i]=B[ini2];
            ini2++;
            cont+=A.size()-ini1-1;
        }
        else{
            V1[i]=A[ini1];
            ini1++;
        }
    }
    
    return cont;
}

int main(){_
    cin>>N;

    for(int i=1;i<=N;i++){
        int A; cin>>A;
        id[A]=i;
    }

    for(int i=1;i<=N;i++){
        int A; cin>>A;
        V.push_back(id[A]);
    }

    cout<<inv(V)<<'\n';

    return 0;
}