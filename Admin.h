#pragma once
#include "News.h"
#include "User.h"
#include<iostream>
#include<conio.h>
#include<string>
#include<list>
#include<stdio.h>
#include<stdlib.h>




using namespace std;

struct Newsdetails {
	string title;
	string name;
	string story;
	string Date;
	string category;
	string rate;
};
class Admin
{
	string  title, name, story, Date, category , rate;
	int countpol ,counteco , countart ,countspo ,countinter , countsoc ;
	string  detail[4];
	
	/*struct node*head;*/
public:
	int option;
	Admin(void);
	void post();
	void readdata();
	void delete_category();
	void update();
	int NumberOfNews(string,int);
	void options();
	void Choice();
	
};
