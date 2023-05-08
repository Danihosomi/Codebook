struct tipo{
    int sum;
};

int n, v[1000000], len;
tipo sqr[10005]; //sqrt decomposition

void build(){
    len=(int)sqrt(n+.0)+1;
    for(int i=0;i<n;i++) sqr[i/len].sum+=v[i];
}

void update(int i,int val){
    sqr[i/len].sum+=val-v[i];
    v[i]=val;
}

int query(int l,int r){
    int ans=0, cl=l/len, cr=r/len;

    if(cl==cr)
        for(int i=l;i<=r;i++) ans+=v[i];
    
    else{
        for(int i=l, end=(cl+1)*len-1;i<=end;i++) ans+=v[i];
        for(int i=cl+1;i<=cr;i++) ans+=sqr[i].sum;
        for(int i=cr*len;i<=r;i++) ans+=v[i];
    }

    return ans;
}
