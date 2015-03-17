#include "ML.h"

ML::ML()
{
	this->bidPrice=" ";
	this->bidQuantity=0;
	this->lastTradedPrice=0;
	this->askPrice=" ";
	this->askQuantity=0;
	this->lastTradedQuantity=0;
	this->numberBidOrder=0;
	this->numberAskOrder=0;
	this->averageWeightedQuotePriceBuy=0;
	this->averageWeightedQuotePriceSell=0;
	this->averageWeightedQuoteVolume=0;
	this->mnemonic=" ";
	this->glid= " ";

}
ML::ML(string _bidPrice,double _bidQuantity,double _lastTradedPrice,string _askPrice,double _askQuantity,double _lastTradedQuantity,int _numberBidOrder,int _numberAskOrder,double _averageWeightedQuotePriceBuy,double _averageWeightedQuotePriceSell,int _averageWeightedQuoteVolume,string _mnemonic,string _glid)
{
	this->bidPrice=_bidPrice;
	this->bidQuantity=_bidQuantity;
	this->lastTradedPrice=_lastTradedPrice;
	this->askPrice=_askPrice;
	this->askQuantity=_askQuantity;
	this->lastTradedQuantity=_lastTradedQuantity;
	this->numberBidOrder=_numberBidOrder;
	this->numberAskOrder=_numberAskOrder;
	this->averageWeightedQuotePriceBuy=_averageWeightedQuotePriceBuy;
	this->averageWeightedQuotePriceSell=_averageWeightedQuotePriceSell;
	this->averageWeightedQuoteVolume=_averageWeightedQuoteVolume;
	this->mnemonic=_mnemonic;
	this->glid= _glid;

}
void ML::afficher()const
{
	cout<<"******************* affichage base ML *********************"<<endl;
	cout<<"le bid price est : "<<bidPrice<<endl;
	cout<<"le bid quantity est: "<<bidQuantity<<endl;
	cout<<"le last traded price est: "<<lastTradedPrice<<endl;
	cout<<"le ask price est: "<<askPrice<<endl;
	cout<<"le ask quantity est: "<<askQuantity<<endl;
	cout<<"le last traded quantity est: "<<lastTradedQuantity<<endl;
	cout<<"le mnémonic est : "<<mnemonic<<endl;
	cout<<"le glid est : "<<glid<<endl;
}