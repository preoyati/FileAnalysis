/*
*
******** created by preoyati
May 5, 2017
*/
#include<iostream>
#include<cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>


#include "hash.h"

using namespace std;

vector <string> data;
void readFile();

int main(int argc, char *argv[])
{
	hash hashobj;

	readFile();
	for(int i=0 ; i<data.size(); i++)
	{
		hashobj.AddItem(data[i]);
	}

	hashobj.PrintItems();

	int count = hashobj.NumberOfItemsInIndex(4);
	cout << "Number of Items in position " << 4 << " is :" << count <<endl;

	return 0;

}

void readFile()
{
    ifstream file;
    file.open ("input.txt");
    if (!file.is_open()) return;

    string word;
    hash hashobj;

    while (file >> word)
    {
    	data.push_back(word);

    }
}
