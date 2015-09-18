/*
** Copyright (C) 2015 Wang Yaofu
** All rights reserved.
**
**Author:Wang Yaofu voipman@qq.com
**Description: The source file of class Area.
*/
#include "area.h"

Area::Area() {
    // for map_function test 围栏测试，初始化正方形
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
    set(100, areas);
}

Area::~Area() {
}

void Area::set(int id, Polygon* poly) {
    if (poly == NULL) {
        return;
    }
    areaMap_[id] = std::move(std::unique_ptr<Polygon>(poly));
}

Polygon* Area::get(int id) {
    if (areaMap_.find(id) != areaMap_.end()) {
        return areaMap_[id].get();
    }
    return NULL;
}