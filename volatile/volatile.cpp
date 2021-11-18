// volatile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

const unsigned long STOPVALUE=4000000000;
volatile unsigned long i=0;
unsigned long long m=0;

int ThreadProc()
{
	for (i=0;i<STOPVALUE;i++)
	{
		m += i;
	}
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	thread th1 (ThreadProc);
	while(i<STOPVALUE)
	{
		printf("Main: %lu,%I64u\n",i,m);
	}
	th1.join();
	return 0;
}

