#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define ld long double


int main() {
    pair<ld, ld> p1, p2, p3;

    p1 = {1, 1}, p2 = {1, 2}, p3 = {2, 1};          // triangle points

    pair<ld, ld> v1 = {p2.x-p1.x, p2.y-p1.y}, v2 = {p3.x-p1.x, p3.y-p1.y};  // arm/vector lenghts

    cout << 0.5f * abs(v1.x*v2.y + v1.y*v2.x) << '\n';      // cross product
}
