#include <iostream>

using std::cout;
using std::endl;
//const int n = 2;
//
//int x[n] = { 1,1 };
//int w_1[3] = { -1,1,1 };
//int w_2[3] = { 1,-1,1 };
//int w_3[3] = { 0,0,0 };
//int s_1, s_2, s_3, a;
//int ref = 1;
//int reac;
//for (int i = 0; i < 1; i++)
//{
//	s_1 = x[0] * w_1[i] + x[1] * w_2[i];
//	if (s_1 <= 0)
//	{
//		s_1 = 0;
//	}
//	else
//	{
//		s_1 = 1;
//	}
//	s_2 = x[0] * w_1[i + 1] + x[1] * w_2[i + 1];
//	if (s_2 <= 0)
//	{
//		s_2 = 0;
//	}
//	else
//	{
//		s_2 = 1;
//	}
//	s_3 = x[0] * w_1[i + 2] + x[1] * w_2[i + 2];
//	if (s_3 <= 0)
//	{
//		s_3 = 0;
//	}
//	else
//	{
//		s_3 = 1;
//	}
//	cout << s_1 << endl << s_2 << endl << s_3 << endl;
//}
//
//a = s_1 * w_3[0] + s_2 * w_3[1] + s_3 * w_3[2];
//if (a <= 0)
//{
//	a = 0;
//}
//else
//{
//	a = 1;
//}
//cout << a << endl;
//
//if (a == ref)
//{
//	a = 0;
//}
//else if (a < ref)
//{
//	a = 1;
//}
//else
//{
//	a = -1;
//}
//for (int i = 0; i < 1; i++)
//{
//	s_1 = w_3[0] + a * s_1;
//	if (s_1 <= 0)
//	{
//		s_1 = 0;
//	}
//	else
//	{
//		s_1 = 1;
//	}
//	s_2 = w_3[1] + a * s_2;
//	if (s_2 <= 0)
//	{
//		s_2 = 0;
//	}
//	else
//	{
//		s_2 = 1;
//	}
//	s_3 = w_3[2] + a * s_3;
//	if (s_3 <= 0)
//	{
//		s_3 = 0;
//	}
//	else
//	{
//		s_3 = 1;
//	}
//	cout << s_1 << endl << s_2 << endl << s_3 << endl;
//
//}
//
//a = s_1 * w_3[0] + s_2 * w_3[1] + s_3 * w_3[2];
//if (a <= 0)
//{
//	a = 0;
//}
//else
//{
//	a = 1;
//}
//cout << a << endl;
class SNeuron
{
public:
	SNeuron(int weight)
	{
		this->weight = weight;
		
	}
	void setInput(int input)
	{
		this->input = input;
	}

	
private:
	int weight;
	int input;
	int output;
};
int main()
{
	SNeuron S_1{1};
	S_1.setInput(1);
	return 0;
}

