/*
** Copyright (C) 2015 Wang Yaofu
** All rights reserved.
**
**Author:Wang Yaofu voipman@qq.com
**Description: The header file of class Area.
*/
#pragma once
#include <unordered_map>
#include <memory>
#include "isinpolygon.h"

// Area item
class Area {
public:
    Area();
    ~Area();
    // set polygon.
    void set(int id, Polygon* poly);
    // get polygon by id.
    Polygon* get(int id);
private:
    // area id AND poly pairs.
    std::unordered_map<int, std::unique_ptr<Polygon> > areaMap_;
};