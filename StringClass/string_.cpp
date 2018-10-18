#include "string_.h"



string_::string_()
{
	this->str = nullptr;
	this->length = 0;
}

string_::string_(int length)
{
	this->str = new char[length + 1];
	str[length] = '\0';
	this->length = length;
}


string_::string_(const char * str)
{
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);
	this->length = strlen(str);
}

string_::string_(const string_ & obj)
{
	this->length = obj.length;
	if (obj.length == 0) {
		this->str = nullptr;
		return;
	}
	this->str = new char[obj.length + 1];
	strcpy_s(this->str, obj.length + 1, obj.str);
}

int string_::getLength()
{
	return this->length;
}

const char * string_::getString()
{
	return this->str;
}

void string_::setString(const char * str)
{
	this->~string_();
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);
	this->length = strlen(str);
}

void string_::print()
{
	cout << this->str;
}

void string_::input()
{
	char tmp[1200];
	cin.getline(tmp, 1200);
	this->~string_();
	this->str = new char[strlen(tmp) + 1];
	strcpy_s(this->str, strlen(tmp) + 1, tmp);
	this->length = strlen(tmp);
}


string_::~string_()
{
	if (this->str != nullptr)
		delete[] str;
	this->str = nullptr;
	this->length = 0;
}

void string_::clear()
{
	this->~string_();
}

void string_::insert(int position, const char* str)
{
	if (str == nullptr || position < 0 || position > this->length)
		return;
	if (this->str == nullptr && position == 0) {
		this->setString(str);
		return;
	}
	char* tmp = new char[this->length + strlen(str) + 1];
	for (int i = 0; i < position; i++) 
		tmp[i] = this->str[i];
	for (int i = position, j = 0; j < position+strlen(str); i++, j++)
		tmp[i] = str[j];
	for (int i = position + strlen(str), j = position; i < this->length + strlen(str); i++, j++) 
		tmp[i] = this->str[j];

	tmp[length + strlen(str)] = '\0';
	this->~string_();
	this->setString(tmp);

}

void string_::erase(int position, int cnt)
{
	if (this->length == 0)
		return;
	char* tmp = new char[this->length - cnt + 1];
	int k = 0;
	for (int i = 0; i < position; i++)
		tmp[k++] = this->str[i];
	for (int i = position + cnt; i < this->length; i++)
		tmp[k++] = this->str[i];
	tmp[length - cnt] = '\0';
	this->~string_();
	this->setString(tmp);
}
