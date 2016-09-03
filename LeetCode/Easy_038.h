/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
#include<string>
using namespace std;
//success
class Count_And_Say{
public:
	string countAndSay(int n)
	{
		if (n == 1)
		{
			return "1";
		}
		else if (n == 2)
		{
			return "11";
		}
		else
		{
			int Start = 2;
			string OldRsult = "11";
			int looptimes = 0;
			while (Start < n)
			{
				string NewResult = "";
				//ÿһ���������ٶ���1
				int Numbers = 1;
				for (int i = 0; i < OldRsult.size(); i++)
				{
					cout << "Numbers = " << Numbers << endl;
					if ((i + 1) < OldRsult.size() && OldRsult[i] == OldRsult[i + 1])
					{
						Numbers++;
					}
					else if ((i + 1) < OldRsult.size() && OldRsult[i] != OldRsult[i + 1])
					{
						//���ǰ��������Ѿ������˵Ļ�����ʼһ���µĶ�����
						NewResult = NewResult + (char)(Numbers + '0');
						NewResult = NewResult + OldRsult[i];
						//ÿһ�����ֵ����ٵĸ�������1������ÿһ�εĳ�ʼ������1
						Numbers = 1;
					}
				}
				cout << (char)(Numbers + '0') << endl;
				//����һ�����ֵĶ�����
				NewResult = NewResult + (char)(Numbers + '0');
				NewResult = NewResult + OldRsult[OldRsult.size()-1];
				OldRsult = NewResult;
				Start++;
			}
			
			return OldRsult;
		}
	}
};