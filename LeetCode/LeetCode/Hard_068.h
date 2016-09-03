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
			//先对string 进行分组操作。
			vector<vector<string>> DataSplit;
			vector<string> OneGroup;
			int GroupLength = 0;
			for (int i = 0; i < words.size(); i++)
			{
				if (GroupLength + words[i].size() < maxWidth)
				{
					//当前的单词可以加进到现在的Group中去，并且加进去之后，还有空余的地方
					OneGroup.push_back(words[i]);
					GroupLength += words[i].size();
					//添加一个空格
					GroupLength++;
				}
				else if (GroupLength + words[i].size() == maxWidth)
				{
					//如果是相等的话，此时可以把最后一个数据添加进去
					OneGroup.push_back(words[i]);
					DataSplit.push_back(OneGroup);
					OneGroup.clear();
					GroupLength = 0;
				}	
				else
				{
					//如果是大于的话，则此时不能把最后一个数据添加进去
					DataSplit.push_back(OneGroup);
					OneGroup.clear();
					OneGroup.push_back(words[i]);
					//添加当前的数据，并且添加了一个空格数据
					GroupLength = words[i].size() + 1;
				}
			}
			//处理最后一个分组
			if (!OneGroup.empty())
			{
				DataSplit.push_back(OneGroup);
			}
			
			//分组已经分好了，现在的事情是如何把" "均匀地分配到每一个单词之间
			for (int i = 0; i < DataSplit.size(); i++)
			{
				//最后一组数据需要特殊处理
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
				//如果当前的数据只有一个单词的话，则直接在单词的后面添加空格即可
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
					//当前分组里面至少有两个数据

					//首先计算当前的数据一共有多少个非空格的数据
					GroupLength = 0;
					for (int j = 0; j < DataSplit[i].size(); j++)
					{
						GroupLength = GroupLength + DataSplit[i][j].size();
					}
					cout << "GroupLength = " << GroupLength << endl;

					//分配空格到每一个字母之间
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

					//查看空格的分配数据
					for (int j = 0; j < SpaceSplit.size(); j++)
					{
						cout << SpaceSplit[j] << "  ";
					}
					cout << endl;

					//根据空格和单词构建数据
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
					//把数据添加进来
					result.push_back(Temp);
				}
				//结束else操作

			}
			//结束for循环
		}
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "|" << endl;
		}
		return result;
	}
};

/*
测试用例
Text_Justification Test;
vector<string> TestData = { "What","must","be","shall","be." };
Test.fullJustify(TestData, 12);

*/