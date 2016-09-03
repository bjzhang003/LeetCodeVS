#pragma once
/*
定义Hard_056中使用的结构体
*/
#include<iostream>
using namespace std;
#ifndef _INTERVAL_
#define _INTERVAL_
struct Interval
{
	int start;
	int end;
	Interval() :start(0), end(0) {}
	Interval(int s, int e) :start(s), end(e) {}
};
#endif // _INTERVAL_
