#pragma once
/*
Given a string s1, 
we may represent it as a binary tree by partitioning 
it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

        great
       /     \
      gr     eat
     /  \   /   \
    g    r e     at
                /  \
               a    t
To scramble the string, 
we may choose any non-leaf node and swap its two children.
For example, if we choose the node "gr" and swap its two children, 
it produces a scrambled string "rgeat".

          rgeat
         /     \
        rg     eat
       /  \   /   \
      r    g e    at
                 /  \
                a    t
We say that "rgeat" is a scrambled string of "great".
Similarly, if we continue to swap the children of nodes "eat" and "at", 
it produces a scrambled string "rgtae".

          rgtae
         /     \
        rg     tae
       /  \   /   \
      r    g ta    e
            /  \
           t    a
We say that "rgtae" is a scrambled string of "great".
Given two strings s1 and s2 of the same length, 
determine if s2 is a scrambled string of s1.
*/
#include<string>
#include<iostream>
using namespace std;
//http://blog.csdn.net/linhuanmars/article/details/24506703
//http://blog.sina.com.cn/s/blog_b9285de20101gy6n.html
//上面的这种方法并不是很好的方法
//这种方法是坤哥教我的
class Scramble_String {
public:
	bool isScramble(string s1, string s2)
	{
		bool result = false;
		if (s1.size() > 0)
		{
			//对长度进行匹配操作
			for (int i = 0; i < s1.size(); i++)
			{
				for (int Len = 1; Len + i < s1.size(); Len++) 
				{

				}
			}
		}
		return result;
	}
};