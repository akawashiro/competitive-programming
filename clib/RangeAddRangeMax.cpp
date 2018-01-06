class RangeAddRangeMax {
    public:
        int N;
        vector<LL> dat, sum_dat;
        RangeAddRangeMax(int n) {
            N = 1;
            while(N < n) N <<= 1;
            dat.assign(2*N-1, 0);
            sum_dat.assign(2*N-1, 0);
        }

        void add(int a, int b, LL x) { add(a,b,x,0,0,N); }
        LL add(int a, int b, LL x, int k, int l, int r) {
            if(b <= l or r <= a) return dat[k];
            if(a <= l and r <= b) {
                sum_dat[k] += x;
                return dat[k] += x;
            }
            const int m = (l+r)/2;
            return dat[k] = max(add(a,b,x,2*k+1,l,m),add(a,b,x,2*k+2,m,r))+sum_dat[k];
        }

        LL rangeMax(int a, int b) { return rangeMax(a,b,0,0,N); }
        LL rangeMax(int a, int b, int k, int l, int r) {
            if(b <= l or r <= a) return 0;
            if(a <= l and r <= b) return dat[k];
            const int m = (l+r)/2;
            return max(rangeMax(a,b,2*k+1,l,m),rangeMax(a,b,2*k+2,m,r))+sum_dat[k];
        }
};

