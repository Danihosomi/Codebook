struct segmentTree{
    const static int MAXN = (int)2e5;
    struct node{
        ll val, lazy;
    };
    
    static int n;
    int v[MAXN];
    node seg3[4*MAXN], nulo;

    void init(int  n1,int *v1){
        n = n1; 
        for(int i=0;i<=n;i++) v[i]=v1[i];
        build();
    }

    node join(node a,node b){
        node resp;
        // implement here
        return resp;
    }

    void build(int id=1,int l=1,int r=n){
        if(l==r){
            seg3[id].val = v[l]; seg3[id].lazy=0;
            return ;
        }
        int m = (l+r)>>1;
        build(L(id),l,m); build(R(id),m+1,r);
        seg3[id] = join(seg3[L(id)],seg3[R(id)]);
    }

    void refresh(int id,int l,int r){
        if(!seg3[id].lazy) return;

        ll num=seg3[id].lazy; seg3[id].lazy=0;
        // Implement Here
        // seg3[id].sum=(r-l+1)*num;
        
        if(l==r) return ; // Need to define if it is a sum or set
        seg3[L(id)].lazy+=num;
        seg3[R(id)].lazy+=num;
    }

    void update(int i,int j,int val,int id=1,int l=1,int r=n){
        refresh(id,l,r);
        if(j<l || r<i) return;
        if(i<=l && r<=j){ // need to define if it is a sum or a set
            seg3[id].lazy=val;
            refresh(id,l,r);
            return ;
        }
        int m=(l+r)>>1;
        update(i,j,val,L(id),l,m); update(i,j,val,R(id),m+1,r);
        seg3[id]=join(seg3[L(id)],seg3[R(id)]);    
    }

    node query(int id,int l,int r,int i,int j){
        refresh(id,l,r);
        if(r<i || j<l) return nulo;
        if(i<=l && r<=j) return seg3[id];
        int meio=(l+r)>>1;
        return join(query(L(id),l,meio,i,j),query(R(id),meio+1,r,i,j));
    }
};
