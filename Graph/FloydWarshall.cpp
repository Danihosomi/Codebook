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

int N, M;
ll dist[501][501][501];

void fw(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dist[k][i][j]=min(dist[k][i][j],dist[k-1][i][k]+dist[k-1][k][j]);
            }
        }
    }
}

int main(){_
    cin>>N>>M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j) continue;
            dist[0][i][j]=INF;
        }
    }

    while(M--){
        int A, B, C; cin>>A>>B>>C;
        dist[0][A][B]=C;
        dist[0][B][A]=C;
    }

    fw();

    return 0;
}