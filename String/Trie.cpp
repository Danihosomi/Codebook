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

struct trie {
	vector<vector<int>> to;
    vector<vector<ll>> sum;
	vector<int> end, pref;
	int sigma; char norm;
	
    trie(int sigma_=26, char norm_='a') : sigma(sigma_), norm(norm_) {
		to = {vector<int>(sigma)};
        sum = {vector<ll>(sigma)};
		end = {0}, pref = {0};
	}

	void insert(string s,ll val) {
		int x = 0;
		for(auto c : s) {
			int &nxt = to[x][c-norm];
			if(!nxt) {
				nxt = to.size();
				to.push_back(vector<int>(sigma));
                sum.push_back(vector<ll>(sigma));
				end.push_back(0), pref.push_back(0);
			}
			x = nxt, pref[x]++;
		}
        sum[x][(s.back())-norm]=val;
		end[x]++;
	}
	
    void erase(string s) {
		int x = 0;
		for(char c : s) {
			int &nxt = to[x][c-norm];
			x = nxt, pref[x]--;
			if(!pref[x]) nxt = 0;
		}
		end[x]--;
	}

	int find(string s) {
		int x = 0;
		for(auto c : s) {
			x = to[x][c-norm];
			if(!x) return 0;
		}
		return x;
	}

	int count_pref(string s) {
		return pref[find(s)];
	}

    ll solve(int id){
        ll ans=0, val=0;
            for(int i=0;i<sigma;i++){
                if(to[id][i]) ans=max(ans,solve(to[id][i]));
                val=max(val,sum[id][i]);
            }
        return ans+val;
    }

};

int main(){_

    int t = 1;
    //cin>>t;

    while(t--){

    }

    return 0;

}	