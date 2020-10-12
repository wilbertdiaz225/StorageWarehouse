#include <iostream>
#include "list.h"
using namespace std;

struct node
{
	Crate box;
	node *next;

list::list()
{
	head=NULL;
    tail=NULL;
}

void list::createlist(Crate box)
{
    node *temp=new node;
    temp->data=value;
    temp->next=NULL;
    if(head==NULL)
    {
		head=temp;
        tail=temp;
        temp=NULL;
	}
    else
    {	
        tail->next=temp;
        tail=temp;
    }
}