#ifndef C_STUDENT_MG_H
#define C_STUDENT_MG_H
#include"CStudent.h"
#include<map>
#include<string>

class CStudentMg{
public:
    CStudentMg();
    ~CStudentMg();
    //add
    CStudent addAStu(std::map<int,CStudent> &m1,CStudent &stu);

    //del
    bool deleteStuById(std::map<int,CStudent> &m1,const int & id);

    //updata
    CStudent updateStu(std::map<int,CStudent> &m1,const CStudent &stu);

    //find
    CStudent findById(const std::map<int,CStudent> &m1,const int & id);

    //showall
    void showAll(const std::map<int,CStudent> &m1) const;

    //save to file
    bool saveToFile(const std::map<int,CStudent> &m1,std::string pathName);

    //read from file

    bool readFromFile(std::map<int,CStudent> & m1,std::string path);

private:

};

#endif