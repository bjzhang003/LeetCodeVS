#pragma once
/*
Given an array of words and a length L, 
format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; 
that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line do not divide evenly between words, 
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, 
it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.
Return the formatted lines as:
["This    is    an",
"example  of text",
"justification.  "]

Note: Each word is guaranteed not to exceed L in length.
Corner Cases:
A line other than the last line might contain only one word.
What should you do in this case?
In this case, that line should be left-justified.
*/
#include<string>
#include<iostream>
#include<vector>
using namespace std;
//success
class Text_Justification {
public:
	vector<string> fullJustify(vector<string>&words, int maxWidth)
	{
		vector<string> result;		
		if (words.size() > 0)
		{
			//�ȶ�string ���з��������
			vector<vector<string>> DataSplit;
			vector<string> OneGroup;
			int GroupLength = 0;
			for (int i = 0; i < words.size(); i++)
			{
				if (GroupLength + words[i].size() < maxWidth)
				{
					//��ǰ�ĵ��ʿ��Լӽ������ڵ�Group��ȥ�����Ҽӽ�ȥ֮�󣬻��п���ĵط�
					OneGroup.push_back(words[i]);
					GroupLength += words[i].size();
					//���һ���ո�
					GroupLength++;
				}
				else if (GroupLength + words[i].size() == maxWidth)
				{
					//�������ȵĻ�����ʱ���԰����һ��������ӽ�ȥ
					OneGroup.push_back(words[i]);
					DataSplit.push_back(OneGroup);
					OneGroup.clear();
					GroupLength = 0;
				}	
				else
				{
					//����Ǵ��ڵĻ������ʱ���ܰ����һ��������ӽ�ȥ
					DataSplit.push_back(OneGroup);
					OneGroup.clear();
					OneGroup.push_back(words[i]);
					//��ӵ�ǰ�����ݣ����������һ���ո�����
					GroupLength = words[i].size() + 1;
				}
			}
			//�������һ������
			if (!OneGroup.empty())
			{
				DataSplit.push_back(OneGroup);
			}
			
			//�����Ѿ��ֺ��ˣ����ڵ���������ΰ�" "���ȵط��䵽ÿһ������֮��
			for (int i = 0; i < DataSplit.size(); i++)
			{
				//���һ��������Ҫ���⴦��
				if (i == DataSplit.size() - 1)
				{
					string Temp = "";
					for (int j = 0; j < DataSplit[i].size(); j++)
					{
						Temp += DataSplit[i][j];
						if (Temp.size() < maxWidth)
							Temp += " ";
					}
					while (Temp.size() < maxWidth)
					{
						Temp += " ";
					}
					result.push_back(Temp);
				}
				//�����ǰ������ֻ��һ�����ʵĻ�����ֱ���ڵ��ʵĺ�����ӿո񼴿�
				else if (DataSplit[i].size() == 1)
				{
					string Temp = "";
					Temp += DataSplit[i][0];
					for (int j = 0; j < maxWidth - DataSplit[i][0].size(); j++)
					{
						Temp += " ";
					}
					result.push_back(Temp);
				}
				else
				{
					//��ǰ����������������������

					//���ȼ��㵱ǰ������һ���ж��ٸ��ǿո������
					GroupLength = 0;
					for (int j = 0; j < DataSplit[i].size(); j++)
					{
						GroupLength = GroupLength + DataSplit[i][j].size();
					}
					cout << "GroupLength = " << GroupLength << endl;

					//����ո�ÿһ����ĸ֮��
					int AllSpace = maxWidth - GroupLength;
					vector<int> SpaceSplit(DataSplit[i].size() - 1, 0);
					while (AllSpace > 0)
					{
						for (int j = 0; j < SpaceSplit.size(); j++)
						{
							SpaceSplit[j]++;
							AllSpace--;
							if (AllSpace == 0)
								break;
						}
					}

					//�鿴�ո�ķ�������
					for (int j = 0; j < SpaceSplit.size(); j++)
					{
						cout << SpaceSplit[j] << "  ";
					}
					cout << endl;

					//���ݿո�͵��ʹ�������
					string Temp = "";
					for (int j = 0; j < DataSplit[i].size(); j++)
					{
						Temp = Temp + DataSplit[i][j];
						if (j < SpaceSplit.size())
						{
							for (int k = 0; k < SpaceSplit[j]; k++)
							{
								Temp += " ";
							}
						}
					}
					//��������ӽ���
					result.push_back(Temp);
				}
				//����else����

			}
			//����forѭ��
		}
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "|" << endl;
		}
		return result;
	}
};

/*
��������
Text_Justification Test;
vector<string> TestData = { "What","must","be","shall","be." };
Test.fullJustify(TestData, 12);

*/