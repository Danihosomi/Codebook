#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define ii pair<int,int>
#define INF 1e9+1
#define NEG -1e9+1
#define BUG(x) cout<<x<<endl;
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int T, N, Q, V[100005], timer;
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

void update(int id,int l,int r,int val, int i){
	if(l==r && l==i){
		seg3[id]+=val;
		return;
	}
	int meio=(l+r)>>1;
	if(meio>=i)
		update(L(id),l,meio,val,i);
	else
		update(R(id),meio+1,r,val,i);
	
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
	cin>>T;

	while(T--){
		timer++;
		cin>>N>>Q;
		for(int i=1;i<=N;i++)
			cin>>V[i];
		build(1,1,N);
		
		cout<<"Case "<<timer<<":"<<'\n';
		while(Q--){
			int A, B;
			ll C;
			cin>>A;
			if(A==1){
				cin>>B;
				C=query(1,1,N,B+1,B+1);
				cout<<C<<'\n';
				update(1,1,N,-C,B+1);
			}
			if(A==2){
				cin>>B>>C;
				update(1,1,N,C,B+1);
			}
			if(A==3){
				cin>>B>>C;
				cout<<query(1,1,N,B+1,C+1)<<'\n';
			}
		}
		for(int i=1;i<=4*N;i++){
			if(i<=N)
				V[i]=0;
			seg3[i]=0;
		}
	}

	return 0;
}