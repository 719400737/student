#include"CMainView.h"
using namespace std;
CMainView::CMainView(){

}
CMainView::~CMainView(){

}
    
    //welcome
void CMainView::welcome(){
    cout<<"welcome to our system"<<endl;
}

    //showMenu
void CMainView::showMenu(){
    cout<<endl;
    cout<<"Menu:"<<endl;
    cout<<"1.add a stu"<<endl;
    cout<<"2.update the information"<<endl;
    cout<<"3.find a stu"<<endl;
    cout<<"4.delete a stu"<<endl;
    cout<<"5.show all stu"<<endl;
    cout<<"6.save to a file"<<endl;
    //cout<<"7.read from a file"<<endl;
    cout<<"0.exit"<<endl;
    cout<<endl;
    cout<<"please input ";
}

    //view all stu
void CMainView::showAllstuAtView(MYSQL *mysql){

    CStudentMg cStuMg;
    cStuMg.showAll(mysql);

    welcome();
    showMenu();

}

    //view add one
void CMainView::addStuAtView(MYSQL *mysql){
    CStudentMg cStuMg;
    int id;
    string name;
    int age;
    cout<<"input id:";
    cin>>id;
    cout<<"name:";
    cin>>name;
    cout<<"age:";
    cin>>age;
    CStudent cStu;
    cStu.setId(id);
    cStu.setAge(age);
    cStu.setName(name);

    cStuMg.addAStu(mysql,cStu);
    system("clear");
    welcome();
    showMenu();
}
    
    //view find one
void CMainView::findStuAtView(MYSQL *mysql){
    system("clear");
    cout<<"input the student Id you want to find"<<endl;
    int id;
    cin>>id;
    CStudentMg cStuMg;
    cStuMg.findById(mysql,id);
    welcome();
    showMenu();
}
    
    //dele one
void CMainView::deleteByIdAtView(MYSQL *mysql){
    cout<<"input the student id you want to delete"<<endl;
    int id;
    cin>>id;
    CStudentMg cStuMg;
    bool b=cStuMg.deleteStuById(mysql,id);
    if(b){
        cout<<"delete success"<<endl;
    }
    else{
        cout<<"can't find this preson"<<endl;
    }
    welcome();
    showMenu();
}

//update
void CMainView::updateByIdAtView(MYSQL *mysql){
    system("clear");
    cout<<"please input the id of student you want to update"<<endl;
    int id;
    cin>>id;
    string name;
    cout<<"input the name of the sutdent"<<endl;
    cin>>name;
    int age;
    cout<<"age"<<endl;
    cin>>age;

    CStudent cStu;
    cStu.setAge(age);
    cStu.setId(id);
    cStu.setName(name);
    CStudentMg CstuMg;

    CstuMg.updateStu(mysql,cStu);
    welcome();
    showMenu();

}

//save to flie
void CMainView::saceToFileAtView(MYSQL *mysql,string pathname){

        CStudentMg cStuMg;
        bool b=cStuMg.saveToFile(mysql,pathname);
        if(b){
            system("clear");
            cout<<"save success"<<endl;
        }
        else{
            cout<<"save falure"<<endl;
        }

    welcome();
    showMenu();

}

//read from file
void CMainView::readFromFileAtView(map<int,CStudent> &stu_m1,string pathname){
    system("clear");
    CStudentMg cStuMg;
    bool b=cStuMg.readFromFile(stu_m1,pathname);
        if(b){
            system("clear");
            cout<<"read success"<<endl;
        }
        else{
            cout<<"read falure"<<endl;
        }
    system("clear");
    welcome();
    showMenu();

}