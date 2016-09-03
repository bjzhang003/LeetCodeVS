/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
#include<string>
using namespace std;
//success
class Implement_strStr{
public:
	int strStr(string haystack, string needle)
	{
		int result = haystack.find(needle);
		return result;
	}
};