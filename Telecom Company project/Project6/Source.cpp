#include <iostream>
#include <string>
using namespace std;
const int USERS_NUMBER = 100, MAX_OF_LINES = 3, Card = 5;

//struct to store data of lines like balance and package type
struct lines
{
	double balance = 10; // 10 L.E as a gift when buy a number
	string number = {}; // to store number
	int flex = 0; // to store flex;
	string packagetype = { "all 0.25" }; // to store package

};
//struct to store data in it ;
struct manage
{
	string username;
	string password;
	lines lines[MAX_OF_LINES];
	string mail;
	string ID;
	string address;

};

//functions
void start_page();
void sign_up_page();
void sign_in_page();
void after_login_successfull(string user, int assign_user);
void make_call(int assign_user);
void send_message(int assign_user);
void recharge_balance(int assign_user);
void transfer_balance(int assign_user);
void change_package(int assign_user);
void add_or_delete_number(int assign_user);
void which_number_you_want(bool &phonenumber1, bool &phonenumber2, bool &phonenumber3);
void Done_or_not(int &line_choose, bool &phonenumber1, bool &phonenumber2, bool &phonenumber3);

int global_iterator = 1; // global iterator to use to know how many user i have in my system
manage signup[USERS_NUMBER]; //variable of structure to store data in it;
//main function
int main()
{
	cout << "Welcom To Telecom Company system, " << endl;
	start_page();
}

//start page function; ****
void start_page() // to
{
	//store defult user
	signup[0].username = "user";
	signup[0].password = "pass";
	signup[0].mail = "mail@mail.com";
	signup[0].address = "Cairo";
	signup[0].ID = "1010101010101010";
	signup[0].lines[0].number = "01442445678";
	signup[0].lines[0].balance = 10;

	string choise; // variable to know what user pressed
	cout << "please , choose the number of what you want " << endl;
	cout << "press (1) to sign in" << endl;
	cout << "press (2) to sign up" << endl;
	cout << "--> ";
	cin >> choise;
	if (choise == "1")
	{
		cout << "------------------------" << endl;
		sign_in_page();
	}
	else if (choise == "2")
	{
		cout << "------------------------" << endl;
		sign_up_page();
	}
	else
	{
		cout << "Wrong choise" << endl;
		cout << "------------------------" << endl;
		start_page();
	}

}

int assign_to_user = 0;//to assign to user who logged in
int local_iterator = 1;//to iterate and store data in deafult index in the next time i signup;

//signup function ******
void sign_up_page()
{
	string username, phone_number; // use in validate
	//validate username to check if user exist or not
	bool check_user_exist = false;
	do
	{
		if (check_user_exist == true)
		{
			cout << "Used username , please use another " << endl;
		}
		int iterat_to_check_user = 0;
		cout << "please Enter your username :" << endl;
		cin >> username;
		while (iterat_to_check_user <= global_iterator)
		{
			if (username == signup[iterat_to_check_user].username)
			{
				check_user_exist = true;
				break;
			}
			else
				check_user_exist = false;
			iterat_to_check_user++;
		}
	} while (check_user_exist == true);
	signup[local_iterator].username = username;//assign user in arry of structure;

	//take password from user
	cout << "please Enter your password : " << endl;
	cin >> signup[local_iterator].password;

	//validate phone number to check if 11 number only and to check if exist or not
	bool number_exist = false, numberonly = true;
	do {
		numberonly = true;
		if (number_exist == true)
		{
			cout << "Used number , please use another " << endl;
		}
		cout << "please Enter your number (only 11 number ) : " << endl;
		cin >> phone_number;
		for (int local_iterator_to_check_line_exist = 0; local_iterator_to_check_line_exist <= global_iterator; local_iterator_to_check_line_exist++)
		{
			for (int lines_of_3number = 0; lines_of_3number < 3; lines_of_3number++)
			{
				if (signup[local_iterator_to_check_line_exist].lines[lines_of_3number].number == phone_number)
				{
					number_exist = true;
					break;
				}
				else
					number_exist = false;
			}
			if (number_exist)
				break;
			for (int i = 0; i < phone_number.size(); i++)
			{
				if (!isdigit(phone_number[i]))
					numberonly = false;
			}
			if (numberonly == false)
			{
				cout << "*please Enter numbers only*" << endl;
			}
		}
	} while (phone_number.size() != 11 || number_exist == true || numberonly == false);
	signup[local_iterator].lines[0].number = phone_number;

	//take email from user

	cout << "please Enter your mail : " << endl;
	getline(cin, signup[local_iterator].mail);
	getline(cin, signup[local_iterator].mail);

	//take affress from user
	cout << "please Enter your address : " << endl;
	getline(cin, signup[local_iterator].address);

	//take id from user
	cout << "please Enter your ID : " << endl;
	cin >> signup[local_iterator].ID;

	local_iterator++;
	global_iterator = local_iterator;
	cout << "------------------------" << endl;
	cout << "Registration successfully *-* " << endl;
	cout << "------------------------" << endl;
	main();
}

string local_username; //global variable used in check ;
//sign in function *****
void sign_in_page()
{
	string local_password;
	assign_to_user = 0;


	cout << "please Enter your username : " << endl;
	cin >> local_username;
	cout << "please Enter yor password : " << endl;
	cin >> local_password;
	bool check_login_successfull = false;
	for (int i = 0; i <= global_iterator; i++)
	{
		if (local_username == signup[i].username && local_password == signup[i].password)
		{
			check_login_successfull = true;
			break;
		}
		assign_to_user++;
	}
	if (check_login_successfull)
	{
		cout << "------------------------" << endl;
		cout << "Login Successfull" << endl;
		cout << "------------------------" << endl;
		after_login_successfull(local_username, assign_to_user);
	}
	else
	{
		cout << "------------------------" << endl;
		cout << "Login failed , if you don't hvae account please sign up " << endl;
		cout << "------------------------" << endl;
		start_page();
	}
}

//after login function ***
void after_login_successfull(string user, int assign_user)
{
	cout << "Hello sir ," << user << endl;
	cout << "Start Date : 4/5/2015 & Renewal Date 4/5/2025" << endl;
	for (int i = 0; i < 3; i++) // i to iterat on line number
	{
		if (signup[assign_to_user].lines[i].number != "\0")
		{
			if (signup[assign_to_user].lines[i].packagetype == "all 0.25")
				cout << signup[assign_to_user].lines[i].number << " balance is --> " << signup[assign_to_user].lines[i].balance << " <-- And you still --> " << signup[assign_to_user].lines[i].packagetype << endl;

			if (signup[assign_to_user].lines[i].packagetype == "flex10")
				cout << signup[assign_to_user].lines[i].number << " balance is --> " << signup[assign_to_user].lines[i].balance << " <-- And you still --> " << signup[assign_to_user].lines[i].packagetype << " <-- you have --> " << signup[assign_to_user].lines[i].flex << " flex " << endl << endl;

			if (signup[assign_to_user].lines[i].packagetype == "flex20")
				cout << signup[assign_to_user].lines[i].number << " balance is --> " << signup[assign_to_user].lines[i].balance << " <-- And you still --> " << signup[assign_to_user].lines[i].packagetype << " <-- you have --> " << signup[assign_to_user].lines[i].flex << " flex " << endl << endl;

		}
	}
	string operate_you_want; // to know what user choise;

	cout << "------------------------" << endl;

	cout << "press (1) to make a call" << endl;
	cout << "press (2) to send a message" << endl;
	cout << "press (3) to recharge your balance" << endl;
	cout << "press (4) to transfer balance" << endl;
	cout << "press (5) to change your package" << endl;
	cout << "press (6) to add/delete number" << endl;
	cout << "press (7) to logout" << endl;
	cout << "press (8) to exit" << endl;
	cin >> operate_you_want;
	if (operate_you_want == "1")
	{
		make_call(assign_to_user);
	}
	else if (operate_you_want == "2")
	{
		send_message(assign_to_user);
	}
	else if (operate_you_want == "3")
	{
		recharge_balance(assign_to_user);
	}
	else if (operate_you_want == "4")
	{
		transfer_balance(assign_to_user);
	}
	else if (operate_you_want == "5")
	{
		change_package(assign_to_user);
	}
	else if (operate_you_want == "6")
	{
		add_or_delete_number(assign_to_user);
	}
	else if (operate_you_want == "7")
	{
		cout << "------------------------" << endl;
		main();
	}
	else if (operate_you_want == "8")
	{
		cout << "------------------------" << endl;
		cout << "Thanks TO USE OUR SYSTEM , BYE *-*" << endl;
		cout << "------------------------" << endl;
	}
	else
	{
		cout << "Wrong choice" << endl;
		cout << "-------------------------" << endl;
		after_login_successfull(local_username, assign_to_user);
	}
}
// function to make user choose the line he want to make a operation on it ****
void which_number_you_want(bool &phonenumber1, bool &phonenumber2, bool &phonenumber3)
{
	phonenumber1 = false; phonenumber2 = false; phonenumber3 = false;
	if (signup[assign_to_user].lines[0].number != "\0")
	{
		cout << signup[assign_to_user].lines[0].number << " --> 1 " << endl;
		phonenumber1 = true;
	}
	if (signup[assign_to_user].lines[1].number != "\0")
	{
		cout << signup[assign_to_user].lines[1].number << " --> 2 " << endl;
		phonenumber2 = true;
	}
	if (signup[assign_to_user].lines[2].number != "\0")
	{
		cout << signup[assign_to_user].lines[2].number << " --> 3 " << endl;
		phonenumber3 = true;
	}

}
//function to know that the operation done or not ****
void Done_or_not(int &line_choose, bool &phonenumber1, bool &phonenumber2, bool &phonenumber3)
{
	if ((line_choose == 1 && phonenumber1) || (line_choose == 2 && phonenumber2) || (line_choose == 3 && phonenumber3))
	{
		if (signup[assign_to_user].lines[line_choose - 1].packagetype == "all 0.25" && signup[assign_to_user].lines[line_choose - 1].balance >= 0.25)
		{
			cout << "------------------------" << endl;
			cout << "Done , you paid 0.25" << endl;
			signup[assign_to_user].lines[line_choose - 1].balance = signup[assign_to_user].lines[line_choose - 1].balance - 0.25;
			cout << "------------------------" << endl;
			after_login_successfull(local_username, assign_to_user);
		}
		else if ((signup[assign_to_user].lines[line_choose - 1].packagetype == "flex10" || signup[assign_to_user].lines[line_choose - 1].packagetype == "flex20") && signup[assign_to_user].lines[0].flex >= 1)
		{
			cout << "------------------------" << endl;
			cout << "Done , you paid 1 flex" << endl;
			signup[assign_to_user].lines[line_choose - 1].flex = signup[assign_to_user].lines[line_choose - 1].flex - 1;
			cout << "------------------------" << endl;
			after_login_successfull(local_username, assign_to_user);
		}
		else
		{
			cout << "------------------------" << endl;
			cout << "failed , please recharge your balance or renew your flex" << endl;
			cout << "------------------------" << endl;
			after_login_successfull(local_username, assign_to_user);


		}
	}

	else
	{
		cout << "------------------------" << endl;
		cout << "Worng choise , please choose a vaild line" << endl;
		cout << "------------------------" << endl;
		after_login_successfull(local_username, assign_to_user);


	}
}
// function to make a call ***
void make_call(int assign_to_user)
{
	string phonenumber;
	bool numberonly = true, phonenumber1 = false, phonenumber2 = false, phonenumber3 = false;
	//validate phone number to know is digit and only 11 number
	do {
		numberonly = true;
		cout << "type number you want to call (only 11 number) : ";
		cin >> phonenumber;
		for (int i = 0; i < phonenumber.size(); i++)
		{
			if (!isdigit(phonenumber[i]))
				numberonly = false;
		}
		if (numberonly == false)
		{
			cout << "*please Enter numbers only*" << endl;
		}
	} while (phonenumber.size() != 11 || numberonly == false);
	cout << "which line use to continue call ?" << endl;
	which_number_you_want(phonenumber1, phonenumber2, phonenumber3);
	int line_choose;
	cin >> line_choose;
	//check if line chossen is correct and the call done or not;
	Done_or_not(line_choose, phonenumber1, phonenumber2, phonenumber3);
}
//function to send message ****
void send_message(int assign_user)
{
	string phone_recieve;
	bool numberonly = true;
	do {
		phone_recieve = true;
		cout << "Type the number you want to send message ( only 11 number ): " << endl;
		cin >> phone_recieve;
		for (int i = 0; i < phone_recieve.size(); i++)
		{
			if (!isdigit(phone_recieve[i]))
				numberonly = false;
		}
		if (numberonly == false)
		{
			cout << "*please Enter numbers only*" << endl;
		}
	} while (phone_recieve.size() != 11 || numberonly == false);
	cout << "Type Your Message : " << endl;
	string message;
	getline(cin, message);
	getline(cin, message);

	cout << "------------------------" << endl;
	cout << "which number you want to use to send message" << endl;
	bool phonenumber1 = false, phonenumber2 = false, phonenumber3 = false;
	which_number_you_want(phonenumber1, phonenumber2, phonenumber3);
	int line_choose = 0;
	cin >> line_choose;
	//check if line chossen is correct and message sent or not ;
	Done_or_not(line_choose, phonenumber1, phonenumber2, phonenumber3);

}
//function to recharge balance **** 

string card_serial_number_10[Card] = { "10101" , "10102" , "10103" , "10104" , "10105" };//card give user 10 L.E
string card_serial_number_50[Card] = { "50501" , "50502" , "50503" , "50504" , "50505" };//card give user 50 L.E
string card_serial_number_100[Card] = { "1001001" , "1001002" , "1001003" , "1001004" , "1001005" };//card give user 100 L.E
string card_serial_number_200[Card] = { "2002001" , "2002002" , "2002003" , "2002004" , "2002005" };//card give user 200 L.E

void recharge_balance(int assign_user)
{

	cout << "------------------------" << endl;
	cout << "which line you want to recharge : " << endl; 
	cout << "------------------------" << endl;
	bool phonenumber1 = false, phonenumber2 = false, phonenumber3 = false;
	which_number_you_want(phonenumber1, phonenumber2, phonenumber3); // to show me lines and chose which line i want to recharge
	int line_choose = 0;
	cin >> line_choose;
	if ((line_choose == 1 && phonenumber1) || (line_choose == 2 && phonenumber2) || (line_choose == 3 && phonenumber3))
	{
		cout << "Enter your Card serial number to recharge your balance : " << endl;
		string Entre_card;
		cin >> Entre_card;
		bool card_valid = false; // to put a flag if the card not vailed ;
		for (int i = 0; i < 6; i++) // to check if card serial number is exist or not ;
		{
			if (Entre_card == card_serial_number_10[i])
			{
				card_serial_number_10[i] = {};
				signup[assign_to_user].lines[line_choose - 1].balance = signup[assign_to_user].lines[line_choose - 1].balance + 10;
				cout << "------------------------" << endl;
				cout << "Recharge balance successfully" << endl;
				cout << "------------------------" << endl;
				card_valid = true;
				after_login_successfull(local_username, assign_to_user);
				break;
			}
			else if (Entre_card == card_serial_number_50[i]) {
				card_serial_number_50[i] = {};
				signup[assign_to_user].lines[line_choose - 1].balance = signup[assign_to_user].lines[line_choose - 1].balance + 50;
				cout << "------------------------" << endl;
				cout << "Recharge balance successfully" << endl;
				cout << "------------------------" << endl;
				card_valid = true;
				after_login_successfull(local_username, assign_to_user);
				break;
			}
			else if (Entre_card == card_serial_number_100[i]) {
				card_serial_number_100[i] = {};
				signup[assign_to_user].lines[line_choose - 1].balance = signup[assign_to_user].lines[line_choose - 1].balance + 100;
				cout << "------------------------" << endl;
				cout << "Recharge balance successfully" << endl;
				cout << "------------------------" << endl;
				card_valid = true;
				after_login_successfull(local_username, assign_to_user);
				break;
			}
			else if (Entre_card == card_serial_number_200[i]) {
				card_serial_number_200[i] = {};
				signup[assign_to_user].lines[line_choose - 1].balance = signup[assign_to_user].lines[line_choose - 1].balance + 200;
				cout << "------------------------" << endl;
				cout << "Recharge balance successfully" << endl;
				cout << "------------------------" << endl;
				card_valid = true;
				after_login_successfull(local_username, assign_to_user);
				break;
			}
		}
		if (!card_valid)
		{
			cout << "------------------------" << endl;
			cout << "Card Not Valid " << endl;
			cout << "------------------------" << endl;
			after_login_successfull(local_username, assign_to_user);
		}

	}
	else
	{
		cout << "------------------------" << endl;
		cout << "please chosse a vaild number to recharge balance " << endl;
		cout << "------------------------" << endl;
		after_login_successfull(local_username, assign_to_user);
	}
}
//function to transfer balance *****
void transfer_balance(int assign_user)
{
	cout << "------------------------" << endl;
	string phone_recieve_balance;
	int local_iterator_to_check_line_exist = 0, lines_of_3number = 0;// to assign which user has this number if the number exist
	bool number_exist = false, numberonly = true;
	do {
		numberonly = true;
		if (number_exist == true)
		{
			break;
		}
		cout << "Type the number you want to transfer the balance : " << endl;
		cin >> phone_recieve_balance;
		for (local_iterator_to_check_line_exist = 0; local_iterator_to_check_line_exist <= global_iterator; local_iterator_to_check_line_exist++)
		{
			for (lines_of_3number = 0; lines_of_3number < 3; lines_of_3number++)
			{
				if (signup[local_iterator_to_check_line_exist].lines[lines_of_3number].number == phone_recieve_balance)
				{
					number_exist = true;
					break;
				}
				else
					number_exist = false;
			}
			if (number_exist)
				break;
		}
	} while (phone_recieve_balance.size() != 11 || number_exist == true || numberonly == false);
	//
	if (number_exist)
	{
		cout << "------------------------" << endl;
		cout << "Type the amount you want to transfer : " << endl;
		double amount_balance = 0;
		cin >> amount_balance;
		cout << "------------------------" << endl;
		cout << "which line use to transfer balance " << endl;
		//
		bool phonenumber1 = false, phonenumber2 = false, phonenumber3 = false;
		which_number_you_want(phonenumber1, phonenumber2, phonenumber3);
		int line_chossen = 0;
		cin >> line_chossen;
		if ((line_chossen == 1 && phonenumber1) || (line_chossen == 2 && phonenumber2) || (line_chossen == 3 && phonenumber3))
		{
			if (signup[local_iterator_to_check_line_exist].lines[lines_of_3number].number == signup[assign_to_user].lines[line_chossen - 1].number)
			{
				cout << "------------------------" << endl;
				cout << "You can't Transfer balance to your self *-*" << endl;
				cout << "------------------------" << endl;
				after_login_successfull(local_username, assign_to_user);
			}
			else if (signup[assign_to_user].lines[line_chossen - 1].balance >= amount_balance)
			{
				signup[assign_to_user].lines[line_chossen - 1].balance = signup[assign_to_user].lines[line_chossen - 1].balance - amount_balance;
				signup[local_iterator_to_check_line_exist].lines[lines_of_3number].balance = signup[local_iterator_to_check_line_exist].lines[lines_of_3number].balance + amount_balance;
				cout << "------------------------" << endl;
				cout << "Done --> balance Transfered" << endl;
				cout << "------------------------" << endl;
				after_login_successfull(local_username, assign_to_user);
			}
			else
			{
				cout << "------------------------" << endl;
				cout << "sorry , You don't have this amount of balance to transfer *-*" << endl;
				cout << "------------------------" << endl;
				after_login_successfull(local_username, assign_to_user);

			}
		}
	}
	else
	{
		cout << "------------------------" << endl;
		cout << "sorry , number dosen't exist to transfer balance " << endl;
		cout << "------------------------" << endl;
		after_login_successfull(local_username, assign_to_user);
	}
}
//function to change line package *******
void change_package(int assign_user)
{
	bool phonenumber1 = false, phonenumber2 = false, phonenumber3 = false;
	if (signup[assign_to_user].lines[0].number != "\0")
	{
		cout << signup[assign_to_user].lines[0].number << " package type is --> " << signup[assign_to_user].lines[0].packagetype << endl;
		phonenumber1 = true;
	}
	if (signup[assign_to_user].lines[1].number != "\0")
	{
		cout << signup[assign_to_user].lines[1].number << " package type is --> " << signup[assign_to_user].lines[1].packagetype << endl;
		phonenumber2 = true;
	}
	if (signup[assign_to_user].lines[2].number != "\0")
	{
		cout << signup[assign_to_user].lines[2].number << " package type is --> " << signup[assign_to_user].lines[2].packagetype << endl;
		phonenumber3 = true;
	}
	cout << "do you want to change package?" << endl;
	cout << "press 'y' for YES or 'n' for NO" << endl;
	char sign_y_or_n;
	
	cin >> sign_y_or_n;
	if (sign_y_or_n == 'y' || sign_y_or_n == 'Y')
	{
		cout << "------------------------" << endl;
		cout << "which line you want to change package?" << endl;
		if (phonenumber1)
		{
			cout << signup[assign_to_user].lines[0].number << "--> 1" << endl;
		}
		if (phonenumber2)
		{
			cout << signup[assign_to_user].lines[1].number << "--> 2" << endl;
		}
		if (phonenumber3)
		{
			cout << signup[assign_to_user].lines[2].number << "--> 3" << endl;

		}
		int line_choose = 0;
		cout << " --> ";
		cin >> line_choose;
		//to know what line user want to change package
		if ((line_choose == 1 && phonenumber1) || (line_choose == 2 && phonenumber2) || (line_choose == 3 && phonenumber3))
		{
			cout << "------------------------" << endl;
			cout << "choose the package you want :" << endl;
			cout << "flex 10 --> 1" << endl;
			cout << "flex 20 --> 2" << endl;
			cout << "all 0.25 --> 3" << endl;
			int package_choose = 0;
			cin >> package_choose; // to know which package the user want to change to ;
			if (package_choose == 1)
			{
				cout << "------------------------" << endl;
				cout << "Do you want to change your package type to flex10 and get 1000 flex for 15 L.E ?" << endl;;
				cout << "prees 'y' for YES or 'n' for NO" << endl;
				char check_yes_or_no;
				cin >> check_yes_or_no;//to know that if user want to change or not
				if (check_yes_or_no == 'y' || check_yes_or_no == 'Y')
				{
					if (signup[assign_to_user].lines[line_choose - 1].balance >= 15)
					{
						signup[assign_to_user].lines[line_choose - 1].balance = signup[assign_to_user].lines[line_choose - 1].balance - 15;
						signup[assign_to_user].lines[line_choose - 1].packagetype = "flex10";
						signup[assign_to_user].lines[line_choose - 1].flex = signup[assign_to_user].lines[line_choose - 1].flex + 1000;
						cout << "------------------------" << endl;
						cout << "Done , package changed to flex 10 and your balance now " << signup[assign_to_user].lines[0].balance << endl;
						cout << "------------------------" << endl;
						after_login_successfull(local_username, assign_to_user);
					}
					else
					{
						cout << "------------------------" << endl;
						cout << "your balance less than 15 L.E , please recharge yout balance " << endl;
						cout << "------------------------" << endl;
						cout << "Nothing changed" << endl;
						cout << "------------------------" << endl;
						after_login_successfull(local_username, assign_to_user);

					}
				}
				else if (check_yes_or_no == 'n' || check_yes_or_no == 'N')
				{
					cout << "------------------------" << endl;
					cout << "Nothing changed" << endl;
					cout << "------------------------" << endl;
					after_login_successfull(local_username, assign_to_user);
				}

			}
			if (package_choose == 2)
			{
				cout << "------------------------" << endl;
				cout << "Do you want to change your package type to flex20 and get 2000 flex for 25 L.E ?" << endl;
				cout << "prees 'y' for YES or 'n' for NO" << endl;

				char check_yes_or_no;
				cin >> check_yes_or_no;//to know that if user want to change or not
				if (check_yes_or_no == 'y' || check_yes_or_no == 'Y')
				{
					if (signup[assign_to_user].lines[line_choose - 1].balance >= 25)
					{
						signup[assign_to_user].lines[line_choose - 1].balance = signup[assign_to_user].lines[line_choose - 1].balance - 25;
						signup[assign_to_user].lines[line_choose - 1].packagetype = "flex20";
						signup[assign_to_user].lines[line_choose - 1].flex = signup[assign_to_user].lines[line_choose - 1].flex + 2000;
						cout << "------------------------" << endl;
						cout << "Done , package changed to flex 20 and your balance now " << signup[assign_to_user].lines[line_choose - 1].balance << endl;
						cout << "------------------------" << endl;
						after_login_successfull(local_username, assign_to_user);
					}
					else
					{
						cout << "------------------------" << endl;
						cout << "your balance less than 25 L.E , please recharge your balance " << endl;
						cout << "------------------------" << endl;
						cout << "Nothing changed" << endl;
						cout << "------------------------" << endl;
						after_login_successfull(local_username, assign_to_user);

					}
				}
				else if (check_yes_or_no == 'n' || check_yes_or_no == 'N')
				{
					cout << "------------------------" << endl;
					cout << "Nothing changed" << endl;
					cout << "------------------------" << endl;
					after_login_successfull(local_username, assign_to_user);
				}

			}
			else if (package_choose == 3)
			{
				cout << "------------------------" << endl;
				cout << "Do you want to change your package type to all 0.25 for 2 L.E ? **you will lose your flex** " << endl;
				cout << "prees 'y' for YES or 'n' for NO" << endl;

				char check_yes_or_no;
				cin >> check_yes_or_no;//to know that if user want to change or not
				if (check_yes_or_no == 'y' || check_yes_or_no == 'Y')
				{
					if (signup[assign_to_user].lines[line_choose - 1].packagetype == "all 0.25")
					{
						cout << "------------------------" << endl;
						cout << "You already on package all 0.25" << endl;
						cout << "------------------------" << endl;
						after_login_successfull(local_username, assign_to_user);
					}
					else if (signup[assign_to_user].lines[line_choose - 1].balance >= 2 && signup[assign_to_user].lines[line_choose - 1].packagetype != "all 0.25")
					{
						signup[assign_to_user].lines[line_choose - 1].packagetype = "all 0.25";
						signup[assign_to_user].lines[line_choose - 1].flex = {};
						signup[assign_to_user].lines[line_choose - 1].balance = signup[assign_to_user].lines[line_choose - 1].balance - 2;
						cout << "------------------------" << endl;
						signup[assign_to_user].lines[line_choose - 1].flex = {};
						cout << "Done , package changed to all 0.25 " << endl;
						cout << "------------------------" << endl;
						after_login_successfull(local_username, assign_to_user);
					}
					else
					{
						cout << "------------------------" << endl;
						cout << "Sorry , you don't have enough balance to change your package please , recharge your balance " << endl;
						cout << "------------------------" << endl;
						after_login_successfull(local_username, assign_to_user);
					}
				}
				else if (check_yes_or_no == 'n' || check_yes_or_no == 'N')
				{
					cout << "------------------------" << endl;
					cout << "Nothing changed" << endl;
					cout << "------------------------" << endl;
					after_login_successfull(local_username, assign_to_user);
				}
			}
			else
			{
				cout << "------------------------" << endl;
				cout << "wron choise , please choose a vaild package" << endl;
				cout << "------------------------" << endl;
				after_login_successfull(local_username, assign_to_user);

			}
		}
		else
		{
			cout << "------------------------" << endl;
			cout << "wron choise , please choose a vaild package" << endl;
			cout << "------------------------" << endl;
			after_login_successfull(local_username, assign_to_user);
		}
	}
}
//function to add number or delete number
void add_or_delete_number(int assign_user)
{
	cout << "------------------------" << endl;
	cout << "choose add or delete number ? " << endl;
	cout << "delete number --> 1" << endl;
	cout << "add number --> 2" << endl;
	int choose = 0;
	bool phonenumber1 = false, phonenumber2 = false, phonenumber3 = false;
	cin >> choose;
	if (choose == 1)
	{
		cout << "choose number you want to delete : " << endl;
		which_number_you_want(phonenumber1, phonenumber2, phonenumber3);
		int number_of_line_you_want_delete = 0;
		cin >> number_of_line_you_want_delete;
		if ((number_of_line_you_want_delete == 1 && phonenumber1) || (number_of_line_you_want_delete == 2 && phonenumber2) || (number_of_line_you_want_delete == 3 && phonenumber3))
		{
			cout << "deleted *-* " << endl;
			cout << "------------------------" << endl;
			signup[assign_to_user].lines[number_of_line_you_want_delete - 1].number = {};
			signup[assign_to_user].lines[number_of_line_you_want_delete - 1].flex = {};
			signup[assign_to_user].lines[number_of_line_you_want_delete - 1].balance = 10;
			signup[assign_to_user].lines[number_of_line_you_want_delete - 1].packagetype = "all 0.25";
			after_login_successfull(local_username, assign_to_user);
		}
	}
	else if (choose == 2)
	{
		string new_line;
		bool number_exist = false, numberonly = true;
		do {
			numberonly = true;
			if (number_exist == true)
			{
				cout << "Used number , please use another " << endl;
			}
			cout << "please Enter your number (only 11 number ) : " << endl;
			cin >> new_line;
			for (int local_iterator_to_check_line_exist = 0; local_iterator_to_check_line_exist <= global_iterator; local_iterator_to_check_line_exist++)
			{
				for (int lines_of_3number = 0; lines_of_3number < 3; lines_of_3number++)
				{
					if (signup[local_iterator_to_check_line_exist].lines[lines_of_3number].number == new_line)
					{
						number_exist = true;
						break;
					}
					else
						number_exist = false;
				}
				if (number_exist)
					break;
				for (int i = 0; i < new_line.size(); i++)
				{
					if (!isdigit(new_line[i]))
						numberonly = false;
				}
				if (numberonly == false)
				{
					cout << "*please Enter numbers only*" << endl;
				}
			}
		} while (new_line.size() != 11 || number_exist == true || numberonly == false);
		if (signup[assign_to_user].lines[0].number == "\0")
		{
			cout << "------------------------" << endl;
			cout << "you added a new number to " << local_username;
			signup[assign_to_user].lines[0].number = new_line;
			cout << "------------------------" << endl;
			after_login_successfull(local_username, assign_to_user);
		}
		else if (signup[assign_to_user].lines[1].number == "\0")
		{
			cout << "------------------------" << endl;
			cout << "you added a new number to " << local_username;
			signup[assign_to_user].lines[1].number = new_line;
			cout << "------------------------" << endl;
			after_login_successfull(local_username, assign_to_user);

		}
		else if (signup[assign_to_user].lines[2].number == "\0")
		{
			cout << "------------------------" << endl;
			cout << "you added a new number to " << local_username;
			signup[assign_to_user].lines[2].number = new_line;
			cout << "------------------------" << endl;
			after_login_successfull(local_username, assign_to_user);
		}
		else
		{
			cout << "------------------------" << endl;
			cout << "you have reached the maximum number of lines , please Delete line before add a new number " << endl;
			cout << "------------------------" << endl;
			after_login_successfull(local_username, assign_to_user);
		}
	}
	else
	{
		cout << "------------------------" << endl;
		cout << "Wrong Choise " << endl;
		cout << "------------------------" << endl;
		after_login_successfull(local_username, assign_to_user);

	}
}
