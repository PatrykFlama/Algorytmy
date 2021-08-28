#include <bits/stdc++.h>
using namespace std;


template <typename T>
struct Point {
    T x, y;

    Point() : Point(0, 0) {}

    Point(T _x, T _y) : x(_x), y(_y) {}

    friend ostream &operator<<(ostream &os, const Point<T> &point) {
        os << point.x << " " << point.y;
        return os;
    }

    friend istream &operator>>(istream &is, Point<T> &point) {
        is >> point.x >> point.y;
        return is;
    }

    Point<T> operator+(const Point<T> &p2) const { return {x + p2.x, y + p2.y}; }

    Point<T> &operator+=(const Point<T> &p2) {
        x += p2.x, y += p2.y;
        return *this;
    }

    Point<T> operator-(const Point<T> &p2) const { return {x - p2.x, y - p2.y}; }

    void fun() {
        x = 10;
    }

    T dot(const Point<T> &p2) const { // iloczyn skalarny
        return x * p2.x + y * p2.y;
    }

    T cross(const Point<T> &p2) const { // iloczyn wektorowy
        return x * p2.y - y * p2.x;
    }
};

template <typename T>
T triangle_area(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3) {
    return 0.5 * abs((p2 - p1).cross(p3 - p1));
}

int main() {
    Point<long double> p1{0, 0};
    Point<long double> p2{10, 0};
    Point<long double> p3(5, 5 * sqrtl(3));
    Point<long double> p4(5, 5 * sqrtl(3));

    p1 = p2 = p3 = p4;

    cout << fixed << setprecision(30);      // precision of float/double output

    cout << 25 * sqrtl(3) << "\n";

    Point<long double> offset(100, 100);
    p1 = p1 + offset;
    p2 = p2 + offset;
    p3 = p3 + offset;

    cout << triangle_area(p1, p2, p3) << "\n";
}
