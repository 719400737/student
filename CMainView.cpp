#include"CMainView.h"
using namespace std;
CMainView::CMainView(){

}
CMainView::~CMainView(){

}
    
    //welcome
void CMainView::welcome(){
    system("cls");
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
    cout<<"7.read from a file"<<endl;
    cout<<"0.exit"<<endl;
    cout<<endl;
    cout<<"please input ";
}

    //view all stu
void CMainView::showAllstuAtView(const map<int,CStudent> & stu_m1){
    system("cls");
    cout<<"id   |"<<"name   |"<<"age"<<endl;
    CStudentMg cStuMg;
    cStuMg.showAll(stu_m1);
    system("pause");
    system("cls");
    welcome();
    showMenu();

}

    //view add one
void CMainView::addStuAtView(map<int,CStudent> &stu_m1){
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

    cStuMg.addAStu(stu_m1,cStu);
    system("cls");
    welcome();
    showMenu();
}
    
    //view find one
void CMainView::findStuAtView(const map<int,CStudent> &stu_m1){
    system("cls");
    cout<<"input the student Id you want to find"<<endl;
    int id;
    cin>>id;
    CStudent cStu;
    CStudentMg cStuMg;
    cStu=cStuMg.findById(stu_m1,id);
    if(cStu.getId()!=-1){
        cout<<cStu<<endl;
    }
    else{
        cout<<"there are not this student"<<endl;
    }

    system("pause");
    system("cls");
    welcome();
    showMenu();
}
    
    //dele one
void CMainView::deleteByIdAtView(map<int,CStudent> &stu_m1){
    system("cls");
    cout<<"input the student id you want to delete"<<endl;
    int id;
    cin>>id;
    CStudentMg cStuMg;
    bool b=cStuMg.deleteStuById(stu_m1,id);
    if(b){
        cout<<"delete success"<<endl;
    }
    else{
        cout<<"can't find this preson"<<endl;
    }
    system("pause");
    system("cls");
    welcome();
    showMenu();
}

//update
void CMainView::updateByIdAtView(map<int,CStudent> &stu_m1){
    system("cls");
    cout<<"please input the id of student you want to update"<<endl;
    int id;
    cin>>id;
    string name;
    cout<<"input the name of the sutdent"<<endl;
    cin>>name;
    int age;
    cout<<"age";
    cin>>age;

    CStudent cStu;
    cStu.setAge(age);
    cStu.setId(id);
    cStu.setName(name);
    CStudentMg CstuMg;
    CStudent cStu2=CstuMg.updateStu(stu_m1,cStu);
    if(cStu.getId()!=-1){
        cout<<cStu2<<endl;
    }
    else{
        cout<<"can't find this people"<<endl;
    }
    system("pause");
    system("cls");
    welcome();
    showMenu();

}

//save to flie
void CMainView::saceToFileAtView(map<int,CStudent> &stu_m1,string pathname){
    if(stu_m1.begin()==stu_m1.end()){
        system("cls");
        cout<<"no student can't save"<<endl;
    }
    else{
        CStudentMg cStuMg;
        bool b=cStuMg.saveToFile(stu_m1,pathname);
        if(b){
            system("cls");
            cout<<"save success"<<endl;
        }
        else{
            cout<<"save falure"<<endl;
        }
    }
    system("pause");
    system("cls");
    welcome();
    showMenu();

}

//read from file
void CMainView::readFromFileAtView(map<int,CStudent> &stu_m1,string pathname){
    system("cls");
    CStudentMg cStuMg;
    bool b=cStuMg.readFromFile(stu_m1,pathname);
        if(b){
            system("cls");
            cout<<"read success"<<endl;
        }
        else{
            cout<<"read falure"<<endl;
        }
    system("pause");
    system("cls");
    welcome();
    showMenu();

}