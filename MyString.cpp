#include "MyString.h"



size_t MyString::strlen ( const char * str )
{
	size_t len = 0;
	while(*(str++))
	{
		len++;
	}
	return len;
}


char* allocate_str(const char *s, size_t size)
{
	char *copy = new char[size + 1];
    char* temp = copy;
	while(*s )
	{
		*temp++ = *s++;
	}

	*(temp) = '\0';

	return copy;
}


MyString::MyString (const MyString& str)
{
	value = allocate_str(str.value, str.length());
	len = str.length();
}



MyString::MyString (const char *s)
{
	len = strlen(s);
	value = allocate_str(s, len);
}


MyString::~MyString()
{

	delete[] value;
}


ostream& operator<<(ostream& os, const MyString& str)
{

    return os << str.c_str();
}

void * MyString::memcpy ( void * destination, const void * source, size_t num )
{
	char * dst = (char *)destination ;
	char * src = (char *)source;

	while(static_cast<int>(num) > -1)
	{
		*dst = *src;
		dst++;
		src++;
		num--;
	}

	return destination;
}


char * MyString::strcpy ( char * destination, const char * source )
{
	while(*source && (*destination++ = *source++)) {}

	return destination;
}



int MyString::strcmp ( const char * str1, const char * str2 )
{

	while(*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return *str1 - *str2; 
		}
		str1++; 
		str2++;
	}

	str1--;
	str2--;

	return *str1 - *str2; 

}


char * MyString::strcat ( char * destination, const char * source )
{
	char *temp = destination + MyString::strlen(destination);

	while(*source)
	{
		*temp++ = *source++;
	}

	*temp = '\0';

	return destination;
}



char& MyString::operator[] (size_t pos)
{
	if(pos >= len || pos < 0 )
	{
		throw std::out_of_range ("possition out of range");
	}
	return value[pos];
}


const char& MyString::operator[] (size_t pos) const
{	

	if(pos >= len || pos < 0 )
	{
		throw std::out_of_range ("possition out of range");
	}
	return value[pos];
}	



MyString& MyString::operator=(const MyString& str)
{
	if(this == &str)
	{
		return *this;
	}
	delete[] this->value;
	// this-> value = NULL;
	len = 0;
	value = allocate_str(str.c_str(), str.length());
	len = str.length();
	return *this;
}


MyString& MyString::operator=(const char* s)
{
	delete[] this->value;
	size_t new_len = strlen(s);
	value = allocate_str(s, new_len);
	len = new_len;
	return *this;
}


MyString& MyString::operator+=(const MyString& str)
{
	char *old_value = value;
	size_t new_len =  strlen(str.c_str());
	value = allocate_str(strcat(value, str.c_str()), new_len);
	len = strlen(value);
	delete[] old_value;
	return *this;
}

