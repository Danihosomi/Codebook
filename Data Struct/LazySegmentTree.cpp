#define R(x) ((x<<1)+1)
#define L(x) (x<<1)

struct node{
    ll sum, lazy;
};

int n, v[200005];
node seg3[4*200005];

ll join(ll a,ll b){
    return a+b;
}

void build(int id,int l,int r){
    if(l==r){
        seg3[id].sum=v[l];
        seg3[id].lazy=0;
        return ;
    }
    int meio=(l+r)>>1;
    build(L(id),l,meio);
    build(R(id),meio+1,r);
    seg3[id].sum=join(seg3[L(id)].sum,seg3[R(id)].sum);
}

void refresh(int id,int l,int r){
    if(!seg3[id].lazy) return;

    ll num=seg3[id].lazy; seg3[id].lazy=0;
    seg3[id].sum=(r-l+1)*num;
    
    if(l==r) return ;
    seg3[L(id)].lazy+=num;
    seg3[R(id)].lazy+=num;
}

void update(int id,int l,int r,int i,int j,int val){
    refresh(id,l,r);
    if(j<l || r<i) return;
    if(i<=l && r<=j){
        seg3[id].lazy=val;
        refresh(id,l,r);
        return ;
    }
    
    int meio=(l+r)>>1;
    update(L(id),l,meio,i,j,val);
    update(R(id),meio+1,r,i,j,val);
    seg3[id].sum=join(seg3[L(id)].sum,seg3[R(id)].sum);    
}

ll query(int id,int l,int r,int i,int j){
    refresh(id,l,r);
    if(r<i || j<l) return 0;
    if(i<=l && r<=j) return seg3[id].sum;
    int meio=(l+r)>>1;
    return join(query(L(id),l,meio,i,j),query(R(id),meio+1,r,i,j));
}
