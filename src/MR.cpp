#include"MR.h"

MR::MR()
{
	this->currency=" ";
	this->tickSize=0;
	this->closingPrice=0;
	this->minimumLot=0;
	this->market=0;
	this->stockName=" ";
	this->placeOfQuotation=0;
	this->groupNumber=" ";
	this->numberOfDecimals=0;
	this->localCode=0;
	this->isinCode=" ";
	this->upperReservationLevel=0;
	this->lowerReservationLevel=0;
	this->glid=" ";
	this->mnemonic=" ";
}
MR::MR(string _currency,double _tickSize,int _closingPrice,int _minimumLot,int _market,string _stockName,int _placeOfQuotation,string _groupNumber,int _numberOfDecimals,int _localCode,string _isinCode,double _upperReservationLevel,double _lowerReservationLevel,string _mnemonic,string _glid)
{
	this->currency=_currency;
	this->tickSize=_tickSize;
	this->closingPrice=_closingPrice;
	this->minimumLot=_minimumLot;
	this->market=_market;
	this->stockName=_stockName;
	this->placeOfQuotation=_placeOfQuotation;
	this->groupNumber=_groupNumber;
	this->numberOfDecimals=_numberOfDecimals;
	this->localCode=_localCode;
	this->isinCode=_isinCode;
	this->upperReservationLevel=_upperReservationLevel;
	this->lowerReservationLevel=_lowerReservationLevel;
	this->mnemonic=_mnemonic;
	this->glid=_glid;

}

void MR::afficher()const
{
	cout<<"******************* affichage base MR *********************"<<endl;
	cout<<"le upper reservation level est: "<<upperReservationLevel<<endl;
	cout<<"le lower reservation level est: "<<lowerReservationLevel<<endl;
	cout<<"le mnémonic est: "<<mnemonic<<endl;
	cout<<"le glid est: "<<glid<<endl;
}