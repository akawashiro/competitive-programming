#define MAX_V
int dat[4*MAX_V];
void add(int a,int b,ll x,int k,int l,int r){
    if(b<=l||r<=a)
        ;
    else{
        if(l<=a&&b<=r)
            dat[k]+=x;
        if(1<r-l){
            add(a,b,x,k*2+1,l,(l+r)/2);
            add(a,b,x,k*2+2,(l+r)/2,r);
        }
    }
}
ll sum(int a,int b,int k,int l,int r){
    if(a<=l&&r<=b){
        return dat[k];
    }else if(b<=l||r<=a){
        return 0;
    }else{
        return sum(a,b,k*2+1,l,(l+r)/2)+sum(a,b,k*2+2,(l+r)/2,r);
    }
}

