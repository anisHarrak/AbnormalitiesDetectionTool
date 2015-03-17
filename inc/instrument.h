#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include "MO.h"
#include "ML.h"
#include "MR.h"
#include "dico.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class Instrument
{
private:
	string stockName;
	string localCode;
	string groupNumber;
	string isinCode;
	string mnemonic;
	string glid;
	vector<ML*> mls;
	vector<MO*> mosBid;
	vector<MO*> mosAsk;
	vector<MR*> mrs;
public:
	Instrument();
	Instrument(string stockName,string localCode,string groupNumber,string isinCode,string mnemonic,string glid);
	~Instrument();
	Instrument(const Instrument& I);
	Instrument& operator=(const Instrument& I);
	void printInstr() const;
	void ajouterMR(MR* mr);
	void ajouterML(ML* ml);
	void ajouterMOBid(MO* mo);
	void ajouterMOAsk(MO* mo);

	void dump_MOBid();
	void dump_MOAsk();
	void dump_ML();
	void dump_MR();
	void dump_Dico();

	unsigned int getNbrmoBid() const
	{
		return mosBid.size();
	}
	unsigned int getNbrmoAsk() const
	{
		return mosAsk.size();
	}

	int getNbrmrs()const
	{
		return getMrs().size();
	}
	int getNbrmls()const
	{
		return getMls().size();
	}

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

	vector<ML*> getMls() const {
		return mls;
	}

	void setMls(vector<ML*> _mls) {
		this->mls = _mls;
	}
	vector<MO*> getMosBid() const {
		return mosBid;
	}

	void setMosBid(vector<MO*> _mosBid) {
		this->mosBid = _mosBid;
	}
	vector<MO*> getMosAsk() const {
		return mosAsk;
	}

	void setMosAsk(vector<MO*> _mosAsk) {
		this->mosAsk = _mosAsk;
	}
	vector<MR*> getMrs() const {
		return mrs;
	}

	void setMrs(vector<MR*> _mrs) {
		this->mrs = _mrs;
	}

};
#endif