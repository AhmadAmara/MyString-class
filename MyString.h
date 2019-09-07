#ifndef _MyString_H_
#define	_MyString_H_

#include <ostream>
#include <stdlib.h>

using std::ostream;


class MyString{
private:
	size_t len;
	char *value;
	char* init_string(const char* s, size_t n);
public:
	MyString();
	MyString (const MyString& str); // cpy ctor
	MyString (const char* s); //from c-string 
	MyString (const char* s, size_t n);
	~MyString();

	const char* c_str() const { return value; }

	inline size_t size() const { return sizeof(value); };
	inline size_t length() const { return len; } ;
	static size_t strlen ( const char * str );


	MyString& operator= (const MyString& str);
	MyString& operator= (const char* s);
	MyString& operator= (char c);


	MyString& operator+= (const MyString& str);
	MyString& operator+= (const char* s);
	MyString& operator+= (char c);

	char& operator[] (size_t pos);
	const char& operator[] (size_t pos) const;

	void swap (MyString& str);


	static void * memcpy ( void * destination, const void * source, size_t num );
	static char * strcpy ( char * destination, const char * source );
	static char * strcat ( char * destination, const char * source );
	static int strcmp ( const char * str1, const char * str2 );

};




ostream& operator<<(ostream& os, const MyString& str);



#endif /*_MyString_H_*/