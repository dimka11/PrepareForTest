#include <ostream>
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <complex>
using namespace std;

struct NotCopyable
{
	NotCopyable() = default;
	NotCopyable(const NotCopyable&) = delete;
	//NotCopyable& operator = (const NotCopyable&) = delete;

	NotCopyable(NotCopyable&&) = default;
	NotCopyable& operator = (NotCopyable&&) = default;
};

class SF
{
	int number;
public:
	SF(const int num) : number(num){}
	void operator()(){
		std::cout << number;
	}
};
class Complex {
	double re, im;
	Complex(double re, double im);
	operator Complex() {
		//return re;
	}
};

class String
{
	char *s;
	size_t size;

public:
	String(char* other)
	{
		s = new char[size + 1];
		strcpy(s, other);
		size = strlen(other);
	}
	String& operator=(String const&other)
	{
		if(this != &other)
		{
			delete[] s;
			s = new char[other.size + 1];
			strcpy(s, other.s);
			size = other.size;
		}
	}
	operator char*(){
		return s;
	}
	bool  operator==(const String& rhs)
	{
		return !(strcmp(s, rhs.s));
	}
	bool  operator>(const String& rhs)
	{
		return strcmp(s, rhs.s) > 0;
	}
	bool  operator<(const String& rhs)
	{
		return strcmp(s, rhs.s) < 0;
	}
	bool  operator>=(const String& rhs)
	{
		return strcmp(s, rhs.s) >= 0;
	}
	bool  operator<=(const String& rhs)
	{
		return strcmp(s, rhs.s) <= 0;
	}

	String(const char* other)
	{
		s = new char[size + 1];
		strcpy(s, other);
		size = strlen(other);
	}

	~String()
	{
		delete[] s;
	}
	String(String const& other)
	{
		s = new char[other.size + 1];
		strcpy(s, other.s);
		size = other.size;
	}
	String(const char other)
	{
		s = new char[1+1];
		strcpy(s, &other);
		size = 1;
	}
	/*
	String operator<<(int i)
	{
		char temp[3];
		itoa(i, temp, 10);
		String other = temp;
		char* b = new char[size + other.size];
		strcpy(b, s);
		strcpy(b + size, other.s);
		try
		{
			String res(b);
			delete[]b;
			return res;
		}
		catch (...)
		{
			delete[]b;
		}
	}
	*/
	/*
	String operator<<(const char* hm)
	{
		if (hm == "toUpper")
		{
			return  strupr(s);
		}
	}
	*/
	ostream& operator<<(ostream& out, String const& s)
	{
		ostream& out << s.s;
		return out;
	}

	friend String operator+(String const& s1, String const& s2);

};
 String operator+(String const& s1, String const& s2)
{
	char* b = new char[s1.size + s2.size];
	strcpy(b, s1.s);
	strcpy(b + s1.size, s2.s);
	 try
	 {
		 String res(b);
		 delete[]b;
		 return res;
	 }
	 catch(...)
	 {
		 delete[]b;
	 }
}


ostream eat(const char c)
 {
	 // some logic here
	return c;
 }
String ToUpper(const char* s)
 {
	return  strupr(s);
 }



int main(int argc, char* argv[])
{
	String s = "stroka";
	s[0] = 'È';
	s << 123;
	s << "toUpper";
	s << eat(',');
	int bg = 20;

	cout << bg;
	sin >> bg;
	return 0;
}
