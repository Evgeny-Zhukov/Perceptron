#include <iostream>
using std::cout;
using std::endl;

class Neuron
{
public:
	

	Neuron()
	{

	}
	Neuron(int input,int weight)
	{
		this->input = input;
		this->weight = weight;
		this->output = input;
	}
	void Print()
	{
		cout << "input = "<<input << " weight = " << weight << " output = " << output << endl;
	}
	void setInput(Neuron a,Neuron b)
	{
		input = (a.output*a.weight+b.output*b.weight);
	}
	void setInput(Neuron a, Neuron b,Neuron c)
	{
		input = (a.output * a.weight + b.output * b.weight+c.output*c.weight);
	}
	void Output()
	{
		if (input < 0)
		{
			output = 0;
		}
		else
		{
			output = 1;
		}
	}
	
private:
	int input;
	int weight;
	int output;

};

int main()
{
	int i = 1;
	int j = 1;
	Neuron S1_A1(i,-1);
	S1_A1.Print();
	Neuron S2_A1(j,1);
	S2_A1.Print();
	Neuron S1_A2(i,1);
	S1_A2.Print();
	Neuron S2_A2(j,-1);
	S2_A2.Print();
	Neuron S1_A3(i,1);
	S1_A3.Print();
	Neuron S2_A3(j,1);
	S2_A2.Print();

	Neuron A1;
	A1.setInput(S1_A1, S2_A1);
	A1.Output();
	A1.Print();

	Neuron A2;
	A2.setInput(S1_A2, S2_A2);
	A2.Output();
	A2.Print();

	Neuron A3;
	A3.setInput(S1_A3, S2_A3);
	A3.Output();
	A3.Print();


	return 0;
}