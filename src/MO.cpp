#include "MO.h"

MO::MO()
{
	this->side=" ";
	this->exchangeOrderId=0;
	this->entryLimitPrice=0;
	this->slice=0;
	this->price=0;
	this->quantity=0;
	this->order_date=0;
	this->mnemonic=" ";
	this->glid=" ";
}
MO::MO(string _side,int _exchangeOrderId,int _entryLimitPrice,int _slice,double _price,double _quantity,int _order_date,string _mnemonic,string _glid)
{
	this->side=_side;
	this->exchangeOrderId=_exchangeOrderId;
	this->entryLimitPrice=_entryLimitPrice;
	this->slice=_slice;
	this->price=_price;
	this->quantity=_quantity;
	this->order_date=_order_date;
	this->mnemonic=_mnemonic;
	this->glid=_glid;

}
void MO::afficher()const
{
	cout<<"******************* affichage base MO *********************"<<endl;
	cout<<"le side est : "<<side<<endl;
	cout<<"le price est : "<<price<<endl;
	cout<<"la quantité est : "<<quantity<<endl;
	cout<<"le order date est : "<<order_date<<endl;
	cout<<"le mnémonic est : "<<mnemonic<<endl;
	cout<<"le glid est : "<<glid<<endl;
}

ostream& operator<<(ostream& out,const MO& mo)
{
	out<<mo.side<<" "<<mo.exchangeOrderId<<" "<<mo.entryLimitPrice<<" "<<mo.slice<<" "<<mo.price<<" "<<mo.quantity<<" "<<mo.order_date<<" "<<mo.mnemonic<<" "<<mo.glid<<endl;

	return out;
}