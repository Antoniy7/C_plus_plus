#ifndef Cookie_H
#define Cookie_H

class Cookie
{
private:
	 char* arr[10];
	char**cookie;
	int string_counter=0;
	~Cookie();

public:
	void fill_Cookie(int string_counter);
	bool operator==(const Cookie& right)const;
	bool readBinary(const Cookie& c, ifstream& in);
	bool writeToBinary(const Cookie& c, ofstream& out);

};



#endif