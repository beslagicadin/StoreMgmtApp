#include <iostream>
#include <cstdlib>
#include <vector>
#include "product.h"
#include "register.h"
#include "worker.h"
#include "polica.h"
using namespace std;

    void resetUnos();
    void pause();
    void cls();
    int unos,unos1,unos2,unos3, unos4,unos5;
    void odabir(int a);


int main()
{

    MENI:
    while((unos<1)||(unos>5))
    {
    cls();
    cout<<"******************************| - Meni - |******************************"<<endl;
    cout<<"*Odaberite objekat nad kojim ce se vrsiti operacije:                   *"<<endl;
    cout<<"*                                                                      *"<<endl;
    cout<<"* OPCIJE:                                                              *"<<endl;
    cout<<"*   1 - RADNIK                                                         *"<<endl;
    cout<<"*   2 - KASA                                                           *"<<endl;
    cout<<"*   3 - POLICA                                                         *"<<endl;
    cout<<"*   4 - ARTIKAL                                                        *"<<endl;
    cout<<"*   5 - IZLAZ                                                          *"<<endl;
    cout<<"*----------------------------------------------------------------------*"<<endl;
    cout<<endl;
    cout<<"Vas unos: ";
    cin>>unos;
    }
    odabir(unos);
    switch(unos)
        {
            case 1:
                RADNIK:
                while((unos1<1)||(unos1>6))
                {
                    cls();
                    cout<<"*****************************| - Radnik - |*****************************"<<endl;
                    cout<<"*Odaberite operaciju koju zelite izvrsiti nad objektom 'radnik':       *"<<endl;
                    cout<<"*                                                                      *"<<endl;
                    cout<<"* OPCIJE:                                                              *"<<endl;
                    cout<<"*   1 - Upisi novog radnika                                            *"<<endl;
                    cout<<"*   2 - Izmijeni radnika                                               *"<<endl;
                    cout<<"*   3 - Obrisi radnika                                                 *"<<endl;
                    cout<<"*   4 - Ispisi sve radnike                                             *"<<endl;
                    cout<<"*   5 - Pretrazi radnike                                               *"<<endl;
                    cout<<"*   6 - Povratak na Meni                                               *"<<endl;
                    cout<<"*----------------------------------------------------------------------*"<<endl;
                    cout<<endl;
                    cout<<"Vas unos: ";
                    cin>>unos1;
                }
                odabir(unos1);
                switch(unos1)
                {
                    case 1:
                        cls();
                        save_rad();
                        resetUnos();
                        goto RADNIK;
                    break;
                    case 2:
                        cls();
                        edit_radnik();
                        resetUnos();
                        goto RADNIK;
                    break;
                    case 3:
                        cls();
                        delete_radnik();
                        resetUnos();
                        goto RADNIK;
                    break;
                    case 4:
                        cls();
                        show_all_radnik();
                        pause();
                        resetUnos();
                        goto RADNIK;
                    break;
                    case 5:
                        cls();
                        display_radnik(entry());
                        pause();
                        resetUnos();
                        goto RADNIK;
                    break;
                    case 6:
                        resetUnos();
                        goto MENI;
                    break;
                }
            break;
            case 2:
                    place_order();
					resetUnos();
					goto MENI;
                break;



            case 3:
                adminP_menu();
                resetUnos();
                goto MENI;
            break;

            case 4:
                admin_menu();
                pause();
                resetUnos();
                goto MENI;
            break;


            case 5:
            break;
        }

    return 0;
}

void odabir(int a)
{
    cout<<"\n************************************************************************"<<endl;
    cout<<"*                                                                      *"<<endl;
    cout<<"*\tVas odabir je "<<a<<".                                               *"<<endl;
    cout<<"*\tPritisnite ENTER za nastavak...                                *"<<endl;
    cout<<"*                                                                      *"<<endl;
    cout<<"************************************************************************"<<endl;
    pause();
}

void resetUnos()
{
    unos=0;
    unos1=0;
    unos2=0;
    unos3=0;
    unos4=0;
    unos5=0;
}


