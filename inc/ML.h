#ifndef ML_H
#define ML_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class ML
{
private:
	string bidPrice;
	double bidQuantity;
	double lastTradedPrice;
	string askPrice;
	double askQuantity;
	double lastTradedQuantity;
	int numberBidOrder;
	int numberAskOrder;
	double averageWeightedQuotePriceBuy;
	double averageWeightedQuotePriceSell;
	int averageWeightedQuoteVolume;
	string mnemonic;
	string glid;
public:
	ML();
	ML(string bidPrice,double bidQuantity,double lastTradedPrice,string askPrice,double askQuantity,double lastTradedQuantity,int numberBidOrder,int numberAskOrder,double averageWeightedQuotePriceBuy,double averageWeightedQuotePriceSell,int averageWeightedQuoteVolume,string mnemonic,string glid);
	void afficher() const;

	void setNumberBidOrder(int _numberBidOrder)
	{
		this->numberBidOrder=_numberBidOrder;
	}
	int getNumberBidOrder() const
	{
		return numberBidOrder;
	}
	void setNumberAskOrder(int _numberAskOrder)
	{
		this->numberAskOrder=_numberAskOrder;
	}
	int getNumberAskOrder() const
	{
		return numberAskOrder;
	}
	void setAverageWeightedQuoteVolume(int _averageWeightedQuoteVolume)
	{
		this->averageWeightedQuoteVolume=_averageWeightedQuoteVolume;
	}
	int getAverageWeightedQuoteVolume() const
	{
		return averageWeightedQuoteVolume;
	}
	void setBidPrice(string _bidPrice)
	{
		this->bidPrice=_bidPrice;
	}
	string getBidPrice() const
	{
		return bidPrice;
	}

	void setAverageWeightedQuotePriceBuy(double _averageWeightedQuotePriceBuy)
	{
		this->averageWeightedQuotePriceBuy=_averageWeightedQuotePriceBuy;
	}
	double getAverageWeightedQuotePriceBuy() const
	{
		return averageWeightedQuotePriceBuy;
	}
	void setAverageWeightedQuotePriceSell(double _averageWeightedQuotePriceSell)
	{
		this->averageWeightedQuotePriceSell=_averageWeightedQuotePriceSell;
	}
	double getAverageWeightedQuotePriceSell() const
	{
		return averageWeightedQuotePriceSell;
	}
	void setBidQuantity(double _bidQuantity)
	{
		this->bidQuantity=_bidQuantity;
	}
	double getBidQuantity() const
	{
		return bidQuantity;
	}
	void setLastTradedPrice(double _lastTradedPrice)
	{
		this->lastTradedPrice=_lastTradedPrice;
	}
	double getLastTradedPrice() const
	{
		return lastTradedPrice;
	}
	void setAskPrice(string _askPrice)
	{
		this->askPrice=_askPrice;
	}
	string getAskPrice() const
	{
		return askPrice;
	}
	void setAskQuantity(double _askQuantity)
	{
		this->askQuantity=_askQuantity;
	}
	double getAskQuantity() const
	{
		return askQuantity;
	}
	void setLastTradedQuantity(double _lastTradedQuantity)
	{
		this->lastTradedQuantity=_lastTradedQuantity;
	}
	double getLastTradedQuantity() const
	{
		return lastTradedQuantity;
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