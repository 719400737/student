#ifndef C_STUDENT_MG_H
#define C_STUDENT_MG_H
#include"CStudent.h"
#include<map>
#include<string>
using namespace std;
class CStudentMg{
public:
    CStudentMg();
    ~CStudentMg();
    //add
    CStudent addAStu(map<int,CStudent> &m1,CStudent &stu);

    //del
    bool deleteStuById(map<int,CStudent> &m1,const int & id);

    //updata
    CStudent updateStu(map<int,CStudent> &m1,const CStudent &stu);

    //find
    CStudent findById(const map<int,CStudent> &m1,const int & id);

    //showall
    void showAll(const map<int,CStudent> &m1) const;

    //save to file
    bool saveToFile(const map<int,CStudent> &m1,string pathName);

    //read from file

    bool readFromFile(map<int,CStudent> & m1,string path);

private:

};

#endif