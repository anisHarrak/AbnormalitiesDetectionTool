#ifndef RECORD_H
#define RECORD_H

#include "SCRecord.hpp" 
#include "SCGLReferential.hpp"
#include <iostream>
#include <string>
using namespace std;

class Record
{
private:
	int id_request;
	SCRecord* record;

public:
	Record();
	Record(int id_request, SCRecord* record);
	~Record();
	Record& operator=( const Record& s );

	string getCurency()const
	{
		string currencyy=record->stringAt(SCFid_currency);
		return currencyy;
	}
	string getMnemo()const
	{
		string mnemo=record->stringAt(SCFid_mnemonic);
		return mnemo;

		//string mnemonic;
		////bool found=false;
		//getRecord()->getStringAt(mnemonic,SCFid_mnemonic);
		//return mnemonic;
	}
	double getTicksize()const
	{
		double value = record->doubleAt(SCFid_tickSize); 
		return value;
	}

	double getUpperReservationLevel()const
	{
		double value = record->doubleAt(SCFid_upperReservationLevel); 
		return value;

		/*double value;
		getRecord()->get(&value, SCFid_upperReservationLevel);
		return value;*/
	}
	double getLowerReservationLevel()const
	{
		double value = record->doubleAt(SCFid_lowerReservationLevel); 
		return value;
		/*double value;
		getRecord()->get(&value, SCFid_lowerReservationLevel);
		return value;*/
	}
	string getGliD() const
	{
		string glid=record->stringAt(SCFid_GLID);
		return glid;
		/*string glid;
		getRecord()->getAt(glid,SCFid_GLID);
		return glid;*/
	}
	string getBidprice()const
	{
		string bidPrice = record->stringAt(SCFid_bidPrice); 
		return bidPrice;
	}
	double getBidQuantity()const
	{
		double value = record->doubleAt(SCFid_bidQuantity); 
		return value;
		/*double value;
		getRecord()->get(&value, 2200);
		return  value;*/
	}
	double getLastTradedprice()const
	{
		double value = record->doubleAt(SCFid_lastTradedPrice); 
		return value;
		/*double value;
		getRecord()->get(&value, 2204);
		return  value;*/
	}
	double getLastTradedquantity()const
	{
		double value = record->doubleAt(SCFid_lastTradedQuantity); 
		return value;
		/*double value;
		getRecord()->get(&value, 2205);
		return  value;*/
	}
	string getAskprice() const
	{
		string sakPrice = record->stringAt(SCFid_askPrice); 
		return sakPrice;
	}
	double getAskquantity()const
	{
		double value = record->doubleAt(SCFid_askQuantity); 
		return value;
		/*double value;
		getRecord()->get(&value, 2203);
		return  value;*/
	}
	string getStockname() const
	{	
		string stockname=record->stringAt(SCFid_stockName);
		return stockname;
		/*string stockname;
		getRecord()->getAt(stockname,2230);
		return stockname;*/
	}
	string getLocalcode()const
	{
		string localcode=record->stringAt(SCFid_localCode);
		return localcode;
		/*string localcode;
		getRecord()->getAt(localcode,2237);
		return localcode;*/
	}

	string getgroupnumber()const
	{
		string groupNumber=record->stringAt(SCFid_groupNumber);
		return groupNumber;
		/*string groupNumber;
		getRecord()->getAt(groupNumber,2233);
		return groupNumber;*/
	}
	string getIsincode()const
	{
		string isincode=record->stringAt(SCFid_isinCode);
		return isincode;
		/*string isincode;
		getRecord()->getAt(isincode,2276);
		return isincode;*/
	}

	string getSide() const
	{
		string side=record->stringAt(SCFid_side);
		return side;
		/*int value;
		getRecord()->get(&value,2);
		return value;*/
	}
	double getPrice() const
	{
		double value = record->doubleAt(SCFid_price); 
		return value;
		/*double value;
		getRecord()->get(&value,22);
		return value;*/
	}
	double getQuantity() const
	{
		double value = record->doubleAt(SCFid_quantity); 
		return value;
		/*double value;
		getRecord()->get(&value,21);
		return  value;*/
	}
	double getAverageWeightedQuotePriceBuy() const
	{
		double value = record->doubleAt(SCFid_ml_averageWeightedQuotePriceBuy); 
		return value;
	}
	double getAverageWeightedQuotePriceSell() const
	{
		double value = record->doubleAt(SCFid_ml_averageWeightedQuotePriceSell); 
		return value;
	}
	int getAverageWeightedQuoteVolume() const
	{
		int value = record->intAt(SCFid_ml_averageWeightedQuoteVolume); 
		return value;
	}
	int getOrderdate()const
	{
		int value = record->intAt(SCFid_mo_orderDate); 
		return value;
		/*int date; 
		getRecord()->get(&date,2488);
		return date;*/
	}
	int getClosingprice()const
	{
		int value = record->intAt(SCFid_closingPrice); 
		return value;
	}
	int getExchangeOrderId()const
	{
		int value = record->intAt(SCFid_exchangeOrderId); 
		return value;
	}
	int getEntrylimitprice()const
	{
		int value = record->intAt(SCFid_mo_entryLimitPrice); 
		return value;
	}
	int getSlice()const
	{
		int value = record->intAt(SCFid_mo_slice); 
		return value;
	}
	int getNumberBidOrder()const
	{
		int value = record->intAt(SCFid_ml_numberBidOrder); 
		return value;
	}
	int getNumberAskOrder()const
	{
		int value = record->intAt(SCFid_ml_numberAskOrder); 
		return value;
	}


	int getLocal_code()const
	{
		int value = record->intAt(SCFid_localCode); 
		return value;
	}
	int getMininumlot()const
	{
		int value = record->intAt(SCFid_minimumLot); 
		return value;
	}
	int getMarket()const
	{
		int value = record->intAt(SCFid_market); 
		return value;
	}
	int getPlaceOfQuotation()const
	{
		int value = record->intAt(SCFid_placeOfQuotation); 
		return value;
	}
	int getNumberofdecimals()const
	{
		int value = record->intAt(SCFid_numberOfDecimals); 
		return value;
	}

	void setId_request(int _id_request)
	{
		this->id_request= _id_request;
	}
	int getId_request() const
	{
		return id_request;
	}
	void setRecord(SCRecord* _record)
	{
		this->record=_record;
	}
	SCRecord* getRecord() const
	{
		return record;
	}

};

#endif