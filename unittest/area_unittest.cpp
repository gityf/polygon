/* 
** Copyright (C) 2015 Wang Yaofu
** All rights reserved.
**
**Author:Wang Yaofu voipman@qq.com
**Description: The source file of class AreaTest.
*/
#include <test_harness.h>
#include <iostream>
#include "area.h"

using std::cout;
using std::endl;

TEST(AreaTest, BasicAreaTriangle) {
    // | ---3--5---> x axis
    // |   /\
    // |  /  \
    // | /    \
    // 5 -------
    // v
    // y axis
    Polygon* areas = new Polygon();
    Point p;
    p.x = 3;
    p.y = 1;
    areas->push_back(p);
    p.x = 1;
    p.y = 5;
    areas->push_back(p);
    p.x = 5;
    p.y = 6;
    areas->push_back(p);
    Area area;
    area.set(1, areas);
    areas = area.get(1);
    EXPECT_EQ(true, areas != NULL);
    p.x = 1.1;
    p.y = 1;
    EXPECT_EQ(false, InPolygon(*areas, p));

    p.x = 1.1;
    p.y = 1.9;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 3.1;
    p.y = 2;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 4;
    p.y = 1;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 5.1;
    p.y = 5.5;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 5;
    p.y = 5.1;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 0.9;
    p.y = 5;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 1.1;
    p.y = 4.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 4.5;
    p.y = 4.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
}
TEST(AreaTest, BasicArea) {
    // --------
    // |      |
    // |      |
    // --------
    //
    Polygon* areas = new Polygon();
    Point p;
    p.x = 1;
    p.y = 1;
    areas->push_back(p);
    p.x = 2;
    p.y = 2;
    areas->push_back(p);
    p.x = 1;
    p.y = 2;
    areas->push_back(p);
    p.x = 2;
    p.y = 1;
    areas->push_back(p);
    Area area;
    area.set(1, areas);
    areas = area.get(1);
    EXPECT_EQ(true, areas != NULL);
    p.x = 1.1;
    p.y = 1;
    EXPECT_EQ(true, InPolygon(*areas, p));

    p.x = 1.1;
    p.y = 1.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 2;
    p.y = 2;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 2.1;
    p.y = 1;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 1;
    p.y = 2.5;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 2.1;
    p.y = 2.5;
    EXPECT_EQ(false, InPolygon(*areas, p));
}

TEST(AreaTest, BasicAreaLONG) {
    // 1-------100000--->x axis 
    // | --------
    // | |      |
    // 2 --------
    // v
    // y axis
    Polygon* areas = new Polygon();
    Point p;
    p.x = 1;
    p.y = 1;
    areas->push_back(p);
    p.x = 1;
    p.y = 2;
    areas->push_back(p);
    p.x = 100000;
    p.y = 2;
    areas->push_back(p);
    p.x = 100000;
    p.y = 1;
    areas->push_back(p);
    Area area;
    area.set(1, areas);
    areas = area.get(1);
    EXPECT_EQ(true, areas != NULL);
    p.x = 1.1;
    p.y = 1;
    EXPECT_EQ(true, InPolygon(*areas, p));

    p.x = 1.1;
    p.y = 1.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 2;
    p.y = 2;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 100001;
    p.y = 1;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 1;
    p.y = 2.5;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 99999;
    p.y = 2.5;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 99999;
    p.y = 1.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 55555;
    p.y = 1.5;
    EXPECT_EQ(true, InPolygon(*areas, p));
}

TEST(AreaTest, BasicAreaOfU) {
    // ---1----------10--------> x axis
    // |  ----    ----
    // |  |  |    |  |
    // |  |  ------  |
    // |  |          |
    // |  |          |
    // 10 ------------
    // |
    // v
    // y axis
    Polygon* areas = new Polygon();
    Point p;
    p.x = 1;
    p.y = 1;
    areas->push_back(p);
    p.x = 1;
    p.y = 10;
    areas->push_back(p);
    p.x = 10;
    p.y = 10;
    areas->push_back(p);
    p.x = 10;
    p.y = 1;
    areas->push_back(p);
    p.x = 8;
    p.y = 1;
    areas->push_back(p);
    p.x = 8;
    p.y = 5;
    areas->push_back(p);
    p.x = 3;
    p.y = 5;
    areas->push_back(p);
    p.x = 3;
    p.y = 1;
    areas->push_back(p);
    Area area;
    area.set(1, areas);
    areas = area.get(1);
    EXPECT_EQ(true, areas != NULL);
    p.x = 2;
    p.y = 2;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 9;
    p.y = 1.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 1.1;
    p.y = 9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 9.9;
    p.y = 9.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 4;
    p.y = 4;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 4.9;
    p.y = 4.9;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 3.1;
    p.y = 4.9;
    EXPECT_EQ(false, InPolygon(*areas, p));
}

TEST(AreaTest, BasicAreaOfN) {
    // ---1----------10--------> x axis
    // |     ------
    // |     |    |
    // |  |---    ---|
    // |  |          |
    // |  |          |
    // 10 ------------
    // |
    // v
    // y axis
    Polygon* areas = new Polygon();
    Point p;
    p.x = 1;
    p.y = 5;
    areas->push_back(p);
    p.x = 1;
    p.y = 10;
    areas->push_back(p);
    p.x = 10;
    p.y = 10;
    areas->push_back(p);
    p.x = 10;
    p.y = 5;
    areas->push_back(p);
    p.x = 8;
    p.y = 5;
    areas->push_back(p);
    p.x = 8;
    p.y = 1;
    areas->push_back(p);
    p.x = 3;
    p.y = 1;
    areas->push_back(p);
    p.x = 3;
    p.y = 5;
    areas->push_back(p);
    Area area;
    area.set(1, areas);
    areas = area.get(1);
    EXPECT_EQ(true, areas != NULL);
    p.x = 2;
    p.y = 2;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 9;
    p.y = 1.9;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 1.1;
    p.y = 9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 9.9;
    p.y = 9.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 4;
    p.y = 4;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 4.9;
    p.y = 4.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 3.1;
    p.y = 4.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 1.1;
    p.y = 5.1;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 8.1;
    p.y = 5.1;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 2.9;
    p.y = 4.9;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 8.1;
    p.y = 4.9;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 0.1;
    p.y = 4.9;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 10.1;
    p.y = 10.1;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 10;
    p.y = 4.9;
    EXPECT_EQ(false, InPolygon(*areas, p));
}


TEST(AreaTest, BasicAreaOflN) {
    // ---1--------8---10---15----> x axis
    // |  -----    ------
    // |  \   |    |      \
    // |   \  ------       \
    // |   /                |
    // |  /                 |
    // 10 -------------------
    // |
    // v
    // y axis

    Polygon* areas = new Polygon();
    Point p;
    p.x = 1;
    p.y = 1;
    areas->push_back(p);
    p.x = 3;
    p.y = 5;
    areas->push_back(p);
    p.x = 1;
    p.y = 10;
    areas->push_back(p);
    p.x = 15;
    p.y = 10;
    areas->push_back(p);
    p.x = 15;
    p.y = 5;
    areas->push_back(p);
    p.x = 10;
    p.y = 1;
    areas->push_back(p);
    p.x = 8;
    p.y = 1;
    areas->push_back(p);
    p.x = 8;
    p.y = 5;
    areas->push_back(p);
    p.x = 5;
    p.y = 5;
    areas->push_back(p);
    p.x = 5;
    p.y = 1;
    areas->push_back(p);
    Area area;
    area.set(1, areas);
    areas = area.get(1);
    EXPECT_EQ(true, areas != NULL);
    p.x = 2;
    p.y = 1.5;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 4.9;
    p.y = 4.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 5.1;
    p.y = 4.9;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 7.9;
    p.y = 4.9;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 8.1;
    p.y = 4.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 1.1;
    p.y = 12;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 9.9;
    p.y = 9.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 4;
    p.y = 4;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 4.9;
    p.y = 4.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 3.1;
    p.y = 4.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 1.1;
    p.y = 5.1;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 8.1;
    p.y = 5.1;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 2.9;
    p.y = 4.9;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 8.1;
    p.y = 4.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 0.1;
    p.y = 4.9;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 10.1;
    p.y = 10.1;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 10;
    p.y = 4.9;
    EXPECT_EQ(true, InPolygon(*areas, p));
    p.x = 14.9;
    p.y = 4.5;
    EXPECT_EQ(false, InPolygon(*areas, p));
    p.x = 14.9;
    p.y = 5.1;
    EXPECT_EQ(true, InPolygon(*areas, p));
}

TEST(AreaTest, point2SegDist) {
    Point A;
    Point B;
    Point C;
    A.x = 1;
    A.y = 1;
    B.x = 5;
    B.y = 1;
    C.x = 1;
    C.y = 3;
    EXPECT_EQ(2, point2SegDist(A,B,C));
    C.x = 5;
    C.y = 3;
    EXPECT_EQ(2, point2SegDist(A,B,C));
    C.x = 0;
    C.y = 3;
    EXPECT_LT(point2SegDist(A,B,C) - 2.23607, 0.000001);
    EXPECT_GT(point2SegDist(A,B,C) - 2.23607, -0.000001);
    C.x = 6;
    C.y = 3;
    EXPECT_LT(point2SegDist(A,B,C) - 2.23607, 0.000001);
    EXPECT_GT(point2SegDist(A,B,C) - 2.23607, -0.000001);
    C.x = 3;
    C.y = 3;
    EXPECT_EQ(2, point2SegDist(A,B,C));
    C.x = 3;
    C.y = -2;
    EXPECT_EQ(3, point2SegDist(A,B,C));
    C.x = 0;
    C.y = -1;
    EXPECT_LT(point2SegDist(A,B,C) - 2.23607, 0.000001);
    EXPECT_GT(point2SegDist(A,B,C) - 2.23607, -0.000001);
    C.x = 6;
    C.y = -1;
    EXPECT_LT(point2SegDist(A,B,C) - 2.23607, 0.000001);
    EXPECT_GT(point2SegDist(A,B,C) - 2.23607, -0.000001);
}