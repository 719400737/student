#ifndef C_STUDENT_MG_H
#define C_STUDENT_MG_H
#include"CStudent.h"
#include<map>
#include<string>
#include<mysql/mysql.h>
#include <iomanip>

class CStudentMg{
public:
    CStudentMg();
    ~CStudentMg();
    //add
    CStudent addAStu(MYSQL *mysql,CStudent &stu);

    //del
    bool deleteStuById(MYSQL *mysql,const int & id);

    //updata
    void updateStu(MYSQL *mysql,const CStudent &stu);

    //find
    void findById(MYSQL *mysql,const int & id);

    //showall
    void showAll(MYSQL *mysql) const;

    //save to file
    bool saveToFile(MYSQL *mysql,std::string pathName);

    //read from file

    bool readFromFile(std::map<int,CStudent> & m1,std::string path);

private:

};

#endif