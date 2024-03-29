// Knuth Optimization: O(N^3) => O(N^2)
int n;
ll C[5005][5005], opt[5005][5005], dp[5005][5005], v[5005];

ll solve(){
    // Have to implement C(i,j) = Cost Function
    // Atention if you want max or min
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++){
            C[j-1][i] = v[i]-v[j];
            if(i==j){
                opt[i][i] = i;
                C[i][j] = 0;
            }
            else C[i][j] = linf;
        }
    
    for(int tam = 2;tam<=n;tam++){
        for(int i=1,j=tam;j<=n;i++,j++){
            dp[i][j]=C[i][j]+dp[i][opt[i][j-1]]+dp[opt[i][j-1]+1][j];
            opt[i][j]=opt[i][j-1];
            for(int k=opt[i][j-1];k<=opt[i+1][j];k++) 
                if(dp[i][j]>C[i][j]+dp[i][k]+dp[k+1][j]) opt[i][j]=k, dp[i][j]=C[i][j]+dp[i][k]+dp[k+1][j]; // Here you can change max or min
        }
    }

    return dp[1][n];
}
