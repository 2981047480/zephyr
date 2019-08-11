#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string user_name;
	cout << "please enter your first name:" << endl;
	cin >> user_name;
	cout << '\n' << "hello," 
		 << user_name 
		 << endl 
		 << "and goodbye";
	system("pause");
	return 0;
}