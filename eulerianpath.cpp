#include <bits/stdc++.h>
#define INF 1e16
#define ii pair<int,int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x) & (-x))
using namespace std;
typedef long long int ll;
 
int N, M, tam, ans;
vector<int> V[100005];
set< ii > S;
vector<int> E;
 
void dfs(int A){
    if(V[A].size()%2!=0)
        ans++;
 
    for(int i=0;i<V[A].size();i++){
        int X;
        X=V[A][i];
        if(S.count({max(A,X),min(X,A)})) continue;
 
        S.insert({max(A,X),min(A,X)});
        dfs(X);
    }
    E.push_back(A);
}
 
int main(){_
    cin>>N>>M;
    tam=M+1;
    while(M--){
        int A, B;
        cin>>A>>B;
        V[A].push_back(B);
        V[B].push_back(A);
    }
 
    dfs(1);
    if(E.size()==tam && E[0]==1 && E[tam-1]==1 && !ans){
        for(int i=tam-1;i>=0;i--)
            cout<<E[i]<<' ';
        cout<<'\n';
    }
    else
        cout<<"IMPOSSIBLE"<<'\n';
 
	return 0;
}