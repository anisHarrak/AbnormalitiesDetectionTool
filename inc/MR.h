#ifndef MR_H
#define MR_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class MR
{
private:
	string currency;
	double tickSize;
	int closingPrice;
	int minimumLot;
	int market;
	string stockName;
	int placeOfQuotation;
	string groupNumber;
	int numberOfDecimals;
	int localCode;
	string isinCode;
	double upperReservationLevel;
	double lowerReservationLevel;
	string mnemonic;
	string glid;
public:
	MR();
	MR(string currency,double tickSize,int closingPrice,int minimumLot,int market,string stockName,int placeOfQuotation,string groupNumber,int numberOfDecimals,int localCode,string isinCode,double upperReservationLevel,double lowerReservationLevel,string mnemonic,string glid);
	void afficher() const;

	void setCurrency(string _currency)
	{
		this->currency=_currency;
	}
	string getCurrency()const
	{
		return currency;
	}
	void setTicksize(double _tickSize)
	{
		this->tickSize=_tickSize;
	}
	double getTicksize()const
	{
		return tickSize;
	}
	void setClosingPrice(int _closingPrice)
	{
		this->closingPrice=_closingPrice;
	}
	int getClosingPrice()const
	{
		return closingPrice;
	}
	void setMininumlot(int _minimumLot)
	{
		this->minimumLot=_minimumLot;
	}
	int getMininumlot()const
	{
		return minimumLot;
	}
	void setMarket(int _market)
	{
		this->market=_market;
	}
	int getMarket()const
	{
		return market;
	}
	void setStockName(string _stockName)
	{
		this->stockName=_stockName;
	}
	string getStockName()const
	{
		return stockName;
	}
	void setPlaceofQuotation(int _placeOfQuotation)
	{
		this->placeOfQuotation=_placeOfQuotation;
	}
	int getPlaceofQuotation()const
	{
		return placeOfQuotation;
	}
	void setGroupNumber(string _groupNumber)
	{
		this->groupNumber=_groupNumber;
	}
	string getGroupNumber()const
	{
		return groupNumber;
	}
	void setNumberOfDecimals(int _numberOfDecimals)
	{
		this->numberOfDecimals=_numberOfDecimals;
	}
	int getNumberOfDecimals()const
	{
		return numberOfDecimals;
	}
	void setLocalCode(int _localCode)
	{
		this->localCode=_localCode;
	}
	int getLocalCode()const
	{
		return localCode;
	}
	void setIsinCode(string _isinCode)
	{
		this->isinCode=_isinCode;
	}
	string getIsinCode()const
	{
		return isinCode;
	}
	void setUpperReservationLevel(double _upperReservationLevel)
	{
		this->upperReservationLevel=_upperReservationLevel;
	}
	double getUpperReservationLevel() const
	{
		return upperReservationLevel;
	}
	void setLowerReservationLevel(double _lowerReservationLevel)
	{
		this->lowerReservationLevel=_lowerReservationLevel;
	}
	double getLowerReservationLevel() const
	{
		return lowerReservationLevel;
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