#include <iostream>
#include <unistd.h>
#include "Crate.h"
using namespace std;

Crate::Crate(int i)
{
	weight = rand() % 7;
	if (weight % 2 != 0)
	{
		priority = "fragile";
	}
	else { priority = "normal"; }
	transported = false;
	number = i;
}

void Crate::TakeCrate(int i)
{
	cout<<"Crate "<<number<<" is taken for transport by worker "<<i<<endl;
	int worktime = rand() % 3 + 1;
	sleep(worktime);
	transported = true;
}

void Crate::printCrate()
{
	cout<<"Crate number: "<<number<<"\n";
	cout<<"Crate weight: "<<weight<<"\n";
	cout<<"Crate type: "<<priority<<"\n";
	cout<<" "<<endl;	
}

string Crate::checkPriority()
{
	return priority;
}

bool Crate::checkTransport()
{
	return transported;
}

Crate::~Crate()
{
	//cout<<"Crate "<<number<<" has been sent"<<endl;
}





