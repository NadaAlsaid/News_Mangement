#pragma once
#include <iostream>
#include "Admin.h"
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>
#include "User.h"
#include <unordered_map>
using namespace std;

struct  Details {

	string Title;
	string Writer;
	string Discrepition;
	string Date;
	string string_rate;
	string count;
	string spam;
};

class News
{

	string comment;
	string userComment;
	int count=0;
	float Rate;
	int total=0;
	int type = 0 ; 
	int NumberOfRate =0;
	int NumberOfSpam = 0;
public :
	void ChangeSpam(string);
	Details detail;
	string	string_type;
	News(void);
	vector<Details> ReadNews();
	unordered_map<int, vector<Details>> ReadCatogNews();
	bool ReadCertainNews(string);
	void WriteNews(int , string[]);
	void WriteComment(string);
	float CalculateRate(string , float , string );
	unordered_map<string , vector<string> > ReadComment();
	//vector<string>ReadComment(string title);
	int EndNumberOfNewsInCatogry(int);
	void ChangeRate(string , float);
};
