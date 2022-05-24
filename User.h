#pragma once
#include "News.h"
#include "Admin.h"

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <unordered_map>
using namespace std;
struct spamDetails {
	string use;
	string title;
};
struct  Details;
class User
{
	
	int choice;
	float rate;
	int count = 0;
	unordered_map<string, vector<string> >  comments;
	unordered_map<int, vector<Details>> specificNews;
	unordered_map<string, vector<string>> mspam;
	//map<string,map<string,vector<string> > m;
public:
	string tit;
	string newsnumber;
	string user;
	string cata;
	void login();
	void registration();
	void intialization();
	void forget_pass();
	bool checkRateAll(string);
	void OptionRateAll();
	void RateAll();
	void Display_Latest_News();
	void Show();
	void Spam();
	bool checkspam(string);
	void OptionSpam();
	void DisplayComment();
	void op();
	unordered_map<string, vector<string>> vspam();
};
