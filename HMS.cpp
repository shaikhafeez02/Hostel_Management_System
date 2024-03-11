/*
       Title : Hotel Management System

*/

#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void head()
{
  system("cls");
  cout<<"\n\t\t\t\t************Grand City Hotel************"<<endl;
}

class Hotel
{
    private:
     int room_no;
     char name[30];
     char address[50];
     char phone[15];
     char type_of_room[20];
     int days;
     float fare;
    
    public:
      void menu();
      void book_room();
      int check_room_avail(int r);
      void display_room();
      void rooms_allocated();
      void change_customer_details();
};

void Hotel::menu()
{
    system("cls");
    int choice;
    while(1){
    system("cls");
    head();
    cout<<"\n\t\t\t\t***************";
    cout<<"\n\t\t\t\t***MENU***";
    cout<<"\n\t\t\t\t***************";
    cout<<"\n\t\t\t\t1.Book a Room";
    cout<<"\n\t\t\t\t2.Display Room Details";
    cout<<"\n\t\t\t\t3 Rooms Allocated List.";
    cout<<"\n\t\t\t\t4.Exit"<<endl;
    cout<<"\n\t\t\t\tEnter your choice: ";
    cin>>choice;
    switch (choice)
      {
       case 1:
       book_room();
       break;
      
       case 2:
       display_room();
       break;

       case 3:
       rooms_allocated();
       break;

       case 4:
        cout<<"\n\t\t\t\tThank you for using this application";
        cout<<"\n\t\t\t\tPress any key to exit";
        getch();
        exit(0);

       default:
          cout<<"\n\t\t\t\tInvalid Input !!!";
          cout<<"\n\t\t\t\tPress any Key to return main menu...."<<endl;
          break;
        }
        getch();
  }   
}

void Hotel::book_room()
{ 
    system("cls");
    head();
    int r,flag;
    ofstream fout("rooms_info.txt",ios::app|ios::binary);
    cout<<"\n Enter Customer Details: ";
    cout<<"\n\nRoom no: ";
    cin.ignore();
    cin>>r;
    flag=check_room_avail(r);
    if(flag)
    {
      cout<<"\n Sorry Room is already booked";
    }
    else
    {
      room_no=r;
      cin.ignore();
      cout<<"Name: ";
      cin.getline(name,29);
      cout<<endl;
      cout<<"Address: ";
      cin.getline(address,49);
      cout<<endl;
      cout<<"Phone: ";
      cin.getline(phone,14);
      cout<<endl;
      cout<<"No of days to checkout: ";
      cin>>days;
      cout<<endl;
      cout<<"Types of room Available : "<<endl;
      cout<<" Standard  - Rs.700 per night"<<endl;
      cout<<" Deluxe  - Rs.900 per night"<<endl;
      cout<<" Suite - Rs.1200 per night"<<endl;
      cout<<"Enter the type of room : ";
      cout<<endl;
      cin.ignore();
      cin.getline(type_of_room,19);
      if(type_of_room=="Standard")
      {
        fare=days*700;
      }
      else if(type_of_room=="Deluxe")
      {
        fare=days*900;
      }
      else{
        fare=days*1200;
      }

      fout.write((char*)this,sizeof(*this));
      cout<<"\n Room is booked...!!!";
    }
    cout<<"\n Press any key to continue...!!";
    fout.close();
}

int Hotel::check_room_avail(int r)
{
    system("cls");
    int flag=0;
    ifstream fin;
    fin.open("rooms_info.txt",ios::in|ios::binary);
    while(!fin.eof())
    {
      fin.read((char*)this,sizeof(*this));
      if(room_no==r){
         flag=1;
         break;
      }
    }
    fin.close();
    return flag;
}


void Hotel::display_room()
{
     system("cls");
     head();
     ifstream fin;
     fin.open("rooms_info.txt",ios::in|ios::binary);
     int r,flag=0;
     cout<<"\n Enter room no: ";
     cin.ignore();
     cin>>r;
     while(!fin.eof())
     {
       fin.read((char*)this,sizeof(*this));
       if(room_no==r)
       {
          system("cls");
          head();
          cout<<"\nCustomer Details";
          cout<<"\n ----------------";
          cout<<"\n\n Room no : "<<room_no;
          cout<<"\n\n Name : "<<name;
          cout<<"\n\n Address : "<<address;
          cout<<"\n\n Phone : "<<phone;
          cout<<"\n\n Number of Days to checkout : "<<days;
          cout<<"\n\n Type of Room : "<<type_of_room;
          cout<<"\n\n Total Fare : "<<fare;
          flag=1;
        }
     }

     if(flag==0)
     {
       cout<<"\n Sorry Room No not found or vacant";
     }
       cout<<"\n\n Press any key to continue !!";
       fin.close();
}

void Hotel::rooms_allocated()
{
  system("cls");
  head();
  ifstream fin("rooms_info.txt",ios::in|ios::binary);
  cout<<"\n\t\t\t List of Rooms Allocated";
  cout<<"\n\t\t\t ------------------------"<<endl;

  while(fin.read((char*)this,sizeof(*this)))
  {
    cout<<"\n\t\t\t "<<room_no<<endl;
  }

  cout<<"\n\n\n\t\t\tPress any key to continue....!!";
  fin.close();
}


int main()
{
    Hotel h;
    string username,password;
    system("cls");
    head();
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
    cout<<"Connecting to Server..."<<endl;
    Sleep(5000);
    system("cls");
    h.menu(); 
    return 0;
}


