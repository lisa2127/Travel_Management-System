/****headers****/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>

using namespace std;

void menu();

class ManageMenu{
	protected:
		string userName;
	public:
		ManageMenu(){
			system("color 0A"); //to change color of terminal
			cout<<"\n\n\n\n\n\n\t Enter your Name to continue as admin : ";
			cin>>userName;
			system("cls");
			menu();
		}
		~ManageMenu(){};
};

class Customers{
public:
	string name,gender,address,mobileNo;
	int age;
	static int cusID;
	char all[999];
	
	void getDetails(){
		
		ofstream out("old-customers.txt",ios::app);
		{
			cout<<"Enter Customer ID : ";
		    cin>>cusID;
		    cout<<"Enter Name : ";
		    cin>>name;
		    cout<<"Enter Age : ";
		    cin>>age;
		    cout<<"Enter Mobile Number : ";
		    cin>>mobileNo;
		    cout<<"Enter Address : ";
		    cin>>address;
		    cout<<"Enter Gender : ";
		    cin>>gender;
		}
		out<<"\nCustomer ID: "<<cusID<<"\nName: "<<name<<"\nAge: "<<age<<"\nMobile Number: "<<mobileNo<<
		"\nAddress: "<<address<<"\nGender: "<<gender<<endl;
		out.close();
		cout<<"\nSAVED \nNOTE: We saved your details for future purposes\n"<<endl;
		
	}
	
	void showDetails(){
		
		ifstream in("old-customers.txt");
		{
			if(!in){
				cout<<"File Error!"<<endl;
			}
			while(!(in.eof())){
				in.getline(all,999);
				cout<<all<<endl;
			}
			in.close();
		}
	}
};

int Customers::cusID;

class Cabs{
	public:
		int cabChoice;
		int kilometers;
		float cabCost;
		static float lastCabCost;
		
		void cabDetails(){
			
			cout<<"Welcome to the fastest,safest and smartest cab sevices "<<endl;
			cout<<"--------------URBAN CABS--------------\n"<<endl;
			cout<<"1.Rent a Standard Cab- Rs.15 per 1 KM"<<endl;
			cout<<"2.Rent a Luxury Cab- Rs.25 per 1 KM"<<endl;
			
			cout<<"\nTo calculate cost of your journey"<<endl;
			cout<<"Please enter which kind of cab you like : ";
			cin>>cabChoice;
			cout<<"Please enter kilometers you have to travel : ";
			cin>>kilometers;
			
			int hireCab;
			if(cabChoice==1){
				cabCost=kilometers*15;
				cout<<"\nThe tour fare is "<<cabCost<<" rupees for a Standarad Cab"<<endl;
				cout<<"Press 1 to book this cab : or ";
				cout<<"\nPress 2 to select the another cab : ";
				cin>>hireCab;
				
				system("cls");
				
				if(hireCab==1){
					lastCabCost=cabCost;
					cout<<"\nYou have successfully hired a standard cab"<<endl;
					cout<<"Go to menu an collect the receipt"<<endl;
				}
				else if(hireCab==2){
					cabDetails();
				}
				else{
					cout<<"Invalid Input! Redirecting to previous menu \nplease wait"<<endl;
					Sleep(999);
					system("cls");
					cabDetails();
				}
			}
			else if(cabChoice==2){
				cabCost=kilometers*25;
				cout<<"\nThe tour fare is "<<cabCost<<" rupees for a Luxury Cab"<<endl;
				cout<<"Press 1 to book this cab : or";
				cout<<"Press 2 ro select the another cab: ";
				cin>>hireCab;
				
				system("cls");
				
				if(hireCab==1){
					lastCabCost=cabCost;
					cout<<"\nYou have successfully hired a luxury cab"<<endl;
					cout<<"Go to menu an collect the receipt"<<endl;
				}
				else if(hireCab==2){
					cabDetails();
				}
				else{
					cout<<"Invalid Input! Redirecting to previous menu \nplease wait"<<endl;
					Sleep(1100);
					system("cls");
					cabDetails();
				}
			}
			else{
				cout<<"Invalid Input! Redirecting to Main menu \nplease wait"<<endl;
				Sleep(1100);
				system("cls");
				cabDetails();
				menu();
			}
			
			cout<<"\nPress 1 to redirect to main menu: "<<endl;
			cin>>hireCab;
			system("cls");
			if(hireCab==1){
				menu();
			}
			else{
				menu();
			}

		}
};
float Cabs::lastCabCost;

class Booking{
	
	public:
		int choiceHotel;
		int packageChoice;
		static float hotelCost;
		
		void hotels(){
			string hotelName[]={"Blue Paradise","Elephant Bay","Avenue Park"};
			 for(int i=0;i<3;i++){
			 	cout<<(i+1)<<". Hotel "<<hotelName[i]<<endl;
			 }
			 cout<<"Available Hotels"<<endl;
			 cout<<"Press any key to go back or Enter the number of hotel you want to book: ";
			 cin>>choiceHotel;
			 system("cls");
			 
			if(choiceHotel==1){
			 	cout<<"------- WELCOME TO HOTEL BLUE PARADISE -------\n"<<endl;
			 	cout<<"The garden,food and beverage.Enjoy all you can drink.Free WiFi and views of mountain.\n"<<endl;
				cout<<"Packages offered:\n "<<endl;
				cout<<"1.Standard Pack"<<endl;
				cout<<"\tAll basic facilities you need just for Rs.5000.00"<<endl;
				cout<<"2.Premium Pack"<<endl;
				cout<<"\tEnjoy Premium for Rs.10000.00"<<endl;
				cout<<"3.Luxury Pack"<<endl;
				cout<<"\tLive a Luxury life at Blue paradise at Rs.15000.00"<<endl;
				
				cout<<"\nPress another key to go back or Select the pacakage you want to book: ";
				cin>>packageChoice;
				
				if(packageChoice==1){
					hotelCost=5000.00;
					cout<<"\nYou have successfully booked Standard package at Blue Paradise"<<endl;
					cout<<"Go to menu and take receipt"<<endl;
				}
				else if(packageChoice==2){
					hotelCost=10000.00;
					cout<<"\nYou have successfully booked Premium package at Blue Paradise"<<endl;
					cout<<"Go to menu and take receipt"<<endl;
				}
				else if(packageChoice==3){
					hotelCost=15000.00;
					cout<<"\nYou have successfully booked Luxury package at Blue Paradise"<<endl;
					cout<<"Go to menu and take receipt"<<endl;
				}
				else{
					cout<<"Invalid Input! Redirecting to Main menu \nplease wait"<<endl;
				    Sleep(1100);
				    system("cls");
				    hotels();
				}
				
				int gotomenu;
				cout<<"\nPress 1 to redirect to main menu: ";
				cin>>gotomenu;
				system("cls");
				if(gotomenu==1){
					menu();
				}
				else{
					menu();
				}
				 
			 }
			else if(choiceHotel==2){
			 	cout<<"------- WELCOME TO HOTEL ELEPHANT BAY -------\n"<<endl;
			 	cout<<"Set in the tropical gardens on the banks of Maha Oya river. Enjoy Beautiful view of Elephants "<<endl;
				cout<<"Packages offered:\n "<<endl;
				cout<<"1.Family Pack"<<endl;
				cout<<"\tEnjoy time with your family for just Rs.15000.00"<<endl;
				cout<<"2.Couple Pack"<<endl;
				cout<<"\tEnjoy Couple pack for Rs.10000.00"<<endl;
				cout<<"3.Standard Pack"<<endl;
				cout<<"\tAll basic facilities you need just for Rs.5000.00"<<endl;
				
				cout<<"\nPress another key to go back or Select the pacakage you want to book: ";
				cin>>packageChoice;
				
				if(packageChoice==1){
					hotelCost=15000.00;
					cout<<"\nYou have successfully booked Family package at Elephant Bay"<<endl;
					cout<<"Go to menu and take receipt"<<endl;
				}
				else if(packageChoice==2){
					hotelCost=10000.00;
					cout<<"\nYou have successfully booked Couple package at Elephant Bay"<<endl;
					cout<<"Go to menu and take receipt"<<endl;
				}
				else if(packageChoice==3){
					hotelCost=5000.00;
					cout<<"\nYou have successfully booked Standard package at Elephant Bay"<<endl;
					cout<<"Go to menu and take receipt"<<endl;
				}
				else{
					cout<<"Invalid Input! Redirecting to Main menu \nplease wait"<<endl;
				    Sleep(1100);
				    system("cls");
				    hotels();
				}
				
				int gotomenu;
				cout<<"\nPress 1 to redirect to main menu: ";
				cin>>gotomenu;
				system("cls");
				if(gotomenu==1){
					menu();
				}
				else{
					menu();
				}
				 
			 }
			else if(choiceHotel==3){
			 	cout<<"------- WELCOME TO HOTEL AVENUE PARK-------\n"<<endl;
			 	cout<<"Your stay with us is what we cherish the most. #staywithus ";
			 	cout<<"Amazing offer in this Summer: 5000.00 for one day !!"<<endl;
			 	cout<<"\nPress another key to go back or Press 1 to book special package: ";
				cin>>packageChoice;
				if(packageChoice==1){
					hotelCost=5000.00;
					cout<<"\nYou have successfully booked Special package at Avenue Park"<<endl;
					cout<<"Go to menu and take receipt"<<endl;
				}
				else{
					cout<<"Invalid Input! Redirecting to Main menu \nplease wait"<<endl;
				    Sleep(1100);
				    system("cls");
				    hotels();
				}
				
				int gotomenu;
				cout<<"\nPress 1 to redirect to main menu: ";
				cin>>gotomenu;
				system("cls");
				if(gotomenu==1){
					menu();
				}
				else{
					menu();
				}
			 }
			 
			else{
					cout<<"Invalid Input! Redirecting to Main menu \nplease wait"<<endl;
				    Sleep(1100);
				    system("cls");
				    menu();
				 
				}
		}
};

float Booking::hotelCost;

class Charges:public Booking, Cabs, Customers
{
	public:
		void printBill(){
			ofstream outf("receipt.txt");
			{
				outf<<"-------------URBAN TRAVELS-------------"<<endl;
				outf<<"\n----------------Receipt----------------"<<endl;
				outf<<"_______________________________________"<<endl;
				
				outf<<"Customer ID : "<<Customers::cusID<<endl<<endl;
				outf<<"Description\t\tTotal"<<endl;
				outf<<"Hotel cost:\t\t"<<fixed<<setprecision(2)<<Booking::hotelCost<<endl;
				outf<<"Travel (Cab) cost:\t"<<fixed<<setprecision(2)<<Cabs::lastCabCost<<endl;
				
				outf<<"_______________________________________"<<endl;
				outf<<"Total Charge:\t\t"<<fixed<<setprecision(2)<<Booking::hotelCost+Cabs::lastCabCost<<endl;
				outf<<"_______________________________________"<<endl;
				outf<<"---------------THANK YOU---------------"<<endl;
			}
			outf.close();
		}
		
		void showBill(){
			ifstream inf("receipt.txt");
			{
				if(!inf){
					cout<<"File opening error!!"<<endl;
				}
				while(!(inf.eof())){
				    inf.getline(all,999);
				    cout<<all<<endl;
			    }
			}
			inf.close();
		}
};

void menu(){
	
	int mainChoice;
	int inChoice;
	int gotomenu;
	
	cout<<"\t\t      * URBAN TRAVELS *\n"<<endl;
	cout<<"----------------------------MAIN MENU----------------------------"<<endl;
	
	cout<<"\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
	cout<<"\t|\t\t\t\t\t|"<<endl;
	cout<<"\t|\tCustomer Management -> 1\t|"<<endl;
	cout<<"\t|\tCabs Management     -> 2\t|"<<endl;
	cout<<"\t|\tBooking Management  -> 3\t|"<<endl;
	cout<<"\t|\tCharges and Bills   -> 4\t|"<<endl;
	cout<<"\t|\tExit                -> 5\t|"<<endl;
	cout<<"\t|\t\t\t\t\t|"<<endl;         
	cout<<"\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|"<<endl;
	
	cout<<"\nEnter your Choice: ";
	cin>>mainChoice;
	system("cls");
	Customers a2;
	Cabs a3;
	Booking a4;
	Charges a5;
	if(mainChoice==1){
		cout<<"----CUSTOMERS----\n";
		cout<<"1.Enter as a new Customer"<<endl;
		cout<<"2.See Details of old customer"<<endl;
		
		cout<<"\nEnter choice: ";
		cin>>inChoice;
		system("cls");
		if(inChoice==1){
			a2.getDetails();
		}
		else if(inChoice==2){
			a2.showDetails();
		}
		else{
			cout<<"Invalid Input! Redirecting to Main menu \nplease wait"<<endl;
			Sleep(1100);
			system("cls");
			menu();
		}
		cout<<"\nPress 1 to redirect Main Menu: ";
		cin>>gotomenu;
		system("cls");
		if(gotomenu==1){
			menu();
		}
		else{
			menu();
		}
	}
	else if(mainChoice==2){
		a3.cabDetails();
	}
	else if(mainChoice==3){
		cout<<"--------Hotel BOOKING SYSTEM--------"<<endl;
		a4.hotels();
	}
	else if(mainChoice==4){
		cout<<"--------Get your Receipt--------"<<endl;
		a5.printBill();
		
		cout<<"your receipt is already printed you can get it from file path\n"<<endl;
		cout<<"to display your receipt on the screen press 1 or press any key to return back to main menu: "<<endl;
		cin>>gotomenu;
		if(gotomenu==1){
			system("cls");
			a5.showBill();
			cout<<"Press 1 to redirect to main menu: ";
			cin>>gotomenu;
			system("cls");
			
			if(gotomenu==1){
				menu();
			}
			else{
				menu();
			}
		}
		else{
			system("cls");
			menu();
		}
	}
	else if(mainChoice==5){
		cout<<"---GOODBYE---"<<endl;
		Sleep(999);
		system("cls");
		menu();
	}
	else{
		cout<<"Invalid Input! Redirecting to Main menu \nplease wait"<<endl;
		Sleep(1100);
		system("cls");
		menu();
	}
}


int main(){
	ManageMenu obj;
	return 0;
}
