/*
 * hash.h
 *
 *  Created on: May 5, 2017
 *      Author: preoyati
 */
#include<iostream>
#include<cstdlib>
#include<string>

#ifndef HASH_H_
#define HASH_H_

class hash{
private:
	static const int tablesize = 10;

	struct item{
		std::string word;
		item* next;
	};

	item* hashtable[tablesize];

public:
	hash();//constractor
	int HashFunc(std::string key);
	void AddItem(std::string word);
	void PrintItems(void);
	int NumberOfItemsInIndex(int index);

};


#endif /* HASH_H_ */
