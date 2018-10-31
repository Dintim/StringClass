#pragma once
#include <iostream>
using namespace std;
class string_
{
	char* str;
	int length;
public:
	string_();
	string_(int length);
	string_(const char* str);
	string_(const string_ &obj);
	int getLength()const;
	const char* getString()const;
	void setString(const char* str);
	void print();
	void input();
	~string_();
	void clear();
	void insert(int position, const char * str);
	void erase(int position, int cnt);
	string_ operator += (const string_&str);
	string_& operator=(const string_&str);
	string_(string_&&str);
	string_& operator=(string_&&str);
};

ostream&operator<<(ostream&os, const string_&obj);
istream&operator>>(istream&is, string_&obj);