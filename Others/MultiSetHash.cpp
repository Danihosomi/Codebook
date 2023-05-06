#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int inf = (int)1e9;
const ll mod = 1e9 + 7;
const ll linf = (ll)1e17;

#define MAX (int)1e6+5
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());
typedef unsigned long long ull;
ull val[MAX];
void init(){
    for(int i=0;i<MAX;i++) val[i] = rng64();
}

ull getHash(vector<int>& vec){
  ull h=0;
  for(auto v : vec) h+=val[v];// xor for set
  return h;
}

int main(){_

    return 0;
}