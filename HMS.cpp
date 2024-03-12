#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<windows.h>
 
using namespace std;

class Hotel
{
private:
	int roomno;
	char name[30];
	char address[50];
	char phoneno[20];
	char typeofroom[20];
	int days;
	float payable;
	float bill;
 
public:
 
	void menu();//shows all the options available
	void room_booking();
	void guest_check_in();
	int check_room_available(int r);
	void display_room();
	void rooms_allocated();
	//void guest_check_out();
	//void billing_and_invoice();//
	//void feedback_and_reviews();//giving guest to rate and give review 
	void all_records();
	void curr_records();//record of customer who are currently stayingin the hotel with room number
	void delete_records(int r);//delete checkout custmer records
	void delete_all_records();//delete all the records
    void modify_records(int r);
	float room_type();
	void showCustomerData();
    void to_get_customer_details_modify();
	void head();
};

void Hotel::head()
{
		cout<<"\n\t\t\t ----------------------------------";
		cout<<"\n\t\t\t      Hotel Management System      ";
		cout<<"\n\t\t\t ----------------------------------";
}

class Admin:public Hotel
{
    private:
     string username;
     string password;

     public:
     Admin()
     {
        username="Admin";
        password="password";
     }

     void admin_info();     
};

class User:public Hotel
{

};

void Admin::admin_info()
{
   ofstream writer;
   writer.open("admin_info.txt",ios::out|ios::binary);
   writer.write((char*)this,sizeof(*this));
   writer.close();
}

// void Admin::admin_info1()
// {
//    ifstream reader;
//    reader.open("admin_info.txt",ios::in|ios::binary);
//    while(reader.read((char*)this,sizeof(*this)))
//    {
// 	 cout<<username<<endl;
// 	 cout<<password;
//    }
//    reader.close();
// }

float Hotel::room_type()
{
	cout << "Types of room availabe are : " << endl;
	cout << "standard --> 700rs/night " << endl;
	cout << "deluxe --> 1000rs/night " << endl;
	cout << "suite --> 1200rs/night " << endl;
	cout << "enter room type " << endl;
	cin >> typeofroom;
 
	if (typeofroom == "standard")
	{
		return 700;
	}
	else if (typeofroom == "deluxe")
	{
		return 1000;
	}
	else
	{
		return 1200;
	}
}

void Hotel::menu()
{
	system("cls");
	int choice;
 
	while (1)
	{
		cout << "\t\t\t\t\t**********************************" << endl;
		cout << "\t\t\t\t\t**************MENU****************" << endl;
		cout << "\t\t\t\t\t**********************************" << endl;
 
		cout << "enter 1 for room booking" << endl;
		cout << "enter 2 for check in" << endl;
		cout << "enter 3 for display rooms" << endl;
		cout << "enter 4 for to check the alocated rooms" << endl;
		cout << "enter 5 to see current records" << endl;
		cout << "enter 6 for billing and invoice" << endl;
		cout << "enter 7 for feedback and review" << endl;
		cout << "enter 8 to see all guest list" << endl;
		cout << "enter 9 to delete records" << endl;
		cout << "enter 10 to delete all the records" << endl;
        cout << "enter 11 to modify the records" << endl;
		cout << "enter 12 to exit " << endl;
 
		int choice;
		cout << "please enter your choice" << endl;
		cin >> choice;
 
		switch (choice)
        {
			system("cls");
		case 1:
			room_booking();
			break;
 
		case 2:
			guest_check_in();
			break;
 
		case 3:
			display_room();
			break;
 
		case 4:
			rooms_allocated();
			break;
 
		case 5:
			curr_records();
			break;
 
			/*
		case 6:
			guest_check_out();
			break;
 
		case 7:
			billing_and_invoice();
			break;
 
		case 8:
			feedback_and_reviews();
			break;
        */
		case 8:
			all_records();
			break;

		case 9:
			delete_records(roomno);
			break;
 
		case 10:
		    delete_all_records();
		 	break;
        
        case 11:
		    modify_records(roomno);
		 	break;
 	
        case 12:
			cout << "Thankyou for using our service " << endl;
			_getch();
			exit(0);
 
		default:
			cout << "Invalid input " << endl;
			cout << "Press any key to return to main menu " << endl;
			_getch();
			break;
 
		}
        _getch();
	}
}


void Hotel::room_booking()
{
	system("cls");
	int r, flag;
 
	ofstream writer("customer_info.txt",ios::app|ios::binary);
    ofstream writer1("all_info.txt", ios::app | ios::binary);

	cout << "enter customer details " << endl;
	cout << "room no " << endl;
	cin.ignore();
	cin >> r;
	flag = check_room_available(r);
	if (flag)
	{
		cout << "\n Sorry room is already booked" << endl;
    }
	else
	{
		roomno = r;
		cin.ignore();
		cout << "enter your name " << endl;
		cin.getline(name, 29);
		cout << "enter address" << endl;
		cin.getline(address, 49);
		cout << "enter phone number " << endl;
		cin.getline(phoneno, 19);
		cout << "no of days to stay" << endl;
		cin >> days;
 
		float perdayprice = room_type();
 
		bill = days * perdayprice;

        writer.write((char*)this, sizeof(*this));
        writer1.write((char*)this, sizeof(*this));

        cout << "room is booked " << endl;
	}
 
	cout << "press any key to continue " << endl;
	writer.close();
    writer1.close();
 
}
 
 
void Hotel::guest_check_in()
{
	Sleep(500);
	cout << " welcome to grand hotel " << endl;
    char n[20],a[30];
    ifstream reader;
    ofstream writer;
    cout<<"Enter your phone no for booking confirmation";
    cin.ignore();
    cin.getline(n,19);
    cout<<"Enter your name for booking confirmation";
    cin.ignore();
    cin.getline(a,29);
	cout << "please wait we are checking the booking" << endl;
	cout << "..";
	Sleep(500);
	cout << "..";
	Sleep(500);
	cout << "..";
	Sleep(500);;
	cout << ".." << endl;
    reader.open("customer_info.txt",ios::in|ios::binary);
    while(!reader.eof())
    {
        reader.read((char*)this,sizeof(*this));
        if(!strcmp(n,phoneno))
        {
	     cout << "your room no is " << roomno << endl;
	     cout << "you have booked the hotel for " << days << "days" << endl;
	     cout << "your booking amount is --> " << bill << endl;
        }
    }
    float advance;
	cout << "enter amount you want to pay in advance" << endl;
	cin >> advance;
    cout << "here is your key " << endl;
    payable = bill - advance;
    cout << " total due amount is " << payable << endl;
    cout << "press any key to continue " << endl;
	reader.close();
}
 

int Hotel::check_room_available(int r)
{
	system("cls");
	cout << "entered" << endl;
	int flag = 0;
 
	ifstream reader;
	reader.open("customer_info.txt", ios::in | ios::binary);
 
	while (!reader.eof())
	{
		reader.read((char*)this, sizeof(*this));
		if (r == roomno)
		{
			flag = 1;
			break;
		}
	}
	reader.close();
	cout << "we are returning" << endl;
	return flag;
}
 

void Hotel::display_room()
{
	system("cls");
	head();
	ifstream fin;
	fin.open("customer_info.txt", ios::in | ios::binary);
	int r, flag = 0;
	cout << "\n Enter room no: ";
	cin.ignore();
	cin >> r;
	while (!fin.eof())
	{
		fin.read((char*)this, sizeof(*this));
		if (roomno == r)
		{
			system("cls");
			head();
			cout << "\nCustomer Details";
			cout << "\n ----------------";
			cout << "\n\n Room no : " << roomno;
			cout << "\n\n Name : " << name;
			cout << "\n\n Address : " << address;
			cout << "\n\n Phone : " << phoneno;
			cout << "\n\n Number of Days to checkout : " << days;
			cout << "\n\n Type of Room : " << typeofroom;
			cout << "\n\n Total Fare : " << bill;
			flag = 1;
		}
	}
 
	if (flag == 0)
	{
		cout << "\n Sorry Room No not found or vacant";
	}
	cout << "\n\n Press any key to continue !!";
	fin.close();
}
 
void Hotel::rooms_allocated()
{
	system("cls");
	head();
	ifstream fin("customer_info.txt", ios::in | ios::binary);
	cout << "\n\t\t\t List of Rooms Allocated";
	cout << "\n\t\t\t ------------------------" << endl;
 
	while (fin.read((char*)this, sizeof(*this)))
	{
		cout << "\n\t\t\t " << roomno << endl;
	}
 
	cout << "\n\n\n\t\t\tPress any key to continue....!!";
	fin.close();
}
 
 
void Hotel::curr_records()
{
	system("cls");
	head();
	ifstream reader;
	reader.open("customer_info.txt", ios::in | ios::binary);
	while (reader.read((char*)this, sizeof(*this)))
	{
        showCustomerData();
	}
	reader.close();
}
 

void Hotel::showCustomerData()
{
	cout << "\nCustomer Details";
	cout << "\n ----------------";
	cout << "\n\n Room no : " << roomno;
	cout << "\n\n Name : " << name;
	cout << "\n\n Address : " << address;
	cout << "\n\n Phone : " << phoneno;
	cout << "\n\n Number of Days to checkout : " << days;
	cout << "\n\n Type of Room : " << typeofroom;
}
 


void Hotel::delete_records(int r)
{
    ifstream reader;
    ofstream writer;
    int q;
    cout<<"Enter room no:";
    cin>>q;
	reader.open("customer_info.txt", ios::in | ios::binary);
    writer.open("tempfile.txt", ios::app | ios::binary);
 
	while (!reader.eof())
    {
        reader.read((char *) this,sizeof(*this));
        if (q != roomno)
      {
           writer.write((char*)this, sizeof(*this));
      }
    }
   reader.close();
   writer.close();
   remove("customer_info.txt");
   rename("tempfile.txt", "customer_info.txt");
   cout<<"Deletion successful";
 }


void Hotel::all_records()
{
    system("cls");
	head();
	ifstream reader;
	reader.open("all_info.txt", ios::in | ios::binary);
	while (reader.read((char*)this,sizeof(*this)))
	{
		showCustomerData();
	}
	reader.close();
 
}

void Hotel::delete_all_records()
{
    ofstream writer;
    writer.open("tempfile_all.txt",ios::app|ios::binary);
    remove("all_info.txt");
    rename("tempfile_all.txt","all_info.txt");
    writer.close();
}

void Hotel::modify_records(int r)
{
    system("cls");
    int b;
    cout<<"Enter room no: ";
    cin>>b;
    fstream readwrite;
    readwrite.open("customer_info.txt",ios::in|ios::out|ios::ate|ios::binary);
    readwrite.seekg(0);
    while(!readwrite.eof())
    { 
	  readwrite.read((char*)this,sizeof(*this));
      if(b==roomno)
      {
          showCustomerData();
          cout<<"Change the details";
          to_get_customer_details_modify();
          readwrite.seekp(readwrite.tellp() - sizeof(*this)); 
          readwrite.write((char*)this,sizeof(*this));
	   cout<<"\n Record is modified....!!";
	   break;
      } 
    }
	readwrite.close();
}

void Hotel::to_get_customer_details_modify()
{
       cout << "Enter your name : ";
	cin.ignore();
       cin.getline(name, 29);
	cout << "Enter address : ";
	cin.getline(address, 49);
	cout << "Enter phone number : ";
	cin.getline(phoneno, 19);
	cout << "Enter No of days to checkout : ";
	cin>>days;
	cout << "Enter the type of room : ";
	float perdayprice = room_type();
       bill = days * perdayprice;
}


int main()
{
    Hotel h;
	Admin a;
	a.admin_info();
	// a.admin_info1();
	
	h.menu();
 
	return 0;
}
