#define R(x) ((x<<1)+1)
#define L(x) (x<<1)

int n, v[100005];
ll seg3[4*100005];

ll join(ll a, ll b){
	return a+b;
}

void build(int id,int l,int r){
	if(l==r){
		seg3[id]=v[l];
		return;
	}
	int meio=(l+r)>>1;
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
	if(meio>=i) update(L(id),l,meio,i,val);
	else update(R(id),meio+1,r,i,val);
	
	seg3[id]=join(seg3[L(id)],seg3[R(id)]);
}

ll query(int id,int l,int r,int i,int j){
	if(i<=l && r<=j) return seg3[id];
	if(r<i || j<l) return 0;
	int meio=(l+r)>>1;
	return join(query(L(id),l,meio,i,j),query(R(id),meio+1,r,i,j));
}
