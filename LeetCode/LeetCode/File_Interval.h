#pragma once
/*
����Hard_056��ʹ�õĽṹ��
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
