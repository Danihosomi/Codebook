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

int n, m;
ll fw[3003][3003];

ll getRes(int x,int y){
    ll ans=0;
    while(x){
        for(int i=y;i>0;i-=lsb(i)) ans+=fw[x][y];
        x-=lsb(x);
    }
    return ans;
}

ll query(int x,int y,int i,int j){
    return getRes(i,j)+getRes(x-1,y-1)-getRes(i,y-1)-getRes(x-1,j);
}

void update(int x,int y,ll val){
    while(x<=n){
        for(int i=y;i<=m;i+=lsb(i)) fw[x][i]+=val;
        x+=lsb(x);
    }
}

int main(){_
    int t = 1;
    //cin>>t;
    while(t--){
    }

    return 0;

}