#include "check.h"
SCLogCategory(sc);

Check::Check(unsigned int bsize):UTPThread(),m_buffer(bsize),m_buffersize(bsize)
{
}

Check::Check(Database BD)
{
	this->BD=BD;
}

bool Check::update(Record& rec)
{

	if(rec.getId_request()== 1003 || rec.getId_request()== 1001  )// 1001 c'est l'id du MR request
	{
		Instrument ins;
		MR *ptr_mr=new MR();
		ptr_mr->setCurrency(rec.getCurency());
		ptr_mr->setClosingPrice(rec.getClosingprice());
		ptr_mr->setGroupNumber(rec.getgroupnumber());
		ptr_mr->setIsinCode(rec.getIsincode());
		ptr_mr->setLocalCode(rec.getLocal_code());
		ptr_mr->setMarket(rec.getMarket());
		ptr_mr->setMininumlot(rec.getMininumlot());
		ptr_mr->setNumberOfDecimals(rec.getNumberofdecimals());
		ptr_mr->setPlaceofQuotation(rec.getPlaceOfQuotation());
		ptr_mr->setStockName(rec.getStockname());
		ptr_mr->setTicksize(rec.getTicksize());
		ptr_mr->setUpperReservationLevel(rec.getUpperReservationLevel());
		ptr_mr->setLowerReservationLevel(rec.getLowerReservationLevel());
		ptr_mr->setGlid(rec.getGliD());
		ptr_mr->setMnemonic(rec.getMnemo());

		ins.ajouterMR(ptr_mr);
	
		if(BD.add(&ins))
		{
			BD.afficher(&ins);
		}
		else
		{
			cout<<"échec de l'ajout ..."<<endl;
		}							
	}
	else if(rec.getId_request()== 1007 || rec.getId_request()== 1005)// 1005 c'est l'id du ML request
	{
		Instrument ins;
		ML *ptr_ml=new ML();
		ptr_ml->setBidPrice(rec.getBidprice());
		ptr_ml->setBidQuantity(rec.getBidQuantity());
		ptr_ml->setLastTradedPrice(rec.getLastTradedprice());
		ptr_ml->setLastTradedQuantity(rec.getLastTradedquantity());
		ptr_ml->setAskPrice(rec.getAskprice());
		ptr_ml->setAskQuantity(rec.getAskquantity());
		ptr_ml->setNumberBidOrder(rec.getNumberBidOrder());
		ptr_ml->setNumberAskOrder(rec.getNumberAskOrder());
		ptr_ml->setAverageWeightedQuotePriceBuy(rec.getAverageWeightedQuotePriceBuy());
		ptr_ml->setAverageWeightedQuotePriceSell(rec.getAverageWeightedQuotePriceSell());
		ptr_ml->setAverageWeightedQuoteVolume(rec.getAverageWeightedQuoteVolume());
		ptr_ml->setMnemonic(rec.getMnemo());
		ptr_ml->setGlid(rec.getGliD());

		ins.ajouterML(ptr_ml);
		
		if(BD.add(&ins))
		{
			BD.afficher(&ins);
		}
		else
		{
			cout<<"échec de l'ajout ..."<<endl;
		}	

	}
	else if(rec.getId_request()== 5109 )// 5109 c'est l'id du dico request
	{
		Instrument *inst = new Instrument();
		inst->setStockName(rec.getStockname());
		inst->setLocalCode(rec.getLocalcode());
		inst->setGroupNumber(rec.getgroupnumber());
		inst->setIsinCode(rec.getIsincode());
		inst->setGlid(rec.getGliD());
		inst->setMnemonic(rec.getMnemo());
		
		if(BD.add(inst))
		{
			BD.afficher(inst);
		}
		else
		{
			cout<<"échec de l'ajout ..."<<endl;
		}			

	}
	else if(rec.getId_request()== 1061 || rec.getId_request()== 1063)// 1061 c'est l'id du Mo request
	{
		Instrument ins;
		MO *ptr_mo=new MO();
		ptr_mo->setSide(rec.getSide());
		ptr_mo->setExchangeOrderId(rec.getExchangeOrderId());
		ptr_mo->setEntryLimitPrice(rec.getEntrylimitprice());
		ptr_mo->setSlice(rec.getSlice());
		ptr_mo->setPrice(rec.getPrice());
		ptr_mo->setQuantity(rec.getQuantity());
		ptr_mo->setOrderDate(rec.getOrderdate());
		ptr_mo->setMnemonic(rec.getMnemo());
		ptr_mo->setGlid(rec.getGliD());

		if(rec.getSide()=="1" || rec.getSide()=="A")
		{
			ins.ajouterMOBid(ptr_mo);
			
			if(BD.add(&ins))
			{
				BD.afficher(&ins);
			}
			else
			{
				cout<<"échec de l'ajout ..."<<endl;
			}		
		}
		else
		{
			ins.ajouterMOAsk(ptr_mo);
			
			if(BD.add(&ins))
			{
				BD.afficher(&ins);
			}
			else
			{
				cout<<"échec de l'ajout ..."<<endl;
			}	
		}

	}
	else
	{
		return false;
	} 


	return true;

}

void Check::run()
{
	Record* rec= new Record();
	while (1)
	{
		if(m_buffer.pop(*rec))
		{
			SCProd("l'id du record retire est %d et l'SCRecord est %O :  ",rec->getId_request(),rec->getRecord());
			//_checkAskPrice(*rec);
			
			/*if(update(*rec))
			{
				SCProd("Record enregistré ... ");
				
			}else
			{
				SCProd("Failure ... ");
			}*/

		}

	}

}

void Check::stop()
{
	Record* rec= new Record();
	while (m_buffer.size())
	{
		m_buffer.pop(*rec);
		delete rec;
	}
}

bool Check::IsBufferFull()
{
	return m_buffer.isfull();
}
unsigned int Check::BufferSize()
{
	return m_buffer.size();
}

//bool Check::_checkAskPrice(Record& rec)
//{
//	//Instrument ins;
//	if(update(rec))
//	{
//		SCProd("Record enregistré avec succés... ");
//				
//	}else
//	{
//		SCProd("Failure ... ");
//	}
//
//		ofstream fichier("log.txt", ios::out | ios::app);  
//		if(fichier)
//		{
//			for(unsigned int i=0;i<BD.getNbrInstrument();i++)
//			{
//				for(unsigned int j=0;j<BD.getInstruments()[j]->getNbrmoAsk();j++)
//				{
//					if(BD.getInstruments()[j]->getMosAsk()[j]->getPrice() < BD.getInstruments()[j+1]->getMosAsk()[j+1]->getPrice())
//					{
//						fichier<<"l'instrument vendu avec le glid  "<<BD.getInstruments()[j]->getMosAsk()[j]->getGlid()<<" et le mnemonic "<<BD.getInstruments()[j]->getMosAsk()[j]->getMnemonic()<<"est trié ..."<<endl;
//						return true;
//					
//					}
//					else
//					{
//						fichier<<"l'instrument vendu avec le glid  "<<BD.getInstruments()[j]->getMosAsk()[j]->getGlid()<<" et le mnemonic "<<BD.getInstruments()[j]->getMosAsk()[j]->getMnemonic()<<"n'est pas trié ..."<<endl;
//						return false;
//					}
//				
//					fichier.close();
//				}
//			}
//		}
//		else
//			cerr << "Impossible d'ouvrir le fichier !" << endl;
//		
//		/*for(unsigned int i=0;i<ins.getNbrmoAsk()-1;i++)
//	{
//		if(ins.getMosAsk()[i]->getPrice() > ins.getMosAsk()[i+1]->getPrice())
//		{
//			cout<<"l'instrument avec le glid  "<<ins.getMosAsk()[i]->getGlid()<<" et le mnemonic "<<ins.getMosAsk()[i]->getMnemonic()<<"n'est pas trié"<<endl;
//			return false;
//		}
//		else
//			return true;
//	}*/
//
//}