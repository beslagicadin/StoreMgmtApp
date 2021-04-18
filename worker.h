#ifndef WORKER_H_INCLUDED
#define WORKER_H_INCLUDED

#include<fstream>
//#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>

#include "register.h"
#include "product.h"


using namespace std;

void pause()
{
    cin.ignore();
    cin.get();
}

void cls()
{
  system("CLS||clear");

}

class radnik
{
	long radnik_number;
	char radnik_fname[50];
    char radnik_lname[50];

	public:

	void create_radnik()
	{
		cout<<endl<<"UNESITE JMBG RADNIKA: ";
		cin>>radnik_number;
		cout<<endl<<"UNESITE IME: ";
		cin.ignore();
		cin.getline(radnik_fname ,50);
        cout<<endl<<"UNESITE PREZIME: ";
        cin.ignore();
		cin.getline(radnik_lname ,50);
	}

	void show_radnik()      //28.12. 12:17
	{
		cout<<endl<<"JMBG: "<<radnik_number;
		cout<<endl<<"IME: "<<radnik_fname;
		cout<<endl<<"PREZIME: "<<radnik_lname;
	}

	long getRadnik()
	{
		return radnik_number;
	}

	char* getFname()
	{
		return radnik_fname;
	}

	char* getLname()
	{
		return radnik_lname;
	}

};



fstream frad;
radnik rad;


void save_rad()
{
	frad.open("Radnik.dat",ios::out|ios::app);
	rad.create_radnik();
	frad.write((char*)&rad,sizeof(radnik));
	frad.close();
	cout<<endl<<endl<<"RADNIK JE USPJESNO UPISAN...";
	pause();
	cls();
}


void show_all_radnik()
{
	cls();
	cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<endl<<"\t\tRADNICI";
	cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	frad.open("Radnik.dat",ios::in);
	while(frad.read((char*)&rad,sizeof(radnik)))
	{
		rad.show_radnik();
		cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"<<endl;
	}
	frad.close();
}


void display_radnik(long num)
{
	bool found=false;
	frad.open("Radnik.dat",ios::in);
	while(frad.read((char*)&rad,sizeof(radnik)))
	{
		if(rad.getRadnik()==num)
		{

			rad.show_radnik();
			found=true;
		}
	}

	frad.close();
	if(found == true)
	pause();
}



void edit_radnik()
{
	int num;
	bool found=false;
	cls();
	cout<<endl<<endl<<"\tUNESITE JMBG RADNIKA: ";
	cin>>num;

	frad.open("Radnik.dat",ios::in|ios::out);
	while(frad.read((char*)&rad,sizeof(radnik)) && found==false)
	{
		if(rad.getRadnik()==num)
		{
			rad.show_radnik();
			cout<<"\nUNESITE NOVE PODATKE ZA ARTIKAL: "<<endl;
			rad.create_radnik();
			int pos=-1*sizeof(rad);
			frad.seekp(pos,ios::cur);
			frad.write((char*)&rad,sizeof(radnik));
			cout<<endl<<endl<<"\t UPISANI RADNIK JE USPJESNO IZMIJENJEN...";
			found=true;
		}
	}
	frad.close();
	if(found==false)
		cout<<endl<<endl<<"ZAPIS NIJE PRONADJEN...";
	getchar();
}
long entry()
{
    long e;
    cout<<endl<<"UNESITE JMBG RADNIKA: ";
    cin>>e;
    return e;
}

void delete_radnik()
{
	int num;
	cls();
	cout<<endl<<endl<<"UNESITE JMBG RADNIKA: ";
	cin>>num;
	frad.open("Radnik.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	frad.seekg(0,ios::beg);
	while(frad.read((char*)&rad,sizeof(radnik)))
	{
		if(rad.getRadnik()!=num)
		{
			fp2.write((char*)&rad,sizeof(radnik));
		}
	}
	fp2.close();
	frad.close();
	remove("Radnik.dat");
	rename("Temp.dat","Radnik.dat");
	cout<<endl<<endl<<"\tZAPIS JE IZBRISAN...";
	getchar();
}


#endif // WORKER_H_INCLUDED
