#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<conio.h>

using namespace std;

class Services
{
private:
    string service_name;	
public:
	int r_total, s_total, g_total, w_total;	
	//these are set as public because they will be used in another class through aggregation
	Services(): r_total(0), s_total(0), g_total(0), w_total(0)
	{	}
	//default constructor to initialize data members
	void room_service()
	{
     	int Price[4], no[4], quantity[4], tot[4],types, a=0, b=0, c=0, d=0;
     	string item[4];
     	service_name = "Room Service";

		cout<<"\n\t                     MENU CARD       "<<endl;
        cout<<"\t-----------------------------------------------------"<<endl;
        cout<<"\t NO.              MENU                    PRICE in Rs"<<endl;
        cout<<"\t  1               Pepperoni Pizza             700"<<endl;
        cout<<"\t  2               Cheeseburger                400"<<endl;
        cout<<"\t  3               Iced Coffee                 350"<<endl;
        cout<<"\t  4               Orange Juice                150"<<endl;    
        cout<<"\t------------------------------------------------------"<<endl;
		       
		cout<<"\nHow many items do you want to order?: ";
		cin>>types; 
		
		if(types>0 && types<=4)
		//condition to check if the inputted number is within range
		{					 
			for(int i = 0; i<types; i++) 
			{
				cout<<"\nEnter your choice "<<i+1<<" : ";
				cin>>no[i];
				cout<<"Enter quantity: ";
				cin>>quantity[i];
				
			    if (no[i]==1){
					item[i]="Pepperoni Pizza";
					Price[i]=700;
					tot[i]=Price[i]*quantity[i];
					a =+ tot[i];
			 	}
			 	else if (no[i]==2){
					item[i]="Cheeseburger";
					Price[i]=400;
					tot[i]=Price[i]*quantity[i];
					b =+ tot[i];
			 	}
			 	else if (no[i]==3){
					item[i]="Iced Coffee";
					Price[i]=350;
					tot[i]=Price[i]*quantity[i];
					c =+ tot[i];
			 	}
			 	else if (no[i]==4){
					item[i]="Orange Juice";
					Price[i]=150;
					tot[i]=Price[i]*quantity[i];
					d =+ tot[i];
			 	}
				cout<<"\n"<< quantity[i] <<" "<< item[i] <<endl;
		    }
			r_total = a+b+c+d;    
			cout<<"\nTotal price: "<< r_total <<" Rs."<<endl;   
     	}
     	
		else
		{
			cout<<"\nItem not available in menu \nTry again\n"<<endl;
		}	
	}
	
	void spa()
	{
		service_name = "Spa";
		string timings;
		cout<<"\n\t         SPA TIMINGS        "<<endl;
		cout<<"\n\t\tPrice: 1000Rs \n\t      Duration: 2 hours \n\t     Timings: Open 24/7! "<<endl;
		cout<<"\nBook time: ";
		cin>>timings;
		cin.sync();
		cout<<"\nSlot for " << timings << " booked!\n"<<endl;
		s_total = 1000;
	}
	
	void wifi()
	{
		string access;
		service_name = "Wifi";
		cout<<"\nGet access to wifi for Rs 200! "<<endl;
		cout<<"y/n: ";
		cin>>access;
		
		if(access=="y" || access=="Y")
		{
			cout<<"\n-------------------------"<<endl;
			cout<<"  ID: Crown&Garter \n  Password: h0t3lw1f1 \n-------------------------";
			cout<<"\n\nPrice: 200Rs \n\nEnjoy!"<<endl;
			w_total = 200;
		}
		else
		{
			cout<< "\nNo access to wifi.";
		}
	}
	
	void gym()
	{
		int duration;
		string timings;
		service_name = "Gym";
		cout<<"\n\t\t  GYM TIMINGS"<<endl;
		cout<<"\n\t     Price: 200Rs per hour \n\t  Timings: Open at all times "<<endl;
		cout<<"\nBook time: ";
		cin>>timings;
		cin.sync();
		cout<<"Enter time duration in hours: ";
		cin>> duration;
		g_total = duration*200;
		cout<<"Total price: "<< g_total <<"Rs"<<endl;
		cout<<"\nBooked!"<<endl;
	}
	
	void book_service()
	{	
		int option;
		cout << "\nSelect a service: \n\n1. Room service \n2. Spa \n3. Wifi \n4. Gym \n\n";
		cout << "Choose an option: ";
    	cin >> option;	
	    switch(option)  
	    {
	    	case 1:
	            room_service();
			    break;	
	        
	        case 2:
				spa();
				break;
				
			case 3:
				wifi();
				break;
			
			case 4:
				gym();
				break;
			
			default:
				cout << "Invalid option, please try again!" << endl;
				book_service();
					
		}
   } 
};

class Room{
private:
	string room_type = "Suite";
	int no_of_beds = 2;
public:
	int no_of_rooms = 16, room_charges = 15000;
	int room[20] = {0}; //array initialized to 0 which means all rooms are available
	
	void room_availabilty()
	{
		int i;
		cout << "\nThe following rooms are available: \n" << endl;
		for(i=1; i <= no_of_rooms; i++)
		{
			if(room[i-1]==0)
			//if value is 1 then that means that the room is unavailable
				cout << "Room " << i <<"  \t" << room_type << "\t\t" << no_of_beds << " beds" << endl;
		}
	}
	
	void add_room()
	{
		no_of_rooms += 1;
		cout << "Enter room type (bedroom/suite): ";
		cin >> room_type;
		cout << "Enter number of beds: ";
		cin >> no_of_beds;
		cout << "\nRoom successfully added!!" << endl;
	}
};

class Admin{
private:
	const string username="user", password="password"; 
	// constant username and password
public:
	Room r1;
	void login()
	{
		string user, pw;
		cout << "\n\nLOG IN:" << endl;
		cout << "\nEnter username: ";
		cin >> user;
		cout << "Enter password: ";
		cin >> pw; 
		
		if (username!=user || password!=pw)
		//to check if the inputted username and password is correct or not
		{
			cout << "Wrong info, please try again!" << endl;
			login();
		}
		else 
		{
			cout << "\nYou're logged in!" << endl;
		}
	}
	
	void view_customer_reviews()
	// to read customer feedback from the file
	{	
		fstream file;
		int MAX=200;
		char str[MAX];
		file.open("Hotel_Feedback.txt");
		while(!file.eof())
		{
			file.getline(str,MAX);
			cout << str << endl;
		}
		file.close();
	}
	
	void view_customer_record()
	// to read customer records from the file
	{	
		fstream File;
		int MAX=300;
		char str[MAX];
		File.open("Hotel_Customers.txt");
		while(!File.eof())
		{
			File.getline(str,MAX);
			cout << str << endl;
		}
		File.close();
	}
	
	void admin_menu()
	{
		int option;
		cout << "\n\n\n\t\t\t     ADMIN MENU: " << endl;
		cout << "\n\n\t\t\t 1. View Available Rooms" << endl;
		cout << "\t\t\t 2. Add rooms " << endl;
		cout << "\t\t\t 3. Customer Record " << endl;
		cout << "\t\t\t 4. View Customer Feedback " << endl;
		cout << "\t\t\t 5. Exit " << endl;
		cout << "\n\n\t\t\t Choose an option: " ;
		cin >> option;
		switch (option)
		{
			case 1:
				r1.room_availabilty();
				cout << "\n\t\t\tPress any key to continue" << endl;
				getch();
				admin_menu();
				break;
			
			case 2:
				r1.add_room();
				cout << "\n\t\t\tPress any key to continue" << endl;
				getch();
				admin_menu();
				break;
			
			case 3:
				view_customer_record();
				cout << "\n\t\t\tPress any key to continue" << endl;
				getch();
				admin_menu();
				break;
				
			case 4:
				view_customer_reviews();
				cout << "\n\t\t\tPress any key to continue" << endl;
				getch();
				admin_menu();
				break;
			
			case 5:
				break;
			
			default:
				cout << "\n\t\t\tIncorrect option! Please try again." << endl;
				admin_menu();
				break;
		}
	}
};

class Guest{
private:
	string guest_name, telephone;
	int duration = 0, guest_ID;
public:
	Room r1;
	Services s1;
	
	void bill_payment(Services s1)
   {    
   		int GRAND_TOTAL=0;
        string Card_no, CVV; 
 	    cout<<"\n\t\t           BILL                     "<<endl;
	    cout<<"------------------------------------------------------------------"<<endl;
	    cout<<"Name:      " <<guest_name<<endl;
	    cout<<"Telephone: " <<telephone<<endl;
	    cout<<"Guest_ID:  " <<guest_ID<<endl;
	    cout<<"------------------------------------------------------------------"<<endl;
	    cout<<"\t   DESCRIPTION                    AMOUNT   \n "<<endl;
	    cout<<"\t   Room charges        :          " << duration * r1.room_charges <<" Rs"<<endl;
		cout<<"\t   Room service        :          " << s1.r_total <<" Rs"<<endl;
		cout<<"\t   Wifi service        :          " << s1.w_total <<" Rs"<<endl;
		cout<<"\t   Spa        	       :          " << s1.s_total <<" Rs"<<endl;
		cout<<"\t   Gym                 :          " << s1.g_total <<" Rs"<<endl;
		cout<<"------------------------------------------------------------------"<<endl;
		GRAND_TOTAL = s1.r_total + s1.s_total + s1.w_total + s1.g_total + duration*r1.room_charges; 
		cout<<"\t\t\t     GRAND TOTAL: PKR " << GRAND_TOTAL <<endl;
		cout<<"------------------------------------------------------------------"<<endl;
		cout<<"\n\t  CREDIT DETAILS:\n";
    	cout<<"\nCard number: "; cin>> Card_no;
    	cout<<"CVV code: ";  cin>> CVV;
    	cout<< "\n\nPKR " << GRAND_TOTAL << " has been debited from your account!" << endl;
    	cout<<"------------------------------------------------------------------";
    	cout<<"\n\nThank you for visiting!";
	}
	
	void check_out()
	{
		int r;
		cout << "\nEnter room number: ";
		cin >> r;
		if (r>0 && r<r1.no_of_rooms)
		{
			if (r1.room[r-1]==0)
			{
				cout << "\nRoom is already vacant, please try again!" << endl;
				check_out();
			}
			else
			{
				r1.room[r-1]=0;
				cout << "\nCustomer at room " << r << " has been checked out!!\n" << endl;
			}
		}
		else
		{
			cout << "\nRoom doesn't exist, please try again!" << endl;
			check_out();
		}
	}
	
	void feedback()
	{
		int star;
		string review;
		cout << "\nEnter your name: ";
		cin >> guest_name;
		cin.sync();
		cout << "\nEnter your rating out of 5: ";
		cin >> star;
		if (star<1 || star>5)
		{
			cout << "Invalid, please try again!" << endl;
			feedback();
		}
		else
		{
			cout << "\nEnter review: ";
			cin >> review;
			cin.sync();
			cout << "\nThank you for your feedback!" << endl;
			
			fstream file;
			file.open("Hotel_Feedback.txt", ios::app);
			file << "\nName: "<< guest_name << endl;
			file << "Rating: " << star << "/5 stars" << endl;
			file << "Review: " << review << endl;
			file.close();
		}
	}

	void book_room()
	{
		int r;
		cout << "\nEnter room number: ";
		cin >> r;
		if (r>=1 && r <= r1.no_of_rooms)
		//condition to check if room exists 
		{
		
			if (r1.room[r-1]==0)
			//condition to check if room is available
			{
				cout << "Enter Name: " ;
				cin >> guest_name;
				cin.sync();
				cout << "Enter Phone Number: " ;
				cin >> telephone;
				cout << "Enter duration of stay (in days): ";
				cin >> duration;	
				srand(time(0));
				guest_ID = rand();
				cout << "Your Guest ID is " << guest_ID << endl;
				r1.room[r-1]=1; // mark room as booked
				cout << "\nRoom is booked!!";
			}
			else
			{
				cout << "Sorry, room is already booked!" << endl;
				book_room();
			}
		}
		
		else
		{
			cout << "\nRoom doesn't exit. Please try again!\n" << endl;
			book_room();
		}
		fstream File;
		File.open("Hotel_Customers.txt", ios::app);
		// Write guest info in file
		File << "\nRoom Number: " << r << endl;
		File << "Name: " << guest_name << endl;
		File << "Phone Number: " << telephone << endl;
		File << "Duration of stay: " << duration << " days" << endl;
		File << "Guest ID: " << guest_ID << endl;
		File.close();
	} 
	
	void guest_menu()
	{
		int option;
		cout << "\n\n\n\t\t\t     GUEST MENU: " << endl;
		cout << "\n\n\t\t 1. Book a Room" << endl;
		cout << "\t\t 2. Check Room Availability " << endl;
		cout << "\t\t 3. Book a Service " << endl;
		cout << "\t\t 4. Check Out " << endl;
		cout << "\t\t 5. Generate bill " << endl;
		cout << "\t\t 6. Give Feedback " << endl;
		cout << "\t\t 7. Exit " << endl;
		cout << "\n\n\t\t\t Choose an option: " ;
		cin >> option;
		switch (option)
		{
			case 1:
				book_room();
				cout << "\n\t\t\tPress any key to continue" << endl;
				getch();
				guest_menu();
				break;
			
			case 2:
				r1.room_availabilty();
				cout << "\n\t\t\tPress any key to continue" << endl;
				getch();
				guest_menu();
				break;

			case 3:
				s1.book_service();
				cout << "\n\t\t\tPress any key to continue" << endl;
				getch();
				guest_menu();
				break;

			case 4:
				check_out();
				cout << "\n\t\t\tPress any key to continue" << endl;
				getch();
				guest_menu();	
				break;
			
			case 5:
				bill_payment(s1);
				cout << "\n\t\t\tPress any key to continue" << endl;
				getch();
				guest_menu();	
				break;
			
			case 6:
				feedback();
				cout << "\n\t\t\tPress any key to continue" << endl;
				getch();
				guest_menu();	
				break;
			
			case 7:
				break;
			
			default:
				cout << "\n\t\t\tIncorrect option! Please try again." << endl;
				guest_menu();
				break;
		}
	}
	
	
};

class Hotel{
private:
	string hotel_name = "Crown & Garter Hotel", address = "132 Wolf Street, London";
	string hotel_email = "crown&garter@email.com", contact = "091654735";
public:
	Admin a1;
	Guest g1;
	void Welcome()
	{
		cout << "\n\t\t Welcome to " << hotel_name << "!!!" << endl;
		cout << "\t\t  Address: " << address << endl;
		cout << "\t\t   Email: " << hotel_email << endl;
		cout << "\t\t\t Contact: " << contact << endl;
	}
	
	void main_menu()
	{
		int option;
		cout << "\n\n\n\t\t\t     MAIN MENU: " << endl;
		cout << "\n\n\t\t\t 1. Admin" << endl;
		cout << "\t\t\t 2. Guest " << endl;
		cout << "\n\n\t\t\t Choose an option: " ;
		cin >> option;
		if (option==1)
		{
			a1.login();
			a1.admin_menu();
		}
		else if (option==2)
		{
			g1.guest_menu();
		}
		else
		{
			cout << "\n\t\t\t\t\t\t Incorrect option. " ;
			main_menu();
		}
	}
};

int main()
{
	Hotel Crown;
	Crown.Welcome();
	Crown.main_menu();
}
