#include <algorithm>
#include <cmath>
#include <cstdio>

#define EPS 1e-7
#define INF 9999999999
#define MAX 10000

using namespace std;

int n;
struct Point {
    double x, y;
} p[MAX];

double cross(Point p1, Point p2, Point p3){
    return (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
}

double dist(Point a, Point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool cmp(Point p1, Point p2) {
    double t = cross(p[0], p1, p2);
    if (fabs(t) >= EPS)
        return t > 0;
    else
        return (dist(p[0], p1) < dist(p[0], p2));
}

void GrahamScan() {
    int m = n - 1, i;
    
    if (n <= 2) return;
    
    sort(p + 1, p + n, cmp);
    while (m > 0 && fabs(cross(p[0], p[m], p[m - 1])) < EPS)
        m--;
    if (m) reverse(p + m, p + n);
    
    m = 2;
    for (i = 2; i < n; ++i) {
        while (m >= 2 && cross(p[m - 2], p[m - 1], p[i]) <= 0)
            m--;
        p[m++] = p[i];
    }
    n = m;
}

int main() {
    int cnt = 1;
    
    while (scanf("%d", &n) && n) {
        int u = 0, i;
        double len = 0;
        
        for (i = 0; i < n; i++){
            scanf("%lf %lf", &p[i].x, &p[i].y);
            if (p[i].y < p[u].y || (p[i].y == p[u].y && p[i].x > p[u].x))
                u = i;
        }
        
        swap(p[u], p[0]);
        GrahamScan();
        
        // print result
        if (cnt != 1) printf("\n");
        
        printf("Region #%d:\n", cnt++);
        
        printf("(%.1lf,%.1lf)", p[0].x, p[0].y);
        for (i = n - 1; i >= 0; i--) {
            printf("-(%.1lf,%.1lf)", p[i].x, p[i].y);
            len += sqrt(dist(p[i], p[(i + 1) % n]));
        }
        
        printf("\nPerimeter length = %.2lf\n", len);
    }
}
