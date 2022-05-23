#include "News.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;
User user;

News::News() {
	Rate = 0;
	count=0;

}

vector<Details>News::ReadNews() {
	ifstream input;
	input.open("News.txt", ios::app);
	assert(!input.fail());
	vector<Details> details;
	while (getline(input ,string_type) && getline(input, detail.Title) && getline(input, detail.Writer) &&
		getline(input, detail.Discrepition)&& getline(input, detail.Date )&& 
		getline(input, detail.string_rate) &&
		getline(input, detail.count) &&
		getline(input, detail.spam))
	{

		details.push_back(detail);

	} input.close();
	return details;
}

unordered_map<int, vector<Details>> News::ReadCatogNews () {
	ifstream input;
	input.open("News.txt", ios::app);
	assert(!input.fail());
	vector<Details> details;
	unordered_map<int, vector<Details>> news;
	while (getline(input, string_type) &&
		getline(input, detail.Title) && 
		getline(input, detail.Writer) &&
		getline(input, detail.Discrepition) && 
		getline(input, detail.Date) &&
		getline(input, detail.string_rate) &&
		getline(input, detail.count) &&
		getline(input, detail.spam))
	{
		
		stringstream geek(string_type);
		geek >> type;
		type = type % 10;
		if (news.find(type) != news.end()) {
			details = news.at(type);
			news.erase(type);
		}
		details.push_back(detail);
		news.insert(make_pair(type, details));
		details.clear();
	}
	
	input.close();
	return news;
}

bool News::ReadCertainNews(string titl) {

	ifstream input;
	input.open("News.txt");

	while (getline(input, string_type) && 
		getline(input, detail.Title) && 
		getline(input, detail.Writer) &&
		getline(input, detail.Discrepition) && 
		getline(input, detail.Date) && 
		getline(input, detail.string_rate) &&
		getline(input, detail.count) &&
		getline(input, detail.spam))
	{
		transform(titl.begin(), titl.end(), titl.begin(), ::tolower);
		if (titl == detail.Title ) {
			
			input.close();
			return true;
		}

	} 
	input.close();
	return false;
//	cout << detail.Title << "        " << detail.Writer << "     " << detail.Discrepition << "        " << detail.Date << endl;
}

float News::CalculateRate(string oldRate , float rate , string counter) {
	float old = stof(oldRate);
	stringstream geek(counter);
	geek >> NumberOfRate;
	++NumberOfRate;
	detail.count = to_string(NumberOfRate);
	return ( (NumberOfRate-1.0)/ NumberOfRate )* old +(1.0 / NumberOfRate )* rate;
}

void News::ChangeRate( string titl , float rate) {

	bool isFoundTitle = ReadCertainNews(titl);
	cout << isFoundTitle << endl;
	if (isFoundTitle == true ) {
		ofstream tempfile;
		tempfile.open("temp.txt");
		ifstream input;
		input.open("News.txt");
		while (getline(input, string_type) &&
			getline(input, detail.Title) &&
			getline(input, detail.Writer) &&
			getline(input, detail.Discrepition) && 
			getline(input, detail.Date )&&
			getline(input, detail.string_rate) &&
			getline(input, detail.count) &&
			getline(input, detail.spam))
		{
			transform(titl.begin(), titl.end(), titl.begin(), ::tolower);
			if (titl != detail.Title)
			{
				tempfile << string_type << "\n"
					<< detail.Title << "\n"
					<< detail.Writer << "\n"
					<< detail.Discrepition << endl
					<< detail.Date << endl
					<< detail.string_rate << endl
					<< detail.count << endl
					<< detail.spam << endl;
			
			}
			else
			{
				float newRate = CalculateRate(detail.string_rate, rate, detail.count);
				if (newRate <= 2) {
					continue;
				}
				cout << newRate << endl;
				tempfile << string_type << "\n"
					<< detail.Title << "\n"
					<< detail.Writer << "\n"
					<< detail.Discrepition << endl
					<< detail.Date << endl
					<< to_string(newRate)<< endl
					<< detail.count << endl
					<< detail.spam << endl;
				
			}

		}
		input.close();
		tempfile.close();
		remove("News.txt");
		rename("temp.txt", "News.txt");
		cout << "Done \n";
	}
	else {
		cout << "Sorry, The title that you search about isn't found ." << endl;
		user.RateAll();
		return;
	}
}

void News::WriteNews(int Type , string detail[]) {
	ofstream input("News.txt", ios::app);
	assert(!input.fail());
	transform(detail[0].begin(), detail[0].end(), detail[0].begin(), ::tolower);
	input << to_string(Type) << endl
		<< detail[0] << endl
		<< detail[1] << endl
		<< detail[2] << endl
		<< detail[3] << endl
		<< to_string(Rate) << endl
		<< to_string(count) << endl 
		<< to_string(NumberOfSpam) << endl;
	system("cls");
	input.close();
}

int News::EndNumberOfNewsInCatogry(int cato) {
	ifstream input;
	input.open("News.txt", ios::app);
	assert(!input.fail());
	while (getline(input, string_type)&&
		getline(input, detail.Title)&&
		getline(input, detail.Writer)&&
		getline(input, detail.Discrepition)&&
		getline(input, detail.Date)&&
		getline(input, detail.string_rate)&& 
		getline(input, detail.count) &&
		getline(input, detail.spam)) {

		stringstream geek(string_type);
		geek >> type;
		if (cato == (type % 10) ){
			
			count = type; 
		}
	}
	return count ;
}

void News::WriteComment(string user) {
	string title, comments;
	cout << "please enter title " << endl;
	getline(cin >> ws, title);
	bool isFound = ReadCertainNews(title);
	bool isComment = false ;
	ifstream input("Comments.txt", ios::app);
	assert(!input.fail());
	ofstream tempfile;
	tempfile.open("tempfile.txt");

	if (isFound) {
		cout << "please enter comment " << endl;
		getline(cin, comments);
		while (getline(input, string_type)  ) {
			tempfile << string_type << "\n";
			while ( getline(input, userComment))
			{
				if (userComment != "1")
				{
					getline(input, comment);
					tempfile << userComment << "\n" << comment << "\n";
				}
				else
				{
					
					if (string_type == title) {
						tempfile << user << " comment :\n"  << comments << "\n";
						isComment = true;
					}
					tempfile << userComment << "\n";
					break;
				}
			}
		}
		if(!isComment)
			tempfile  << title << "\n" << user << " comment :\n" << comments << "\n" << "1" << "\n";
		input.close();
		tempfile.close();
		remove("Comments.txt");
		rename("tempfile.txt", "Comments.txt");
		
	}
	else 
	{
		cout << "Sorry, The title that you search about isn't found ." << endl;
		cout << " press 1 To continue to comment on another news or press 2 if not " << endl;
		string choose;
		cin >> choose;
		if (choose == "1") {
			WriteComment(user);
			return;
		}
		else if (choose == "2") {
			return;
		}
		else {
			cout << "Please , Enter 1 or 2 only" << endl;
			cin >> choose;
			WriteComment(user);
		}
	}
	system("cls");
}

unordered_map<string, vector<string>> News::ReadComment() {
	ifstream input;
	input.open("Comments.txt", ios::app);
	assert(!input.fail());
	vector<string> details;
	unordered_map<string, vector<string>> comments ;
	while (getline(input, string_type) ) {
		while ( getline(input, userComment) )
		{
			if (userComment == "1")
			{
				break;
			}
			else
			{
				getline(input, comment);
				details.push_back(userComment);
				details.push_back(comment);
			
			}
		}
		if(!details.empty())
			comments.insert(make_pair(string_type, details));
		details.clear();
	}
	input.close();
	return comments;
}

//vector<string> News::ReadComment(string title) {
//	ifstream input;
//	input.open("Comments.txt", ios::app);
//	assert(!input.fail());
//	vector<string> details;
//	transform(title.begin(), title.end(), title.begin(), ::tolower);
//	while (getline(input, string_type)) {
//		while (getline(input, userComment))
//		{
//			if (userComment == "1")
//			{
//				break;
//			}
//			else
//			{
//				getline(input, comment);
//				if (string_type == title) {
//					details.push_back(userComment);
//					details.push_back(comment);
//
//				}
//			}
//		}
//	}
//	input.close();
//	return details;
//}

void News::ChangeSpam(string titl) {

	bool isFoundTile = ReadCertainNews(titl);
	cout << isFoundTile << endl;
	if (isFoundTile == true) {
		ofstream tempfile;
		tempfile.open("temp.txt");
		ifstream input;
		input.open("News.txt");
		while (getline(input, string_type) &&
			getline(input, detail.Title) &&
			getline(input, detail.Writer) &&
			getline(input, detail.Discrepition) &&
			getline(input, detail.Date) &&
			getline(input, detail.string_rate) &&
			getline(input, detail.count) &&
			getline(input, detail.spam))
		{
			transform(titl.begin(), titl.end(), titl.begin(), ::tolower);
			if (titl != detail.Title)
			{
				tempfile << string_type << "\n"
					<< detail.Title << "\n"
					<< detail.Writer << "\n"
					<< detail.Discrepition << endl
					<< detail.Date << endl
					<< detail.string_rate << endl
					<< detail.count << endl
					<< detail.spam << endl;
			}
			else
			{
				stringstream geek(detail.spam);
				geek >> NumberOfSpam;
				NumberOfSpam++;
				tempfile << string_type << "\n"
					<< detail.Title << "\n"
					<< detail.Writer << "\n"
					<< detail.Discrepition << endl
					<< detail.Date << endl
					<< detail.string_rate << endl
					<< detail.count << endl
					<< to_string(NumberOfSpam) << endl;
				
			}

		}
		input.close();
		tempfile.close();
		remove("News.txt");
		rename("temp.txt", "News.txt");
		cout << "Done \n";
	}
	else {
		cout << "Sorry, The title that you search about isn't found ." << endl;
		cout << " press 1 To continue to Spam news or press 2 if not " << endl;
		int choose;
		cin >> choose;
		if (choose == 1) {
			user.Spam();
		}
		else if (choose == 2) {
			return;
		}
		else
		{
			cout << "Please , Enter 1 or 2 only" << endl;
		}
	}
}
