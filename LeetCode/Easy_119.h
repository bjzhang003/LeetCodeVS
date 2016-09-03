/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
#include<vector>
using namespace std;
//success
class Pascals_Troangle_II{
public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> result;
		vector<int> old;
		if (rowIndex >= 0)
		{
			for (int i = 0; i <= rowIndex; i++)
			{
				cout << "i = " << i << endl;
				cout << "old = " << old.size() << ", result = " << result.size() << endl;
				for (int j = 0; j <= i; j++)
				{
					if (j == 0 || j == i)
					{
						result.push_back(1);
					}
					else
					{
						result.push_back(old[j - 1] + old[j]);
					}
				}
				old = result;
				if (i != rowIndex)
					result.clear();
			}
			cout << "result = " << endl;
			for (int i = 0; i < result.size(); i++)
			{
				cout << result[i] << "  ";
			}
			cout << endl;
		}
		return result;
	}
};