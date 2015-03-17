#include "database.h"
#include <iostream>
#include <string>
#include <fstream>


Database::Database()
{
	vector<Instrument*> instruments(10, static_cast<Instrument*>(0)) ;
}
Database::~Database()
{
	for(unsigned int i=0;i<instruments.size();i++)
	{
		delete instruments[i];
	}


}
Database::Database(vector<Instrument*> instruments)
{
	this->setInstruments(instruments);
}
Database::Database(const Database& D)
{

	Instrument *p;

	for(unsigned int i=0;i<D.instruments.size();i++)
	{
		p= new Instrument(*(D.instruments[i]));
		instruments.push_back(p);
	}

}
Database& Database::operator=(const Database& D)
{
	if(this!=&D)
	{
		for(unsigned int i=0;i<instruments.size();i++)
		{
			delete instruments[i];
		}
		instruments.clear();


		Instrument *p;

		for(unsigned int i=0;i<D.instruments.size();i++)
		{
			p= new Instrument(*(D.instruments[i]));
			instruments.push_back(p);
		}


	}
	return *this;
}

bool Database::add(Instrument* ins)
{
	instruments.push_back(ins);
	return true;
}
unsigned int Database::getNbrInstrument() const
{
	return instruments.size();
}

void Database::print()const
{
	Instrument ins;
	//ins.printInstr();

	ins.dump_MR();
	ins.dump_Dico();
	ins.dump_ML();
	ins.dump_MOAsk();
	ins.dump_MOBid();


	/*for(unsigned int i=0;i<instruments.size();i++)
	{
	cout<<"le stock name est : "<<instruments[i]->getStockName()<<endl;
	cout<<"le local code est : "<<instruments[i]->getLocalCode()<<endl;
	cout<<"le groupe number est : "<<instruments[i]->getGroupNumber()<<endl;
	cout<<"le isincode est : "<<instruments[i]->getIsinCode()<<endl;
	cout<<"le mnemonic est : "<<instruments[i]->getMnemonic()<<endl;
	cout<<"le glid est : "<<instruments[i]->getGlid()<<endl;
	for(unsigned int i=0;i<ins.getNbrmoAsk();i++)
	{
	instruments[i]->getMosAsk()[i]->afficher();
	}
	for(unsigned int i=0;i<ins.getNbrmoBid();i++)
	{
	instruments[i]->getMosBid()[i]->afficher();
	}
	for(unsigned int i=0;i<ins.getNbrmrs();i++)
	{
	instruments[i]->getMrs()[i]->afficher();
	}
	for(unsigned int i=0;i<ins.getNbrmls();i++)
	{
	instruments[i]->getMls()[i]->afficher();
	}

	}*/
}

void Database::afficher(Instrument* ins)
{
	if(getNbrInstrument()!=0)
	{
		ins->dump_Dico();
		ins->dump_ML();
		ins->dump_MOAsk();
		ins->dump_MOBid();
		ins->dump_MR();

	}else
	{
		printf("base vide....");
	}

}

void Database::printBaseDico()
{	
	if(getNbrInstrument()!=0)
	{
		for(unsigned int i=0;i<instruments.size();i++)
		{
			cout<<"le stock name est : "<<instruments[i]->getStockName()<<endl;
			cout<<"le local code est : "<<instruments[i]->getLocalCode()<<endl;
			cout<<"le groupe number est : "<<instruments[i]->getGroupNumber()<<endl;
			cout<<"le isincode est : "<<instruments[i]->getIsinCode()<<endl;
			cout<<"le mnemonic est : "<<instruments[i]->getMnemonic()<<endl;
			cout<<"le glid est : "<<instruments[i]->getGlid()<<endl;

		}
	}else
	{
		printf("base DICO vide....");
	}
}