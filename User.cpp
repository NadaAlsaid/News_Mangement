#include "User.h"
#include<iostream>
#include<fstream>
#include<string>
#include <unordered_map>

using namespace std;

Admin admin;
News news;

//login

void User::login()
{
	string Username, Password, name, pass;
	system("cls");
	cout << "please enter the username and pass to login" << endl;
	cout << "User name -->" << endl;
	getline(cin >> ws, Username);
	user = Username;
	cout << "password -->" << endl;
	getline(cin, Password);

	ifstream input("project.txt");
	while (getline(input, name) && getline(input, pass))
	{
		if (name == Username && pass == Password)
		{
			if (Username == "nada" && Password == "2468")
			{
				
				system("cls");
				admin.options();
				cout << endl;
			}
			else
			{
				count = 1;
				system("cls");
			}
		}
	}
	input.close();
	comments = news.ReadComment();
	specificNews = news.ReadCatogNews();
	msam = pam();
	if (count == 1)
	{
		
		cout << "\t\t\t\t\t # Your Login is successful #" << endl;
		cout << "To display news press --> 1 " << endl;
		cout << "To show news in categories press --> 2 " << endl;
		cout << "To logout press--> 3 " << endl;

		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			Display_Latest_News();
		}
		else if (choice == 2)
		{
			system("cls");
			Show();
		}
		else if (choice == 3)
		{
			system("cls");
			intialization();
		}

	}
	else
	{
		cout << "Your User Name or Password is not correct" << endl;
		cout << " press 1 To main menu " << endl;
		int choose;
		cin >> choose;
		if (choose == 1) {
			system("cls");
			intialization();
		}
	}
}

//registration

void User::registration()
{
	string Reg_Username, Reg_Password, reg_name, reg_pass;
	system("cls");
	cout << "User name" << endl;
	getline(cin >> ws, Reg_Username);
	for (int i = 0; i < 1; i++)
	{
		if (isdigit(Reg_Username[i]))
		{
			count++;
		}
	}
	if (count == 1)
	{
		cout << "The user name should not contain numbers " << endl;
	}
	else
	{
		cout << "password" << endl;
		getline(cin, Reg_Password);
		if (Reg_Password.length() < 4)
		{
			cout << "passowrd is weak" << endl;
			cout << endl;
			cout << "To go to the main menue press--> 5 " << endl;
			cin >> choice;
			if (choice == 5)
				intialization();
		}
		else
		{
			ifstream input("project.txt");
			while (getline(input, reg_name) && getline(input, reg_pass))
			{
				if (reg_name == Reg_Username)
				{
					count = 2;
					system("cls");
				}
			}

			input.close();
			if (count == 2)
			{
				cout << "the name has already exist" << endl;
				cout << "please change it" << endl;
				cout << endl;
				cout << "------------------------------------------------------------" << endl;
				cout << "To go to the main menue press--> 5 " << endl;
				cin >> choice;
				if (choice == 5)
					intialization();
			}
			else
			{
				ofstream input("project.txt", ios::app);
				input << Reg_Username << endl << Reg_Password << endl;
				system("cls");
				cout << "\t\t\t\t\t # Registration is successful # " << endl;
				cout << "Enter your info to login to system" << endl;
				login();

			}
		}
	}
}

//forget password
void User::forget_pass() {

	bool d = false;
	string  f_Username, f_name, f_pass;
	string s;
	system("cls");
	cout << "To recover your password press-->(1)" << endl;
	cout << "To go to the main menue press--> (2) " << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "Enter your username -->";
		cin >> f_Username;
		ifstream f3("project.txt");
		while (f3 >> f_name >> f_pass)
		{
			if (f_name == f_Username)
			{
				s = f_pass;
				count = 3;
				system("cls");
			}
		}
		f3.close();
		if (count == 3)
		{
			cout << f_Username << "\t your account is found and your password is-->(" << s << ")" << endl;
			intialization();
		}
		else
		{
			cout << "your account is not found" << endl;
			intialization();
		}
	}
	else if (choice == 2)
	{
		system("cls");
		intialization();
	}
}
//------------------------------------------

void User::intialization()
{
	cout << "\t\t\t\t---------------------------------------------------" << endl;
	cout << "\t\t\t\t\t welcome to news management system" << endl;
	cout << "\t\t\t\t---------------------------------------------------" << endl;
	cout << "Menu" << endl;
	cout << "---------" << endl;
	cout << "press (1) to Login" << endl;
	cout << "press (2) to Register" << endl;
	cout << "press (3) to forget password" << endl;
	cout << "press (4) to Exit" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		login();
		break;

	case 2:
		registration();
		break;

	case 3:
		forget_pass();
		break;
	case 4:
		cout << "Good bye" << endl;
		break;
	default:
		system("cls");
		cout << "wrong selection,please select" << endl;
		cout << endl;
		cout << " --> (1 to Login) or" << endl;
		cout << " --> (2 to Registration) or" << endl;
		cout << " --> (3 to Exist)" << endl;
		intialization();
	}
}

//------------------------------------------

bool User::checkRateAll(string title)
{

	string d_name, d_rate, d_title;
	ifstream f1("rateAll.txt", ios::app);

	while (getline(f1, d_name) && getline(f1, d_title) && getline(f1, d_rate))
	{

		//cout << r_name << "            " << r_cata << "      " << r_new << endl;
		if (d_name == user && d_title == title)
		{
			f1.close();
			return true;
			system("cls");
		}
	}
	f1.close();
	return false;
}

void User::RateAll()
{
	cout << "Title" << endl;
	getline(cin >> ws, tit);

	bool flage = checkRateAll(tit);
	if (flage)
	{
		cout << "Sorry,You cannot rate again" << endl;
		OptionRateAll();

	}
	else
	{
		cout << "rate" << endl;
		//getline(cin, rate);
		cin >> rate;
		if (rate > 0 && rate <= 5)
		{
			news.ChangeRate(tit, rate);
			ofstream input("rateAll.txt", ios::app);
			input << user << endl << tit << endl << to_string(rate) << endl;
		}
		else
		{
			cout << "you can’t rate more than 5 strars" << endl;
			OptionRateAll();
		}
		
		OptionRateAll();
		system("cls");
	}
}

void User::OptionRateAll()
{
	cout << endl;
	cout << "Do you rate on another news ? " << endl;
	cout << "Y/N" << endl;
	string option;
	getline(cin >> ws , option);
	if (option == "y" || option == "Y")
		RateAll();
	else if (option == "n" || option == "N")
	{
		op();
		return;
	}
	else {
		cout << "       Enter character Y or N       " << endl;
		OptionRateAll();
	}
}

//----------------------------------------

void User::op() {
	cout << "**************" << endl;
	cout << "To write comment press--> 1 " << endl;
	cout << "To rate press--> 2 " << endl;
	cout << "To spam press--> 3 " << endl;
	cout << "To display news please press-->4\n";
	cout << "To show news in categories press -->5\n ";
	cout << "To logout press--> 6 " << endl;


	string choose;
	cin >> choose;
	if (choose == "1")
	{
		news.WriteComment(user);
		comments = news.ReadComment();
		specificNews = news.ReadCatogNews();
		op();
	}
	else if (choose == "2")
	{
		RateAll();
		comments = news.ReadComment();
		specificNews = news.ReadCatogNews();
	}
	else if (choose == "3")
	{
		Spam();
		msam = pam();
		comments = news.ReadComment();
		specificNews = news.ReadCatogNews();
	}
	else if (choose == "4")
	{
		system("cls");
		msam = pam();
		Display_Latest_News();

	}
	else if (choose == "5")
	{
		system("cls");
		msam = pam();
		Show();
	}
	else if (choose == "6")
	{
		system("cls");
		intialization();
	}
	else {
		cout << "\t\t\t\t\t * invalid option *\n";
		op();
	}

}

void User::Display_Latest_News()
{

	News news;
	vector<Details> v = news.ReadNews();
	Details s;


	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if ((v[i].string_rate < v[j].string_rate) && (v[i].Date > v[j].Date))
			{
				s = v[i];
				v[i] = v[j];
				v[j] = s;

			}
		}

	}
	vector<string> d;
	if (msam.find(user) != msam.end()) {
		d = msam.at(user);
	}
	cout << "                                  ******* THE NEWS ******* \n";
	for (int i = 0; i < v.size(); i++)
	{
		if (d.size() != 0 && find(d.begin(), d.end(), v[i].Title) != d.end()) {
			continue;
		}else{
			cout << "                                      " << v[i].Title << endl;
			cout << "Date : " << v[i].Date << endl;
			cout << "   " << v[i].Discrepition << endl;
			cout << "Writen by :" << v[i].Writer << endl;
			cout << "Rate :" << v[i].string_rate << endl;
			cout << "The number of spam :" << v[i].spam << endl;
			if (comments.find(v[i].Title) != comments.end()) {
				vector<string> comment = comments.at(v[i].Title);
				//if (comment[0] != "00") {
				for (int j = 0; j < comment.size(); j += 2) {
					if (j == 0)
						cout << endl;
					cout << "*********************************************** \n";
					cout << comment[j] << endl << comment[j + 1] << endl;
				}
				//}
				cout << endl;
			}
		}
	}
	op();
}

void User::Show()
{
	cout << "Press 1 to display political news \n";
	cout << "Press 2 to display economic news\n";
	cout << "Press 3 to display art news\n";
	cout << "Press 4 to display sports news\n";
	cout << "Press 5 to display social news\n";
	cout << "Press 6 to display weather news\n ";
	int catoType;
	cin >> catoType;
	if (catoType < 7 && catoType>0) {
		if (specificNews.find(catoType) != specificNews.end()) {
			vector<Details> v = specificNews.at(catoType);
			vector<string> d;
			if (msam.find(user) != msam.end()) {
				 d = msam.at(user);
			}
			cout << "                                  ******* THE NEWS ******* \n";
			for (int j = 0; j < v.size(); j++)
			{
					if (d.size() != 0 && find(d.begin(), d.end(), v[j].Title) != d.end()) {
						continue;
					}
				
				else
				{
					cout << "                                     " << v[j].Title << endl;
					cout << "Date : " << v[j].Date << endl;
					cout << "   " << v[j].Discrepition << endl;
					cout << "Writer : " << v[j].Writer << endl;
					cout << "Rate :" << v[j].string_rate << endl;
					cout << "The number of spam :" << v[j].spam << endl;

					if (comments.find(v[j].Title) != comments.end()) {
						vector<string> comment = comments.at(v[j].Title);
						//if (comment[0] != "00") {
						for (int z = 0; z < comment.size(); z += 2) {
							if (z == 0)
								cout << endl;
							cout << "*********************************************** \n";
							cout << comment[z] << endl << comment[z + 1] << endl;
						}
						//}

					}
					cout << endl;
				}
			}
			op();
		}
			else {
				cout << "This category hasn't news yet" << endl;
				op();
			}
		}
	else {
		cout << "Wrong choose" << endl;
		op();
	}

}

//-----------------------------------------

bool User::checkspam(string title) {
	spamDetails spamdetails;
	ifstream f1("spam.txt", ios::app);
	while (getline(f1, spamdetails.use)) {
		while (getline(f1, spamdetails.title))
		{
			if (spamdetails.title == "1")
			{
				break;
			}
			else
			{
				if (user == spamdetails.use) {
					if (title == spamdetails.title) {
						f1.close();
						return false;
					}
				}
				else
				{
					continue;
				}
			}
		}


	}

	f1.close();
	return true;
}

void User::Spam()
{
	cout << "please enter title " << endl;
	getline(cin >> ws ,tit);
	bool isSpamed = checkspam(tit);
	bool isFound = false;
	ifstream f1("spam.txt", ios::app);
	ofstream tempfile;
	tempfile.open("tempfile.txt");
	spamDetails spamdetails;
	if (isSpamed) {
		news.ChangeSpam(tit);
		while (getline(f1, spamdetails.use)) {
			tempfile << spamdetails.use << "\n";
			while (getline(f1, spamdetails.title))
			{
				if (spamdetails.title != "1")
				{
					tempfile << spamdetails.title << "\n";
				}
				else
				{

					if (user == spamdetails.use) {
						isFound = true;
						tempfile << tit << "\n";

					}
					tempfile << spamdetails.title << "\n";
					break;
				}
			}
		}
		if (!isFound) {
			tempfile << user << "\n" << tit << "\n" << "1" << "\n";
		}
		f1.close();
		tempfile.close();
		remove("spam.txt");
		rename("tempfile.txt", "spam.txt");
		cout << "Data is spammed .\n";
		OptionSpam();

	}
	else
	{
		cout << "Sorry,You cannot spam again" << endl;
		OptionSpam();
	}

}

void User::OptionSpam()
{
	cout << endl;
	cout << "Do you spam another news ? " << endl;
	cout << "Y/N" << endl;
	string option;
	getline(cin >> ws, option) ;
	if (option == "y" || option == "Y")
		Spam();
	else if (option == "n" || option == "N")
	{
		op();
		return;
	}
	else {
		cout << "       Enter character Y or N       " << endl;
		OptionSpam();
	}
}

unordered_map<string, vector<string>> User::pam()
{

	ifstream f1("spam.txt", ios::app);
	string use;
	unordered_map<string, vector<string> > mapspam;
	while (getline(f1,use )) {
		while (getline(f1, tit))
		{
			if (tit != "1")
				spamNews.push_back(tit);
			else
				break;
		}
		cout << spamNews.size() << endl;
		mapspam.insert(make_pair(use, spamNews));
		spamNews.clear();
	}
	f1.close();
	return mapspam;
}
