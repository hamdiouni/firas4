#include"connection.h"


connection::connection(){}

 bool connection::createconnection()
 {

     QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("firas_qt");
db.setUserName("firas");
db.setPassword("hamdiouni");

if(db.open())test=true;
return test;
 }
