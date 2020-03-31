#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<sstream>
#include"CStudent.h"
#include"CStudentMg.h"

using namespace std;

MYSQL_RES *res;
MYSQL_ROW row;

CStudentMg::CStudentMg(){}
CStudentMg::~CStudentMg(){}

CStudent CStudentMg::addAStu(MYSQL *mysql,CStudent & stu){
    char sqlstr[1024];
    int id=stu.getId();
    string name=stu.getName();
    const char *n=name.c_str();
    int age=stu.getAge();
    int len = sprintf(sqlstr, "INSERT INTO student2 \
							  VALUES('%d','%s','%d');",id,n,age);
    mysql_query(mysql,sqlstr);
    return stu;
}

//del
bool  CStudentMg::deleteStuById(MYSQL *mysql,const int & id){
    bool b=false;
    char sqlstr[1024];
    int len;
    len=sprintf(sqlstr,"select * from student2 where id='%d'",id);
    mysql_query(mysql,sqlstr);
	res = mysql_store_result(mysql);
    row = mysql_fetch_row(res);
    if(row){
        b=true;
        len=sprintf(sqlstr,"delete from student2 where id='%d';",id);
        mysql_query(mysql,sqlstr);
    }
    mysql_free_result(res);
    return b;
}

//updata
void CStudentMg::updateStu(MYSQL *mysql,const CStudent &cstu){

    int id=cstu.getId();
    char sqlstr[1024];
    int len;
    len=sprintf(sqlstr,"select * from student2 where id='%d'",id);
    mysql_query(mysql,sqlstr);
	res = mysql_store_result(mysql);
    row = mysql_fetch_row(res);
    if(row){
        string name=cstu.getName();
        const char *n=name.c_str();
        int age=cstu.getAge();
        len=sprintf(sqlstr,"update student2 set name='%s' where id='%d';",n,id);
        mysql_query(mysql,sqlstr);
        len=sprintf(sqlstr,"update student2 set age='%d' where id='%d';",age,id);
        mysql_query(mysql,sqlstr);
        mysql_free_result(res);
        return;
        
    }
    cout<<"can't find this student"<<endl;
    mysql_free_result(res);

}

//find
void CStudentMg::findById(MYSQL *mysql,const int & id){


    char sqlstr[1024];
    int len;
    len=sprintf(sqlstr,"select * from student2 where id='%d'",id);
    mysql_query(mysql,sqlstr);
	res = mysql_store_result(mysql);
    row = mysql_fetch_row(res);
    if(row){
        cout << left << setw(8) << row[0];
		cout << left << setw(8) << row[1];
		cout << left << setw(8) << row[2];
		cout << endl;
    }
    mysql_free_result(res);

}

//showall
void CStudentMg::showAll(MYSQL *mysql) const{
    mysql_query(mysql,"select * from student2");
	res = mysql_store_result(mysql);
	printf("sno\tname\tage\t\n");
	while (row = mysql_fetch_row(res))
	{
		cout << left << setw(8) << row[0];
		cout << left << setw(8) << row[1];
		cout << left << setw(8) << row[2];
		cout << endl;
	}
	mysql_free_result(res);


}

//save to file
bool CStudentMg::saveToFile(MYSQL *mysql,string pathName){

    bool b=true;
    mysql_query(mysql,"select * from student2");
	res = mysql_store_result(mysql);
	printf("sno\tname\tage\t\n");
	
    fstream ofs(pathName,ios::out);
    if(ofs){
        stringstream ss;
        cout<<"open the file"<<endl;
        ss<<"sno\tname\tage\t\n";
        while (row = mysql_fetch_row(res))
        {
            ss << left << setw(8) << row[0];
            ss << left << setw(8) << row[1];
            ss << left << setw(8) << row[2];
            ss << endl;
        }
	    mysql_free_result(res);
        ofs<<ss.str();
        ofs.close();
    }
    else{
        b=false;
        cout<<"file open falure"<<endl;
    }
    
    
    return b;
}
//read from file
bool CStudentMg::readFromFile(map<int,CStudent> & m1,string path){

    bool b=true;
    fstream inf(path,ios::in);
    if(inf){
        cout<<"open file success"<<endl;
        string s;
        stringstream ss;
        while(getline(inf,s)){
            CStudent cStu;
            ss<<s;
            ss>>cStu;
            ss.clear();

            m1.insert(make_pair(cStu.getId(),cStu));
        }
        inf.close();
    }
    else{
        cout<<"file open falure"<<endl;
        b=false;
    }
    return b;
}
