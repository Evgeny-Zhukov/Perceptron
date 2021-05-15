#include <iostream>

using std::cout;
using std::endl;

class Neuron
{
public:
	int input;
	int weight;
	int output;
	Neuron()
	{
		this->output = 0;
		this->weight = 1;
	}
	Neuron(int weight, int output)
	{
		this->weight = weight;
		this->output = output;
		
	}

	int Out(int weight, int input)
	{
		return (this->output = (input * weight));
	}
	
	
	/*int getInput()
	{
		return this->input;
	}
	int getWeight()
	{
		return this->weight;
	}
	
	int getOutput()
	{
		return output;
	}*/
	
	int Inp(Neuron a,Neuron b)
	{
		if ((a.output*a.weight+b.output*b.weight)<=0)
		{
			return (this->input=0);
		}
		else
		{
			return (this->input=1);
		}
	}
	int Inp(Neuron a, Neuron b, Neuron c)
	{
		if ((a.output * a.weight + b.output * b.weight + c.output*c.weight)<=0)
		{
			return (this->input = 0);
		}
		else
		{
			return (this->input = 1);
		}
	}
	
	void Print()
	{
		cout << "input " << input << " weight " << weight << " output " << output << endl;
	}
	
private:
	
};
int Check(int a, int ref)// сравнивает выходной сигнал R нейрона с эталоном
{
	if (a < ref)
	{
		
		return 1;
	}
	else if (a > ref)
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
	setlocale(LC_ALL, "Russian");

	int i = 1;
	int j = 1;

	const int ref = -1;

	Neuron S1_A1(-1,i);
	Neuron S2_A1(1, j);
	Neuron S1_A2(1, i);
	Neuron S2_A2(-1, j);
	Neuron S1_A3(1, i);
	Neuron S2_A3(1, j);

	//определяем вес от S к А
	Neuron A1_R1;
	A1_R1.Inp(S1_A1, S2_A1);
	A1_R1.Out(A1_R1.weight,A1_R1.Inp(S1_A1, S2_A1));
	A1_R1.Print();

	Neuron A2_R1;
	A2_R1.Inp(S1_A2, S2_A2);
	A2_R1.Out(A2_R1.weight, A2_R1.Inp(S1_A2, S2_A2));
	A2_R1.Print();

	Neuron A3_R1;
	A3_R1.Inp(S1_A3, S2_A3);
	A3_R1.Out(A3_R1.weight, A3_R1.Inp(S1_A3, S2_A3));
	A3_R1.Print();
	
	Neuron R;
	R.Out(R.weight, R.Inp(A1_R1, A2_R1, A3_R1));
	R.Print();

	
	for (int k = 0; k < 10; k++)
	{
		if (Check(R.output, ref) == 1)
		{
			cout << "weight+" << endl;
			A1_R1.weight = (A1_R1.weight + Check(R.output, ref) * A1_R1.output);
			A2_R1.weight = (A2_R1.weight + Check(R.output, ref) * A2_R1.output);
			A3_R1.weight = (A3_R1.weight + Check(R.output, ref) * A3_R1.output);
			R.Out(R.weight, R.Inp(A1_R1, A2_R1, A3_R1));
		}
		else if (Check(R.output, ref) == -1)
		{
			cout << "weight-" << endl;
			A1_R1.weight = (A1_R1.weight + Check(R.output, ref) * A1_R1.output);
			A2_R1.weight = (A2_R1.weight + Check(R.output, ref) * A2_R1.output);
			A3_R1.weight = (A3_R1.weight + Check(R.output, ref) * A3_R1.output);
			R.Out(R.weight, R.Inp(A1_R1, A2_R1, A3_R1));
		}
		else
		{
			cout << "weight unchanged" << endl;
			A1_R1.weight = (A1_R1.weight + Check(R.output, ref) * A1_R1.output);
			A2_R1.weight = (A2_R1.weight + Check(R.output, ref) * A2_R1.output);
			A3_R1.weight = (A3_R1.weight + Check(R.output, ref) * A3_R1.output);
			R.Out(R.weight, R.Inp(A1_R1, A2_R1, A3_R1));
		}
		cout << "k = " << k << endl;
		A1_R1.Print();
		A2_R1.Print();
		A3_R1.Print();
		R.Print();
		if (R.output == ref)
		{
			break;
		}
	}
	
	return 0;
}
