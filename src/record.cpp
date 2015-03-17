#include "record.h"

Record::Record()
{
	this->id_request=0;
	this->record=NULL;
}
Record::~Record()
{
	delete record;
}
Record::Record(int _id_request, SCRecord* _record)
{
	this->id_request=_id_request;
	this->setRecord(_record);
}

Record& Record::operator=( const Record& s )
{
	this->id_request=s.id_request;
	this->record=s.record;
	return *this;
}