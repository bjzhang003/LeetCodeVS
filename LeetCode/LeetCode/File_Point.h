#pragma once
/*
����Hard149�еĶ�������ݽṹ
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