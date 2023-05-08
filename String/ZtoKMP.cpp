int n;

vi ZtoKMP(vi z){
    vi kmp(sz(z)+1);
    for(int i=0;i<n;i++) kmp[i+z[i]]=max(kmp[i+z[i]],z[i]);
    for(int i=n-1;i>=0;i--) kmp[i]=max(kmp[i+1]-1,kmp[i]);
    kmp.erase(kmp.begin());
    return kmp;
}

vi KMPtoZ(vi kmp){
    vi z(sz(kmp));

    for(int i=1;i<n;i++)
    if(kmp[i]) z[i-kmp[i]+1] = kmp[i];
 
    if(z[1])
        for(int i=1;i<z[1];i++)
            z[i+1] = z[1]-i;
    
    for(int i = z[1]+1;i<n-1;i++){
        int t = i;
            
        if(z[i] && !z[i+1]){
            for(int j=1;j<z[i] && z[i+j]<=z[j];j++)
                z[i+j] = min(z[j],z[i]-j), t=i+j;
        }
 
        i = t;
    }

    return z;
}
