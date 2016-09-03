#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<stdint.h>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<utility>
#include<functional>
#include<unordered_set>
#include<bitset>
#include <sstream>
#include<Windows.h>
#include<fstream>
#include<assert.h>
#include"File_ListNode.h"
#include"File_TreeNode.h"
#include"A_Binary_Search.h"
#include"File_TreeLinkNode.h"
#include"A_Template_Test.h"
#include"A_FileStream.h"
#include"File_UndirectedGraphNode.h"
#include"Hard_149.h"
using namespace std;

int main()
{
	std::cout << "Start My Code Now ! " << std::endl << std::endl;

	Max_Points_On_A_Line Test;
	vector<Point> points = { {0,0},{0,0} };
	Test.maxPoints(points);

	std::cout << std::endl << std::endl << "End My Code Now !" << std::endl;
	system("pause");
	return 0;
}
