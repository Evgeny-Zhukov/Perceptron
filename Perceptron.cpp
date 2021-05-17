#include <iostream>
using std::cout;
using std::endl;

class Neuron
{
public:
	

	Neuron()
	{
		this->weight = 0;
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
		this->input = (a.output * a.weight + b.output * b.weight);
	}
	void setInput(Neuron a, Neuron b, Neuron c)
	{
		this->input = (a.output * a.weight + b.output * b.weight + c.output * c.weight);
	}
	void Output()//функция активации
	{
		if (this->input <= 0)
		{
			this->output = 0;

		}
		else 
		{
			this->output = 1;
		}
		
	}
	void ROutput()
	{
		if (this->input <= 0)
		{
			this->output = -1;
		}
		else
		{
			this->output = 1;
		}
	}
	int input;
	int weight;
	int output;
private:
	

};
int Reaction(int a,int ref)
{
	if (a < ref)
	{
		return 1;
	}
	else if (a > ref)
	{
		return -1;
	}
	else return 0;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 1;
	int j = 0;

	const int ref = 1;

	Neuron S1_A1(i,-1);
	
	Neuron S2_A1(j,1);
	
	Neuron S1_A2(i,1);
	
	Neuron S2_A2(j,-1);
	
	Neuron S1_A3(i,1);
	
	Neuron S2_A3(j,1);

	Neuron A1;
	A1.setInput(S1_A1, S2_A1);
	A1.Output();
	//A1.Print();

	Neuron A2;
	A2.setInput(S1_A2, S2_A2);
	A2.Output();
	//A2.Print();

	Neuron A3;
	A3.setInput(S1_A3, S2_A3);
	A3.Output();
	//A3.Print();

	Neuron R;
	R.setInput(A1, A2, A3);
	R.ROutput();
	//R.Print();
	

	for (int k = 1; k < 10; k++)
	{
		int reactiaon = Reaction(R.output, ref);
		if (Reaction(R.output, ref) != 0)
		{
			A1.weight += reactiaon * A1.output;
			A2.weight += reactiaon * A2.output;
			A3.weight += reactiaon * A3.output;
			cout << "\t" << endl;

			A1.Output();
			A1.Print();

			A2.Output();
			A2.Print();

			A3.Output();
			A3.Print();

			R.setInput(A1, A2, A3);
			R.Output();
			R.Print();
			cout << endl;
		}
		else
		{
			A1.Print();
			A2.Print();
			A3.Print();
			R.Print();
			cout << "Перцептрон обучен, эпох прошло " << k << endl;
			break;
		}
		
	}
		
	
	return 0;
}