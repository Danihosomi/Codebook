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
// SegTree Persistente
//
// SegTree de soma, update de somar numa posicao
//
// query(a, b, t) retorna a query de [a, b] na versao t
// update(a, x, t) faz um update v[a]+=x a partir da
// versao de t, criando uma nova versao e retornando seu id
// Por default, faz o update a partir da ultima versao
const int MAX = 1e5+10, UPD = 1e5+10, LOG = 18;
const int MAXS = 2*MAX+UPD*LOG;

struct node{
    ll sum;
};

namespace perseg {
	node seg[MAXS]; node nulo=make(0);
	int rt[UPD], L[MAXS], R[MAXS], cnt, t;
	int n, *v;

    node join(node a,node b){
        node ans;
        ans.sum=a.sum+b.sum;
        return ans;
    }

    node make(ll a){
        node ans; ans.sum=a;
        return ans;
    }

	node build(int p, int l, int r) {
		if (l == r) return seg[p]=make(v[l]);
		L[p] = cnt++, R[p] = cnt++;
		int m = (l+r)/2;
		return seg[p] = join(build(L[p], l, m),build(R[p], m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		rt[0] = cnt++;
		build(0, 0, n-1);
	}
	node query(int a, int b, int p, int l, int r) {
		if (b < l or r < a) return nulo;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return join(query(a, b, L[p], l, m) , query(a, b, R[p], m+1, r));
	}
	node query(int a, int b, int tt) {
		return query(a, b, rt[tt], 0, n-1);
	}
	node update(int a, int x, int lp, int p, int l, int r) {
		if (l == r) return seg[p] = make(seg[lp].sum+x);
		int m = (l+r)/2;
		if (a <= m)
			return seg[p] = join(update(a, x, L[lp], L[p]=cnt++, l, m) , seg[R[p]=R[lp]]);
		return seg[p] = join(seg[L[p]=L[lp]] , update(a, x, R[lp], R[p]=cnt++, m+1, r));
	}
	int update(int a, int x, int tt=t) {
		update(a, x, rt[tt], rt[++t]=cnt++, 0, n-1);
		return t;
	}
};

int main(){_


    return 0;

}