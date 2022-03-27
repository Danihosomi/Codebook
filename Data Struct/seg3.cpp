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

int N, Q, V[100005];
ll seg3[4*100005];

ll join(ll A, ll B){
	return A+B;
}

void build(int id,int l,int r){
	if(l==r){
		seg3[id]=V[l];
		return;
	}
	int meio;
	meio=(l+r)>>1;
	build(L(id),l,meio);
	build(R(id),meio+1,r);
	seg3[id]=join(seg3[L(id)],seg3[R(id)]);
}

void update(int id,int l,int r,int i,int val){
	if(l==r && l==i){
		seg3[id]+=val;
		return;
	}
	int meio=(l+r)>>1;
	if(meio>=i)
		update(L(id),l,meio,i,val);
	else
		update(R(id),meio+1,r,i,val);
	
	seg3[id]=join(seg3[L(id)],seg3[R(id)]);
}

ll query(int id,int l,int r,int i,int j){
	if(i<=l && r<=j)
		return seg3[id];
	if(r<i || j<l)
		return 0;
	int meio=(l+r)>>1;
	ll X, Y;
	X=query(L(id),l,meio,i,j);
	Y=query(R(id),meio+1,r,i,j);
	return join(X,Y);
}

int main(){_
	cin>>N>>Q;

	for(int i=1;i<=N;i++)
		cin>>V[i];

	build(1,1,N);
	while(Q--){
		int A, B, C;
		cin>>A>>B>>C;
		if(A==1)
			update(1,1,N,B,C);
		else
			cout<<query(1,1,N,B,C)<<'\n';
	}

	return 0;
}