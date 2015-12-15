#include "data.h"
#include "utilities/constants.h"
#include "utilities/utils.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>

#include <stdio.h>
#include <string>

using namespace constants;
using namespace utils;


Data::Data() {
    computersOrderBy = "computerID";
    programmersOrderBy = "programmerID";
    openDB();
}

Data::~Data() {
    closeDB();
}

void Data::openDB()  {
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(QString(DATABASE_FILE_NAME.c_str()));
    if (!mydb.open())
        cout << "error open db ";


}

void Data::closeDB() {
    mydb.close();

}

void Data::disconnect(int programmerID, int computerID){
    QSqlQuery query;
    string sql = string("DELETE FROM PCConnection WHERE ProgrammerID=") +intToString(programmerID)+ string(" and computerID =") +intToString(computerID);
    query.exec(sql.c_str());
}


// ********* PROGRAMMERS *************************************************************************

Programmer Data::getProgrammer(int programmerID){
    QSqlQuery query;
    string sql =  string("select * from Programmers  where programmerID=") +intToString(programmerID);
    query.exec(sql.c_str());
    Programmer p;
    p.programmerID = 0;


    if(query.next()){
        p.programmerID = stringToInt(query.value("programmerID").toString().toStdString());
        p.Name = query.value("Name").toString().toStdString();
        p.Gender = stringToGender(query.value("Gender").toString().toStdString());
        p.BirthYear = stringToInt(query.value("BirthYear").toString().toStdString());
        p.DeadYear = stringToInt(query.value("DeadYear").toString().toStdString());
    }
    return p;
}

vector<Programmer> Data::findProgrammers(string search){
    vector<Programmer> programmers;
    int year = stringToInt(search);
    QSqlQuery query;
    string sql =  string("select * from Programmers ");
    if (search.length()>0)
        sql +=  string(" where name like '%") +search+ string("%' or gender like '%") +search+ string("%'");//
    if(year>0)
        sql+= string (" or birthyear like '%")+ search+ string("%' or deadyear like '%") +search+ string("%' ");
    sql +=  string(" order by ") +programmersOrderBy;
    query.exec(sql.c_str());
    Programmer p;
    while(query.next())
    {
        p.programmerID = stringToInt(query.value("programmerID").toString().toStdString());
        p.Name = query.value("Name").toString().toStdString();
        p.Gender = stringToGender(query.value("Gender").toString().toStdString());
        p.BirthYear = stringToInt(query.value("BirthYear").toString().toStdString());
        p.DeadYear = stringToInt(query.value("DeadYear").toString().toStdString());

        programmers.push_back(p);
    }
    return programmers;
}

vector<Programmer> Data::getProgrammers(int computerID){
    vector<Programmer> programmers;
    QSqlQuery query;
    string sql =  string("SELECT p. * from Programmers p, PCConnection bob")+
                  string(" where p.programmerID = bob.programmerID and bob.computerID =") + intToString(computerID)+
                  string(" order by ") +programmersOrderBy;
    query.exec(sql.c_str());
    Programmer p;
    while(query.next())
    {
        p.programmerID =  stringToInt(query.value("ProgrammerID").toString().toStdString());
        p.Name = query.value("Name").toString().toStdString();
        p.Gender = stringToGender(query.value("Gender").toString().toStdString());
        p.BirthYear = stringToInt(query.value("BirthYear").toString().toStdString());
        p.DeadYear = stringToInt(query.value("DeadYear").toString().toStdString());

        programmers.push_back(p);
    }
    return programmers;
}

void Data::addProgrammer(Programmer p){
    QSqlQuery query;
    string sql = string("insert into Programmers(name, gender, birthyear, deadyear) values('")+p.Name+string("','")+p.Gender+string("',")+intToString(p.BirthYear)+string(",")+intToString(p.DeadYear)+string(")");
    query.exec(sql.c_str());
}

void Data::deleteProgrammer(int programmerID){
    QSqlQuery query;
    string sql = string("DELETE FROM PCConnection WHERE ProgrammerID=") +intToString(programmerID);
    query.exec(sql.c_str());

     sql = string("DELETE FROM Programmers WHERE ProgrammerID=") +intToString(programmerID);
    query.exec(sql.c_str());
}

void Data::updateProgrammer(Programmer p){
    QSqlQuery query;
    string sql = string("UPDATE Programmers SET Name ='" ) + p.Name+ string("', Gender = '")+p.Gender+string("', BirthYear = ")+intToString(p.BirthYear)+string(", DeadYear = ")+intToString(p.DeadYear)+string("  WHERE ProgrammerID=") + intToString(p.programmerID);
    query.exec(sql.c_str());
}

void Data::orderProgrammersBy(string order){
    programmersOrderBy = order;
}

void Data::connectProgrammerToComputer(int computerID, int programmerID){
    QSqlQuery query;
    string sql = string("insert into PCConnection(programmerID, computerID) values(")+intToString(programmerID)+string(", ")+intToString(computerID)+string(")");
    query.exec(sql.c_str());

}

// ********* COMPUTERS *************************************************************************

Computer Data::getComputer(int computerID) {
    QSqlQuery query;
    string sql =  string("select * from Computers where computerID=") + intToString(computerID);
    query.exec(sql.c_str());
    Computer c;
    c.computerID = 0;


    if(query.next())
    {
        c.computerID = stringToInt(query.value("computerID").toString().toStdString());
        c.Name = query.value("Name").toString().toStdString();
        c.Type = query.value("Type").toString().toStdString();
        c.WasItBuilt = query.value("WasItBuilt").toInt();
        c.YearBuilt = stringToInt(query.value("YearBuilt").toString().toStdString());
    }
    return c;
}

vector<Computer> Data::findComputers(string search) {
    vector<Computer> computers;
    int year = stringToInt(search);
    QSqlQuery query;
    string sql =  string("select * from Computers ");
    if (search.length()>0)
        sql +=  string(" where name like '%") +search+ string("%' or type like '%") +search+ string("%' ");
    if(year>0)
        sql+= string(" or yearbuilt like '%") +search+ string("%' ");
    sql +=  string(" order by ") +computersOrderBy;
    query.exec(sql.c_str());
    Computer c;
    while(query.next())
    {
        c.computerID = stringToInt(query.value("computerID").toString().toStdString());
        c.Name = query.value("Name").toString().toStdString();
        c.Type = query.value("Type").toString().toStdString();
        c.WasItBuilt = query.value("WasItBuilt").toInt();
        c.YearBuilt = stringToInt(query.value("YearBuilt").toString().toStdString());

        computers.push_back(c);
    }
    return computers;
}

vector<Computer> Data::getComputers(int programmerID){
    vector<Computer> computers;
    QSqlQuery query;
    string sql =  string("SELECT c. * from Computers c, PCConnection bob")+
                  string(" where c.computerID = bob.computerID and bob.programmerID =") + intToString(programmerID)+
                  string(" order by ") +computersOrderBy;
    query.exec(sql.c_str());
    Computer c;
    while(query.next())
    {
        c.computerID = stringToInt(query.value("computerID").toString().toStdString());
        c.Name = query.value("Name").toString().toStdString();
        c.Type = query.value("Type").toString().toStdString();
        c.WasItBuilt = query.value("WasItBuilt").toInt();
        c.YearBuilt = stringToInt(query.value("YearBuilt").toString().toStdString());

        computers.push_back(c);
    }
    return computers;
}

void Data::addComputer(Computer c) {
    QSqlQuery query;
    string sql = string("insert into Computers(name, type, wasitbuilt, yearbuilt) values('")+c.Name+string("','")+c.Type+string("',")+intToString(c.WasItBuilt)+string(",")+intToString(c.YearBuilt)+string(")");
    query.exec(sql.c_str());
}

void Data::deleteComputer(int computerID) {
    QSqlQuery query;
    string sql = string("DELETE FROM PCConnection WHERE computerID=") +intToString(computerID);
    query.exec(sql.c_str());
     sql = string("DELETE FROM Computers WHERE computerID=") +intToString(computerID);
    query.exec(sql.c_str());
}

void Data::updateComputer(Computer c) {
    QSqlQuery query;
    string sql = string("UPDATE Computers SET Name ='" ) + c.Name+ string("', Type = '")+c.Type+string("', WasItBuilt = ")+intToString(c.WasItBuilt)+string(", YearBuilt = ")+intToString(c.YearBuilt)+string("  WHERE ComputerID=") + intToString(c.computerID);
    query.exec(sql.c_str());
}

    // input : order - sort order
    // sets the display order for the selected computers
void Data::orderComputersBy(string order) {
    computersOrderBy = order;
}
