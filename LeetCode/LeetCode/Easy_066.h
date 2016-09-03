/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include<vector>
#include<iostream>
using namespace std;
//success
class Plus_One{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		int Carry = 1;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			int Temp = digits[i];
			digits[i] = (digits[i] + Carry) % 10;
			Carry = (Temp + Carry) / 10;
		}
		if (Carry > 0)
		{
			digits.insert(digits.begin(),Carry);
		}
		for (int i = 0; i < digits.size(); i++)
		{
			cout << digits[i] << "  ";
		}
		cout << endl;
		return digits;

	}
};