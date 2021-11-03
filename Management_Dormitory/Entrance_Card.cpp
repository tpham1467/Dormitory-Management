#include "Entrance_Card.h"
Entrance_Card::Entrance_Card()
{
}
Entrance_Card::~Entrance_Card()
{
}
Entrance_Card::Entrance_Card(const string& _CardIO, const string& _Registration_Date, const string& _Expiration_Date)
             :CardIO(_CardIO), Registration_Date(_Registration_Date), Expiration_Date(_Expiration_Date)
{
}
//CardIO
void Entrance_Card::Set_CardIO(const string &_CardIO)
{
    this->CardIO = _CardIO;
}
const string &Entrance_Card::Get_CardIO()
{
    return this->CardIO;  
}
//Registration_Date
void Entrance_Card::Set_Registration_Date(const string &_Registration_Date)
{
    this->Registration_Date = _Registration_Date;
}
const string &Entrance_Card::Get_Registration_Date()
{
    return this->Expiration_Date;
}
//Expiration_Date
void Entrance_Card::Set_Registration_Date(const string &_Expiration_Date)
{
    this->Expiration_Date = _Expiration_Date;
}
const string &Entrance_Card::Get_Expiration_Date()
{
    return this->Expiration_Date;
}