#include<iostream>
#include<iomanip>
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

class Categories{
    public:
    int serialNo;
    string name;
    int price;
    Categories* next;
    Categories* head = NULL;

    void insert(int SerialNo, string Name, int Price){
        Categories *current= head;
        Categories *last;
        last = new Categories;
        last->serialNo = SerialNo;
        last ->name = Name;
        last->price = Price;
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

    void displayList(){
        Categories *current = head;
        while(current != NULL){
            cout<<current ->serialNo<<") "<<left<<setw(30)<<current ->name/*<<left<<setw(10)*/<<"Rs. "<<current ->price<<"\n";
            current = current->next;
        }
    }
};



int main(){
    UserDatabase u1;
    u1.insert("abc@gmail.com", "123", "ABC",8);
    u1.insert("xyz@gmail.com", "456", "XYZ",4);
    u1.insert("ijk@gmail.com", "789", "ijk",2);
    
    Categories fruits, vegetables, dairy, meats, snacks, bakery;
    
    fruits.insert(1, "Apple", 150);
    fruits.insert(2, "Banana", 60);
    fruits.insert(3, "Grape", 25);
    fruits.insert(4,"Peaches",100);
    fruits.insert(5,"Pineapple",65);
    fruits.insert(6,"Papaya",50);
    fruits.insert(7,"Dragon fruit",120);
    fruits.insert(8,"Orange",65);
    fruits.insert(9,"Mango",180);
    

    vegetables.insert(1, "Potatoes", 40);
    vegetables.insert(2,"Tomatoes",60);
    vegetables.insert(3,"Onion",50);
    vegetables.insert(4,"Spinach",30);
    vegetables.insert(5,"Bell Pepper",100);
    vegetables.insert(6,"Carrot",25);
    vegetables.insert(7,"Raddish",60);
    vegetables.insert(8,"Cucumber",40);
    vegetables.insert(9,"Cabbage",35);
    

    dairy.insert(1,"Milk",65);
    dairy.insert(2,"Cottage Cheese",120);
    dairy.insert(3,"Curd",80);
    dairy.insert(4,"Butter",75);
    dairy.insert(5,"Eggs",60);
    dairy.insert(6,"Cream Cheese",100);
    dairy.insert(7,"Sour Cream",110);
    dairy.insert(8,"Yogurt",90);
    dairy.insert(9,"Cheese",120);

    meats.insert(1,"Boneless Chicken Tenders", 500);
    meats.insert(2,"Chicken Livers", 350);
    meats.insert(3,"Boneless Chicken Breast", 600);
    meats.insert(4,"Grounded veal", 300);
    meats.insert(5,"Chicken Wings", 400);
    meats.insert(6,"Chicken thigh", 225);
    meats.insert(7,"Turkey Drumstick", 700);
    meats.insert(8,"Chicken Drumstick", 400);
    meats.insert(9,"Bacon", 250);

    snacks.insert(1, "Lays Chip Indian Masala", 20);
    snacks.insert(2, "Pringels Cream and Onions",100);
    snacks.insert(3, "Aloo Bhujia",50);
    snacks.insert(4, "Khata Mitha",50);
    snacks.insert(5, "Sev Bhujia",100);
    snacks.insert(6, "Mad Angles",20);
    snacks.insert(7, "Puffcorn",20);
    snacks.insert(8, "Doritos",50);
    snacks.insert(9, "Hide and Seek",30);

    bakery.insert(1,"French Baguette",200);
    bakery.insert(2,"Egg Twist Challah",350);
    bakery.insert(3,"Pumpkin Pie",500);
    bakery.insert(4,"Blueberry Muffins",200);
    bakery.insert(5,"Chocolate Chip Cookies",50);
    bakery.insert(6,"Crossiant",30);
    bakery.insert(7,"Bagel",50);
    bakery.insert(8,"Velvet Cupcake",50);
    bakery.insert(9,"Apple Pie",750);

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
        cout<<"\n1. Display account information \n2. Modify account information \n3. Order groceries \n";
        int ch1, ch2;
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

            case 3:
                while (true){
                    cout<<"Select category for grocery: \n1. Fruits \n2.Vegetables  \n3.Dairy \n4.Meats \n5.Snacks  \n6.Bread & Bakery \n7.Back ";
                    cin>>ch2;
                    switch (ch2){
                    case 1:
                        cout<<"Fruits Menu :- \n";
                        fruits.displayList();
                        break;

                    case 2:
                        cout<<"Vegetables Menu :- \n";
                        vegetables.displayList();
                        break;

                    case 3:
                        cout<<"dairy Menu :- \n";
                        dairy.displayList();
                        break;

                    case 4:
                        cout<<"Meats Menu :- \n";
                        meats.displayList();
                        break;

                    case 5:
                        cout<<"Snacks Menu :- \n";
                        snacks.displayList();
                        break;

                    case 6:
                        cout<<"Bread & Bakery Menu :- \n";
                        bakery.displayList();
                        break;

                    case 7:

                        break;

                    default:
                        break;
                }
                }
                break; 

            
            default:
                return 0;
                break;
        }
    }
    
}