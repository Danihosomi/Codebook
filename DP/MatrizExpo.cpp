struct matrix{
    ll m[tam][tam];
    matrix(){
        for (int i=0;i<tam;i++)
            for (int j=0;j<tam;j++)
                m[i][j]=(i==j ? 1 : 0);
    }
    matrix(int x){
        for (int i=0;i<x;i++)
            for (int j=0;j<x;j++)
                    m[i][j]=0;
    }
};

matrix mult(matrix a,matrix b){
    matrix ans(tam);
    for (int i=0;i<tam;i++)
        for (int j=0;j<tam;j++)
            for (int k=0;k<tam;k++) 
                ans.m[i][j]=(ans.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
    return ans;
}
 
matrix fexpo(matrix b,ll e){
    matrix ans;
        
    while(e){
        if(e&1) ans=mult(ans,b);
        b=mult(b,b); e>>=1;
    }
 
    return ans;
}
