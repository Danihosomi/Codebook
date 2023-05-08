#define lsb(x) ((x)&(-x))

int n, m;
ll fw[3003][3003];

ll getRes(int x,int y){
    ll ans=0;
    while(x){
        for(int i=y;i>0;i-=lsb(i)) ans+=fw[x][y];
        x-=lsb(x);
    }
    return ans;
}

ll query(int x,int y,int i,int j){
    return getRes(i,j)+getRes(x-1,y-1)-getRes(i,y-1)-getRes(x-1,j);
}

void update(int x,int y,ll val){
    while(x<=n){
        for(int i=y;i<=m;i+=lsb(i)) fw[x][i]+=val;
        x+=lsb(x);
    }
}
