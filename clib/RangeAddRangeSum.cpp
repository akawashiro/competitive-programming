class RangeAddRangeSum {
    public:
        int N;
        vector<int> dat, sum_dat;
        RangeAddRangeSum(int n) {
            N = 1;
            while(N < n) N <<= 1;
            dat.assign(2*N-1, 0);
            sum_dat.assign(2*N-1, 0);
        }

        void add(int a, int b, int x) { add(a,b,x,0,0,N); }
        int add(int a, int b, int x, int k, int l, int r) {
            if(b <= l or r <= a) return dat[k];
            if(a <= l and r <= b) {
                sum_dat[k] += x;
                return dat[k] += x*(r-l);
            }
            const int m = (l+r)/2;
            return dat[k] = add(a,b,x,2*k+1,l,m)+add(a,b,x,2*k+2,m,r)+sum_dat[k]*(min(r,b)-max(l,a));
        }

        int sum(int a, int b) { return sum(a,b,0,0,N); }
        int sum(int a, int b, int k, int l, int r) {
            if(b <= l or r <= a) return 0;
            if(a <= l and r <= b) return dat[k];
            const int m = (l+r)/2;
            return sum(a,b,2*k+1,l,m)+sum(a,b,2*k+2,m,r)+sum_dat[k]*(min(r,b)-max(l,a));
        }
};

