#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
#define inf (int)1e9
#define linf (ll)1e17
typedef pair<int,int> ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

ll inv(vi &v){
    if(sz(v)==1) return 0;

    int i1=0, i2=0;
    ll ans=0;
    vi a, b;
    
    for(int i=0;i<sz(v)/2;i++) a.pb(v[i]);
    for(int i=sz(v)/2;i<sz(v);i++) b.pb(v[i]);

    ans = inv(a)+inv(b);
    a.pb(inf); b.pb(inf);

    for(int i=0;i<sz(v);i++){
        if(a[i1]>b[i2]){
            v[i]=b[i2]; i2++; ans+=sz(a)-i1-1;
        }
        else{
            v[i]=a[i1]; i1++;
        }
    }

    return ans;
}

int main(){_

    return 0;
}