const int MAX_N = 1 << 18;

class RangeUpdateRangeSum{
    public:
        int sz;
        LL node[MAX_N], lazy[MAX_N];

        RangeUpdateRangeSum(int n) {
            sz = 1;
            while (n > sz )sz *= 2;
            for (int i = 0; i < 2 * sz - 1; i++)lazy[i] = -1;
        }

        void lazy_evaluate_node(int k, int l, int r) {
            if (lazy[k] != -1) { 
                node[k] = lazy[k] * (r - l); 
                if (r - l > 1) {
                    lazy[k * 2 + 1] = lazy[k]; 
                    lazy[k * 2 + 2] = lazy[k]; 
                }
                lazy[k] = -1;
            }
        }

        void update(int a, int b, LL v){    update(a,b,v,0,0,sz);   }
        void update(int a, int b, LL v, int k, int l, int r) {
            lazy_evaluate_node(k, l, r); 
            if (r <= a || b <= l)return; 
            if (a <= l && r <= b) {
                lazy[k] = v;
                lazy_evaluate_node(k, l, r);
            }
            else {
                update(a, b, v, k * 2 + 1, l, (l + r) / 2);
                update(a, b, v, k * 2 + 2, (l + r) / 2, r);
                node[k] = node[k * 2 + 1] + node[k * 2 + 2];
            }
        }

        LL sum(int a, int b){   return sum(a,b,0,0,sz); }
        LL sum(int a, int b, int k, int l, int r) {
            lazy_evaluate_node(k, l, r);
            if (r <= a || b <= l)return 0;
            if (a <= l && r <= b)return node[k];
            LL x = sum(a, b, k * 2 + 1, l, (l + r) / 2); 
            LL y = sum(a, b, k * 2 + 2, (l + r) / 2, r);
            return x + y;
        }
};


