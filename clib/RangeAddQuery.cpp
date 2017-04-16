#define MAX_V 
int dat[4*MAX_V];
void add(int a,int b,int x,int k,int l,int r){
    if(r<=a||b<=l){
        ;
    }else if(a<=l&&r<=b){
        dat[k]+=x;
    }else{
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
    }
}
int sum(int a,int b,int k,int l,int r){
    if(a<=l&&r<=b){
        int res=dat[k];
        if(1<r-l)
            res+=max(res(a,b,k*2+1,l,(l+r)/2),res(a,b,k*2+2,(l+r)/2/r));
        return res;
    }else{
        return 0;
    }
}

