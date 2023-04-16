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
#include<string.h>
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int fw[200005], n;

void update(int x,int val){
    while(x<=n){
        fw[x]+=val;
        x+=lsb(x);
    }
}

int query(int x){
    int ans=0;
    while(x){
        ans+=fw[x];
        x-=lsb(x);
    }
    return ans;
}

int main(){_

    return 0;
}