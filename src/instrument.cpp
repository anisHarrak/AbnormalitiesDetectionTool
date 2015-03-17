#include "instrument.h"

Instrument::Instrument()
{
	this->stockName=" ";
	this->localCode=" ";
	this->groupNumber=" ";
	this->isinCode=" ";
	this->mnemonic=" ";
	this->glid=" ";
	vector<MO*> mosBid(10, static_cast<MO*>(0)) ;
	vector<MO*> mosAsk(10, static_cast<MO*>(0)) ;
	vector<ML*> mls(10, static_cast<ML*>(0)) ;
	vector<MR*> mrs(10, static_cast<MR*>(0)) ;

}
Instrument::Instrument(string _stockName,string _localCode,string _groupNumber,string _isinCode,string _mnemonic,string _glid)
{
	this->stockName=_stockName;
	this->localCode=_localCode;
	this->groupNumber=_groupNumber;
	this->isinCode=_isinCode;
	this->mnemonic=_mnemonic;
	this->glid=_glid;
}

Instrument::~Instrument()
{
	for(unsigned int i=0;i<mls.size();i++)
	{
		delete mls[i];
	}
	for(unsigned int i=0;i<mosBid.size();i++)
	{
		delete mosBid[i];
	}
	for(unsigned int i=0;i<mosAsk.size();i++)
	{
		delete mosAsk[i];
	}
	for(unsigned int i=0;i<mrs.size();i++)
	{
		delete mrs[i];
	}
}

Instrument::Instrument(const Instrument& I)
{
	stockName=I.stockName;
	localCode=I.localCode;
	groupNumber=I.groupNumber;
	isinCode=I.isinCode;
	mnemonic=I.mnemonic;
	glid=I.glid;
	ML *p2;
	MO *p3;
	MR *p4;


	for(unsigned int i=0;i<I.mls.size();i++)
	{
		p2= new ML(*(I.mls[i]));
		mls.push_back(p2);
	}
	for(unsigned int i=0;i<I.mosBid.size();i++)
	{
		p3= new MO(*(I.mosBid[i]));
		mosBid.push_back(p3);
	}
	for(unsigned int i=0;i<I.mosAsk.size();i++)
	{
		p3= new MO(*(I.mosAsk[i]));
		mosAsk.push_back(p3);
	}
	for(unsigned int i=0;i<I.mrs.size();i++)
	{
		p4= new MR(*(I.mrs[i]));
		mrs.push_back(p4);
	}
}

Instrument& Instrument::operator=(const Instrument& I)
{

	if(this!=&I)
	{

		for(unsigned int i=0;i<mls.size();i++)
		{
			delete mls[i];
		}
		mls.clear();
		for(unsigned int i=0;i<mosBid.size();i++)
		{
			delete mosBid[i];
		}
		mosBid.clear();
		for(unsigned int i=0;i<mosAsk.size();i++)
		{
			delete mosAsk[i];
		}
		mosAsk.clear();
		for(unsigned int i=0;i<mrs.size();i++)
		{
			delete mrs[i];
		}
		mrs.clear();

		stockName=I.stockName;
		localCode=I.localCode;
		groupNumber=I.groupNumber;
		isinCode=I.isinCode;
		mnemonic=I.mnemonic;
		glid=I.glid;

		ML *p2;
		MO *p3;
		MR *p4;


		for(unsigned int i=0;i<I.mls.size();i++)
		{
			p2= new ML(*(I.mls[i]));
			mls.push_back(p2);
		}
		for(unsigned int i=0;i<I.mosBid.size();i++)
		{
			p3= new MO(*(I.mosBid[i]));
			mosBid.push_back(p3);
		}
		for(unsigned int i=0;i<I.mosAsk.size();i++)
		{
			p3= new MO(*(I.mosAsk[i]));
			mosAsk.push_back(p3);
		}
		for(unsigned int i=0;i<I.mrs.size();i++)
		{
			p4= new MR(*(I.mrs[i]));
			mrs.push_back(p4);
		}
	}

	return *this;
}

void Instrument::printInstr() const
{
	cout<<"**************affichage de la dico *****************"<<endl;
	cout<<"le stock name est : "<<stockName<<endl;
	cout<<"le local code est : "<<localCode<<endl;
	cout<<"le groupe number est : "<<groupNumber<<endl;
	cout<<"le isincode est : "<<isinCode<<endl;
	cout<<"le mnemonic est : "<<mnemonic<<endl;
	cout<<"le glid est : "<<glid<<endl;
	cout<<"**************FIN dico *****************"<<endl;

	for(unsigned int i=0;i<mosBid.size();i++)
	{
		cout<<"**************affichage de la liste des ventes MO *****************"<<endl;
		(*(mosBid[i])).afficher();
		cout<<"************* FIN MO *****************"<<endl;
	}
	for(unsigned int i=0;i<mosAsk.size();i++)
	{
		cout<<"**************affichage de la liste des achats MO *****************"<<endl;
		(*(mosAsk[i])).afficher();
		cout<<"************* FIN MO *****************"<<endl;
	}
	for(unsigned int i=0;i<mls.size();i++)
	{
		cout<<"**************affichage de la liste des ML *****************"<<endl;
		(*(mls[i])).afficher();
		cout<<"************* FIN ML *****************"<<endl;
	}
	for(unsigned int i=0;i<mrs.size();i++)
	{
		cout<<"**************affichage de la liste des MR *****************"<<endl;
		(*(mrs[i])).afficher();
		cout<<"************* FIN MR *****************"<<endl;

	}

}
void Instrument::dump_MR()
{
	ofstream fichier("baseMR.txt", ios::out | ios::app);  // ouverture en écriture avec effacement du fichier ouvert

	if(fichier)
	{
		for(unsigned int i=0;i<mrs.size();i++)
		{
			string currency=(*(mrs[i])).getCurrency();
			double tickSize=(*(mrs[i])).getTicksize();
			int closingPrice=(*(mrs[i])).getClosingPrice();
			int minimumLot=(*(mrs[i])).getMininumlot();
			int market=(*(mrs[i])).getMarket();
			string stockName=(*(mrs[i])).getStockName();
			int placeOfQuotation=(*(mrs[i])).getPlaceofQuotation();
			string groupNumber=(*(mrs[i])).getGroupNumber();
			int numberOfDecimals=(*(mrs[i])).getNumberOfDecimals();
			int localCode=(*(mrs[i])).getLocalCode();
			string isinCode=(*(mrs[i])).getIsinCode();
			string glid=(*(mrs[i])).getGlid(); 
			double lowerRes=(*(mrs[i])).getLowerReservationLevel();
			double upperRes=(*(mrs[i])).getUpperReservationLevel();
			string mnemo=(*(mrs[i])).getMnemonic();

			fichier<<"Currency"<<" / "<<"TickSize"<<" / "<<"ClosingPrice"<<" / "<<"Minimumlot"<<" / "<<"Market"<<" / "<<"Stockname"<<" / "<<"PlaceOfQuotation"<<" / "<<"groupNumber"<<" / "<<"NumberOfDecimals"<<" / "<<"LocalCode"<<" / "<<"IsinCode"<<" / "<<"glid"<<" / "<<"lowerResLevel"<<" / "<<"upperReserLevel"<<" / "<<"mnemonic"<<endl;
			fichier<<currency<<" - "<<tickSize<<" - "<<closingPrice<<" - "<<minimumLot<<" - "<<market<<" - "<<stockName<<" - "<<placeOfQuotation<<" - "<<groupNumber<<" - "<<numberOfDecimals<<" - "<<localCode<<" - "<<isinCode<<" - "<<glid<<" - "<<lowerRes<<" - "<<upperRes<<" - "<<mnemo<<endl;

		}

		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;

}
void Instrument::dump_MOBid()
{
	ofstream fichier("baseMO.txt", ios::out | ios::app);  // ouverture en écriture avec effacement du fichier ouvert

	if(fichier)
	{
		for(unsigned int i=0;i<mosBid.size();i++)
		{
			string side=(*(mosBid[i])).getSide(); 
			int exchangeOrderId=(*(mosBid[i])).getExchangeOrderId();
			int entryLimitPrice=(*(mosBid[i])).getEntryLimitPrice();
			int slice=(*(mosBid[i])).getSlice();
			double price=(*(mosBid[i])).getPrice();
			double quantity=(*(mosBid[i])).getQuantity();
			int orderDate=(*(mosBid[i])).getOrderDate();
			string mnemo=(*(mosBid[i])).getMnemonic();
			string glid=(*(mosBid[i])).getGlid();

			fichier<<"side"<<" / "<<"exchangeOrderId"<<" / "<<"entryLimitPrice"<<" / "<<"slice"<<" / "<<"price"<<" / "<<"quantity"<<" / "<<"orderDate"<<" / "<<"mnemo"<<" / "<<"glid"<<endl;
			fichier<<side<<" - "<<exchangeOrderId<<" - "<<entryLimitPrice<<" - "<<slice<<" - "<<price<<" - "<<quantity<<" - "<<orderDate<<" - "<<mnemo<<" - "<<glid<<endl;

		}

		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;

}
void Instrument::dump_MOAsk()
{
	ofstream fichier("baseMO.txt", ios::out | ios::app);  // ouverture en écriture avec effacement du fichier ouvert

	if(fichier)
	{
		for(unsigned int i=0;i<mosAsk.size();i++)
		{
			string side=(*(mosAsk[i])).getSide(); 
			int exchangeOrderId=(*(mosAsk[i])).getExchangeOrderId();
			int entryLimitPrice=(*(mosAsk[i])).getEntryLimitPrice();
			int slice=(*(mosAsk[i])).getSlice();
			double price=(*(mosAsk[i])).getPrice();
			double quantity=(*(mosAsk[i])).getQuantity();
			int orderDate=(*(mosAsk[i])).getOrderDate();
			string mnemo=(*(mosAsk[i])).getMnemonic();
			string glid=(*(mosAsk[i])).getGlid();

			fichier<<"side"<<" / "<<"exchangeOrderId"<<" / "<<"entryLimitPrice"<<" / "<<"slice"<<" / "<<"price"<<" / "<<"quantity"<<" / "<<"orderDate"<<" / "<<"mnemo"<<" / "<<"glid"<<endl;
			fichier<<side<<" - "<<exchangeOrderId<<" - "<<entryLimitPrice<<" - "<<slice<<" - "<<price<<" - "<<quantity<<" - "<<orderDate<<" - "<<mnemo<<" - "<<glid<<endl;

		}

		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;

}
void Instrument::dump_ML()
{
	ofstream fichier("baseML.txt", ios::out | ios::app);  // ouverture en écriture avec effacement du fichier ouvert

	if(fichier)
	{
		for(unsigned int i=0;i<mls.size();i++)
		{
			string bidPrice=(*(mls[i])).getBidPrice();
			double bidQuantity=(*(mls[i])).getBidQuantity();
			double lastTradedPrice=(*(mls[i])).getLastTradedPrice();
			string askPrice=(*(mls[i])).getAskPrice();
			double askQuantity=(*(mls[i])).getAskQuantity();
			double lastTradedQuantity=(*(mls[i])).getLastTradedQuantity();
			int numberBidOrder=(*(mls[i])).getNumberBidOrder();
			int numberAskOrder=(*(mls[i])).getNumberAskOrder();
			double averageWeightedQuotePriceBuy=(*(mls[i])).getAverageWeightedQuotePriceBuy();
			double averageWeightedQuotePriceSell=(*(mls[i])).getAverageWeightedQuotePriceSell();
			int averageWeightedQuoteVolume=(*(mls[i])).getAverageWeightedQuoteVolume();
			string mnemonic=(*(mls[i])).getMnemonic();
			string glid=(*(mls[i])).getGlid();

			fichier<<"bidPrice"<<" / "<<"bidQuantity"<<" / "<<"lastTradedPrice"<<" / "<<"askPrice"<<" / "<<"askQuantity"<<" / "<<"lastTradedQuantity"<<" / "<<"numberBidOrder"<<" / "<<"numberAskOrder"<<" / "<<"averageWeightedQuotePriceBuy"<<" / "<<"averageWeightedQuotePriceSell"<<" / "<<"averageWeightedQuoteVolume"<<" / "<<"mnemonic"<<" / "<<"glid"<<endl;
			fichier<<bidPrice<<" - "<<bidQuantity<<" - "<<lastTradedPrice<<" - "<<askPrice<<" - "<<askQuantity<<" - "<<lastTradedQuantity<<" - "<<numberBidOrder<<" - "<<numberAskOrder<<" - "<<averageWeightedQuotePriceBuy<<" - "<<averageWeightedQuotePriceSell<<" - "<<averageWeightedQuoteVolume<<" - "<<mnemonic<<" - "<<glid<<endl;

		}

		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;

}
void Instrument::dump_Dico()
{
	ofstream fichier("baseDico.txt", ios::out | ios::app);  // ouverture en écriture avec effacement du fichier ouvert

	if(fichier)
	{
		fichier<<"stockName"<<" / "<<"localCode"<<" / "<<"groupNumber"<<" / "<<"isinCode"<<" / "<<"mnemonic"<<" / "<<"glid"<<endl;
		fichier<<stockName<<" - "<<localCode<<" - "<<groupNumber<<" - "<<isinCode<<" - "<<mnemonic<<" - "<<glid<<endl;

		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;

}

void Instrument::ajouterMR(MR* mr)
{
	mrs.push_back(mr);
}
void Instrument::ajouterML(ML* ml)
{
	mls.push_back(ml);
}
void Instrument::ajouterMOBid(MO* mo)
{
	mosBid.push_back(mo);
}
void Instrument::ajouterMOAsk(MO* mo)
{
	mosAsk.push_back(mo);
}