#include<iostream>
#include<vector>

using namespace std;

//Визначити шаблонну функцію, яка підраховує кількість елементів, відмінних від вказаного i - го елемента в масиві.
//Передбачити перехоплення винятків при невірному значенні i.

template<typename T>
size_t function(T* arr, T element, size_t size)
{
	size_t countElementInArray = size;
	size_t count = 0;
	auto p = find(arr, arr + countElementInArray, element);
	if (p == arr + countElementInArray)
	{
		throw invalid_argument("Item does not exist");
	}
	for (size_t i = 0; i < countElementInArray; i++)
	{
		if (arr[i] != element)
		{
			count++;
		}
		else
		{
			continue;
		}
	}
	return count;
}

//int main()
//{
//	string arr[] = { "hello", "hi", "hello", "pryvit" };
//	string str = "hi";
//	try
//	{
//		cout << function(arr, str, 4);
//	}
//	catch (invalid_argument& ex)
//	{
//		cout << ex.what() << endl;
//	}
//	catch (exception& ex)
//	{
//		cout << ex.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "unexpected exception" << endl;
//	}
//	return 0;
//}