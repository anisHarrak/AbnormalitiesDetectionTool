#include "checkPrice.h"
SCLogCategory(sc);

CheckPrice::CheckPrice():CheckMO(){}
CheckPrice::CheckPrice(Database& _BD)
{
	this->BD=_BD;
}

bool CheckPrice::_checkAskPrice(Record& rec)
{
	//Instrument ins;
	if(update(rec))
	{
		SCProd("Record enregistré avec succés... ");
				
	}else
	{
		SCProd("Failure ... ");
	}

		ofstream fichier("log.txt", ios::out | ios::app);  
		if(fichier)
		{
			for(unsigned int i=0;i<BD.getNbrInstrument();i++)
			{
				for(unsigned int j=0;j<BD.getInstruments()[j]->getNbrmoAsk();j++)
				{
					if(BD.getInstruments()[j]->getMosAsk()[j]->getPrice() < BD.getInstruments()[j+1]->getMosAsk()[j+1]->getPrice())
					{
						fichier<<"l'instrument vendu avec le glid  "<<BD.getInstruments()[j]->getMosAsk()[j]->getGlid()<<" et le mnemonic "<<BD.getInstruments()[j]->getMosAsk()[j]->getMnemonic()<<"est trié ..."<<endl;
						return true;
					
					}
					else
					{
						fichier<<"l'instrument vendu avec le glid  "<<BD.getInstruments()[j]->getMosAsk()[j]->getGlid()<<" et le mnemonic "<<BD.getInstruments()[j]->getMosAsk()[j]->getMnemonic()<<"n'est pas trié ..."<<endl;
						return false;
					}
				
				}
			}
			fichier.close();
		}
		else
			cerr << "Impossible d'ouvrir le fichier !" << endl;
	
}
bool CheckPrice::_checkBidPrice(Record& rec)
{
	
	if(update(rec))
	{
		SCProd("Record enregistré ... ");
				
	}else
	{
		SCProd("Failure ... ");
	}

	
	ofstream fichier("log.txt", ios::out | ios::app);  
		if(fichier)
		{
			for(unsigned int i=0;i<BD.getNbrInstrument();i++)
			{
				for(unsigned int j=0;j<BD.getInstruments()[j]->getNbrmoBid();j++)
				{
					if(BD.getInstruments()[i]->getMosBid()[i]->getPrice() > BD.getInstruments()[i+1]->getMosBid()[i+1]->getPrice())
					{
						fichier<<"l'instrument acheté avec le glid  "<<BD.getInstruments()[i]->getMosBid()[i]->getGlid()<<" et le mnemonic "<<BD.getInstruments()[i]->getMosBid()[i]->getMnemonic()<<"est trié ..."<<endl;
						return true;
					
					}
					else
					{
						fichier<<"l'instrument acheté avec le glid  "<<BD.getInstruments()[i]->getMosBid()[i]->getGlid()<<" et le mnemonic "<<BD.getInstruments()[i]->getMosBid()[i]->getMnemonic()<<"n'est pas trié ..."<<endl;
						return false;
					}
				}
			}
			fichier.close();
		}
		else
			cerr << "Impossible d'ouvrir le fichier !" << endl;

}

bool CheckPrice::_checkBdvsAk(Record& rec)
{
	if(update(rec))
	{
		SCProd("Record enregistré ... ");
				
	}else
	{
		SCProd("Failure ... ");
	}

	ofstream fichier("log.txt", ios::out | ios::app);  
		if(fichier)
		{
			for(unsigned int i=0;i<BD.getNbrInstrument();i++)
			{
				for(unsigned int j=0;j<BD.getInstruments()[j]->getNbrmoAsk();j++)
				{
					for(unsigned int k=0;k<BD.getInstruments()[k]->getNbrmoBid();k++)
					{
						if(BD.getInstruments()[k]->getMosBid()[k]->getPrice() < BD.getInstruments()[j]->getMosAsk()[j]->getPrice())
						{
							fichier<<"le prix d'achat de l'instrument avec le glid  "<<BD.getInstruments()[k]->getMosBid()[k]->getGlid()<<"et le mnemonic "<<BD.getInstruments()[k]->getMosBid()[k]->getMnemonic()<<"est inférieur au prix de vente "<<endl;
							i++;
							return true;
						}
						else
						{
							fichier<<"le prix d'achat de l'instrument avec le glid  "<<BD.getInstruments()[k]->getMosBid()[k]->getGlid()<<"et le mnemonic "<<BD.getInstruments()[k]->getMosBid()[k]->getMnemonic()<<"est supérieur au prix de vente "<<endl;
							return false;
						}
					}
				}
			}
			fichier.close();
		}
		else
			cerr << "Impossible d'ouvrir le fichier !" << endl;

}

void CheckPrice::run()
{
	Record* rec= new Record();
	while (1)
	{
		if(m_buffer.pop(*rec))
		{
			SCProd("l'id du record retiré est %d et l'SCRecord correspondant est %O :  ",rec->getId_request(),rec->getRecord());
			_checkAskPrice(*rec);
			//_checkBidPrice(*rec);
			//_checkBdvsAk(*rec);
			
		}
	
	}

}
bool CheckPrice::start(int id)
{
	run();
	return true;
}