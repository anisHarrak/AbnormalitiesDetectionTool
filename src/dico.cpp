#include "dico.h"

Dico::Dico()
{
	this->stockName=" ";
	this->localCode=" ";
	this->groupNumber=" ";
	this->isinCode=" ";
	this->mnemonic=" ";
	this->glid=" ";
}
Dico::Dico(string _stockName,string _localCode,string _groupNumber,string _isinCode,string _mnemonic,string _glid)
{
	this->stockName=_stockName;
	this->localCode=_localCode;
	this->groupNumber=_groupNumber;
	this->isinCode=_isinCode;
	this->mnemonic=_mnemonic;
	this->glid=_glid;

}
void Dico::afficher()const
{
	cout<<"le stock name est : "<<stockName<<endl;
	cout<<"le local code est : "<<localCode<<endl;
	cout<<"le groupe number est : "<<groupNumber<<endl;
	cout<<"le isin code est : "<<isinCode<<endl;
	cout<<"le mnémonic est : "<<mnemonic<<endl;
	cout<<"le glid est : "<<glid<<endl;

}