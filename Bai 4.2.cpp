// Một điểm trong không gian 2 chiều được biểu diễn bằng pair. Hãy viết hàm tính diện tích tam giác theo tọa độ 3 đỉnh.

#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double distance(Point a, Point b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

double area(Point a, Point b, Point c) {

    double ab = distance(a,b);
    double bc = distance(b,c);
    double ca = distance(c,a);

    double p = (ab + bc + ca) /2;
    return sqrt(p * (p-ab) * (p-bc) * (p-ca));

}

