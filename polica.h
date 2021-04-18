#ifndef POLICA_H_INCLUDED
#define POLICA_H_INCLUDED

#include<fstream>
//#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>

#include "product.h"
#include "register.h"


using namespace std;



class polica
{


	public:

    int prod_kol, prod_number;
	char polica_name[50];

	void show_polica1()
	{

		cls();
        cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout<<endl<<"\t\tPOLICA 1";
        cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        fp.open("Polica1.txt",ios::in);
        string str1;
        char c;
        while(!fp.eof()){
            fp>>c;
            str1+=c;
        }
        cout<<str1;
        str1="";
        cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"<<endl;
        pause();
        fp.close();

	}
	void show_polica2()
	{
		cls();
        cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout<<endl<<"\t\tPOLICA 2";
        cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        fp.open("Polica2.txt",ios::in);
        string str1;
        char c;
        while(!fp.eof()){
            fp>>c;
            str1+=c;
        }
        cout<<str1;
        str1="";
        cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"<<endl;
        pause();
        fp.close();

	}
	void show_polica3()
	{
        cls();
        cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout<<endl<<"\t\tPOLICA 3";
        cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        fp.open("Polica3.txt",ios::in);
        string str1;
        char c;
        while(!fp.eof()){
            fp>>c;
            str1+=c;
        }
        cout<<str1;
        str1="";
        cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"<<endl;
        pause();
        fp.close();

	}


	void create_productP()
	{

		cout<<endl<<"#ID PROIZVODA: ";
		cin>>prod_number;
		cout<<endl<<"UNESITE KOLICINU PROIZVODA: ";
		cin>>prod_kol;


	}


};



fstream fpo;
polica poli;

void nupisPolica1()
{
	int order_arr[50],quan[50],c=0;
	float amt,damt,total=0;
	char ch='Y';
	product_menu();
	do{
		cout<<"\n\nUNESITE #ID ARTIKLA: ";
		cin>>order_arr[c];
		cout<<"\nKOLICINA: ";
        cin>>quan[c];
		c++;
		cout<<"\nDa li zelite unijeti jos artikala? (y/n)";
		cin>>ch;
		}while(ch=='y' ||ch=='Y');
	pause();
	cls();
	cout<<"\n\n***************************| POLICA 1 |************************\n";
	cout<<"\n#ID A.\tNaziv A.\tKolicina \tCijena";
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
				cout<<"\n"<<order_arr[x]<<"\t"<<produc.getName()<<"\t\t"<<quan[x]<<"\t\t"<<produc.getPrice()<<"\n";
				fpo.open("Polica1.txt",ios::out|ios::app);
				fpo<<"\n"<<order_arr[x]<<"\t"<<produc.getName()<<"\t\t"<<quan[x]<<"\t\t"<<produc.getPrice()<<"\n";
				fpo.close();;
				total+=damt;
			}
			fp.read((char*)&produc,sizeof(product));
		}
		fp.close();
	}
	pause();

}
void nupisPolica2()
{
	int order_arr[50],quan[50],c=0;
	float amt,damt,total=0;
	char ch='Y';
	product_menu();
	do{
		cout<<"\n\nUNESITE #ID ARTIKLA: ";
		cin>>order_arr[c];
		cout<<"\nKOLICINA: ";
        cin>>quan[c];
		c++;
		cout<<"\nDa li zelite unijeti jos artikala? (y/n)";
		cin>>ch;
		}while(ch=='y' ||ch=='Y');
	pause();
	cls();
	cout<<"\n\n***************************| POLICA 2 |************************\n";
	cout<<"\n#ID A.\tNaziv A.\tKolicina \tCijena";
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
				cout<<"\n"<<order_arr[x]<<"\t"<<produc.getName()<<"\t\t"<<quan[x]<<"\t\t"<<produc.getPrice()<<"\n";
				fpo.open("Polica2.txt",ios::out|ios::app);
				fpo<<"\n"<<order_arr[x]<<"\t"<<produc.getName()<<"\t\t"<<quan[x]<<"\t\t"<<produc.getPrice()<<"\n";
				fpo.close();;
				fpo.close();
				total+=damt;
			}
			fp.read((char*)&produc,sizeof(product));
		}
		fp.close();
	}
	pause();

}
void nupisPolica3()
{
	int order_arr[50],quan[50],c=0;
	float amt,damt,total=0;
	char ch='Y';
	product_menu();
	do{
		cout<<"\n\nUNESITE #ID ARTIKLA: ";
		cin>>order_arr[c];
		cout<<"\nKOLICINA: ";
        cin>>quan[c];
		c++;
		cout<<"\nDa li zelite unijeti jos artikala? (y/n)";
		cin>>ch;
		}while(ch=='y' ||ch=='Y');
	pause();
	cls();
	cout<<"\n\n***************************| POLICA 3 |************************\n";
	cout<<"\n#ID A.\tNaziv A.\tKolicina \tCijena";
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
				cout<<"\n"<<order_arr[x]<<"\t"<<produc.getName()<<"\t\t"<<quan[x]<<"\t\t"<<produc.getPrice()<<"\n";
				fpo.open("Polica3.txt",ios::out|ios::app);
				fpo<<"\n"<<order_arr[x]<<"\t"<<produc.getName()<<"\t\t"<<quan[x]<<"\t\t"<<produc.getPrice()<<"\n";
				fpo.close();
				total+=damt;
			}
			fp.read((char*)&produc,sizeof(product));
		}
		fp.close();
	}
	pause();

}
void save_polica()
{
    int x, prod_number, prod_kol;
	cout << "UNESITE NA KOJU POLICU DODAJETE ARTIKAL: (1,2 ili 3)";
	cin >> x;
	if(x==1)
        {
            fstream fpo;
            fpo.open("Polica1.txt",ios::out|ios::app);
            produc.create_productq();
            fpo.write((char*)&produc,sizeof(product));
            fpo.close();
            cout<<endl<<endl<<"ARTIKAL JE USPJESNO UPISAN U POLICU 1...";
            pause();
            cls();
        }
    if(x==2)
        {
            fstream fpo;
            fpo.open("Polica2.txt",ios::out|ios::app);
            produc.create_productq();
            fpo.write((char*)&produc,sizeof(product));
            fpo.close();
            cout<<endl<<endl<<"ARTIKAL JE USPJESNO UPISAN U POLICU 2...";
            pause();
            cls();
        }
    if(x==3)
        {
            fstream fpo;
            fpo.open("Polica3.txt",ios::out|ios::app);
            produc.create_productq();
            fpo.write((char*)&produc,sizeof(product));
            fpo.close();
            cout<<endl<<endl<<"ARTIKAL JE USPJESNO UPISAN U POLICU 3...";
            pause();
            cls();
        }

}


void show_all_polica()
{
	cls();
	cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<endl<<"\t\tODABERITE POLICU ZA PRIKAZ";
	cout<<endl<<"\t\t1. PRVA";
	cout<<endl<<"\t\t2. DRUGA";
	cout<<endl<<"\t\t3. TRECA";
	cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    int y;
    cin >> y;
    if(y==1)
        {
            fpo.open("Polica1.txt",ios::in);
            while(!fpo.eof())
            {
                poli.show_polica1();
                cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"<<endl;
                pause();
            }
            fpo.close();
            y=0;
        }
    if(y==2)
        {
            fpo.open("Polica2.txt",ios::in);
            while(fpo.read((char*)&produc,sizeof(product)))
            {
                poli.show_polica2();
                cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"<<endl;
                pause();
            }
            fpo.close();
            y=0;
        }
    if(y==3)
        {
            fpo.open("Polica3.txt",ios::in);
            while(fpo.read((char*)&produc,sizeof(product)))
            {
                poli.show_polica3();
                cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"<<endl;
                pause();
            }
            fpo.close();
            y=0;
        }


}


/*void display_record(int num)
{
	bool found=false;
	fpo.open("Polica.dat",ios::in);
	while(fpo.read((char*)&poli,sizeof(polica)))
	{
		if(poli.getPolica()==num)
		{
			cls();
			poli.show_polica();
			found=true;
		}
	}

	fpo.close();
	if(found == true)
	pause();
}
*/


void edit_polica()
{
	int num;
	bool found=false;
	cls();
	cout<<endl<<endl<<"\tUNESITE #ID POLICE: ";
	cin>>num;

	if(num==1)
        {
            fpo.open("Polica1.txt",ios::in|ios::out);
            while(fpo.read((char*)&poli,sizeof(polica)) && found==false)
                {
                    poli.show_polica1();
                    cout<<"\nUNESITE NOVE PODATKE ZA POLICU: "<<endl;
                    produc.create_productq();
                    int pos=-1*sizeof(poli);
                    fpo.seekp(pos,ios::cur);
                    fpo.write((char*)&produc,sizeof(product));
                    cout<<endl<<endl<<"\tPOLICA JE USPJESNO IZMIJENJENA...";
                    found=true;
                }
            fpo.close();
            getchar();

        }
    if(num==2)
        {
            fpo.open("Polica2.txt",ios::in|ios::out);
            while(fpo.read((char*)&poli,sizeof(polica)) && found==false)
                {
                    poli.show_polica1();
                    cout<<"\nUNESITE NOVE PODATKE ZA POLICU: "<<endl;
                    produc.create_productq();
                    int pos=-1*sizeof(poli);
                    fpo.seekp(pos,ios::cur);
                    fpo.write((char*)&produc,sizeof(product));
                    cout<<endl<<endl<<"\tPOLICA JE USPJESNO IZMIJENJENA...";
                    found=true;
                }
            fpo.close();
            getchar();

        }
    if(num==3)
        {
            fpo.open("Polica3.txt",ios::in|ios::out);
            while(fpo.read((char*)&poli,sizeof(polica)) && found==false)
                {
                    poli.show_polica1();
                    cout<<"\nUNESITE NOVE PODATKE ZA POLICU: "<<endl;
                    produc.create_productq();
                    int pos=-1*sizeof(poli);
                    fpo.seekp(pos,ios::cur);
                    fpo.write((char*)&produc,sizeof(product));
                    cout<<endl<<endl<<"\tPOLICA JE USPJESNO IZMIJENJENA...";
                    found=true;
                }
            fpo.close();
            getchar();

        }
}


void delete_polica()
{
	int num;
	cls();
	cout<<endl<<endl<<"UNESITE #ID POLICE: ";
	cin>>num;
	if(num==1)
        {
            /*fpo.open("Polica1.txt",ios::in|ios::out);
            fstream fpo2;
            fpo2.open("Temp.dat",ios::out);
            fpo.seekg(0,ios::beg);
            while(fpo.read((char*)&poli,sizeof(polica)))
            {
                if(poli.getPolica1()!=num)
                {
                    fpo2.write((char*)&poli,sizeof(polica));
                }
            }
            fpo2.close();
            fpo.close();
            remove("Polica1.txt");
            rename("Temp.dat","Polica1.txt");*/
            ofstream ofs;
            ofs.open("Polica1.txt", std::ofstream::out | std::ofstream::trunc);
            ofs.close();
            cout<<endl<<endl<<"\tPOLICA 1 JE IZBRISANA...";
            pause();
        }
    if(num==2)
        {
            /*fpo.open("Polica2.txt",ios::in|ios::out);
            fstream fpo2;
            fpo2.open("Temp.dat",ios::out);
            fpo.seekg(0,ios::beg);
            while(fpo.read((char*)&poli,sizeof(polica)))
            {
                if(poli.getPolica2()!=num)
                {
                    fpo2.write((char*)&poli,sizeof(polica));
                }
            }
            fpo2.close();
            fpo.close();
            remove("Polica2.txt");
            rename("Temp.dat","Polica2.txt");*/
            ofstream ofs;
            ofs.open("Polica2.txt", std::ofstream::out | std::ofstream::trunc);
            ofs.close();
            cout<<endl<<endl<<"\tPOLICA 2 JE IZBRISANA...";
            pause();
        }
    if(num==3)
        {
            /*fpo.open("Polica3.txt",ios::in|ios::out);
            fstream fpo2;
            fpo2.open("Temp.dat",ios::out);
            fpo.seekg(0,ios::beg);
            while(fpo.read((char*)&poli,sizeof(polica)))
            {
                if(poli.getPolica3()!=num)
                {
                    fpo2.write((char*)&poli,sizeof(polica));
                }
            }
            fpo2.close();
            fpo.close();
            remove("Polica3.txt");
            rename("Temp.dat","Polica3.txt");*/
            ofstream ofs;
            ofs.open("Polica3.txt", std::ofstream::out | std::ofstream::trunc);
            ofs.close();
            cout<<endl<<endl<<"\tPOLICA 3 JE IZBRISANA...";
            pause();
        }
}

void upisiPolicu()
{
    int num;
	cls();
	cout<<endl<<endl<<"UNESITE #ID POLICE: ";
	cin>>num;
	switch(num)
	{
	    while((num<1)||(num>3))
        {
            case 1:
            nupisPolica1();
            num=0;
            break;
            case 2:
            nupisPolica2();
            num=0;
            break;
            case 3:
            nupisPolica3();
            num=0;
            break;
        }

	}
}






void adminP_menu()
{
    POLICA:
	cls();
	int option;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\t1 - UPIS ARTIKALA U POLICU";
	//cout<<"\n\t2 - PRIKAZ POLICA";
	//cout<<"\n\t2 - IZMJENA UPISA POLICE";
	cout<<"\n\t2 - BRISANJE POLICE";
	cout<<"\n\t3 - NAZAD NA MENI";
	cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	cout<<"\n\n\tOPCIJE: ";
	cin>>option;
	switch(option)
	{
		case 1: cls();
                upisiPolicu();
                option=0;
				break;

		/*case 5: show_all_polica();
                option=0;
				break;*/

		/*case 2: edit_polica();
                option=0;
		break;*/

		case 2: delete_polica();
                option=0;
		        break;

		case 3: cls();
                option=0;
				break;

		default:adminP_menu();
	}
}


#endif // POLICA_H_INCLUDED

