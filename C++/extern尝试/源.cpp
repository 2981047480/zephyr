#include<iostream>
using namespace std;

extern void write_extern();

int main(void)
{
	int count = 5;
	write_extern();
}