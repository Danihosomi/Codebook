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

ll kadane(vector<ll>& v){
    ll ans=0, sum=0;

    for(auto x : v){
        sum=max(0LL,sum+x);
        ans=max(ans,sum);
    }

    return ans;
}

int main(){_

    return 0;

}