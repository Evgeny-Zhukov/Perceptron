#pragma once
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

void XOR(int i,int j,int ref)
{

	Neuron S1_A1(i, -1);

	Neuron S2_A1(j, 1);

	Neuron S1_A2(i, 1);

	Neuron S2_A2(j, -1);

	Neuron S1_A3(i, 1);

	Neuron S2_A3(j, 1);

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

	Neuron R;
	R.setInput(A1, A2, A3);
	R.ROutput();
	R.Print();


	for (int k = 1; k < 10; k++)
	{
		int reactiaon = Reaction(R.output, ref);
		if (reactiaon != 0)
		{
			if (reactiaon==1)
			{
				cout << "weight+" << endl;
			}
			else
			{
				cout << "weight-" << endl;
			}
			A1.weight += reactiaon * A1.output;
			A2.weight += reactiaon * A2.output;
			A3.weight += reactiaon * A3.output;
			cout << endl;

			A1.Output();
			A1.Print();

			A2.Output();
			A2.Print();

			A3.Output();
			A3.Print();

			R.setInput(A1, A2, A3);
			R.ROutput();
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
}