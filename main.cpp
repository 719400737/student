#include<iostream>
#include<string>
#include<map>
#include"CStudent.h"
#include"CStudentMg.h"
#include"CMainView.h"

using namespace std;

int main(){
    string pathName="C:/Users/Administrator/Desktop/student.txt";
    map<int,CStudent> stu_v1;
    CMainView cview;
    cview.welcome();
    cview.showMenu();
    string operateType;
    cin>>operateType;
    while (operateType!="0"){
        if(operateType=="1")
            cview.addStuAtView(stu_v1);
        else if(operateType=="2")
            cview.updateByIdAtView(stu_v1);
        else if(operateType=="3")
            cview.findStuAtView(stu_v1);
        else if(operateType=="4")
            cview.deleteByIdAtView(stu_v1);
        else if(operateType=="5")
            cview.showAllstuAtView(stu_v1);
        else if(operateType=="6")
            cview.saceToFileAtView(stu_v1,pathName);
        else if(operateType=="7")
            cview.readFromFileAtView(stu_v1,pathName);
        else{
            cview.welcome();
            cview.showMenu();
        }
        cin>>operateType;
    }


    return 0;
}