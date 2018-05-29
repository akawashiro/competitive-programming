// S means segment, L means infinite length line
// P means a point, C means a circle.
const double EPS = 1e-10;
const double INF = 1e12;
typedef complex<double> Point;
namespace std {
      bool operator < (const Point& a, const Point& b) {
              return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
                }
}
double cross(const Point& a, const Point& b) {
      return imag(conj(a)*b);
}
double dot(const Point& a, const Point& b) {
      return real(conj(a)*b);
}
double dist(const Point &a, const Point &b){
    Point d = a - b;
    return sqrt(imag(d)*imag(d) + real(d)*real(d));
}
Point left_rotate(const Point &a){
    Point r(-imag(a), real(a));
    return r;
}

struct Line : public vector<Point> {
    Line(const Point &a, const Point &b) {
        push_back(a); push_back(b);
    }
};
class Circle{
    public:
        Point c;
        double r;
        Circle(const Point &cc, const double rr){
            c = cc;
            r = rr;
        }
};

int ccw(Point a, Point b, Point c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // counter clockwise
    if (cross(b, c) < 0)   return -1;       // clockwise
    if (dot(b, c) < 0)     return +2;       // c--a--b on line
    if (norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0;
}

bool intersectLL(const Line &l, const Line &m) {
    return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || // non-parallel
        abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;   // same line
}
bool intersectLS(const Line &l, const Line &s) {
    return cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l
        cross(l[1]-l[0], s[1]-l[0]) < EPS; // s[1] is right of l
}
bool intersectLP(const Line &l, const Point &p) {
    return abs(cross(l[1]-p, l[0]-p)) < EPS;
}
bool intersectSS(const Line &s, const Line &t) {
    return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
        ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool intersectSP(const Line &s, const Point &p) {
    return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

Point projection(const Line &l, const Point &p) {
    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
    return l[0] + t*(l[0]-l[1]);
}
Point reflection(const Line &l, const Point &p) {
    return p + 2.0 * (projection(l, p) - p);
}
double distanceLP(const Line &l, const Point &p) {
    return abs(p - projection(l, p));
}
double distanceLL(const Line &l, const Line &m) {
    return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}
double distanceLS(const Line &l, const Line &s) {
    if (intersectLS(l, s)) return 0;
    return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}
double distanceSP(const Line &s, const Point &p) {
    const Point r = projection(s, p);
    if (intersectSP(s, r)) return abs(r - p);
    return min(abs(s[0] - p), abs(s[1] - p));
}
double distanceSS(const Line &s, const Line &t) {
    if (intersectSS(s, t)) return 0;
    return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
            min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
Point crosspoint(const Line &l, const Line &m) {
    double A = cross(l[1] - l[0], m[1] - m[0]);
    double B = cross(l[1] - l[0], l[1] - m[0]);
    if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
    if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
    return m[0] + B / A * (m[1] - m[0]);
}
vector<Point> convex_hull(vector<Point> ps) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end());
    vector<Point> ch(2*n);
    for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
        while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
        while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    ch.resize(k-1);
    return ch;
}
enum { OUT, ON, IN };
int contains(const vector<Point>& polygon, const Point& p) {
    bool in = false;
    for (int i = 0; i < (int)polygon.size(); ++i) {
        Point a = polygon[i] - p, b = polygon[(i+1)%polygon.size()] - p;
        if (imag(a) > imag(b)) swap(a, b);
        if (imag(a) <= 0 && 0 < imag(b))
            if (cross(a, b) < 0) in = !in;
        if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
    }
    return in ? IN : OUT;
}
bool crossCircle(const Circle& c1, const Circle& c2){
    double r1 = c1.r;
    double r2 = c2.r;
    double d = abs(c1.c-c2.c);
    if(d<r1||d<r2)
        return d-abs(r1-r2)>EPS;
    return r1+r2-d>-EPS;
}
bool containPoint(const Circle& c, const Point& p){
    double dist = abs(c.c-p);
    return dist < c.r+EPS;
}
vector<Point> crosspointCC(const Circle& c1, const Circle& c2){
    vector<Point> res;
    if(!crossCircle(c1,c2))
        return res;
    double r1 = c1.r;
    double r2 = c2.r;
    double r3 = abs(c1.c-c2.c);
    double rc = (r3*r3+r1*r1-r2*r2)/(2*r3);
    double rs = sqrt(r1*r1-rc*rc);
    Point dif = (c2.c-c1.c)/r3;
    res.push_back(c1.c+dif*Point(rc, rs));
    res.push_back(c1.c+dif*Point(rc,-rs));
    return res;
}
double arg3P(const Point& a,const Point &b,const Point &c){
    Point ab = b - a;
    Point bc = c - b;
    double ic=real(ab)*real(bc)+imag(ab)*imag(bc);
    double aa=abs(ab)*abs(bc);
    int d = ccw(a,b,c);
    if(-1==d){
        return M_PI + acos(ic/aa);
    }else if(1==d){
        return M_PI - acos(ic/aa);
    }else if(2==d){
        return 0;
    }else if(-2==d){
        return M_PI;
    }else if(0==d){
        return M_PI;
    }else{
        assert(false);
    }
}
// input for onSameLine function must be longer than 3
vector<Point> onSameLine(const vector<Point> &ps){
    int N = ps.size();
    vector<Point> ret;
    for(int i=0;i<N-2;i++){
        int c = ccw(ps[i],ps[i+1],ps[i+2]);
        if(c==1 || c==-1)
            return ret;
    }
    double dist = -1;
    int idist1=-1,idist2=-1;
    for(int i=1;i<N;i++)
        if(abs(ps[0]-ps[i]) > dist){
            dist = abs(ps[0]-ps[i]);
            idist1 = i;
        }
    for(int i=0;i<N;i++)
        if(i!=idist1 && abs(ps[idist1]-ps[i]) > dist){
            dist = abs(ps[idist1]-ps[i]);
            idist2 = i;
        }
    ret.push_back(ps[idist1]);
    ret.push_back(ps[idist2]);
    return ret;
}


