#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<windows.h>

using namespace std;


class Hotel
{
protected:
    int roomno;
    char name[30];
    char address[50];
    char phoneno[20];
    char typeofroom[20];
    int days;
    float payable;
    float bill;
    int a, b, c;
    char rev[500];

public:
    void rooms_allocated();
    void feedback_and_reviews(char arr[]);
    float room_type();
    void showCustomerData();
    void to_get_customer_details_modify();
    void menu();
    void head();
    void get_review();

};

void Hotel::head()
{
    cout << "\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*|" << endl;
    cout << "\t\t\t\t\t\t\t|                                                  |" << endl;
    cout << "\t\t\t\t\t\t\t|             Hotel Management System              |" << endl;
    cout << "\t\t\t\t\t\t\t|                                                  |" << endl;
    cout << "\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*|" << endl;
}

void Hotel::showCustomerData()
{
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*|" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                                  |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                CUSTOMER DETAILS                  |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                                  |" << endl;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*|" << endl;
    cout << "\t\t\t\t\t\t\t\t                                                    " << endl;
    cout << "\t\t\t\t\t\t\t\t  Room No          : " << roomno << "               " << endl;
    cout << "\t\t\t\t\t\t\t\t  Name             : " << name << "                 " << endl;
    cout << "\t\t\t\t\t\t\t\t  Address          : " << address << "              " << endl;
    cout << "\t\t\t\t\t\t\t\t  Phone            : " << phoneno << "              " << endl;
    cout << "\t\t\t\t\t\t\t\t  Days to checkout : " << days << "                 " << endl;
    cout << "\t\t\t\t\t\t\t\t  Type             : " << typeofroom << "           " << endl;
    cout << "\t\t\t\t\t\t\t\t                                                    " << endl;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*|" << endl;
    cout << endl;
}

void Hotel::to_get_customer_details_modify()
{
    ofstream writer;
    writer.open("modify_all_file.txt", ios::out | ios::binary);
    cout << "Enter your name : ";
    cin.ignore();
    cin.getline(name, 29);
    cout << "Enter address : ";
    cin.getline(address, 49);
    cout << "Enter phone number : ";
    cin.getline(phoneno, 19);
    cout << "Enter No of days to checkout : ";
    cin >> days;
    cout << "Enter the type of room : ";
    float perdayprice = room_type();
    bill = days * perdayprice;

    writer.write((char*)this, sizeof(*this));
}

void Hotel::get_review()
{

}

void Hotel::feedback_and_reviews(char ph[20])
{
    ofstream writer;
    writer.open("reviewfeedback_file.txt", ios::app | ios::binary);
    ifstream reader("customer_info.txt", ios::in | ios::binary);

    reader.seekg(0);

    while (reader.read((char*)this, sizeof(*this)))
    {
        if (!strcmp(ph, phoneno))
        {
            cout << "\t\t\t\t\t\t\t\tPlease Enter the Room No you Stayed : ";
            cin >> roomno;
            cout << "\t\t\t\t\t\t\t\tPlease Enter your Name : ";
            cin.getline(name, 29);
            cout << "\t\t\t\t\t\t\t\tPlease rate us from [1-5] for the following services : ";
            cout << "\t\t\t\t\t\t\t\tAmbiance : ";
            cin >> a;
            cout << "\t\t\t\t\t\t\t\tCleanliness : ";
            cin >> b;
            cout << "\t\t\t\t\t\t\t\tBooking Experience : ";
            cin >> c;

            cout << endl;
            cout << "\t\t\t\t\t\t\t\tPlease write the review for us and mention if any improvemwent needed : " << endl;
            cout << "\t\t\t\t\t\t\t\t";
            cin.ignore();
            cin.getline(rev, 499);
            writer.write((char*)this, sizeof(*this));
        }
    }

    writer.close();
    reader.close();

    cout << "\t\t\t\t\t\t\t\tThank you for giving us review" << endl;
    _getch();
}



float Hotel::room_type()
{
    int a;
    cout << "\n\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|       Types of Room Available        |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t| 1.Standard    -   700  Rs per day    |" << endl;
    cout << "\t\t\t\t\t\t\t\t| 2.Deluxe      -   1000 Rs per day    |" << endl;
    cout << "\t\t\t\t\t\t\t\t| 3.Suite       -   1200 Rs per day    |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\tEnter Your Type : ";
    cin.ignore();
    cin >> a;
    switch (a)
    {
    case 1:
        strncpy_s(typeofroom, "Standard", 20);
        return 700;
        break;

    case 2:
        strncpy_s(typeofroom, "Deluxe", 20);
        return 1000;
        break;

    case 3:
        strncpy_s(typeofroom, "Suite", 20);
        return 1200;
        break;

    default:
        cout << "\t\t\t\t\t\t\t\tInvalid room type" << endl;
        cout << "\t\t\t\t\t\t\t\tEnter room type again, press a key to continue...";
        room_type();
        _getch();
        break;
    }
}

class Admin :public Hotel
{
private:
    string username;
    string password;

public:
    Admin()
    {
        username = "admin";
        password = "password";
    }
    void admin_menu();
    void admin_info();
    string getPassword();
    string getUsername();
    void room_booking();
    int check_room_available(int r);
    void display_room();
    void curr_records();
    void edit_room_info();
    void modify_records(int r);
    void delete_records(int r);
    void delete_all_records();
    void all_records();
    void rooms_allocated();
    void read_feedback_and_reviews();
    void admin_login_menu();
    void show_review();
};


void Admin::admin_menu()
{
    system("cls");
    while (1)
    {
        system("cls");
        head();
        cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
        cout << "\t\t\t\t\t\t\t\t|            ADMIN MENU                |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
        cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  1. Book a Room                      |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  2. Display a Room Info              |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  3. Display Rooms Alloted            |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  4. Display Current Guest Info       |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  5. Display All Guest Info till date |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  6. To Edit Room Info                |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  7. Read Feedback and Reviews        |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  8. Go Back to Main Menu             |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
        cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  Choose Option : [1/2/3/4/5/6/7/8}   |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
        cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
        cout << endl;

        int choice;
        char c = 'Y';
        cin >> choice;

        switch (choice)
        {
            system("cls");
        case 1:
            do {
                room_booking();
                cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
                cout << "\t\t\t\t\t\t\t\t|                                              |" << endl;
                cout << "\t\t\t\t\t\t\t\t|    Do you want to book another room ?(y/n)   |" << endl;
                cout << "\t\t\t\t\t\t\t\t|                                              |" << endl;
                cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*|" << endl;
                cin >> c;
            } while (c == 'y' || c == 'Y');
            cout << "\n\t\t\t\t\t\t\t\tThank you for Booking !!! " << endl;
            _getch();
            break;

        case 2:
            system("cls");
            display_room();
            break;

        case 3:
            system("cls");
            rooms_allocated();
            break;

        case 4:
            system("cls");
            curr_records();
            break;

        case 5:
            system("cls");
            all_records();
            break;

        case 6:
            system("cls");
            edit_room_info();
            break;

        case 7:
            system("cls");
            read_feedback_and_reviews();
            break;

        case 8:
            system("cls");
            menu();
            break;

        default:
            cout << "\n\t\t\tInvalid input " << endl;
            cout << "\t\t\tReturning to main menu " << endl;
            Sleep(5000);
            break;

        }
        _getch();
    }
}


void Admin::show_review()
{

}

void Admin::edit_room_info()
{
    system("cls");
    char c = 'Y';
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|             EDIT MENU                |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|  1. Delete a Room Info               |" << endl;
    cout << "\t\t\t\t\t\t\t\t|  2. Delete Room Info till date       |" << endl;
    cout << "\t\t\t\t\t\t\t\t|  3. Modify the Room Info             |" << endl;
    cout << "\t\t\t\t\t\t\t\t|  4. Back to ADMIN MENU               |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|    Choose Option : [1/2/3/4}         |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
        system("cls");
    case 1:
        do
        {
            delete_records(roomno);
            cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|" << endl;
            cout << "\t\t\t\t\t\t\t\t|                                               |" << endl;
            cout << "\t\t\t\t\t\t\t\t| Do you want to delete another Room Info?(y/n) |" << endl;
            cout << "\t\t\t\t\t\t\t\t|                                               |" << endl;
            cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-|" << endl;
            cin >> c;
        } while (c == 'y' || c == 'Y');
        cout << "\n\t\t\t\t\t\t\t\tDeleted Succesfully" << endl;
        _getch();
        system("cls");
        break;

    case 2:
        delete_all_records();
        break;

    case 3:
        do {
            modify_records(roomno);
            cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|" << endl;
            cout << "\t\t\t\t\t\t\t\t|                                               |" << endl;
            cout << "\t\t\t\t\t\t\t\t| Do you want to modify another Room Info?(y/n) |" << endl;
            cout << "\t\t\t\t\t\t\t\t|                                               |" << endl;
            cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-|" << endl;
            cin >> c;
        } while (c == 'y' || c == 'Y');
        cout << "\n\t\t\t\t\t\t\t\tModified Succesfully" << endl;
        _getch();
        system("cls");
        break;

    case 4:
        admin_menu();
        break;

    default:
        cout << "\n\t\t\t\t\t\t\t\tInvalid input " << endl;
        cout << "\t\t\t\t\t\t\t\tPress any key to return to ADMIN MENU " << endl;
        _getch();
        break;
    }
}

void Admin::read_feedback_and_reviews()
{
    system("cls");
    head();
    ifstream reader;
    reader.open("reviewfeedback_file.txt", ios::in | ios::binary);
    while (reader.read((char*)this, sizeof(*this)))
    {
        cout << "\t\t\t\t\t\t\t\tRoom No : " << roomno << endl;
        cout << "\t\t\t\t\t\t\t\tName : " << name << endl;
        cout << "\t\t\t\t\t\t\t\tAmbiance Rating : " << a << endl;
        cout << "\t\t\t\t\t\t\t\tCleanliness Rating : " << b << endl;
        cout << "\t\t\t\t\t\t\t\tBooking Experience : " << c << endl;
        cout << "\t\t\t\t\t\t\t\tReview : " << rev << endl;
    }
    reader.close();
}

void Admin::room_booking()
{
    system("cls");
    head();
    int r, flag;

    ofstream writer("customer_info.txt", ios::app | ios::binary);
    ofstream writer1("all_info.txt", ios::app | ios::binary);

    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*|" << endl;
    cout << "\t\t\t\t\t\t\t\t|                           |" << endl;
    cout << "\t\t\t\t\t\t\t\t|   Enter Customer Details  |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                           |" << endl;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*|" << endl;
    cout << "\n\t\t\t\t\t\t\t\tEnter Room No : ";
    cin >> r;
    cin.ignore();
    flag = check_room_available(r);
    if (flag)
    {
        cout << "\n\t\t\t\t\t\t\t\tSorry room is already booked" << endl;
    }
    else
    {
        roomno = r;
        head();
        cout << "\t\t\t\t\t\t\t\tEnter your Name : ";
        cin.getline(name, 29);
        cout << "\t\t\t\t\t\t\t\tEnter Address : ";
        cin.getline(address, 49);
        cout << "\t\t\t\t\t\t\t\tEnter Phone Number : ";
        cin.getline(phoneno, 19);
        cout << "\t\t\t\t\t\t\t\tNo of Days to Stay : ";
        cin >> days;

        float perdayprice = room_type();

        bill = days * perdayprice;

        writer.write((char*)this, sizeof(*this));
        writer1.write((char*)this, sizeof(*this));

        cout << "\n\t\t\t\t\t\t\t\tRoom is Booked " << endl;
    }

    cout << "\n\t\t\t\t\t\t\t\tPress any key to continue... " << endl;
    writer.close();
    writer1.close();
}

void Admin::admin_info()
{
    ofstream writer;
    writer.open("admin_info.txt", ios::out | ios::binary);
    writer.write((char*)this, sizeof(*this));
    writer.close();
}

string Admin::getPassword()
{
    return password;
}

string Admin::getUsername()
{
    return username;
}

int Admin::check_room_available(int r)
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


void Admin::display_room()
{
    system("cls");
    head();
    ifstream reader;
    reader.open("customer_info.txt", ios::in | ios::binary);
    int r, flag = 0;
    cout << "\n\t\t\t\t\t\t\t\tEnter room no: ";
    cin.ignore();
    cin >> r;
    while (!reader.eof())
    {
        reader.read((char*)this, sizeof(*this));
        if (roomno == r)
        {
            system("cls");
            cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*|" << endl;
            cout << "\t\t\t\t\t\t\t\t|                                                  |" << endl;
            cout << "\t\t\t\t\t\t\t\t|                CUSTOMER DETAILS                  |" << endl;
            cout << "\t\t\t\t\t\t\t\t|                                                  |" << endl;
            cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*|" << endl;
            cout << "\t\t\t\t\t\t\t\t                                                    " << endl;
            cout << "\t\t\t\t\t\t\t\t  Room No          : " << roomno << "               " << endl;
            cout << "\t\t\t\t\t\t\t\t  Name             : " << name << "                 " << endl;
            cout << "\t\t\t\t\t\t\t\t  Address          : " << address << "              " << endl;
            cout << "\t\t\t\t\t\t\t\t  Phone            : " << phoneno << "              " << endl;
            cout << "\t\t\t\t\t\t\t\t  Days to checkout : " << days << "                 " << endl;
            cout << "\t\t\t\t\t\t\t\t  Type             : " << typeofroom << "           " << endl;
            cout << "\t\t\t\t\t\t\t\t  Total Fare       : " << bill << "                 " << endl;
            cout << "\t\t\t\t\t\t\t\t                                                    " << endl;
            cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*|" << endl;
            cout << endl;
            flag = 1;
        }
    }

    if (flag == 0)
    {
        cout << "\n Sorry Room No not found or vacant";
    }
    cout << "\n\n Press any key to continue !!";
    reader.close();
}

void Admin::rooms_allocated()
{
    for (int i = 0; i < 2; i++)
    {
        system("cls");
    }
    head();
    ifstream reader("customer_info.txt", ios::in | ios::binary);
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|           Rooms Booked               |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;

    while (reader.read((char*)this, sizeof(*this)))
    {
        cout << "\n\t\t\t " << roomno << endl;
    }

    reader.close();
    cout << "\n\n\n\t\t\t\t\t\t\t\tPress any key to Continue....!!" << endl;
}


void Admin::curr_records()
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

void Admin::delete_records(int r)
{
    system("cls");
    head();
    ifstream reader;
    ofstream writer;
    int q;
    cout << "Enter room no:";
    cin >> q;
    reader.open("customer_info.txt", ios::in | ios::binary);
    writer.open("tempfile.txt", ios::app | ios::binary);

    while (!reader.eof())
    {
        reader.read((char*)this, sizeof(*this));
        if (q != roomno)
        {
            writer.write((char*)this, sizeof(*this));
        }
    }
    reader.close();
    writer.close();
    remove("customer_info.txt");
    rename("tempfile.txt", "customer_info.txt");
}


void Admin::all_records()
{
    system("cls");
    head();
    ifstream reader;
    reader.open("all_info.txt", ios::in | ios::binary);
    while (reader.read((char*)this, sizeof(*this)))
    {
        showCustomerData();
    }
    reader.close();

}

void Admin::delete_all_records()
{
    system("cls");
    head();
    ofstream writer;
    writer.open("tempfile_all.txt", ios::app | ios::binary);
    remove("all_info.txt");
    rename("tempfile_all.txt", "all_info.txt");
    writer.close();
}

void Admin::modify_records(int r)
{
    system("cls");
    head();
    int b;
    cout << "Enter room no: ";
    cin >> b;
    ifstream reader;
    ofstream writer;
    ifstream reader1;
    writer.open("temp2.txt", ios::out | ios::binary);
    reader.open("customer_info.txt", ios::in | ios::binary);
    reader1.open("customer_info.txt", ios::in | ios::binary);
    int count = 0;
    while (reader1.read((char*)this, sizeof(*this)))
    {
        if (b == roomno) {
            while (reader.read((char*)this, sizeof(*this)))
            {
                if (b != roomno)
                {
                    writer.write((char*)this, sizeof(*this));
                }
                else
                {
                    writer.close();
                    showCustomerData();
                    cout << "Change the details : " << endl;
                    to_get_customer_details_modify();
                    ifstream reader;
                    fstream readerwrite1;
                    reader.open("modify_all_file.txt", ios::in | ios::binary);
                    reader.read((char*)this, sizeof(*this));
                    readerwrite1.open("temp2.txt", ios::app | ios::binary);
                    readerwrite1.write((char*)this, sizeof(*this));
                    readerwrite1.close();
                    count++;
                }
            }
        }
        else {
            continue;
        }
    }
    reader1.close();
    reader.close();

    if (count == 1)
    {
        remove("customer_info.txt");
        rename("temp2.txt", "customer_info.txt");
    }

    ifstream reader2;
    ofstream writer1;
    ifstream reader3;
    writer1.open("temp1.txt", ios::out | ios::binary);
    reader2.open("all_info.txt", ios::in | ios::binary);
    reader3.open("all_info.txt", ios::in | ios::binary);
    int count1 = 0;
    while (reader3.read((char*)this, sizeof(*this)))
    {
        if (b == roomno) {
            while (reader2.read((char*)this, sizeof(*this)))
            {
                if (b != roomno)
                {
                    writer1.write((char*)this, sizeof(*this));
                }
                else
                {
                    writer1.close();
                    ifstream reader2;
                    fstream readerwrite2;
                    reader.open("modify_all_file.txt", ios::in | ios::binary);
                    reader.read((char*)this, sizeof(*this));
                    readerwrite2.open("temp1.txt", ios::app | ios::binary);
                    readerwrite2.write((char*)this, sizeof(*this));
                    readerwrite2.close();
                    count1++;
                }
            }
        }
        else {
            continue;
        }
    }
    reader2.close();
    reader3.close();

    if (count1 == 1)
    {
        remove("all_info.txt");
        rename("temp1.txt", "all_info.txt");
    }
}


class User :public Hotel
{
protected:
    string user_username;
    string user_password;
public:
    void user_info();
    void user_menu();
    void guest_check_in();
    void check_room_detail();
    void guest_check_out(int r);
    void delete_user_record(int r);
    void booked_room_details(int r);
};


void User::booked_room_details(int r)
{
    system("cls");
    head();
    ifstream reader;
    reader.open("customer_info.txt", ios::in | ios::binary);
    int y, flag = 0;
    cout << "\n\t\t\t\t\t\t\t\tEnter room no: ";
    cin.ignore();
    cin >> y;
    while (!reader.eof())
    {
        reader.read((char*)this, sizeof(*this));
        if (roomno == y)
        {
            system("cls");
            head();
            cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*|" << endl;
            cout << "\t\t\t\t\t\t\t\t|                                                  |" << endl;
            cout << "\t\t\t\t\t\t\t\t|                CUSTOMER DETAILS                  |" << endl;
            cout << "\t\t\t\t\t\t\t\t|                                                  |" << endl;
            cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*|" << endl;
            cout << "\t\t\t\t\t\t\t\t                                                    " << endl;
            cout << "\t\t\t\t\t\t\t\t  Room No          : " << roomno << "               " << endl;
            cout << "\t\t\t\t\t\t\t\t  Name             : " << name << "                 " << endl;
            cout << "\t\t\t\t\t\t\t\t  Address          : " << address << "              " << endl;
            cout << "\t\t\t\t\t\t\t\t  Phone            : " << phoneno << "              " << endl;
            cout << "\t\t\t\t\t\t\t\t  Days to checkout : " << days << "                 " << endl;
            cout << "\t\t\t\t\t\t\t\t  Type             : " << typeofroom << "           " << endl;
            cout << "\t\t\t\t\t\t\t\t  Total Fare       : " << bill << "                 " << endl;
            cout << "\t\t\t\t\t\t\t\t                                                    " << endl;
            cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*|" << endl;
            cout << endl;
            flag = 1;
        }
    }

    if (flag == 0)
    {
        cout << "\n Sorry Room No not found or vacant";
    }
    cout << "\n\n Press any key to continue !!";
    reader.close();
}


void User::delete_user_record(int r)
{
    system("cls");
    head();
    ifstream reader;
    ofstream writer;
    reader.open("customer_info.txt", ios::in | ios::binary);
    writer.open("tempfile.txt", ios::app | ios::binary);

    while (!reader.eof())
    {
        reader.read((char*)this, sizeof(*this));
        if (r != roomno)
        {
            writer.write((char*)this, sizeof(*this));
        }
    }
    reader.close();
    writer.close();
    remove("customer_info.txt");
    rename("tempfile.txt", "customer_info.txt");
}


void User::user_menu()
{
    system("cls");
    head();
    while (1)
    {
        int choice;
        cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
        cout << "\t\t\t\t\t\t\t\t|            USER MENU                 |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
        cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  1. Check-In                         |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  2. Check Room Details               |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  3. Check-Out                        |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  4. Exit                             |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
        cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
        cout << "\t\t\t\t\t\t\t\t|    Choose Option : [1/2/3/4}         |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
        cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
        cout << endl;
        cin >> choice;

        switch (choice)
        {
            system("cls");
        case 1:
            guest_check_in();
            break;

        case 2:
            booked_room_details(roomno);
            break;

        case 3:
            guest_check_out(roomno);
            break;

        case 4:
            menu();
            break;

        default:
            cout << "\t\t\t\t\t\t\t\tInvalid input " << endl;
            cout << "\t\t\t\t\t\t\t\tPress any key to return to main menu " << endl;
            _getch();
            break;

        }
        _getch();
    }

}

void User::guest_check_in()
{
    system("cls");
    head();
    Sleep(500);
    cout << "\t\t\t\t\t\t\t\tWelcome to HMS " << endl;
    char n[20], a[30];
    ifstream reader;
    ofstream writer;
    cout << "\t\t\t\t\t\t\t\tEnter your Phone No for booking confiramtion : ";
    cin.ignore();
    cin.getline(n, 19);
    cout << "\t\t\t\t\t\t\t\tEnter your Name for booking confirmation : ";
    cin.getline(a, 29);
    cout << "\t\t\t\t\t\t\t\tPlease Wait for a while..." << endl;
    cout << "\t\t\t\t\t\t\t\t..";
    Sleep(500);
    cout << "\t\t\t\t\t\t\t\t..";
    Sleep(500);
    cout << "\t\t\t\t\t\t\t\t..";
    Sleep(500);;
    cout << "\t\t\t\t\t\t\t\t.." << endl;
    Sleep(500);;
    cout << "\t\t\t\t\t\t\t\t.." << endl;
    reader.open("customer_info.txt", ios::in | ios::binary);
    int flag = 0;
    while (reader.read((char*)this, sizeof(*this)))
    {
        if (!strcmp(n, phoneno))
        {
            cout << "\t\t\t\t\t\t\t\tRoom No : " << roomno << endl;
            cout << "\t\t\t\t\t\t\t\tNo of Days: " << days << "days" << endl;
            cout << "\t\t\t\t\t\t\t\tTotal Amount : " << bill << endl;
            flag++;
        }
    }
    if (flag > 0)
    {
        float advance = 0;
        cout << "\t\t\t\t\t\t\t\tAmount to pay in advance : " << endl;
        cin >> advance;
        cout << "\t\t\t\t\t\t\t\tWelcome,We are delighted to have you as our guest. Enjoy your stay!" << endl;
        cout << bill << " " << advance << endl;
        payable = bill - advance;
        cout << "\t\t\t\t\t\t\t\tDue Amount : " << payable << endl;
        cout << "\t\t\t\t\t\t\t\tPress any key to continue " << endl;
        _getch();
        reader.close();
    }
    else
    {
        cout << "\t\t\t\t\t\t\t\tNo Room is Booked" << endl;
    }
}


void User::guest_check_out(int r)
{
    system("cls");

    char ph[20];

    cout << "\t\t\t\t\t\t\t\tEnter your Phone No : ";
    cin.ignore();
    cin.getline(ph,19);

    cout << "\t\t\t\t\t\t\t\tEnter your Name : ";
    cin.getline(name, 19);

    cout << "\t\t\t\t\t\t\t\tEnter your room no : ";
    cin.getline(name, 19);

    ofstream writer;
    writer.open("reviewfeedback_file.txt", ios::app | ios::binary);
    ifstream reader("customer_info.txt", ios::in | ios::binary);

    reader.seekg(0);

    while (reader.read((char*)this, sizeof(*this)))
    {
        if (!strcmp(ph, phoneno))
        {
            cout << "\t\t\t\t\t\t\t\tPlease rate us from [1-5] for the following services : ";
            cout << "\t\t\t\t\t\t\t\tAmbiance : ";
            cin >> a;
            cout << "\t\t\t\t\t\t\t\tCleanliness : ";
            cin >> b;
            cout << "\t\t\t\t\t\t\t\tBooking Experience : ";
            cin >> c;

            cout << endl;
            cout << "\t\t\t\t\t\t\t\tPlease write the review for us and mention if any improvemwent needed : " << endl;
            cout << "\t\t\t\t\t\t\t\t";
            cin.ignore();
            cin.getline(rev, 499);
            writer.write((char*)this, sizeof(*this));
        }
    }
    writer.close();
    reader.close();

    cout << "\t\t\t\t\t\t\t\tThank you for giving us review" << endl;
    _getch();

    delete_user_record(roomno);

    cout << "\n\t\t\t\t\t\t\t\tThankyou for  choosing us ! ";
    cout << "\n\t\t\t\t\t\t\t\tPlease visit again";
    _getch();
    cout << "]n\t\t\t\t\t\t\t\tPress any key to continue";

}

void Admin::admin_login_menu()
{
    ifstream reader;
    ofstream writer;
    string adminuname, adminpasswd;
    string useruname, userpasswd;
    char ch;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|           ADMIN LOGIN                |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << "\t\t\t\t\t\t\t\tEnter username: ";
    cin.ignore();
    getline(cin, adminuname);
    cout << "\t\t\t\t\t\t\t\tEnter password: ";
    ch = _getch();
    while (ch != 13) // Check for "Enter" key (key code 13)
    {
        adminpasswd.push_back(ch);
        cout << "*";
        ch = _getch();
    }
    reader.open("admin_info.txt", ios::in | ios::binary);
    while (!reader.eof())
    {
        if (adminpasswd == getPassword() && adminuname == getUsername())
        {
            cout << "\n\n\t\t\t\t\t\t\t\t| Verfiying Admin |\n";
            cout << "\t\t\t\t\t\t\t\t";
            for (int a = 1; a < 8; a++)
            {
                Sleep(500);
                cout << "...";
            }
            cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted..\n\n";
            cout << "\n\n\t\t\t\t\t\t\t\tPress any key to continue..";
            _getch();
            admin_menu();
            break;
        }
        else {
            cout << endl;
            cout << "\n\n\t\t\t\t\t\t\t\t| Verfiying Admin |\n";
            cout << "\t\t\t\t\t\t\t\t";
            for (int a = 1; a < 8; a++)
            {
                Sleep(500);
                cout << "...";
            }
            cout << endl;
            cout << "\n\t\t\t\t\t\t\t\tWrong Credentials" << endl;
            cout << "\t\t\t\t\t\t\t\tYou will be redirected to Main Menu..." << endl;
            Sleep(5000);
            menu();
            break;
        }
    }
    _getch();
    reader.close();
}


void Hotel::menu()
{
    User u;
    Admin a;
    system("cls");
    int n;
    char ch;
    char c = 'Y';
    int flag = 0;

    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|      HOTEL MANAGEMENT SYSTEM         |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|  1. ADMIN                            |" << endl;
    cout << "\t\t\t\t\t\t\t\t|  2. USER                             |" << endl;
    cout << "\t\t\t\t\t\t\t\t|  3. EXIT                             |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|    Choose Option : {1/2/3}           |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                      |" << endl;
    cout << "\t\t\t\t\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\tEnter Your Option : ";
    cin >> n;
    switch (n)
    {

    case 1:
        system("cls");
        a.admin_info();
        a.admin_login_menu();
        break;

    case 2:
        u.user_menu();
        break;

    case 3:
        cout << "\n\n\t\t\t\t\t\t\t\tThank you for using the application" << endl;
        exit(0);

    default:
        cout << "\t\t\t\t\t\t\t\tInvalid Input" << endl;
        exit(0);
    }
}

int main()
{
    Hotel h;
    h.menu();
    return 0;
}
