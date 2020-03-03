#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<sstream>
#include"CStudent.h"
#include"CStudentMg.h"

using namespace std;

CStudentMg::CStudentMg(){}
CStudentMg::~CStudentMg(){}

CStudent CStudentMg::addAStu(map<int,CStudent> & m1,CStudent & stu){
    
    return stu;
}

//del
bool  CStudentMg::deleteStuById(map<int,CStudent> &m1,const int & id){


    bool b=true;
    return b;
}

//updata
CStudent CStudentMg::updateStu(map<int,CStudent> &m1,const CStudent &stu){

    return stu;
}

//find
CStudent CStudentMg::findById(const map<int,CStudent> &m1,const int & id){

    CStudent stu;
    return stu;
}

//showall
void CStudentMg::showAll(const map<int,CStudent> &m1) const{



}

//save to file
bool CStudentMg::saveToFile(const map<int,CStudent> &m1,string pathName){

    bool b=true;
    return b;
}
//read from file
bool CStudentMg::readFromFile(map<int,CStudent> & m1,string path){


    bool b=true;
    return b;
}