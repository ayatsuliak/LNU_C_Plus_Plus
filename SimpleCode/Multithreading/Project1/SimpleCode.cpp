#include <iostream>;
#include <thread>;
#include <chrono>;

using namespace std;

//mutex - �� �����, ��� �������� ��������� ��� �� ��������

void DoWork()
{

}

int main()
{
	//this_thread::get_id(); //��� ������
	//this_thread::sleep_for(chrono::milliseconds(1000)); //���������� ��������� ��������� ������

	thread th(DoWork); //�� ���� ����������� �����, �� �������� ��� �-���
	// th(DoWork, ref::q);
	th.detach(); //������������ ��� ������� ������ ������(���������)
	th.join(); //�������� ���������� ����� ������(� ���� ����, � ����� ������ ���������� ��������� ������)


	return 0;
}