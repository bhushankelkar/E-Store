#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
using namespace std;
int i,n;
ifstream fin;
ofstream fout;
fstream fio;
void disp();
class stock
{
		char name[20],pass[10];
	float pr; int quant;

public:
	void get();
	void get2();
	void show();
    int stchk(char nm[30]);    
    void withd(int qty);
    void refil(int qty);
}st;
void stock::withd(int qty) //Withdrawing Stock and stock updated
{
	if(quant>=qty)
	{
		quant-=qty;
		cout<<"\n\nStock updated.\n";
		cout<<"\n\nTotal price to be paid:"<<pr*qty;
    }
	else 
	   cout<<"\n\nInsufficient stock";
	    getch();
		
	
}

void stock::refil(int qty) //Refills Stock
{
	
		quant+=qty;
		cout<<"\n\nStock updated.";
	    getch();
		
	
}
int stock::stchk(char nm[30])  //Checking the status of the stock
{
	if(strcmp(nm,name)==0)
	 return 0;
	else 
	return 1;
}
void stock::get()  //Entering a new product
{
	cin>>name>>pr>>quant;
	
}
void stock::get2()
{
	cin>>name>>quant;
}

void stock::show() //Displaying the columns
{
	
	cout<<"\n"<<name<<"\t\t\t"<<quant<<"\t\t\t"<<pr;
}
void addnew()  //Adding new products
{
     system("cls");
	cout<<"\nEnter the No. of Products that you wish to add: ";
    cin>>n;
	 if (n!=0)
    {
	
	int j,l,sum=0;
	fout.open("shop.dat",ios::binary|ios::app);  //Opening a binary file to store the deatils of the new product
	for(i=0;i<n;i++)
	{
	cout<<"\n\nInput the name, price and the quantity of item respectively\n\n";
	    st.get();
	    fout.write((char*)&st,sizeof(st));  //Writing to the file
        cout<<"\n\nitem updated";
		cin.get();
}
    cout<<"\n\nStock Updated!!";
    fout.close();
    cin.get();
    system("cls");
    disp();  //Displaying the updated stock
}

	else
{

	fout.close();
	cin.get();
	system("cls");
	cout<<"\n\nNo items to be added";

}
}
void withdraw()  //Buying a product
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the product's name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  
		  st.withd(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     
    
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    cin.get();
    system("cls");
	 disp(); 
	getch();
}
void disp() //Displaying the current stock available
{
	int i=1;
	cout<<"\n==================================================================";
	cout<<"\n\n=================\tTHE STOCK ITEMS ARE\t==================";
	cout<<"\n\n==================================================================\n";
	cout<<"\n\nPARTICULARS\tSTOCK AVAILABLE\t\t\t PRICE";
	cout<<"\n\n============================================================\n";	
	 fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	i=0; break;}
	     st.show();
	  }
     }
     if(i==0)
     {	cout<<"\n\n\t\t\t!!Empty record room!!";
	getch();
     }
     fin.close();
    
}
void refill() //Refilling the stock by a dealer
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the products name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  
		  st.refil(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    system("cls");
    cin.get();
	 disp(); cin.get();
    
	
}
void remove()  //Removing a product
{
	system("cls");	
	 int i=0;
     char temp[30];
     cout<<"\n\t\t\t\tDelete Record";
     cout<<"\n\nEnter the name of the product:";
     cin>>temp;
     fout.open("temp.dat",ios::binary);
     fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	    if(st.stchk(temp)==0)
	    {
		  st.show();
		  cout<<"\n\n\t\tRecord deleted";
		  i++;
	    }
	    else
		  fout.write((char*)&st,sizeof(st));
     }
     if(i==0)
       cout<<"\n\n!!Record not found!!";
     fin.close();
     fout.close();
     remove("shop.dat");
     rename("temp.dat","shop.dat");
}

int main()
{
	char pass[10],pass2[10];
	int i,j;
	cout<<"\t\t\t|============ WELCOME TO STORE MANAGEMENT ============|";
	getch();
	system("cls");
	cout<<"\n\t\t   STORE MANAGEMENT SYSTEM\n";	
	do{
	cout<<"=============================================================";
	cout<<"\n\n\t\t   1. Dealer Menu\n\n\t\t   2. Customer Menu\n\n\t\t   3. Employee Menu\n\n\t\t   4. Exit";
	cout<<"\n\n=============================================================\n";
	cout<<"\n\nEnter Your Choice:";
	cin>>j;
	switch(j)
	{
	  case 1: //Dealer Menu
    system("cls");
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
	for(int z=0;z<6;z++)
	{
		pass[z]=getch();
		system("cls");  //clears the screen
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*"; //Prints * for every character entered thereby emulating a real life software
		}
	}
	if(strcmp(pass,"dealer")==0) //Only if password matches access is granted
	{
    cout<<"\n\n\nCongrats!!Access Granted!!\n\n";
    do
	{
		cout<<"=================================================================";
	cout<<"\n\n\t\t\t    DEALER MENU\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Back to Main Menu:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	switch(i)
	{
		case 1:
		addnew();
		break;
		case 2:
		disp();
		break;	
        case 3:
		refill();
		break;
		break;	
	    case 4:
	    	remove();
	    	case 5:
	    		break;
   }
	
	}while(i!=5);
}
	else  //If strcmp fails(no authorisation granted)
	 {
	 	cout<<"\n\n\nAuthorised Personnel Only\n\n";
     }
	break;
     case 2: //Customer Menu
	do{
		cout<<"=================================================================";
	cout<<"\n\n\t\t\t    CUSTOMER MENU\n1. Purchase\n2. Display stock\n3. Back to Main Menu:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	switch(i)
	{
		case 1:
		withdraw();break;
	case 2:
	disp();break;
	case 3:
	break;	
	}
	}while(i!=3);
	break;
	case 3:
	system("cls");
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
	for(int z=0;z<3;z++)
	{
		pass2[z]=getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	if(strcmp(pass2,"emp")==0)
	{
		cout<<"\n\n\nCongrats!!Access Granted!!\n\n";
   do
	{
		cout<<"=================================================================";
	cout<<"\n\n\t\t\tEMPLOYEE MENU\n1. Display stock\n2. Refill\n3. Back to Main Menu"; //Employee Menu
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	switch(i)
	{
	 case 1:
	disp();break;
	case 2:
    refill();break;
	case 3:
	break;
	}
	}while(i!=3);
	}
	else
{
	cout<<"\n\nSorry!! Access Denied..\n\n";
	}
break;
case 4:
	break;
	default:
		cout<<"\n You have entered a wrong option";
}
}while(j!=4);
}
