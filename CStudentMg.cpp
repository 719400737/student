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
    m1.insert(make_pair(stu.getId(),stu));
    return stu;
}

//del
bool  CStudentMg::deleteStuById(map<int,CStudent> &m1,const int & id){
    bool b=false;
    map<int,CStudent>::iterator it;
    it=m1.find(id);
    if(it!=m1.end()){
        m1.erase(it);
        b=true;
    }
    
    return b;
}

//updata
CStudent CStudentMg::updateStu(map<int,CStudent> &m1,const CStudent &cstu){
    CStudent stu;
    int id=cstu.getId();
    map<int,CStudent>::iterator it;
    it=m1.find(id);
    if(it!=m1.end()){
        it->second=cstu;
        stu=cstu;
    }
    return stu;
}

//find
CStudent CStudentMg::findById(const map<int,CStudent> &m1,const int & id){

    CStudent stu;
    map<int,CStudent>::const_iterator it;
    it=m1.find(id);
    if(it!=m1.end()){
        stu=it->second;
    }
    return stu;
}

//showall
void CStudentMg::showAll(const map<int,CStudent> &m1) const{
    for(auto p:m1){
        cout<<p.second<<endl;
    }


}

//save to file
bool CStudentMg::saveToFile(const map<int,CStudent> &m1,string pathName){

    bool b=true;

    fstream ofs(pathName,ios::out);
    if(ofs){
        stringstream ss;
        cout<<"open the file"<<endl;

        CStudent stu;
        for(auto p=m1.begin();p!=m1.end();p++){
            stu=p->second;
            ss<<stu<<endl;
        }
        ofs<<ss.str();
        ofs.close();
    }
    else{
        b=false;
        cout<<"file open falure"<<endl;
    }
    
    
    return b;
}
//read from file
bool CStudentMg::readFromFile(map<int,CStudent> & m1,string path){

    bool b=true;
    fstream inf(path,ios::in);
    if(inf){
        cout<<"open file success"<<endl;
        string s;
        stringstream ss;
        while(getline(inf,s)){
            CStudent cStu;
            ss<<s;
            ss>>cStu;
            ss.clear();

            m1.insert(make_pair(cStu.getId(),cStu));
        }
        inf.close();
    }
    else{
        cout<<"file open falure"<<endl;
        b=false;
    }
    return b;
}
