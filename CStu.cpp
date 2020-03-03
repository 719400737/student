#include<iostream>
#include<string>
#include"CStudent.h"

using namespace std;
//学生默认id为-1，说明为一个无效学生
CStudent::CStudent(){this->id=-1;}
CStudent::~CStudent(){}
//声明函数进行定义
int CStudent::getId() const {return id;}
void CStudent::setId(int val) {id=val;}

string CStudent::getName() const {return name;}
void CStudent::setName(string val) { name=val;}

int CStudent::getAge() const {return age;}
void CStudent::setAge(int val) {age=val;}

ostream & operator<<(ostream & os,CStudent & stu){
    os<<stu.getId()<<"  "<<stu.getName()<<"  "<<stu.getAge();
    return os;
}
istream & operator>>(istream & is,CStudent & stu){
    is>>stu.id>>stu.name>>stu.age;
    return is;
}