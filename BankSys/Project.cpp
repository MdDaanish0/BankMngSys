
#include <iostream>
#include <windows.h>
#include <sstream>
#include <time.h>
#include <string>
#include "Avl.h"
#include "Linked_List.h"
using namespace std;

int main();
struct node *root = NULL;
int sleep_value =130;
int admin_pswd= 1122;
int staff_pswd= 2233;

int create_Acc()
{
  //Declared Variables
  string full_name;
  string cnic;
  string Acc_type;
  char g;
  int acc_no;
  int pin;
  long long Balance;
  int load=0;
  int a=1;
  //END Declared Variables
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<""<<endl;
  cout<<"                                                 Create User Account"<<endl;
  cout<<" "<<endl;
  cout<<"                                            Enter Customer's Full Name : ";cin.ignore();getline(cin,full_name);
  cout<<" "<<endl;
  cout<<"                                            Enter CNIC (xxxxx-xxxxxxx-x) : ";getline(cin,cnic);
  cout<<" "<<endl;
  cout<<"                                            Enter Gender  (M/F) : ";cin>>g;
  cout<<" "<<endl;
  cout<<"                                            Enter Account Type (C/S) : ";cin.ignore();cin>>Acc_type;
  cout<<" "<<endl;
  load=findMax(root);
  acc_no = load + 1;
  cout<<"                                            Your Account Number is : "<<acc_no<<endl;
  cout<<" "<<endl;
  cout<<"                                            Enter Pin : " ;cin.ignore();cin>>pin;
  cout<<" "<<endl;
  jump2:
  cout<<"                                            Enter Balance (Min:500) : ";cin.ignore();cin>> Balance;
  if(Balance >= 500){goto jump3;}
  else{cout<<"                                            Minimum Balance is 500Rs. "<<endl;goto jump2;}

  jump3:
      root = insertion(root,full_name,cnic,g,Acc_type,acc_no,pin,Balance); //insertion(root)
      insertion_for_log(acc_no);
  return 1;
}


int admin_panel()
{
  //Declared Variables
  int b;
  int admin_delete_cin;
  int admin_search_cin;
  int result_admin_1;
  int result_admin_2;
  int result_admin_3;
  int result_admin_4;
  int admin_return;

  int acc_1;
  int pin_1;
  string cnc_1;
  char gen_1;
  string acc_type_1;
  string new_cnc_1;
  int new_pin_1;
  string new_acc_1;
  int admin_logs_cin;
  //END Declared Variables

  /////////////JUMP_2
  jump2:
  system("Color B");
  system("cls");
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *************ADMIN|||PANEL*************"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *  Press 1 To Create Account          *"<<endl;
  cout<<"                                                       *  Press 2 To Delete Account          *"<<endl;
  cout<<"                                                       *  Press 3 To Search Account          *"<<endl;
  cout<<"                                                       *  Press 4 To Show List of All Acc    *"<<endl;
  cout<<"                                                       *  Press 5 To Edit Information        *"<<endl;
  cout<<"                                                       *  Press 6 To Show Logs of Deleted Acc*"<<endl;
  cout<<"                                                       *  Press 7 To Go Back to Main Menu    *"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       Enter an Option : ";
  cin>>b;
  if(b == 1){
            lol_admin_1:
            system("cls");
            create_Acc();
            lol_admin_2:
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"                                         Press 1 to create another account or Press 7 to return to ADMIN PANEL ...!!! ";
            cin>>admin_return;
            if(admin_return == 7){goto jump2;}
            else if(admin_return == 1){goto lol_admin_1;}
            else{goto lol_admin_2;}}
  else if(b == 2){
  	 		lol_admin_3:
                system("cls");
                cout<<"                                         Enter the Account Number to Delete :";
                cin>>admin_delete_cin;
                result_admin_1 = search(root,admin_delete_cin);
			    cout<<result_admin_1<<endl;
	        if(result_admin_1 == 1){
			    cout<<"                                         Account number Found....!!!"<<endl;
			    cout<<" " <<endl;
			    deletion(root,admin_delete_cin);
			    cout<<" " <<endl;
			    cout<<"                                         Account is Deleted....!!!"<<endl;}
			else{
			    cout<<" " <<endl;
			    cout<<"                                         Account not found ....!!!"<<endl;
				cout<<" "<<endl;}
	        lol_admin_4:
                cout<<" "<<endl;
                cout<<" "<<endl;
                cout<<"                                         Press 2 to Delete another account or Press 7 to return to ADMIN PANEL ...!!! ";
                cin>>admin_return;
                if(admin_return==7){goto jump2;}
                else if(admin_return==2){goto lol_admin_3;}
                else{cout<<"                                         Invalid Output !! "<<endl;goto lol_admin_4; }}

  else if(b == 3){
            lol_admin_5:
  			  system("cls");
              cout<<"                                         Enter the Account Number to Search : ";
			  cin>>admin_search_cin;
              result_admin_2 = search(root,admin_search_cin);
              if(result_admin_2 == 1){
				cout<<" "<<endl;
				cout<<"                                         User Found..!!"<<endl;
				cout<<" "<<endl;
				print_data(root,admin_search_cin);
	      	    cout<<" "<<endl;}
	      	  else if(result_admin_2 == 0){
				     cout<<" "<<endl;
					 cout<<" "<<endl;
					 cout<<"                                         User not found..!! :("<<endl;
				     cout<<" "<<endl;
				     cout<<" "<<endl;}
		        cout<<" "<<endl;
			lol_admin_6:
                cout<<" "<<endl;
             	cout<<" "<<endl;
                cout<<"                                         Press 3 to Search another account or Press 7 to return to ADMIN PANEL ...!!! ";
                cin>>admin_return;
                if(admin_return==7){goto jump2;}
                else if(admin_return == 3){goto lol_admin_5;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_admin_6; }}

  else if(b == 4){
    	    lol_admin_7:
  	            system("cls");
                cout<<"        ####################################################################################################################################"<<endl;
    		    cout<<" "<<endl;
    			cout<<"          "<<"ACC_Number"<<"                 "<<"NAME"<<"                   "<<"CNIC"<<"                     "<<"GENDER"<<"            "<<"Type"<<"          "<<"PIN"<<"          "<<"BALANCE"<<endl;
    			cout<<" "<<endl;
    			cout<<"        ####################################################################################################################################"<<endl;
    			cout<<" "<<endl;
				print_for_admin(root);
            lol_admin_8:
                cout<<" "<<endl;
                cout<<" "<<endl;
                cout<<"                                         Press 4 to Show list of accounts or Press 7 to return to ADMIN PANEL ...!!! ";
                cin>>admin_return;
                if(admin_return==7){goto jump2;}
                else if(admin_return == 4){goto lol_admin_7;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_admin_8;}}
  else if(b == 5){
    	    lol_admin_9:
  	            system("cls");
  	            cout<<"                                            Change Informaion of Account "<<endl;
  	            cout<<"                                            Enter User_Account Number : ";
  	            cin>>acc_1;
  	            cout<<"                                            Enter User_Account PIN number : ";
  	            cin>>pin_1;
  	            result_admin_3 = check_acc_pin(root,acc_1,pin_1);
  	            if(result_admin_3 == 1){
  	            	cout<<"                                            Change Informaion of Account "<<endl;
  	            	cout<<"\n"<<endl;
  	            	cout<<"                                            Enter New Name / previous Name : ";
  	            	cin>>new_acc_1;
  	            	getline(cin, new_acc_1);
  	            	cout<<"                                            Enter New Cnic / Previous Cnic : ";
  	            	getline(cin, new_cnc_1);
  	            	cout<<"                                            Enter Gender : ";
  	            	cin>>gen_1;
  	            	cout<<"                                            Enter Account Type C/S : ";
  	            	cin>> acc_type_1;
  	            	cout<<"                                            Enter New PIN / Previous PIN : ";
  	            	cin>> new_pin_1;
  	            	change_info(root,new_acc_1,new_cnc_1,gen_1,acc_type_1,acc_1,new_pin_1);
  	            	cout<<"                                            Account information is Sucessfully Changed"<<endl;
				  }
				else if(result_admin_3 == -1){cout<<"                                            PIN is Incorrect...!!!"<<endl;}
				else if(result_admin_3 == 0){cout<<"                                            Account is not Present...!!!"<<endl;}
				else{cout<<"                                            Account is not Present...!!!"<<endl;}
			lol_admin_10:
                cout<<" "<<endl;
                cout<<" "<<endl;
                cout<<"                                         Press 5 to Change other Account info or Press 7 to return to ADMIN PANEL ...!!! ";
                cin>>admin_return;
                if(admin_return==7){goto jump2;}
                else if(admin_return == 5){goto lol_admin_9;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_admin_10;}}
  else if(b == 6){
  	        lol_admin_11:
                system("cls");
  	            cout<<"                                         Enter Account Number: ";
  	            cin>>admin_logs_cin;
                result_admin_4 = display1(admin_logs_cin);
                print_data(root,admin_logs_cin);
                if(result_admin_4 == 1){
                	cout<<""<<endl;
                	cout<<""<<endl;
                	display(admin_logs_cin);
				    }
                else{cout<<""<<endl;
                	cout<<""<<endl;
                	display(admin_logs_cin);}
			lol_admin_12:
				cout<<"                                         Press 6 to Check Logs of  another account or Press 7 to return to ADMIN PANEL...!!! ";
                cin>>admin_return;
                if(admin_return==6){goto lol_admin_11;}
                else if(admin_return==7){goto jump2;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_admin_12;}
                }
  else if(b == 7){main();}
            else{
                system("cls");
	            goto jump2;}
}

int staff_panel(){
   //Variable Used
   int staff_acc_no;
   int staff_pin_no;
   int staff_amount_to_dep;
   int staff_acc_no_1;
   int staff_pin_no_1;
   int staff_amount_to_wdraw_1;
   int account_logs_cin;
   int c;
   int staff_return;
   int lol_staff_1;
   int lol_staff_2;
   int account_info_cin;
   int result_staff_1;
   int result_staff_2;
   int result_staff_3;
   int result_staff_4;
   //End Variable Declaration

   ////////////JUMP_3:
  jump3:
  system("Color B");
  system("cls");
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *************STAFF|||PANEL*************"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *  Press 1 To Check Account Info      *"<<endl;
  cout<<"                                                       *  Press 2 To Deposit Cash            *"<<endl;
  cout<<"                                                       *  Press 3 To With_Draw Cash          *"<<endl;
  cout<<"                                                       *  Press 4 To Check Logs of User      *"<<endl;
  cout<<"                                                       *  Press 5 To Go Back to Main Menu    *"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       Enter an Option : ";
  cin>>c;
  if(c == 1){
  	    lol_staff_1:
  	        system("cls");
            cout<<"                                         Enter the Account Number to Check info : ";
			cin>>account_info_cin;
            result_staff_1= search(root,account_info_cin);
			if(result_staff_1 == 1){cout<<" "<<endl;
             	cout<<"                                         User Found..!!"<<endl;
				cout<<" "<<endl;
				print_data(root,account_info_cin);
				cout<<" "<<endl;}
            else if(result_staff_1 == 0){cout<<"                                         User not found..!! :("<<endl;
				cout<<" "<<endl;
				cout<<" "<<endl;}

				cout<<" "<<endl;
			lol_staff_2:
				cout<<"                                         Press 1 to search again or Press 5 to return to STAFF PANEL..!! ";
				cin>>staff_return;
				if(staff_return  == 1){goto lol_staff_1;}
				else if(staff_return == 5){ goto jump3;}
				else{cout<<"                                         Invalid Output !!"<<endl;goto lol_staff_2;}
				}
  else if(c == 2){
  	  		lol_staff_3:
  				system("cls");
  	            cout<<"                                         Enter Account : ";
  	            cin>>staff_acc_no;
  	            cout<<"                                         Enter Account PIN : ";
  	            cin>>staff_pin_no;
  	            cout<<"                                         Enter The Amount Deposit : ";
  	            cin>>staff_amount_to_dep;
  	            cout<<" "<<endl;
  	            cout<<"                                                   Status ""BEFORE"" Deposit Amount in ACCOUNT"<<endl;
  	            cout<<" "<<endl;
    			print_data(root,staff_acc_no);
    			cout<<" "<<endl;
    			cout<<" "<<endl;
    			result_staff_2 = deposit(root,staff_acc_no,staff_pin_no,staff_amount_to_dep);
    			if(result_staff_2 == 1){
    		    		cout<<"                                                   Status ""AFTER"" Deposit Amount in ACCOUNT"<<endl;
  	            		cout<<" "<<endl;
    					print_data(root,staff_acc_no);
    					cout<<" "<<endl;
    					cout<<" "<<endl;
    			time_t now = time(0);
                char* dt = ctime(&now);
                ostringstream str1;
                str1 << staff_amount_to_dep;
                        string add = "Amount " + str1.str();
                        string add1 = add + " has been deposited  at " + dt;

						cout<<"                                         Amount "<<staff_amount_to_dep<<" has been Deposited in Account Number  "<<staff_acc_no<<endl; insert_log(staff_acc_no,add1);}
    			else if(result_staff_2 == 0){cout<<"                                                     Account not Found....Amount is not Deposit in your Account...!"<<endl;}
				else if(result_staff_2 == -1){cout<<"                                                     PIN is Incorrect"<<endl;}
    			cout<<" "<<endl;
    			cout<<" "<<endl;
			lol_staff_4:
				cout<<"                                         Press 4 to Deposit amount in another account : 5 to return to STAFF PANEL...!!! ";
                cin>>staff_return;
                if(staff_return==4){goto lol_staff_3;}
                else if(staff_return==5){goto jump3;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_staff_4;}}
  else if(c == 3){cout<<"with draw cash"<<endl;
            lol_staff_5:
  				system("cls");
  	            cout<<"                                         Enter Account Number : ";
  	            cin>>staff_acc_no_1;
  	            cout<<"                                         Enter Account PIN : ";
  	            cin>>staff_pin_no_1;
  	            cout<<"                                         Enter The Amount WithDraw : ";
  	            cin>>staff_amount_to_wdraw_1;
  	            cout<<" "<<endl;
  	            cout<<"                                                   Status ""BEFORE"" WITHDRAW Amount from ACCOUNT"<<endl;
  	            cout<<" "<<endl;
    			print_data(root,staff_acc_no_1);
    			cout<<" "<<endl;
    			cout<<" "<<endl;
    			result_staff_3 = with_draw(root,staff_acc_no_1,staff_pin_no_1,staff_amount_to_wdraw_1);
    			if(result_staff_3 == 1){
    		    		cout<<"                                                   Status ""AFTER"" WITHDRAW Amount from ACCOUNT"<<endl;
  	            		cout<<" "<<endl;
    					print_data(root,staff_acc_no_1);
    					cout<<" "<<endl;
    					cout<<" "<<endl;
    				time_t now = time(0);
                	char* dt = ctime(&now);
                	ostringstream str1;
                	str1 << staff_amount_to_dep;
                        string add2 = "Amount " + str1.str();
                        string add3 = add2 + " has been Withdrawn  at " + dt;
						cout<<"                                         Amount "<<staff_amount_to_wdraw_1<<" has been Withdraw in Account Number  "<<staff_acc_no_1<<endl;insert_log(staff_acc_no_1,add3);}
    			else if(result_staff_3 == 0){cout<<"                                                     Account not Found....Amount is not With Drawn from User Account...!"<<endl;}
				else if(result_staff_3 == -1){cout<<"                                                     Account Balance is Insufficient "<<endl;}
				else if(result_staff_3 == -2){cout<<"                                                     PIN is InCorrect..!! "<<endl;}
    			cout<<" "<<endl;
    			cout<<" "<<endl;
			lol_staff_6:
				cout<<"                                         Press 3 to With Draw from another account : 5 to return to STAFF PANEL...!!! ";
                cin>>staff_return;
                if(staff_return==3){goto lol_staff_5;}
                else if(staff_return==5){goto jump3;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_staff_6;}}
  else if(c == 4){
            lol_staff_7:
  				system("cls");
  	            cout<<"                                         Enter Account Number: ";
  	            cin>>account_logs_cin;
                result_staff_4 = display1(account_logs_cin);
                print_data(root,account_logs_cin);
                if(result_staff_4 == 1){
                	cout<<""<<endl;
                	cout<<""<<endl;
                	display(account_logs_cin);
				    }
                else{cout<<"                                         Logs Not Found....!!!"<<endl;}
			lol_staff_8:
				cout<<"                                         Press 4 to Check Logs of  another account : 5 to return to STAFF PANEL...!!! ";
                cin>>staff_return;
                if(staff_return==4){goto lol_staff_7;}
                else if(staff_return==5){goto jump3;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_staff_8;}
			}
  else if(c == 5){
      system("cls");main();}
  else{goto jump3;}
}

int atm_panel()
{
  // declare variable
  int d;
  int atm_acc_no_1;
  int atm_pin_no_1;
  int atm_amount_to_wdraw_1;
  int result_atm_3;
  int atm_return;
  //End Variable Declaration

  ////////////JUMP_4
  jump4:
  system("Color B");
  system("cls");
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *******************ATM*****************"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *  Press 1 To Withdraw Cash            *"<<endl;
  cout<<"                                                       *  Press 2 To Go Back to Main Menu    *"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       Enter an Option : ";
  cin>>d;
  if(d == 1){
  			lol_atm_1:
  				system("cls");
  	            cout<<"                                         Enter Account Number : ";
  	            cin>>atm_acc_no_1;
  	            cout<<"                                         Enter Account PIN : ";
  	            cin>>atm_pin_no_1;
  	            cout<<"                                         Enter The Amount WithDraw : ";
  	            cin>>atm_amount_to_wdraw_1;
  	            cout<<" "<<endl;
  	            cout<<"                                                   Status ""BEFORE"" WITHDRAW Amount from ACCOUNT"<<endl;
  	            cout<<" "<<endl;
    			print_data(root,atm_acc_no_1);
    			cout<<" "<<endl;
    			cout<<" "<<endl;
    			result_atm_3 = with_draw(root,atm_acc_no_1,atm_pin_no_1,atm_amount_to_wdraw_1);
    			if(result_atm_3 == 1){
    		    		cout<<"                                                   Status ""AFTER"" WITHDRAW Amount from ACCOUNT"<<endl;
  	            		cout<<" "<<endl;
    					print_data(root,atm_acc_no_1);
    					cout<<" "<<endl;
    					cout<<" "<<endl;
    				time_t now = time(0);
                	char* dt = ctime(&now);
                	ostringstream str1;
                	str1 << atm_amount_to_wdraw_1;
                        string add2 = "Amount " + str1.str();
                        string add3 = add2 + " has been Withdrawn  at " + dt;
						cout<<"                                         Amount "<<atm_amount_to_wdraw_1<<" has been Withdrawn from Account Number  "<<atm_acc_no_1<<endl;insert_log(atm_acc_no_1,add3);}
    			else if(result_atm_3 == 0){cout<<"                                                     Account not Found....Amount is not With Drawn from User Account...!"<<endl;}
				else if(result_atm_3 == -1){cout<<"                                                     Account Balance is Insufficient "<<endl;}
				else if(result_atm_3 == -2){cout<<"                                                     PIN is InCorrect..!! "<<endl;}
    			cout<<" "<<endl;
    			cout<<" "<<endl;
			lol_staff_6:
				cout<<"                                         Press 3 to With Draw from another account : 5 to return to ATM PANEL...!!! ";
                cin>> atm_return;
                if(atm_return==3){goto lol_atm_1;}
                else if(atm_return==5){goto jump4;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_atm_1;}}

  else if(d == 2){
      system("cls");main();}
  else{goto jump4;}
}


int main()
{
  //Declare RECORD
    root = insertion(root,"Mohammad Daanish","12345-6789101-1",'M',"C",5010050,1234,2000);
    insertion_for_log(5010050);
    root = insertion(root,"Tanmay Singh","12345-6789101-2",'M',"C",5010051,1122,500);
    insertion_for_log(5010051);
    root = insertion(root,"Isha Verma","12345-6789101-3",'F',"S",5010052,3214,1000);
    insertion_for_log(5010052);
    root = insertion(root,"Aryan Srivastava","12345-6789101-4",'M',"C",5010053,3215,1000);
    insertion_for_log(5010053);
    root = insertion(root,"Vineet Kumar","12345-6789101-5",'M',"C",5010054,3216,2000);
    insertion_for_log(5010054);
    root = insertion(root,"Sahil Rawat","12345-6789101-6",'M',"S",5010055,3217,2000);
    insertion_for_log(5010055);
    root = insertion(root,"Vivek Vardhan","12345-6789101-7",'M',"C",5010056,3218,2000);
    insertion_for_log(5010056);
    root = insertion(root,"Dilpreet Dhillon","12345-6789101-8",'M',"C",5010057,3219,231);
    insertion_for_log(5010057);
    root = insertion(root,"Sahiba Asif","12345-6789101-9",'F',"S",5010058,3220,2231);
    insertion_for_log(5010058);
    root = insertion(root,"Mohammad Ali","12345-6789102-0",'M',"C",5010059,3221,546);
    insertion_for_log(5010059);
    root = insertion(root,"Deepak Tiwari","12345-6789102-1",'M',"C",5010060,3222,56467);
    insertion_for_log(5010060);
    root = insertion(root,"Saumya Yadav","12345-6789102-2",'F',"S",5010061,3223,5674687);
    insertion_for_log(5010061);
    root = insertion(root,"Archana Jaiswal","12345-6789102-3",'F',"S",5010062,3224,557);
    insertion_for_log(5010062);
    root = insertion(root,"Peter DSouza","12345-6789102-4",'M',"S",5010063,3225,56498);
    insertion_for_log(5010063);
    root = insertion(root,"Neeraj Jain","12345-6789102-5",'M',"S",5010064,3226,637);
    insertion_for_log(5010064);
    root = insertion(root,"Shiv Narang","12345-6789102-6",'M',"S",5010065,3227,65468);
    insertion_for_log(5010065);
    root = insertion(root,"Haider Abbas","12345-6789102-7",'M',"C",5010066,3228,6546);
    insertion_for_log(5010066);
    root = insertion(root,"Vibhor Sharma","12345-6789102-8",'M',"C",5010067,3229,567);
    insertion_for_log(5010067);
    root = insertion(root,"Akansha Dubey","12345-6789102-9",'F',"C",5010068,3230,654768);
    insertion_for_log(5010068);
    root = insertion(root,"Praveen Pathak","12345-6789103-0",'M',"C",5010069,3231,500);
    insertion_for_log(5010069);
    root = insertion(root,"Hamza Ibrahim","12345-6789103-0",'M',"C",5010070,3233,500);
    insertion_for_log(5010070);
  //END of Declare RECORD

  //Declare Variables
  int a;
  int b;
  system("MODE 150, 40");
  //End Variable Declaration
  /////////////JUMP_1
  jump1:
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";


  system("Color B");
  system("cls");
  cout<<"\n";
  cout<<"                   ____              _      __  __                                                   _      _____           _                  "<<endl;
  cout<<"                  |  _ \            | |    |  \/  |                                                 | |    / ____|         | |                 "<<endl;
  cout<<"                  | |_) | __ _ _ __ | | __ | \  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  | (___  _   _ ___| |_ ___ _ __ ___   "<<endl;
  cout<<"                  |  _ < / _` | '_ \| |/ / | |\/| |/ _` | '_ \ / _` |/ _` |/ _ \ '_ ` _ \ / _ \ '_ \| __|  \___ \| | | / __| __/ _ \ '_ ` _ \  "<<endl;
  cout<<"                  | |_) | (_| | | | |   <  | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ____) | |_| \__ \ ||  __/ | | | | | "<<endl;
  cout<<"                  |____/ \__,_|_| |_|_|\_\ |_|  |_|\__,_|_| |_|\__,_|\__, |\___|_| |_| |_|\___|_| |_|\__| |_____/ \__, |___/\__\___|_| |_| |_| "<<endl;
  cout<<"                                                                      __/ |                                        __/ |                       "<<endl;
  cout<<"                                                                     |___/                                        |___/                        "<<endl;
  cout<<"                                                                                                                                               "<<endl;
  cout<<"                                                            Made by MOHAMMAD DAANISH                                                          "<<endl;
  cout<<"\n"<<endl;
  cout<<"                                                       ********************************"<<endl;
  cout<<"                                                       **********LOGIN||PANEL**********"<<endl;
  cout<<"                                                       ********************************"<<endl;
  cout<<"                                                       *  Press 1 For ADMIN Login     *"<<endl;
  cout<<"                                                       *  Press 2 For STAFF Login     *"<<endl;
  cout<<"                                                       *  Press 3 For ATM Service     *"<<endl;
  cout<<"                                                       *  Press 4 To  Exit            *"<<endl;
  cout<<"                                                       ********************************"<<endl;
  cout<<"                                                       ********************************"<<endl;
  cout<<"\n"<<endl;
  cout<<"                                                       Enter Your Choice : ";
  cin>>a;
  if(a == 1){
        jump2:
        system("Color B");
        system("cls");
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"                                                       Enter Pin : ";
        cin >>b;
        if(b == admin_pswd){admin_panel();}
        else{goto jump2;}}
  else if(a == 2){
        jump3:
        system("Color B");
        system("cls");
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"                                                       Enter Pin : ";
        cin >>b;
        if(b == staff_pswd){staff_panel();}
        else{goto jump3;}}
  else if(a == 3){atm_panel();}
  else if(a == 4){exit(0);}
  else {goto jump1;}


}
                                                  //-------------------xxxxxxxxxxxxxxxxx---------------------------\\
