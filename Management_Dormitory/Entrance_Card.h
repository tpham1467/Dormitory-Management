#include <string>
using namespace std;
#pragma once
class Entrance_Card
{
    private:
      string CardIO;
      string Registration_Date;
      string Expiration_Date;
    public:
    Entrance_Card();
    Entrance_Card(const string&,const string&,const string&);
    ~Entrance_Card();
    //_CardIO
    void Set_CardIO(const string&);
    const string& Get_CardIO();
    //_Registration_Dat
    void Set_Registration_Date(const string&);
    const string& Get_Registration_Date();
    //_Expiration_Date
    void Set_Expiration_Date(const string&);
    const string& Get_Expiration_Date();
};

