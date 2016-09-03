#pragma once
/*
定义Hard149中的额外的数据结构
*/
#ifndef _POINT_
#define _POINT_
struct Point {
	int x;
	int y;
	Point() :x(0), y(0) {}
	Point(int a, int b) :x(a), y(b) {}
};
#endif