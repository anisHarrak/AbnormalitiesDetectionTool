#ifndef DATABASE_H
#define DATABASE_H

#include "instrument.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Database
{

	vector< Instrument* > instruments;

public:
	Database();
	~Database();
	Database(vector<Instrument*> instruments);
	Database(const Database& D);
	Database& operator=(const Database& D);

	bool add(Instrument* ins);
	void afficher(Instrument* ins);
	void print()const;
	void printBaseDico();
	unsigned int getNbrInstrument() const;
	string getMnemonic() const;

	vector<Instrument*> getInstruments() const {
		return instruments;
	}

	void setInstruments(vector<Instrument*> _instruments) {
		this->instruments = _instruments;
	}


};

#endif