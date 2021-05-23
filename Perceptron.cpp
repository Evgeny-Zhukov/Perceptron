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
private:


};
int Reaction(int a, int ref)
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
	int ref1 = 1;
	int ref_1 = -1;

	Neuron A1(0, 0);
	Neuron A2(0, 0);
	Neuron A3(1, 0);
	Neuron R;
	cout << "Эпоха 1" << endl;
	R.input = A1.output * A1.weight + A2.output * A2.weight + A3.output * A3.weight;

	if (R.input > 0)
	{
		R.output = 1;
	}
	else
	{
		R.output = -1;
	}

	int reaction = Reaction(R.output, ref1);
	switch (reaction)
	{
	case 0:
		cout << "weight unchanged" << endl;
		break;
	case -1:
		A1.weight += reaction * A1.output;
		A2.weight += reaction * A2.output;
		A3.weight += reaction * A3.output;
		cout << "weight -" << endl;
		break;
	case 1:
		A1.weight += reaction * A1.output;
		A2.weight += reaction * A2.output;
		A3.weight += reaction * A3.output;
		cout << "weight +" << endl;
		break;
	default:
		break;
	}
	R.Print();

	Neuron A4(1, A1.weight);
	Neuron A5(0, A2.weight);
	Neuron A6(1, A3.weight);
	R.input = A4.output * A4.weight + A5.output * A5.weight + A6.output * A6.weight;

	if (R.input > 0)
	{
		R.output = 1;
	}
	else
	{
		R.output = -1;
	}

	reaction = Reaction(R.output, ref_1);
	switch (reaction)
	{
	case 0:
		cout << "weight unchanged" << endl;
		break;
	case -1:
		A4.weight += reaction * A4.output;
		A5.weight += reaction * A5.output;
		A6.weight += reaction * A6.output;
		cout << "weight -" << endl;
		break;
	case 1:
		A4.weight += reaction * A4.output;
		A5.weight += reaction * A5.output;
		A6.weight += reaction * A6.output;
		cout << "weight +" << endl;
		break;
	default:
		break;
	}
	R.Print();
	Neuron A7(0, A4.weight);
	Neuron A8(1, A5.weight);
	Neuron A9(1, A6.weight);
	R.input = A7.output * A7.weight + A8.output * A8.weight + A9.output * A9.weight;

	if (R.input > 0)
	{
		R.output = 1;
	}
	else
	{
		R.output = -1;
	}

	reaction = Reaction(R.output, ref_1);
	switch (reaction)
	{
	case 0:
		cout << "weight unchanged" << endl;
		break;
	case -1:
		A7.weight += reaction * A7.output;
		A8.weight += reaction * A8.output;
		A9.weight += reaction * A9.output;
		cout << "weight -" << endl;
		break;
	case 1:
		A7.weight += reaction * A7.output;
		A8.weight += reaction * A8.output;
		A9.weight += reaction * A9.output;
		cout << "weight +" << endl;
		break;
	default:
		break;
	}
	R.Print();
	cout << endl;
	cout << "Эпоха 2" << endl;
	A1.weight = A7.weight;
	A2.weight = A8.weight;
	A3.weight = A9.weight;
	R.input = A1.output * A1.weight + A2.output * A2.weight + A3.output * A3.weight;

	if (R.input > 0)
	{
		R.output = 1;
	}
	else
	{
		R.output = -1;
	}

	reaction = Reaction(R.output, ref1);
	switch (reaction)
	{
	case 0:
		cout << "weight unchanged" << endl;
		break;
	case -1:
		A1.weight += reaction * A1.output;
		A2.weight += reaction * A2.output;
		A3.weight += reaction * A3.output;
		cout << "weight -" << endl;
		break;
	case 1:
		A1.weight += reaction * A1.output;
		A2.weight += reaction * A2.output;
		A3.weight += reaction * A3.output;
		cout << "weight +" << endl;
		break;
	default:
		break;
	}
	R.Print();

	A4.weight = A1.weight;
	A5.weight = A2.weight;
	A6.weight = A3.weight;
	R.input = A4.output * A4.weight + A5.output * A5.weight + A6.output * A6.weight;

	if (R.input > 0)
	{
		R.output = 1;
	}
	else
	{
		R.output = -1;
	}

	reaction = Reaction(R.output, ref_1);
	switch (reaction)
	{
	case 0:
		cout << "weight unchanged" << endl;
		break;
	case -1:
		A4.weight += reaction * A4.output;
		A5.weight += reaction * A5.output;
		A6.weight += reaction * A6.output;
		cout << "weight -" << endl;
		break;
	case 1:
		A4.weight += reaction * A4.output;
		A5.weight += reaction * A5.output;
		A6.weight += reaction * A6.output;
		cout << "weight +" << endl;
		break;
	default:
		break;
	}
	R.Print();

	A7.weight = A4.weight;
	A8.weight = A5.weight;
	A9.weight = A6.weight;
	R.input = A7.output * A7.weight + A8.output * A8.weight + A9.output * A9.weight;

	if (R.input > 0)
	{
		R.output = 1;
	}
	else
	{
		R.output = -1;
	}

	reaction = Reaction(R.output, ref_1);
	switch (reaction)
	{
	case 0:
		cout << "weight unchanged" << endl;
		break;
	case -1:
		A7.weight += reaction * A7.output;
		A8.weight += reaction * A8.output;
		A9.weight += reaction * A9.output;
		cout << "weight -" << endl;
		break;
	case 1:
		A7.weight += reaction * A7.output;
		A8.weight += reaction * A8.output;
		A9.weight += reaction * A9.output;
		cout << "weight +" << endl;
		break;
	default:
		break;
	}
	R.Print();
	cout << endl;
	cout << "Эпоха 3" << endl;
	A1.weight = A7.weight;
	A2.weight = A8.weight;
	A3.weight = A9.weight;
	R.input = A1.output * A1.weight + A2.output * A2.weight + A3.output * A3.weight;

	if (R.input > 0)
	{
		R.output = 1;
	}
	else
	{
		R.output = -1;
	}

	reaction = Reaction(R.output, ref1);
	switch (reaction)
	{
	case 0:
		cout << "weight unchanged" << endl;
		break;
	case -1:
		A1.weight += reaction * A1.output;
		A2.weight += reaction * A2.output;
		A3.weight += reaction * A3.output;
		cout << "weight -" << endl;
		break;
	case 1:
		A1.weight += reaction * A1.output;
		A2.weight += reaction * A2.output;
		A3.weight += reaction * A3.output;
		cout << "weight +" << endl;
		break;
	default:
		break;
	}
	R.Print();

	A4.weight = A1.weight;
	A5.weight = A2.weight;
	A6.weight = A3.weight;
	R.input = A4.output * A4.weight + A5.output * A5.weight + A6.output * A6.weight;

	if (R.input > 0)
	{
		R.output = 1;
	}
	else
	{
		R.output = -1;
	}

	reaction = Reaction(R.output, ref_1);
	switch (reaction)
	{
	case 0:
		cout << "weight unchanged" << endl;
		break;
	case -1:
		A4.weight += reaction * A4.output;
		A5.weight += reaction * A5.output;
		A6.weight += reaction * A6.output;
		cout << "weight -" << endl;
		break;
	case 1:
		A4.weight += reaction * A4.output;
		A5.weight += reaction * A5.output;
		A6.weight += reaction * A6.output;
		cout << "weight +" << endl;
		break;
	default:
		break;
	}
	R.Print();

	A7.weight = A4.weight;
	A8.weight = A5.weight;
	A9.weight = A6.weight;
	R.input = A7.output * A7.weight + A8.output * A8.weight + A9.output * A9.weight;

	if (R.input > 0)
	{
		R.output = 1;
	}
	else
	{
		R.output = -1;
	}

	reaction = Reaction(R.output, ref_1);
	switch (reaction)
	{
	case 0:
		cout << "weight unchanged" << endl;
		break;
	case -1:
		A7.weight += reaction * A7.output;
		A8.weight += reaction * A8.output;
		A9.weight += reaction * A9.output;
		cout << "weight -" << endl;
		break;
	case 1:
		A7.weight += reaction * A7.output;
		A8.weight += reaction * A8.output;
		A9.weight += reaction * A9.output;
		cout << "weight +" << endl;
		break;
	default:
		break;
	}
	R.Print();
	cout << endl;
	cout << "Эпоха 4" << endl;
	A1.weight = A7.weight;
	A2.weight = A8.weight;
	A3.weight = A9.weight;
	R.input = A1.output * A1.weight + A2.output * A2.weight + A3.output * A3.weight;

	if (R.input > 0)
	{
		R.output = 1;
	}
	else
	{
		R.output = -1;
	}

	reaction = Reaction(R.output, ref1);
	switch (reaction)
	{
	case 0:
		cout << "weight unchanged" << endl;
		break;
	case -1:
		A1.weight += reaction * A1.output;
		A2.weight += reaction * A2.output;
		A3.weight += reaction * A3.output;
		cout << "weight -" << endl;
		break;
	case 1:
		A1.weight += reaction * A1.output;
		A2.weight += reaction * A2.output;
		A3.weight += reaction * A3.output;
		cout << "weight +" << endl;
		break;
	default:
		break;
	}
	R.Print();

	A4.weight = A1.weight;
	A5.weight = A2.weight;
	A6.weight = A3.weight;
	R.input = A4.output * A4.weight + A5.output * A5.weight + A6.output * A6.weight;

	if (R.input > 0)
	{
		R.output = 1;
	}
	else
	{
		R.output = -1;
	}

	reaction = Reaction(R.output, ref_1);
	switch (reaction)
	{
	case 0:
		cout << "weight unchanged" << endl;
		break;
	case -1:
		A4.weight += reaction * A4.output;
		A5.weight += reaction * A5.output;
		A6.weight += reaction * A6.output;
		cout << "weight -" << endl;
		break;
	case 1:
		A4.weight += reaction * A4.output;
		A5.weight += reaction * A5.output;
		A6.weight += reaction * A6.output;
		cout << "weight +" << endl;
		break;
	default:
		break;
	}
	R.Print();

	A7.weight = A4.weight;
	A8.weight = A5.weight;
	A9.weight = A6.weight;
	R.input = A7.output * A7.weight + A8.output * A8.weight + A9.output * A9.weight;

	if (R.input > 0)
	{
		R.output = 1;
	}
	else
	{
		R.output = -1;
	}

	reaction = Reaction(R.output, ref_1);
	switch (reaction)
	{
	case 0:
		cout << "weight unchanged" << endl;
		break;
	case -1:
		A7.weight += reaction * A7.output;
		A8.weight += reaction * A8.output;
		A9.weight += reaction * A9.output;
		cout << "weight -" << endl;
		break;
	case 1:
		A7.weight += reaction * A7.output;
		A8.weight += reaction * A8.output;
		A9.weight += reaction * A9.output;
		cout << "weight +" << endl;
		break;
	default:
		break;
	}
	R.Print();
	return 0;
}