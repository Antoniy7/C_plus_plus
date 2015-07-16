#pragma once
//asbtract class

class Reader
{
protected:

	virtual bool readASCI()=0;
	virtual bool writeASCI(const char*output) = 0;
	virtual bool readBinary()=0;
	virtual bool writeBinary()=0;

	virtual bool histogram() = 0;

	
	virtual bool checkIsAlreadyGrayScale(const char*x)
	{
		if ((strcmp(x, "P2") == 0) || (strcmp(x, "P5") == 0))//x - tittle
			return true;
		else false;

	}
	
	virtual bool checkIsAlreadyMonochrome(const char*x)
	{
		if ((strcmp(x, "P1") == 0) || (strcmp(x, "P4") == 0))//x - tittle
			return true;
		else false;
	}
};