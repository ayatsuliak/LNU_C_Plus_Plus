#include "ElectricalAppliance.h"
#include<algorithm>
#include<memory>

using namespace std;

//��������� ����������� ��� ��������������(�����, �����, ����).
//��������� 3 ������ �� ����� ���� : ����������(���������, ����), �������� ������(������� �������, �ᒺ�), 
//��������(���������, ������� �������).
//� ���������� ���� ������ ��� ��� 7 ����� ��������������.������� ��� � ���� ����� � ������� � 
//����1 �� ��������������, ���������� �� ������ �� ����������� �� �������.
//������� � ����2 ������ ���� ��  �������� ������� �������������� ������� �����.

int main()
{
	fstream fileInput;
	fstream F1;
	fstream F2;

	fileInput.open("Input.txt");
	F1.open("File1.txt");
	F2.open("File2.txt");

	size_t SIZE;
	char ch;
	fileInput >> SIZE;
	size_t i = 0;

	IElectricalAppliance** arr = new IElectricalAppliance* [SIZE];
	while (i!=SIZE)
	{
		fileInput >> ch;
		if (ch == 's')
		{
			arr[i] = new Steamer;
		}
		else if (ch == 'w')
		{
			arr[i] = new WashingMachine;
		}
		else if (ch == 'c')
		{
			arr[i] = new Combine;
		}
		arr[i]->Input(fileInput);
		i++;		
	}

	sort(arr, arr + SIZE);
	for_each(arr, arr + SIZE, [&](IElectricalAppliance* mas)
		{
			F1 << mas->nameElectricalAppliance() << endl;
		});


	//////////////////////////////////////////////////////////////////////////
	double totalCost = 0;
	string valueForCompanyName;
	cout << "Enter company name: " << endl;
	cin >> valueForCompanyName;
	for_each(arr, arr + SIZE, [&](IElectricalAppliance* mas)
		{
			if (mas->nameCompanyElectricalAppliance() == valueForCompanyName)
			{
				F2 << mas->nameElectricalAppliance() << endl;
				totalCost += mas->priceElectricalAppliance();
			}
			else
			{
				i++;
			}
		});

	if (totalCost == 0)
	{
		F2 << "The product does not exist" << endl;
	}
	else
	{
		F2 << "Total cost: " << totalCost << endl;
	}
	
	

	fileInput.close();
	F1.close();
	F2.close();
	return 0;
}