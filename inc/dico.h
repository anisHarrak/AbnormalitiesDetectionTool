#ifndef DICO_H
#define DICO_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Dico
{
private:
	string stockName;
	string localCode;
	string groupNumber;
	string isinCode;
	string mnemonic;
	string glid;
public:
	Dico();
	Dico(string stockName,string localCode,string groupNumber,string isinCode,string mnemonic,string glid);
	void afficher() const;

	void setStockName(string _stockName)
	{
		this->stockName=_stockName;
	}
	string getStockName() const
	{
		return stockName;
	}
	void setLocalCode(string _localCode)
	{
		this->localCode=_localCode;
	}
	string getLocalCode() const
	{
		return localCode;
	}
	void setGroupNumber(string _groupNumber)
	{
		this->groupNumber=_groupNumber;
	}
	string getGroupNumber() const
	{
		return groupNumber;
	}
	void setIsinCode(string _isinCode)
	{
		this->isinCode=_isinCode;
	}
	string getIsinCode() const
	{
		return isinCode;
	}
	void setMnemonic(string _mnemonic)
	{
		this->mnemonic=_mnemonic;
	}
	string getMnemonic() const
	{
		return mnemonic;
	}
	void setGlid(string _glid)
	{
		this->glid=_glid;
	}
	string getGlid() const
	{
		return glid;
	}

};
#endif 