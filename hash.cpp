/*
*
******** created by preoyati
May 5, 2017
*/
#include<iostream>
#include<cstdlib>
#include<string>

#include "hash.h"

using namespace std;
hash::hash()
{
	//tablesize = 10;
	for(int i =0 ; i < tablesize ; i ++)
	{
		hashtable[i] = new item;
		hashtable[i]->word = "empty";
		hashtable[i]->next = NULL;

	}

}
int hash::HashFunc(std::string key)
{

	int hash = 0;
	int index;
	//generating hash value for the input string:

	for(int i= 0; i < key.length(); i++)
	{
		hash = hash + (int) key[i];
	}

	index = hash % tablesize;

	return index;
}
void hash::AddItem(std::string s)
{
	int index = HashFunc(s);

	if(hashtable[index]->word == "empty")
	{
		hashtable[index]->word = s;
	}
	else
	{
		item* ptr = hashtable[index];//saving the pointer

		//creating new node to add
		item* n = new item;
		n->word = s;
		n->next = NULL;

		//finding where to add this node
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		//now adding this node
		ptr->next = n;

	}
}
void hash::PrintItems(void)
{
	for(int i = 0; i< tablesize; i++)
	{
		item* ptr = hashtable[i];// saving pointer at position i ( index )
		cout << "index = " << i << ": ";

		while(ptr->next != NULL)
		{
			cout<< ptr->word <<",";
			ptr = ptr->next;

		}
		cout<< ptr->word << " , "<< endl;


	}

}
int hash::NumberOfItemsInIndex(int index)
{
	int count = 0;
	item* ptr = hashtable[index];
	if(ptr->word != "empty")
	{
		count++;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
			count++;

		}
	}
	 return count;
}
