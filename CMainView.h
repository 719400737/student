#ifndef C_MAIN_VIEW_H
#define C_MAIN_VIEW_H

#include<iostream>
#include<map>
#include<string>
#include"CStudent.h"
#include"CStudentMg.h"

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
    void showAllstuAtView(const std::map<int,CStudent> & stu_m1);

    //view add one
    void addStuAtView(std::map<int,CStudent> &stu_m1);

    //view find one
    void findStuAtView(const std::map<int,CStudent> &stu_m1);

    //dele one
    void deleteByIdAtView(std::map<int,CStudent> &stu_m1);

    //update
    void updateByIdAtView(std::map<int,CStudent> &stu_m1);

    //save to flie
    void saceToFileAtView(std::map<int,CStudent> &stu_m1,std::string pathname);

    //read from file
    void readFromFileAtView(std::map<int,CStudent> &stu_m1,std::string pathname);

private:




};

#endif