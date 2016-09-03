/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, 
print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/
#include<vector>
using namespace std;
//success
//寻找到相应的规律
class Gray_Code{
public:
	vector<int> grayCode(int n)
	{
		if (n == 0)
		{
			vector<int> result;
			result.push_back(0);
			return result;
		}
		else if (n == 1)
		{
			vector<int> result;
			result.push_back(0);
			result.push_back(1);
			return result;
		}
		else if (n > 1)
		{
			vector<int> TempData = grayCode(n - 1);
			vector<int> result;
			//正序来一次
			for (int i = 0; i < TempData.size(); i++)
				result.push_back(TempData[i]);
			int Add = pow(2, n - 1);
			//逆序来一次
			for (int i = TempData.size() - 1; i >= 0; i--)
			{
				result.push_back(Add + TempData[i]);
			}
			return result;
		}
		vector<int> result;
		return result;
	}
};