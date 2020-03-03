#ifndef C_STUDENT_H
#define C_STUDENT_H
#include<string>
#include<iostream>
using namespace std;
class CStudent
{
    //friend function
    friend ostream & operator <<(ostream & os,CStudent & stu);
    friend istream & operator >>(istream & os,CStudent & stu);
public:
    CStudent();
    ~CStudent();

    int getId() const;
    void setId(int val);
    string getName() const;
    void setName(string val);
    int getAge() const;
    void setAge(int val);

private:
    int id;
    string name;
    int age;
};
#endif