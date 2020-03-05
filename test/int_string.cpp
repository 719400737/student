#include<iostream>
#include<string>

using namespace std;


int main(){

    string num;
    cout<<"input a number:";
    while(1){
        cin>>num;
        int b=1;
        for(auto c:num){
            if(isdigit(c))
                continue;
            else{
                b=0;
                break;
            }
        }
        
    
        if(b){
            int num1=stoi(num);
            cout<<num1;
            break;
        }
        else{
            cout<<"input int:"<<endl;
        }
    }
    
        
    
    

    return 0;
}