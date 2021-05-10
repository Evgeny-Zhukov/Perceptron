#include <iostream>

using std::cout;
using std::endl;

class Neuron
{
public:
	Neuron(int weight, int input)
	{
		this->weight = weight;
		this->input = input;
		
	}

	int Output(int input, int weight)
	{
		return (this->output = input * weight);
	}
	int getInput()
	{
		return this->input;
	}
	int getWeight()
	{
		return this->weight;
	}
	int setWeight(int weight)
	{
		return(this->weight = weight);
	}
private:
	int input;
	int weight;
	int output;
};
template<typename T>
int Output(T a,T b)
{
	if (a.Output(a.getInput(), a.getWeight()) + b.Output(b.getInput(), b.getWeight()) <= 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

template<typename T>
int Output(T a, T b,T c)
{
	if (a.Output(a.getInput(), a.getWeight()) + b.Output(b.getInput(), b.getWeight()) + c.Output(c.getInput(), c.getWeight()) <= 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
template<typename T>
int Check(T a,T b, T c, int ref)
{
	if (Output(a, b, c) < ref)
	{
		return 1;
	}
	else if (Output(a, b, c) > ref)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int i = 1;
	int j = 1;
	const int ref = 1;

	Neuron S1_A1(-1,i);
	Neuron S2_A1(1, j);
	cout<<Output(S1_A1, S2_A1)<<endl;
	
	Neuron S1_A2(1, i);
	Neuron S2_A2(-1, j);

	cout << Output(S1_A2, S2_A2) << endl;
	Neuron S1_A3(1, i);
	Neuron S2_A3(1, j);

	cout << Output(S1_A3, S2_A3) << endl;

	

	Neuron A1_R1(0, Output(S1_A1, S2_A1));
	Neuron A2_R1(0, Output(S1_A2, S2_A2));
	Neuron A3_R1(0, Output(S1_A2, S2_A2));

	cout <<"Output R = "<< Output(A1_R1, A2_R1, A3_R1) << endl;
	cout << "ref = " << ref << endl;

	int check_value;
	check_value = Check(A1_R1, A2_R1, A3_R1, ref);

	for (int i = 0; i < 100; i++)
	{
		A1_R1.setWeight(A1_R1.getWeight() + check_value * Output(S1_A1, S2_A1));
		A2_R1.setWeight(A2_R1.getWeight() + check_value * Output(S1_A2, S2_A2));
		A3_R1.setWeight(A3_R1.getWeight() + check_value * Output(S1_A3, S2_A3));
		check_value = Check(A1_R1, A2_R1, A3_R1, ref);
		
		if (Check(A1_R1, A2_R1, A3_R1, ref) == 0)
		{
			cout << "Output R = " << Output(A1_R1, A2_R1, A3_R1) << endl;
			cout << "ref = " << ref << endl;
			cout<<"i = "<<i << endl;
			break;
		}
	}
	return 0;
}
