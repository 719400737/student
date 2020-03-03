#ifndef C_MAIN_VIEW_H
#define C_MAIN_VIEW_H

#include<iostream>
#include<map>
#include<string>
#include"CStudent.h"
#include"CStudentMg.h"
using namespace std;

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
    void showAllstuAtView(const map<int,CStudent> & stu_m1);

    //view add one
    void addStuAtView(map<int,CStudent> &stu_m1);

    //view find one
    void findStuAtView(const map<int,CStudent> &stu_m1);

    //dele one
    void deleteByIdAtView(map<int,CStudent> &stu_m1);

    //update
    void updateByIdAtView(map<int,CStudent> &stu_m1);

    //save to flie
    void saceToFileAtView(map<int,CStudent> &stu_m1,string pathname);

    //read from file
    void readFromFileAtView(map<int,CStudent> &stu_m1,string pathname);

private:




};

#endif