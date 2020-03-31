#include<iostream>
#include<string>
#include<mysql/mysql.h>
#include<map>
#include"CStudent.h"
#include"CStudentMg.h"
#include"CMainView.h"

using namespace std;

MYSQL mysql;
void mysql_test(){
    char user[]="root";
    char pswd[]="123456";
    char host[]="localhost";
    char db[]="stu";
    unsigned int port=3306;
    mysql_init(&mysql);
    if(mysql_real_connect(&mysql,host,user,pswd,db,port,NULL,0)){
        cout<<"*****欢迎进入学生系统*****"<<endl;
    }
    else{
        cout<<"进入失败，请稍后再试"<<endl;
    }
}

int main(){
    string pathName="/home/han/桌面/studentSQL/student.txt";
    map<int,CStudent> stu_v1;
    //使用数据库代替map
    mysql_test();
    
    CMainView cview;
    cview.welcome();
    cview.showMenu();
    string operateType;
    cin>>operateType;
    while (operateType!="0"){
        if(operateType=="1")
            cview.addStuAtView(&mysql);
        else if(operateType=="2")
            cview.updateByIdAtView(&mysql);
        else if(operateType=="3")
            cview.findStuAtView(&mysql);
        else if(operateType=="4")
            cview.deleteByIdAtView(&mysql);
        else if(operateType=="5")
            cview.showAllstuAtView(&mysql);
        else if(operateType=="6")
            cview.saceToFileAtView(&mysql,pathName);
        // else if(operateType=="7")
        //     cview.readFromFileAtView(stu_v1,pathName);
        else{
            cview.welcome();
            cview.showMenu();
        }
        cin>>operateType;
    }


    return 0;
}