#include<iostream>
#include<string>

using namespace std;

//Визначити шаблонну функцію, яка за заданим масивом елементів – розбиває його на два масиви – 
//1) ті елементи, які більші за останній і 
//2) ті, які менші чи рівні за останній елемент масиву.Функція повертає той масив, який має меншу кількість елементів.
//Перевірити виконання функції для масиву цілих чисел та масиву рядків.Передбачити перехоплення виняткових ситуацій.

template<typename T, int n>
T Array(T* arr, int border)
{
	int index_bigger_arr = 0;
	int index_smaller_arr = 0;
	T* bigger_arr = new T[n];
	T* smaller_arr = new T[n];
	if (border > n)
	{
		throw out_of_range("Border > n");
	}

	for (int i = 0; i < border; i++)
	{
		if (arr[i] > arr[border -1])
		{
			bigger_arr[index_bigger_arr] = arr[i];
			index_bigger_arr++;
		}
		else 
		{
			smaller_arr[index_smaller_arr] = arr[i];
			index_smaller_arr++;
		}
	}
	if (index_bigger_arr > index_smaller_arr)
	{
		//cout << "Elements smaller array: ";
		/*for (int i = 0; i < index_smaller_arr; i++)
		{
			cout << smaller_arr[i] << " ";
		}*/
		return *smaller_arr;
	}
	else
	{
		//cout << "Elements bigger array: ";
		/*for (int i = 0; i < index_bigger_arr; i++)
		{
			cout << bigger_arr[i] << " ";
		}*/
		return *bigger_arr;
	}
	
	delete[] bigger_arr;
	delete[] smaller_arr;
}

int main()
{
	int arr[6];
	for (int i = 0; i < 6; i++)
	{
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "\tInt" << endl;
	
	try
	{
		cout << Array<int, 6>(arr, 6);
	}
	catch (out_of_range& ex)
	{
		cout << ex.what() << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "unexpected exception" << endl;
	}
	cout << endl;
	

	cout << "\tString" << endl;

	string arr2[4];
	arr2[0] = "string1";
	arr2[1] = "string4";
	arr2[2] = "string2";
	arr2[3] = "string3";
	
	try
	{
		cout<<Array<string, 4>(arr2, 4);
	}
	catch (out_of_range& ex)
	{
		cout << ex.what() << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "unexpected exception" << endl;
	}

	return 0;
}