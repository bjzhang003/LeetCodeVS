/*
Implement int sqrt(int x).

Compute and return the square root of x.

�����Ҵ���ʵ��һ��ţ�ٵ�����
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
//success
class Sqrt_X{
public:
	int mySqrt(int x)
	{
		int result = 0;
		if (x > 0)
		{
			double root0 = 10;
			double root1 = 0;
			//ţ�ٵ�������ʵ��
			while (abs(root0 - root1) > 0.1)
			{
				root1 = root0 - (root0*root0 - x) / (2 * root0);
				double tempData = root1;
				root1 = root0;
				root0 = tempData;

			}
			cout << "root1 = " << root1 << ", root0 = " << root0 << endl;
			result = int(root0);
		}
		
		return result;
	}
};