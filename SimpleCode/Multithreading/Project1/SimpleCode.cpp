#include <iostream>;
#include <thread>;
#include <chrono>;

using namespace std;

//mutex - це штука, яка допомагає захистити дані між потоками

void DoWork()
{

}

int main()
{
	//this_thread::get_id(); //айді потоку
	//this_thread::sleep_for(chrono::milliseconds(1000)); //призупиняє виконання поточного потоку

	thread th(DoWork); //чз кому передаються парам, які необхідні для ф-ції
	// th(DoWork, ref::q);
	th.detach(); //переривається при зупинці іншого потоку(головного)
	th.join(); //дозволяє дочекатись інших потоків(в тому місці, в якому хочемо дочекатись виконання роботи)


	return 0;
}