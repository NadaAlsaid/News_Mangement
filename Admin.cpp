#include "Admin.h"
//#include "News.h"
#include<iostream>
#include<fstream>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;
User re;
Admin::Admin()
{
	category = "";
	title = "";
	name = "";
	story = "";
	countpol = 0;
	counteco = 0;
	countart = 0;
	countspo = 0;
	countinter = 0;
	countsoc = 0;
}

int Admin::NumberOfNews(string cato , int PostOrUpdate) {
	News news;
	int value = 0;
	transform(cato.begin(), cato.end(), cato.begin(), ::tolower);
	if ( cato == "political" )
	{
		value = news.EndNumberOfNewsInCatogry(1);
		if (value == 0)
			return 11;
		else {
			countpol = 1 + ((value / 10) + 1) * 10;
			return countpol;
		}
	}
	else if (cato == "economic" ) {
		value = news.EndNumberOfNewsInCatogry(2);
		if (value == 0)
			return 12;
		else {
			counteco = 2+ ((value / 10) + 1) * 10;
			return counteco;
		}
	}
	else if (cato == ("art")) {
		value = news.EndNumberOfNewsInCatogry(3);
		if (value == 0)
			return 13;
		else {
			countart = 3 + ((value / 10) + 1) * 10;
			return countart;
		}
	}
	else if (cato == "sports") {
		value = news.EndNumberOfNewsInCatogry(4);
		if (value == 0)
			return 14;
		else {
			countspo = 4 + ((value / 10) + 1) * 10;
			return countspo;
		}
	}
	else if (cato == ("social")) {
		
		value = news.EndNumberOfNewsInCatogry(5);
		
		if (value == 0)
			return 15;
		else {
			countsoc = 5 +( (value / 10)+1 ) * 10;
			return countsoc;
		}
	}
	else if (cato == "weather") {
		value = news.EndNumberOfNewsInCatogry(6);
		
		if (value == 0)
			return 16;
		else {
			cout << countinter << endl;
			countinter = 6 + ((value / 10) + 1) * 10;
		
			return countinter;
		}
	}
	else {
		cout << "Sorry, The category that you search about isn't found ."<< endl ;
		if (PostOrUpdate == 0)
			post();
		else if (PostOrUpdate == 1)
			update();
		return 0;
	}
	
}

//
//void Admin::post() {
//	News news;
//	cout << "enter the category of the news: \n";
//	getline(cin>> ws, category);
//	int value = NumberOfNews(category, 0);
//	if (value == 0)
//		return;
//	cout << "enter the title of the news: \n";
//
//	getline(cin, title);
//	detail[0] = title;
//	//cout << title<< endl;
//	cout << "enter the name of the writer:\n";
//
//	getline(cin, name);
//	detail[1] = name;
//	//cout << name<<endl;
//	cout << "enter the story of the news: \n";
//
//	getline(cin, story ) ;
//	detail[2] = story;
//	//cout << story<< endl;
//	cout << "enter the Date of the news: \n";
//	
//	getline(cin, Date );
//	detail[3] = Date;
//	//cout << Date << endl;
//	news.WriteNews( value , detail);
//
//	cout << " data saved:\n";
//	
//}

void Admin::post() {
	News news;
	Newsdetails newsdetails;
	cout << "enter the category of the news: \n";
	getline(cin >> ws, newsdetails.category);
	int value = NumberOfNews(newsdetails.category, 0);
	if (value == 0)
		return;
	cout << "enter the title of the news: \n";

	getline(cin, newsdetails.title);
	detail[0] = newsdetails.title;
	//cout << title<< endl;
	cout << "enter the name of the writer:\n";

	getline(cin, newsdetails.name);
	detail[1] = newsdetails.name;
	//cout << name<<endl;
	cout << "enter the story of the news: \n";

	getline(cin, newsdetails.story);
	detail[2] = newsdetails.story;
	//cout << story<< endl;
	cout << "enter the Date of the news: \n";

	getline(cin, newsdetails.Date);
	detail[3] = newsdetails.Date;
	//cout << Date << endl;
	news.WriteNews(value, detail);
	cout << " data saved:\n";

}

void Admin::delete_category() {
	News news;
	string titl;
	cout << "enter the title: \n";
	cin >> titl;
	bool r= news.ReadCertainNews(titl);
	if (r == true) {
		cout << "if you want to delete a record press( y):\n";
		char option;
		cin >> option;
		if (option == 'y' || option == 'Y') {
			ofstream tempfile;
			tempfile.open("temp.txt");
			ifstream read;
			read.open("News.txt");
			while (getline(read, category) &&
				getline(read, title) &&
				getline(read, name) &&
				getline(read, story) &&
				getline(read, Date) &&
				getline(read, rate) &&
				getline(read, news.detail.count) &&
				getline(read, news.detail.spam))
			{
				transform(titl.begin(), titl.end(), titl.begin(), ::tolower);
				if (titl != title)
				{
					tempfile << category << "\n"
						<< title << "\n"
						<< name << "\n"
						<< story << endl
						<< Date << endl
						<< rate << endl
						<< news.detail.count << endl
						<< news.detail.spam << endl;

				}

			}
			read.close();
			tempfile.close();
			remove("News.txt");
			rename("temp.txt", "News.txt");
			cout << "data is removed:\n";
		}
	}
	else 
	{
		cout << "Sorry, The title that you search about isn't found ." << endl;
		cout << " press 1 To continue to delete news or press 2 if not " << endl;
		int choose; 
		cin >> choose;
		if (choose == 1) {
			delete_category();
		}
		else if (choose == 2) {
			return;
		}
		else {
			cout << "Please , Enter 1 or 2 only" << endl;
		}
	}
}

void Admin::update() {
	News news;
	string titl;
	cout << "enter the title: \n";
	cin >> titl;
	bool r = news.ReadCertainNews(titl);
	if (r) {
		char option;
		cout << "if you want to Update a record press( y):\n";
		cin >> option;
		if (option == 'y' || option == 'Y') {
			ofstream tempfile;
			tempfile.open("temp.txt");
			ifstream read;
			read.open("News.txt");
			cout << "enter the category of the news: " << endl;
			getline(cin >> ws, category);
			int value = NumberOfNews(category, 1);
			if (value > 0) {
				cout << "enter the title of the news: " << endl;
				getline(cin, title);
				//cout << title << endl;
				cout << "enter the name of the writer:\n";
				getline(cin, name);
				//cout << name << endl;
				cout << "enter the story of the news: \n";
				getline(cin, story);
				//cout << story << endl;
				cout << "enter the Date of the news: \n";
				getline(cin, Date);
				//cout << Date << endl;
				while (getline(read, news.string_type) && 
					getline(read, news.detail.Title) && 
					getline(read, news.detail.Writer) &&
					getline(read, news.detail.Discrepition) && 
					getline(read, news.detail.Date) &&
					getline(read, news.detail.string_rate)&& 
					getline(read, news.detail.count) &&
					getline(read, news.detail.spam))
				{
					transform(titl.begin(), titl.end(), titl.begin(), ::tolower);
					if (titl != news.detail.Title)
					{
						tempfile << news.string_type << "\n"
							<< news.detail.Title << "\n"
							<< news.detail.Writer << "\n"
							<< news.detail.Discrepition << endl
							<< news.detail.Date << endl
							<< news.detail.string_rate << endl
							<< news.detail.count << endl
							<< news.detail.spam << endl;
						
					}
					else
					{
						transform(title.begin(), title.end(), title.begin(), ::tolower);
						tempfile << to_string(value) << "\n"
							<< title << "\n"
							<< name << "\n"
							<< story << endl
							<< Date << endl
							<< news.detail.string_rate << endl
							<< news.detail.count << endl
							<< news.detail.spam << endl;
						
					}
				}
			}
			read.close();
			tempfile.close();
			remove("News.txt");
			rename("temp.txt", "News.txt");
			cout << "data is Updated .\n";
		}
	}
	else
	{
		cout << "Sorry, The title that you search about isn't found ." << endl;
		cout << " press 1 To continue to update news or press 2 if not " << endl;
		int choose;
		cin >> choose;
		if (choose == 1) {
			update();
		}
		else if (choose == 2) {
			return;
		}
		else {
			cout << "Please , Enter 1 or 2 only" << endl;
		}
	}
}

void Admin::readdata() {
	News news;
	vector<Details> st = news.ReadNews();
	
	cout << "****** THE NEWS ******* \n";
	for (int i = 0 ; i < st.size() ; i++) {
		cout << st[i].Title << "\n";
		cout << st[i].Writer << "\n";
		cout << st[i].Discrepition << "\n";
		cout << st[i].Date << "\n";
		cout << st[i].string_rate << "\n";
		
	}
	
}
void Admin::options() {


	cout << "1:To post a new \n";
	cout << "2:To update a new \n";
	cout << "3:To delete data a new \n";
	cout << "4:To read data a new \n";
	cout << "5:To logout \n";
	cout << "enter your option :\n";
	cin >> option;
	switch (option)
	{
	case 1:
		post();
		break;
	case 2:
		update();
		break;
	case 3:
		delete_category();
		break;
	case 4:
		readdata();
		break;
	case 5:
		system("cls");
		re.intialization();
		break;
	default:
		cout << "invalid option: \n";
		break;
	}
	Choice();
}

void Admin::Choice()
{
	cout << "If you want to choose another choice press --> 7 or 8 to log out" << endl;
	cin >> option;
	if (option == 7) {
		options();
		system("cls");
	}
	else if (option == 8)
	{
		re.intialization();
		system("cls");
	}

}
