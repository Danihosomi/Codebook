int maxSuffix(string c,int mi=0){
    int ans=0; c.pb(*min_element(all(c))-1);
 
    for(int i=1;i<sz(c);i++){
        int j=0;
        while(ans+j<i && c[j+ans]==c[i+j]) j++;
        if(c[i+j]>c[ans+j]){
            if(!mi || i!=sz(c)-2) ans=i;
        }
        else if(j) i+=j-1;
    }
 
    return ans;
}

int minSuffix(string c){
    for(auto &i : c) i*=-1;
    c.pb(*max_element(all(c))+1);
    return maxSuffix(c,1);
}

int maxCyclicShift(string c){
    int tam=sz(c);
    for(int i=0;i<tam;i++) c.pb(c[i]);
    return maxSuffix(c);
}

int minCyclicShift(string c){
    for(auto &i : c) i*=-1;
    return maxCyclicShift(c);
}
