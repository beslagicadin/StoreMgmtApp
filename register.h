#ifndef REGISTER_H_INCLUDED
#define REGISTER_H_INCLUDED


#include<fstream>
//#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include "product.h"

using namespace std;

class Register
{
	int register_number;
	char register_name[50];

	public:

    void place_order();

};


#endif // REGISTER_H_INCLUDED
