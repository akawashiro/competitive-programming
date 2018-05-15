const double EPS = 1e-5;
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

