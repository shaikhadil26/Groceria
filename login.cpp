#include<iostream>
using namespace std;
//TODO : hidden password
class UserDatabase{
    public:
    string userId;
    string pass;
    string name;
    int orders;
    int counter = 0;
    UserDatabase* next;
    UserDatabase* head = NULL;

    void insert(string user_Id, string Pass, string Name, int Orders){
        UserDatabase *current= head;
        UserDatabase *last;
        last = new UserDatabase;
        last->userId = user_Id;
        last->pass = Pass;
        last ->name = Name;
        last->orders = Orders;
        last->next = NULL;

        if (head == NULL){
            head = last;
        }
        else{
            while (current->next != NULL){
                current = current->next; 
            }
            current->next = last;    
        }    
    }
    
    bool checkUser(string User, string Pass){
        counter = 0;
        UserDatabase *current= head;
        while(current != NULL ){
            if(current ->userId == User && current->pass == Pass){
                return true;
            }
            else{
                counter++; 
                current = current->next;
            }        
        }
        return false;
    }

    void modifyUser(string user_Id, string Pass, string Name){
    UserDatabase *current = head;
    for(int i = 0; i < counter - 1; i++)
        current = current ->next;
    current ->userId = user_Id;
    current ->pass = Pass;
    current ->name = Name;
    }

    string getName(){
        UserDatabase *c = head;
        for(int i = 0; i < counter ; i++)
            c = c->next;
        return c->name;    
    }
    int getOrder(){
        UserDatabase *c = head;
        for(int i = 0; i < counter ; i++)
            c = c->next;
        return c->orders;    
    }

};



int main(){
    UserDatabase u1;
    u1.insert("abc@gmail.com", "123", "ABC",8);
    u1.insert("xyz@gmail.com", "456", "XYZ",4);
    u1.insert("ijk@gmail.com", "789", "ijk",2);

    string id, pass, name;
    bool condition;
    int counter = 3;
    char ch;

    cout<<"\t\tWelcome to Groceria\n\tYour one step shop to all things grocery\n\nAre you an existing customer (enter y/n): "; 
    cin>>ch;
    
    if( ch == 'n'){
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter email id: ";
        cin>>id;
        cout<<"Enter password: ";
        cin>>pass;
        u1.insert(id, pass, name, 0);
        cout<<"Account created \nPlease login again :) \n";
    }

    retry:
    cout<<"Enter email id: ";
    cin>>id;
    cout<<"Enter password: ";
    cin>>pass;
    if( ch == 'n'){
        cout<<"Enter name: ";
        cin>>name;
        u1.insert(id, pass, name, 0);
    }
    condition = u1.checkUser(id, pass);
    if(condition == false){
        cout<<"Invalid ID/Pass";
        cout<<"\nYou have "<<counter<<" valid retries \n";
        counter--;
        if(counter >= 0)
            goto retry;
        else 
            return 0;
    }
                
    name = u1.getName();
    cout<<"Welcome "<<name<<"\nWhat would you like to do today\n";
    while(true){
        cout<<"\n1. Display account information \n2. Modify account information ";
        int ch1;
        cin>>ch1; 
        switch (ch1){
            case 1:
                int tOrders;
                tOrders = u1.getOrder();
                cout<<"Name: "<<name<<"\n";
                cout<<"Email ID: "<<id<<"\t";
                cout<<"Total number of orders: "<<tOrders;
                break;
            case 2:
                bool check;
                cout<<"Please re-enter account password ";
                cin>>pass;
                check = u1.checkUser(id, pass);
                if(check == true){
                    cout<<"Enter new name: ";
                    cin>>name;
                    cout<<"Enter new email id: ";
                    cin>>id;
                    cout<<"Enter new password: ";
                    cin>>pass;
                    u1.modifyUser(name, id, pass);
                }
                else
                    cout<<"Invalid password! ";
                break;
            
            default:
                return 0;
                break;
        }
    }
    
}