#pragma once
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
	Neuron(int input, int weight)
	{
		this->input = input;
		this->weight = weight;
		this->output = input;
	}
	void Print()
	{
		cout << "input = " << input << " weight = " << weight << " output = " << output << endl;
	}
	void setInput(Neuron a, Neuron b)
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
};

