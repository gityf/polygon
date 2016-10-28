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
#define EARTH_RADIUS (6378137)
#define RAD          (3.14159265/180.0)

static double distance(double lat1, double lng1, double lat2, double lng2) {
    double radLat1 = lat1 * RAD;
    double radLat2 = lat2 * RAD;
    double a = radLat1 - radLat2;
    double b = (lng1 - lng2) * RAD;

    double s = 2
        * asin(
        sqrt(
        pow(sin(a / 2), 2)
        + cos(radLat1) * cos(radLat2)
        * pow(sin(b / 2), 2)));
    return s * EARTH_RADIUS;
}

static bool radius(const Point& src, const Point& dst, int len) {
    return distance(src.x, src.y, dst.x, dst.y) >= len;
}

//to get length of the point to line.
static double point2SegDist(const Point& src, const Point& dst, const Point& point) {
    double link = (dst.x - src.x) * (point.x - src.x) + (dst.y - src.y) * (point.y - src.y);
    if (link <= 0) {
        return sqrt((point.x - src.x) * (point.x - src.x) + (point.y - src.y) * (point.y - src.y));
    }
    double d2 = (dst.x - src.x) * (dst.x - src.x) + (dst.y - src.y) * (dst.y - src.y);
    if (link >= d2) {
        return sqrt((point.x - dst.x) * (point.x - dst.x) + (point.y - dst.y) * (point.y - dst.y));
    }
    double r = link / d2;
    double px = src.x + (dst.x - src.x) * r;
    double py = src.y + (dst.y - src.y) * r;
    return sqrt((point.x - px) * (point.x - px) + (point.y - py) * (point.y - py));
}

//to get min length of the point to polygon
static double minLen2Polygon(const Polygon& polygon, const Point& point) {
    int n = polygon.size();
    if (n == 1) {
        return distance(polygon[0].x, polygon[0].y, point.x, point.y);
    }
    int offset = 0;
    double minLen = point2SegDist(polygon[n-1], polygon[0], point);
    double theLen = 0.0;
    for(;offset < n-1;) {
        theLen = point2SegDist(polygon[offset], polygon[offset+1], point);
        if (theLen < minLen) {
            minLen = theLen;
        }
        offset++;
    }
    return minLen;
}

//to get max length of the point to polygon
static double maxLen2Polygon(const Polygon& polygon, const Point& point) {
    int n = polygon.size();
    if (n == 1) {
        return distance(polygon[0].x, polygon[0].y, point.x, point.y);
    }
    int offset = 0;
    double maxLen = point2SegDist(polygon[n-1], polygon[0], point);
    double theLen = 0.0;
    for(;offset < n-1;) {
        theLen = point2SegDist(polygon[offset], polygon[offset+1], point);
        if (theLen > maxLen) {
            maxLen = theLen;
        }
        offset++;
    }
    return maxLen;
}

//to get mean length of the point to polygon
static double meanLen2Polygon(const Polygon& polygon, const Point& point) {
    int n = polygon.size();
    if (n == 1) {
        return distance(polygon[0].x, polygon[0].y, point.x, point.y);
    }
    int offset = 0;
    double theLen = point2SegDist(polygon[n-1], polygon[0], point);
    for(;offset < n-1;) {
        theLen += point2SegDist(polygon[offset], polygon[offset+1], point);
        offset++;
    }
    return theLen/n;
}