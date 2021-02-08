#include <iostream>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

const int SIZE = 1000;

void zadanie1() 
{
  	ifstream liczby("liczby1.txt");
  	int tab[SIZE];
  	for (int i=0; i<SIZE; i++) liczby>>tab[i];
  	liczby.close();
  	int min=9999999;
  	int max=0;
  	for (int i=0; i<SIZE; i++) 
  	{
    	if(tab[i]<min) min=tab[i];
    	if(tab[i]>max) max=tab[i];
  	}
  	cout << "Najmniejsza: "<<min<<endl;
  	cout << "Najwieksza: "<<max<<endl;
}
void zadanie2() 
{
  	int tab[SIZE];
  	ifstream zbior("liczby2.txt");
  	for (int i=0; i<1000; i++) zbior>>tab[i];
  	zbior.close();
  	int lacznie=0, maxlacznie=0, pierwszy=0;
  	int maxpierwszy;
  	for (int i=1; i<SIZE; i++) 
	{
    	if (tab[i]>=tab[i-1]) 
		{
      		lacznie++;
      		if(pierwszy==0) 
			{
        		pierwszy=tab[i-1];
        		lacznie++;
      		}
    	}
    	else 
		{
      	if (lacznie>maxlacznie) 
		{
        	maxlacznie=lacznie;
        	maxpierwszy=pierwszy;
      	}
      	pierwszy=0;
      	lacznie=0;
    	}
  	}
  	cout<<"Pierwszy element: "<<maxpierwszy<<endl;
  	cout<<"Iloœæ elementow: "<<maxlacznie<<endl;
}

void zadanie3() 
{
  	int tab1[SIZE], tab2[SIZE];
  	ifstream zbior1("liczby1.txt");
  	ifstream zbior2("liczby2.txt");
  	for(int i=0; i<SIZE; i++) zbior1>>oct>>tab1[i];
  	for(int i=0; i<SIZE; i++) zbior2>>tab2[i];
  	zbior1.close();
  	zbior2.close();
  	int a=0, b=0;
  	for (int i=0; i<SIZE; i++) 
	{
    	if (tab1[i]==tab2[i]) a++;
    	if (tab1[i]>tab2[i]) b++;
  	}
  	cout<<"Liczb o tych samych wartosciach jest "<<a<<endl;
	cout<<"Liczba z pierwszego jest wieksza od liczby z drugiego pliku w "<<b<<" wierszach"<<endl;
}

void zadanie4() 
{
  	ifstream zbior("liczby2.txt");
  	int tab[SIZE];
  	for (int i=0; i<SIZE; i++) zbior>>tab[i];
  	int count6=0, count10=0;
  	int liczba;
  	for (int i=0; i<SIZE; i++) 
  	{
    	liczba=tab[i];
    	while(liczba) 
		{
      		if(liczba %10==6) count6++;
      		liczba/=10;
    	}
    	liczba=tab[i];
    	while(liczba) 
		{
      		if(liczba %8==6) count10++;
      		liczba/=8;
    	}
  	}
  	cout<<"W osemkowym: "<<count6<<endl;
   	cout<<"W dziesietnym: "<<count10<<endl;
}

int main(int argc, char** argv) {
	zadanie1();
	zadanie2();
	zadanie3();
	zadanie4();
	return 0;
}
