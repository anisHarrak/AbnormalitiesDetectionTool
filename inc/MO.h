#ifndef MO_H
#define MO_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class MO
{
private:
	string side;
	int exchangeOrderId;
	int entryLimitPrice;
	int slice;
	double price;
	double quantity;
	int order_date;
	string mnemonic;
	string glid;
public:
	MO();
	MO(string side,int exchangeOrderId,int entryLimitPrice,int slice,double price,double quantity,int order_date,string mnemonic,string glid);
	void afficher() const;
	friend ostream& operator<<(ostream&,const MO&);

	void setSide(string _side)
	{
		this->side=_side; 
	}
	string getSide() const
	{
		return side;
	}
	void setExchangeOrderId(int _exchangeOrderId)
	{
		this->exchangeOrderId=_exchangeOrderId;
	}
	int getExchangeOrderId() const
	{
		return  exchangeOrderId;
	}
	void setEntryLimitPrice(int _entryLimitPrice)
	{
		this->entryLimitPrice=_entryLimitPrice;
	}
	int getEntryLimitPrice() const
	{
		return  entryLimitPrice;
	}
	void setSlice(int _slice)
	{
		this->slice=_slice;
	}
	int getSlice() const
	{
		return  slice;
	}

	void setPrice(double _price)
	{
		this->price=_price;
	}
	double getPrice() const
	{
		return price;
	}

	void setQuantity(double _quantity)
	{
		this->quantity=_quantity;
	}
	double getQuantity() const
	{
		return quantity;
	}
	void setOrderDate(int _order_date)
	{
		this->order_date=_order_date;
	}
	int getOrderDate() const
	{
		return  order_date;
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

ostream& operator<<(ostream&,const MO&);
#endif
