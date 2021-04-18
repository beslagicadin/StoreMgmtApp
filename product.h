#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include<fstream>
//#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include "register.h"
#include "worker.h"


using namespace std;




class product
{
	int product_number;
	char product_name[50];
	float product_price,product_quantity,product_discount;

	public:

	void create_product()
	{
		cout<<endl<<"UNESITE #ID PROIZVODA: ";
		cin>>product_number;
		cout<<endl<<"UNESITE NAZIV PROIZVODA: ";
		cin.ignore();
		cin.getline(product_name ,50);
		cout<<endl<<"UNESITE CIJENU PROIZVODA: ";
		cin>>product_price;


	}
	void create_productq()
	{
		cout<<endl<<"UNESITE #ID PROIZVODA: ";
		cin>>product_number;
		cout<<endl<<"UNESITE NAZIV PROIZVODA: ";
		cin.ignore();
		cin.getline(product_name ,50);
		cout<<endl<<"UNESITE CIJENU PROIZVODA: ";
		cin>>product_price;
		cout<<endl<<"UNESITE KOLIcINU PROIZVODA: ";
		cin>>product_quantity;


	}

	void show_product()
	{
		cout<<endl<<"#ID ARTIKLA: "<<product_number;
		cout<<endl<<"NAZIV ARTIKLA: "<<product_name;
		cout<<endl<<"CIJENA ARTIKLA: "<<product_price;
	}

	int getProduct()
	{
		return product_number;
	}

	float getPrice()
	{
		return product_price;
	}

	char* getName()
	{
		return product_name;
	}

	float getDiscount()
	{
		return product_discount;
	}
	float getQuantity()
	{
		return product_quantity;
	}
};



fstream fp;
product produc;


void save_product()
{
	fp.open("Artikal.dat",ios::out|ios::app);
	produc.create_product();
	fp.write((char*)&produc,sizeof(product));
	fp.close();
	cout<<endl<<endl<<"ARTIKAL JE USPJESNO UPISAN...";
	pause();
	cls();
}


void show_all_product()
{
	cls();
	cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<endl<<"\t\tARTIKLI";
	cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	fp.open("Artikal.dat",ios::in);
	while(fp.read((char*)&produc,sizeof(product)))
	{
		produc.show_product();
		cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"<<endl;

	}
	fp.close();
	pause();
}


void display_record(int num)
{
	bool found=false;
	fp.open("Artikal.dat",ios::in);
	while(fp.read((char*)&produc,sizeof(product)))
	{
		if(produc.getProduct()==num)
		{
			cls();
			produc.show_product();
			found=true;
		}
	}

	fp.close();
	if(found == true)
	pause();
}
void display_recordNOCLS(int num)
{
	bool found=false;
	fp.open("Artikal.dat",ios::in);
	while(fp.read((char*)&produc,sizeof(product)))
	{
		if(produc.getProduct()==num)
		{
			//cls();
			produc.show_product();
			found=true;
		}
	}

	fp.close();
	if(found == true)
	pause();
}


void edit_product()
{
	int num;
	bool found=false;
	cls();
	cout<<endl<<endl<<"\tUNESITE #ID ARTIKLA: ";
	cin>>num;

	fp.open("Artikal.dat",ios::in|ios::out);
	while(fp.read((char*)&produc,sizeof(product)) && found==false)
	{
		if(produc.getProduct()==num)
		{
			produc.show_product();
			cout<<"\nUNESITE NOVE PODATKE ZA ARTIKAL: "<<endl;
			produc.create_product();
			int pos=-1*sizeof(produc);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&produc,sizeof(product));
			cout<<endl<<endl<<"\t UPISANI ARTIKAL JE USPJESNO IZMIJENJEN...";
			found=true;
		}
	}
	fp.close();
	if(found==false)
		cout<<endl<<endl<<"ZAPIS NIJE PRONADJEN...";
	getchar();
}


void delete_product()
{
	int num;
	cls();
	cout<<endl<<endl<<"UNESITE #ID ARTIKLA: ";
	cin>>num;
	fp.open("Artikal.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&produc,sizeof(product)))
	{
		if(produc.getProduct()!=num)
		{
			fp2.write((char*)&produc,sizeof(product));
		}
	}
	fp2.close();
	fp.close();
	remove("Artikal.dat");
	rename("Temp.dat","Artikal.dat");
	cout<<endl<<endl<<"\tZAPIS JE IZBRISAN...";
	getchar();
}


void product_menu()
{
	cls();
	fp.open("Artikal.dat",ios::in);

	cout<<endl<<endl<<"\t\tARTIKAL\n\n";
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"#ID\t\tNAZIV ARTIKLA\t\tCIJENA ARTIKLA\n";
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	while(fp.read((char*)&produc,sizeof(product)))
	{
		cout<<produc.getProduct()<<"\t\t\t"<<produc.getName()<<"\t\t"<<produc.getPrice()<<endl;
	}
	fp.close();
}







void admin_menu()
{
	cls();
	int option;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\t1 - UPIS NOVOG ARTIKLA";
	cout<<"\n\t2 - PRIKAZ SVIH ARTIKALA";
	cout<<"\n\t3 - PRETRAZIVANJE";
	cout<<"\n\t4 - IZMJENA UPISA ARTIKLA";
	cout<<"\n\t5 - BRISANJE ARTIKLA";
	cout<<"\n\t6 - NAZAD NA MENI";
	cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	cout<<"\n\n\tOPCIJE: ";
	cin>>option;
	switch(option)
	{
		case 1: cls();
				save_product();
				break;

		case 2: show_all_product();
				break;

		case 3:
				int num;
				cls();
				cout<<"\n\n\tUNESITE #ID ARTIKLA: ";
				cin>>num;
				display_record(num);
				break;

		case 4: edit_product();
		break;

		case 5: delete_product();
		        break;

		case 6: cls();
				break;

		default:admin_menu();
	}
}

void place_order()
{
	int order_arr[50],quan[50],c=0;
	long jmb;
	float amt,damt,total=0;
	char ch='Y';
	cout<<"Unesite JMBG radnika: ";
	cin>>jmb;
	display_radnik(jmb);
	product_menu();
	cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\nUNESITE NARUDZBU";
	cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	do{
		cout<<"\n\nUNESITE #ID ARTIKLA: ";
		cin>>order_arr[c];
		cout<<"\nKOLICINA: ";
        cin>>quan[c];
		c++;
		cout<<"\nDa li zelite unijeti jos artikala? (y/n)";
		cin>>ch;
		}while(ch=='y' ||ch=='Y');
	cout<<"\n\nHvala...";
	pause();
	cls();
	cout<<"\n\n********************************RACUN************************\n";
	cout<<"\n#ID A.\tNaziv A.\tKolicina \tCijena \tIznos \n";
	for(int x=0;x<=c;x++)
	{
		fp.open("Artikal.dat",ios::in);
		fp.read((char*)&produc,sizeof(product));
		while(!fp.eof())
		{
			if(produc.getProduct()==order_arr[x])
			{
				amt=produc.getPrice()*quan[x];
				damt=amt-(amt*produc.getDiscount()/100);
				cout<<"\n"<<order_arr[x]<<"\t"<<produc.getName()<<"\t\t"<<quan[x]<<"\t\t"<<produc.getPrice()<<"\t"<<amt<<"\t"<<damt<<"\n";
				total+=damt;
			}
			fp.read((char*)&produc,sizeof(product));
		}
		fp.close();
	}
	cout<<"\n\n\t\t\t\t\tUKUPNO = "<<total;
	pause();

}

#endif // PRODUCT_H_INCLUDED
