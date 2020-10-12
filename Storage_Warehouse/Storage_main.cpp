#include <iostream>
#include <pthread.h>
#include <thread>
#include <unistd.h>
#include "Crate.h"
#include <queue>
using namespace std;
	
int numofWorkers = 5;
int numofCrates = 10;
int fcounter = 0;

bool fbool = false;

queue<Crate> storage;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER; 
pthread_mutex_t lock3 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER; 

void *work(void* i);

/*
struct arg {
    int arg1;
    Crate arg2;
};
*/
	
int main()
{	
	for(int j = 0; j < numofCrates; j++) { storage.push( Crate(j) ); storage.back().printCrate();} 
	pthread_t thread[numofWorkers];
	for (int i = 0; i < numofWorkers; i++)
	{
		/*
		struct arg items;
		items.arg1 = i;
		items.arg2 = storage[i];
		*num = i; 
		*/
		pthread_create(&thread[i],NULL,work,(void*)i); 
	}
	for (int j = 0; j < numofWorkers; j++)
	{
		pthread_join(thread[j],NULL);
	}
	return 0;
} 

void *work(void* args)
{ 
	int x = (int)args;
	while(storage.size() != 0)
	{
		/*
		struct arg *ptr = (struct arg*)args;
		int x = ptr -> arg1;
		Crate box = ptr -> arg2;
		*/
		pthread_mutex_lock(&lock2);
		Crate box = storage.front();
		storage.pop();
		pthread_mutex_unlock(&lock2);
		if (box.checkPriority() == "fragile")
		{
			fcounter++;
			pthread_mutex_lock(&lock3);
			box.TakeCrate(x);
			fcounter--;
			pthread_mutex_unlock(&lock3);
			if(fcounter == 0) { fbool = true; }
			
			
		}
		else
		{
			while(fbool == false) { usleep(1000); }
			pthread_mutex_lock(&lock3);
			box.TakeCrate(x);
			pthread_mutex_unlock(&lock3);
			pthread_cond_broadcast(&cond1);
		}
	}
	return 0;
}

