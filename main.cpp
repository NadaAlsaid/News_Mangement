#include <iostream> 
#include "News.h"
#include "Admin.h"
#include "User.h"
#include <fstream>
#include <string>
#include <vector>
//#include "User.h"
using namespace std;

int main() {
	//User users;

	News n;
	//unordered_map<string, vector<string> >  comment = n.ReadComment();
	User r;//(comment);
	Admin a;
	
	/*vector<Details> v = news.ReadNews();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].Date << "      " << v[i].Discrepition << endl;

	}*/
	r.intialization();

	/*
	r.intialization();
	r.Spam();
	a.readdata();
	a.update();
	a.readdata();
	a.delete_category();
	a.readdata();
	news.ChangeRate("bassant", 3.3);
	a.readdata();
	system("Pause");*/
	return 0;
}


