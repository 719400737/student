#ifndef C_MAIN_VIEW_H
#define C_MAIN_VIEW_H

#include<iostream>
#include<map>
#include<string>
#include"CStudent.h"
#include"CStudentMg.h"
#include<mysql/mysql.h>

class CMainView
{
public:
    CMainView();
    ~CMainView();
    
    //welcome
    void welcome();

    //showMenu
    void showMenu();

    //view all stu
    void showAllstuAtView(MYSQL *mysql);

    //view add one
    void addStuAtView(MYSQL *mysql);

    //view find one
    void findStuAtView(MYSQL *mysql);

    //dele one
    void deleteByIdAtView(MYSQL *mysql);

    //update
    void updateByIdAtView(MYSQL *mysql);

    //save to flie
    void saceToFileAtView(MYSQL *mysql,std::string pathname);

    //read from file
    void readFromFileAtView(std::map<int,CStudent> &stu_m1,std::string pathname);

private:




};

#endif