#define lsb(x) ((x)&(-x))
namespace FW{
    int fw[200005], n;

    void update(int x,int val){
        while(x<=n){
            fw[x]+=val;
            x+=lsb(x);
        }
    }

    int query(int x){
        int ans=0;
        while(x){
            ans+=fw[x];
            x-=lsb(x);
        }
        return ans;
    }
};
