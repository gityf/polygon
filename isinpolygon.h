/*
** Copyright (C) 2015 Wang Yaofu
** All rights reserved.
**
**Author:Wang Yaofu voipman@qq.com
**Description: The header file of Polygon.
*/
#pragma once
#include <cmath>
#include <vector>
#include <algorithm>
using std::vector;
using std::max;
using std::min;

//const double INFINITY = 1e10;
static const double ESP = 1e-5;

struct Point {
    double x, y;
};

struct LineSegment {
    Point pt1, pt2;
};

typedef vector<Point> Polygon;


// cross product  |P0P1| ¡Á |P0P2|
static double Multiply(const Point& p1, const Point& p2, const Point& p0) {
    return ((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));
}

// to check whether the point is in line  or not.
static bool IsOnline(const Point& point, const LineSegment& line) {
    return((fabs(Multiply(line.pt1, line.pt2, point)) < ESP) &&
        ((point.x - line.pt1.x) * (point.x - line.pt2.x) <= 0) &&
        ((point.y - line.pt1.y) * (point.y - line.pt2.y) <= 0));
}

// to check whether two lines has same point or not.
static bool Intersect(const LineSegment& L1, const LineSegment& L2) {
    return((max(L1.pt1.x, L1.pt2.x) >= min(L2.pt1.x, L2.pt2.x)) &&
        (max(L2.pt1.x, L2.pt2.x) >= min(L1.pt1.x, L1.pt2.x)) &&
        (max(L1.pt1.y, L1.pt2.y) >= min(L2.pt1.y, L2.pt2.y)) &&
        (max(L2.pt1.y, L2.pt2.y) >= min(L1.pt1.y, L1.pt2.y)) &&
        (Multiply(L2.pt1, L1.pt2, L1.pt1) * Multiply(L1.pt2, L2.pt2, L1.pt1) >= 0) &&
        (Multiply(L1.pt1, L2.pt2, L2.pt1) * Multiply(L2.pt2, L1.pt2, L2.pt1) >= 0)
        );
}


// to check whether the point is in poly or not.
static bool InPolygon(const Polygon& polygon, const Point& point) {
    int n = polygon.size();
    if (n == 1) {
        return ((fabs(polygon[0].x - point.x) < ESP) && (fabs(polygon[0].y - point.y) < ESP));
    }
    else if (n == 2) {
        LineSegment side;
        side.pt1 = polygon[0];
        side.pt2 = polygon[1];
        return IsOnline(point, side);
    }

    int count = 0;
    LineSegment line;
    line.pt1 = point;
    line.pt2.y = point.y;
    line.pt2.x = -INFINITY;

    for (int i = 0; i < n; i++) {
        // to get edge of the poly.
        LineSegment side;
        side.pt1 = polygon[i];
        side.pt2 = polygon[(i + 1) % n];

        if (IsOnline(point, side)) {
            return true;
        }

        // ignore the line parallel as x axis.
        if (fabs(side.pt1.y - side.pt2.y) < ESP) {
            continue;
        }

        if (IsOnline(side.pt1, line)) {
            if (side.pt1.y > side.pt2.y) count++;
        }
        else if (IsOnline(side.pt2, line)) {
            if (side.pt2.y > side.pt1.y) count++;
        }
        else if (Intersect(line, side)) {
            count++;
        }
    }

    return (count % 2 == 1);
}
