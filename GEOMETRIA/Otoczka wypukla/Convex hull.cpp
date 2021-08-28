#include <bits/stdc++.h>

using namespace std;

using point = pair<int, int>;
#define x first
#define y second

using ll = long long;


bool ccw(point a, point b, point c) {           // determines if is this turn counter clockwise
    return (1LL * (b.y - a.y) * (c.x - b.x) - 1LL * (c.y - b.y) * (b.x - a.x) ) >= 0;
}

vector<point> make_hull(vector<point> points) {
    if (points.size() <= 1) {
        return points;
    }

    sort(points.begin(), points.end());

    vector<point> hull;


    for (int i = 0; i < 2; i++) {
        int prev_size = hull.size();
        for (point pkt : points) {
            while (hull.size() >= 2 + prev_size and ccw(hull[hull.size() - 2], hull[hull.size() - 1], pkt)) {
                hull.pop_back();
            }
            hull.push_back(pkt);
        }

        hull.pop_back();
        reverse(points.begin(), points.end());
    }

    if (hull.size() == 2 and hull[0] == hull[1]) {
        hull.pop_back();
    }

    return hull;
}


int main() {
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        vector<point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }

        auto hull = make_hull(points);
        cout << hull.size() << "\n";
        for (auto[x, y] : hull) {
            cout << x << " " << y << "\n";
        }
    }
}
