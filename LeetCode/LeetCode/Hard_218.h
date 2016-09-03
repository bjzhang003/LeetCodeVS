#pragma once
/*
https://leetcode.com/problems/the-skyline-problem/
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. 
Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), 
write a program to output the skyline formed by these buildings collectively (Figure B).

The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], 
where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, 
and Hi is its height. It is guaranteed that 0 �� Li, Ri �� INT_MAX, 0 < Hi �� INT_MAX, and Ri - Li > 0. 
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
For instance, the dimensions of all buildings in Figure A are recorded as: 
[ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. 
A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, 
is merely used to mark the termination of the skyline, and always has zero height. 
Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.
For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
Notes:
The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, 
[...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; 
the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
*/
#include<vector>
#include<set>
#include<utility>
#include<algorithm>
#include<stack>
using namespace std;

class The_Skyline_Problem {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>> & buildings)
	{
		vector<pair<int, int>> result;
		if (buildings.size() > 0)
		{
			//�ȶ����ݽ����������
			sort(buildings.begin(), buildings.end(), mycompare);
			stack<pair<int, int>> First, Second;
			First.push({ buildings[0][0],buildings[0][2] });
			Second.push({ buildings[0][1],buildings[0][2] });
			for (int i = 1; i < buildings.size(); i++)
			{
				//�ж���ߵĵ��ǲ���Ӧ��д��result��ȥ
				if (buildings[i][3]>First.top().second)
				{
					result.push_back(First.top());
					First.pop();
					First.push({ buildings[i][0],buildings[i][3] });
				}
				else if (buildings[i][2] > Second.top().first)
				{

				}
			}
		}
		return result;	
	}
private:
	struct Compare {
		bool operator()(const vector<int> &One, const vector<int> &Two) const
		{
			return *One.cbegin() < *Two.cbegin();
		}
	}mycompare;
};