#include "slcFeedGetter.h"
#include <iostream>
#include <string>
#include <fstream>
SCLogCategory(sc);

SLCFeedGetter::SLCFeedGetter():UTPThread(){}
SLCFeedGetter::~SLCFeedGetter()
{
	delete checker;
	delete buffer;
}
SLCFeedGetter::SLCFeedGetter(Check* checker):UTPThread()
{
	setChecker(checker);

}


bool  SLCFeedGetter::configurerServeur( const char *filename)
{
	SCConfig config;
	bool result = config.load(filename);
	if (result) 
	{
		int uti;

		SCAddress ServerId,StationId;
		std::string p3Host;
		std::string p3Service;
		std::string password;
		const char *section = "server";
		result &= config.doGet(section, "ServerId", ServerId);
		result &= config.doGet(section, "StationId", StationId);
		result &= config.doGetIPAddress(section, "p3", p3Host, p3Service);
		result &= config.doGet(section, "password", password);

		if (result) 
		{
			session.setP3(p3Host, p3Service);
			session.setSource(StationId);
			session.setDestination(ServerId);
			session.setUti(uti);
			session.setPassword(password.c_str());
			session.setReadTimeout(500000);
			session.setWriteTimeout(500000);
			session.setConnectionTimeout(500000);
		}
	}

	if (result) 
	{
		printf("Configuration successful");
	}
	else
	{
		printf("Configuration failed");
	}

	return result;
}

bool SLCFeedGetter::start(int id)
{

	const char *filename="anomalyConf.ini";

	SCLogger &logger = SCLogger::Singleton();
	logger.setConfigurationPath(filename);
	logger.setApplicationVersion("1.0");
	logger.open();
	configurerServeur(filename);       //configurer le serveur 
	session.open();                   //ouvrir la session

	SCConfig config;
	bool result_config = config.load(filename);
	if (result_config)
	{
		std::string Glid;
		const char *section = "server";
		config.doGet(section, "Glid", Glid);

		SCRecord record0;
		record0.setAt(1, SCFid_sessionKey);
		SCRecord record1;
		record1.setAt(Glid.c_str(), SCFid_GLID);

		std::vector<SCRecord *> requestDICO;
		requestDICO.push_back(&record0);
		requestDICO.push_back(&record1);

		std::vector<SCRecord *> request;
		SCRecord record3;
		record3.setAt(1, SCFid_sessionKey);
		record3.setAt(Glid.c_str(), SCFid_GLID);
		record3.setAt("1", SCFid_selectAll);
		record3.setAt(100, SCFid_numberOfDesiredOrders);	
		request.push_back(&record3);

		result= session.write(5109, requestDICO);
		result=session.write(1061, request);
		result= session.write(1001, request);
		result= session.write(1005, request);
		//SCThread::start();
		checker->start();
		run();

	}

	return result;

}
void SLCFeedGetter::run()
{

	std::vector<SCRecord *> response;
	int id=0;

	while (session.read(response,&id) )
	{

		for (int i=0, n=response.size(); i<n; i++) 
		{
			//SCProd("id est : %d",id);
			if(result)

			{
				Record *rec = new Record(id,response[i] );
				buffer->push(*rec);
				//SCProd("l'id ajouté est %d et l'SCRecord est %O : ",rec->getId_request(), rec->getRecord());					

			}

		}

		session.recycleRecords(response);

	}

	session.close();


}
void SLCFeedGetter::stop()
{
	Record* rec=new Record();
	while (buffer->size())
	{
		buffer->pop(*rec);
		delete rec;
	}
}
