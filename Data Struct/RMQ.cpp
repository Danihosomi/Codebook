namespace RMQ{
    const int MAXL = 16;
    int st[MAXL][500005], lg[500005], n;

    void build(const vi v){
        n=sz(v);
        for(int i=0;i<n;i++) st[0][i]=v[i];        

        for(int j=1;j<MAXL;j++)
            for(int i=0;i+(1<<j)<=n;i++)
                st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
    
        lg[1]=0;
        for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
    }

    int query(int l,int r){
        return min(st[lg[r-l]][l],st[lg[r-l]][r-(1<<lg[r-l])+1]);
    }
};
