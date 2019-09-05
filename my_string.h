#ifndef _MY_STRING_H_
#define	_MY_STRING_H_

#include <iostream>

class my_string{
private:
	char *value;

public:
	my_string();
	my_string (const my_string& str); // cpy ctor
	my_string (const char* s); //from c-string 
	my_string (const char* s, size_t n);
	~my_string();

	size_t size() const;
	size_t length() const;
	size_t strlen ( const char * str );

	void * memcpy ( void * destination, const void * source, size_t num );
	char * strcpy ( char * destination, const char * source );
	char * strcat ( char * destination, const char * source );
	int strcmp ( const char * str1, const char * str2 );


	my_string& operator= (const my_string& str);
	my_string& operator= (const char* s);
	my_string& operator= (char c);


	my_string& operator+= (const my_string& str);
	my_string& operator+= (const char* s);
	my_string& operator+= (char c);

	char& operator[] (size_t pos);
	const char& operator[] (size_t pos) const;

	void swap (string& str);


};


my_string operator+ (const my_string& lhs, const my_string& rhs);
my_string operator+ (const my_string& lhs, const char*   rhs);
my_string operator+ (const char*   lhs, const my_string& rhs);
my_string operator+ (const my_string& lhs, char          rhs);
my_string operator+ (char          lhs, const my_string& rhs);

void swap (string& x, string& y);

istream& operator>> (istream& is, string& str);
ostream& operator<< (ostream& os, const string& str);


bool operator== (const string& lhs, const string& rhs);
bool operator== (const char*   lhs, const string& rhs);
bool operator== (const string& lhs, const char*   rhs);
bool operator!= (const string& lhs, const string& rhs);
bool operator!= (const char*   lhs, const string& rhs);
bool operator!= (const string& lhs, const char*   rhs);
bool operator<  (const string& lhs, const string& rhs);
bool operator<  (const char*   lhs, const string& rhs);
bool operator<  (const string& lhs, const char*   rhs);
bool operator<= (const string& lhs, const string& rhs);
bool operator<= (const char*   lhs, const string& rhs);
bool operator<= (const string& lhs, const char*   rhs);
bool operator>  (const string& lhs, const string& rhs);
bool operator>  (const char*   lhs, const string& rhs);
bool operator>  (const string& lhs, const char*   rhs);
bool operator>= (const string& lhs, const string& rhs);
bool operator>= (const char*   lhs, const string& rhs);
bool operator>= (const string& lhs, const char*   rhs);

#endif /*_MY_STRING_H_*/