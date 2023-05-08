ll kadane(vector<ll>& v){
    ll ans=0, sum=0;

    for(auto x : v){
        sum=max(0LL,sum+x);
        ans=max(ans,sum);
    }

    return ans;
}

