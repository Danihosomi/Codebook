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
#define LINF 1e9*1e8
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

struct node{
    ll sum, seta, setr, adda, addr;
};

int n, q, v[200005];
node seg3[4*200005];

ll join(ll a,ll b){
    return a+b;
}

int inter(pair<int, int> a, pair<int, int> b) {
	if (a.f > b.f) swap(a, b);
	return max(0, min(a.s, b.s) - b.f +1);
}

void build(int id,int l,int r){
    if(l==r){
        seg3[id].sum=v[l];
        seg3[id].seta=LINF;
        return ;
    }
    int meio=(l+r)>>1;
    build(L(id),l,meio);
    build(R(id),meio+1,r);
    seg3[id].sum=join(seg3[L(id)].sum,seg3[R(id)].sum); seg3[id].seta=LINF;
}

void refresh(int id,int l,int r){
		int tam = r-l+1;
		ll &sum = seg3[id].sum, &set_a = seg3[id].seta, &set_r = seg3[id].setr,
			&add_a = seg3[id].adda, &add_r = seg3[id].addr;

		if (set_a != LINF) {
			set_a += add_a, set_r += add_r;
			sum = set_a*tam + set_r*tam*(tam+1)/2;
			if (l != r) {
				int m = (l+r)/2;

				seg3[L(id)].seta = set_a;
				seg3[L(id)].setr = set_r;
				seg3[L(id)].adda = seg3[L(id)].addr = 0;

				seg3[R(id)].seta = set_a + set_r * (m-l+1);
				seg3[R(id)].setr = set_r;
				seg3[R(id)].adda = seg3[R(id)].addr = 0;
			}
			set_a = LINF, set_r = 0;
			add_a = add_r = 0;
		} else if (add_a || add_r) {
			sum += add_a*tam + add_r*tam*(tam-1)/2;
			if (l != r) {
				int m = (l+r)/2;

				seg3[L(id)].adda += add_a;
				seg3[L(id)].addr += add_r;

				seg3[R(id)].adda += add_a + add_r * (m-l+1);
				seg3[R(id)].addr += add_r;
			}
			add_a = add_r = 0;
		}
}

void updateSET(int id,int l,int r,int i,int j,ll A0,ll razao){
    refresh(id,l,r);
    if(j<l || r<i) return;
    if(i<=l && r<=j){
        seg3[id].seta=A0;
        seg3[id].setr=razao;
        refresh(id,l,r);
        return ;
    }
    
    int meio=(l+r)>>1;
    ll intersec=inter({l,meio},{i,j});
    updateSET(L(id),l,meio,i,j,A0,razao);
    updateSET(R(id),meio+1,r,i,j,A0+razao*intersec,razao);
    seg3[id].sum=join(seg3[L(id)].sum,seg3[R(id)].sum);    
}


void updateADD(int id,int l,int r,int i,int j,ll A0,ll razao){
    refresh(id,l,r);
    if(j<l || r<i) return;
    if(i<=l && r<=j){
        seg3[id].adda+=A0;
        seg3[id].addr+=razao;
        refresh(id,l,r);
        return ;
    }
    
    int meio=(l+r)>>1;
    ll intersec=inter({l,meio},{i,j});
    updateADD(L(id),l,meio,i,j,A0,razao);
    updateADD(R(id),meio+1,r,i,j,A0+razao*intersec,razao);
    seg3[id].sum=join(seg3[L(id)].sum,seg3[R(id)].sum);    
}

ll query(int id,int l,int r,int i,int j){
    refresh(id,l,r);
    if(r<i || j<l) return 0;
    if(i<=l && r<=j) return seg3[id].sum;
    int meio=(l+r)>>1;
    return join(query(L(id),l,meio,i,j),query(R(id),meio+1,r,i,j));
}


int main(){_

    return 0;

}