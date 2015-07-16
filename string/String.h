#ifndef String_H
#define String_H

class String
{
private:
	char*data;
	size_t length;
	void setData(const char*); 

public:
	String(const char*); 
	
	~String();
	String(const String &other); //copy const
	String&operator=(const String&right);
	   
	
	      
	String operator+(const String&)const; 

	String& operator+=(const String&);
	bool operator!() const;
	
	char& operator[](size_t position); 

	const char& operator[](size_t position) const;

	bool operator==(const String&str1)const;

	String operator()(size_t position, size_t number_elements)const;   
	operator const char* () const;  //(char*) str
 






};




#endif