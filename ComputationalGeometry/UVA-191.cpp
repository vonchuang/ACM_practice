#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define EPS 1e-9

using namespace std;

typedef struct Point{
    double x, y;
}point;

typedef struct Segment{
    point a, b;
}segment;

bool inBoxCheck(double x, double y, double ax, double ay, double bx, double by){
    if(min(ax, bx) <= x && x <= max(ax, bx) && min(ay, by) <= y && y <= max(ay, by))
        return true;
    else
        return false;
}

bool intersectionCheck(segment u, segment v){
    double c0 = (v.b.y-v.a.y)*(u.a.x-v.a.x)-(v.b.x-v.a.x)*(u.a.y-v.a.y);
    double c1 = (u.b.x-u.a.x)*(v.a.y-u.a.y)-(u.b.y-u.a.y)*(v.a.x-u.a.x);
    double det = (u.b.y-u.a.y)*(v.b.x-v.a.x)-(v.b.y-v.a.y)*(u.b.x-u.a.x);
    if (fabs(det) < EPS){
        if (fabs(c0) < EPS || fabs(c1) < EPS){
            if(inBoxCheck(u.a.x, u.a.y, v.a.x, v.a.y, v.b.x, v.b.y) || inBoxCheck(u.b.x, u.b.y, v.a.x, v.a.y, v.b.x, v.b.y) ||
               inBoxCheck(v.a.x, v.a.y, u.a.x, u.a.y, u.b.x, u.b.y) || inBoxCheck(v.b.x, v.b.y, u.a.x, u.a.y, u.b.x, u.b.y))
                return true;
            else
                return false;
        }else{
            return false;
        }
    }else{
        c0 /= det;
        c1 /= det;
        
        if (0 <= c0 && c0 <= 1 && 0 <= c1 && c1 <= 1)
            return true;
        else
            return false;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    while (n--){
        double xs, ys, xe, ye, xl, yt, xr, yb;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &xs, &ys, &xe, &ye, &xl, &yt, &xr, &yb);
        bool flag = inBoxCheck(xs, ys, xl, yt, xr, yb) || inBoxCheck(xe, ye, xl, yt, xr, yb);
        
        if(flag == true){
            printf("T\n");
            continue;
        }
        // points
        point a, b, c, d, e, f;
        a.x = xl;   a.y = yt;
        b.x = xl;   b.y = yb;
        c.x = xr;   c.y = yt;
        d.x = xr;   d.y = yb;
        e.x = xs;   e.y = ys;
        f.x = xe;   f.y = ye;
        
        // lines
        segment line, reac1, reac2, reac3, reac4;
        line.a = e; line.b = f;
        reac1.a = a;    reac1.b = b;
        reac2.a = a;    reac2.b = c;
        reac3.a = b;    reac3.b = d;
        reac4.a = c;    reac4.b = d;
        
        flag = intersectionCheck(line, reac1) || intersectionCheck(line, reac2) ||
                    intersectionCheck(line, reac3) || intersectionCheck(line, reac4);
        
        if(flag == true)
            printf("T\n");
        else
            printf("F\n");
    }
    return 0;
}
