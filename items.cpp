#include<iostream>
using namespace std;

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
            cout<<current ->serialNo<<") "<<current ->name<<"\tRs. "<<current ->price;
            current = current->next;
        }
    }
};


int main(){
    Categories fruits, vegetables, dairy, meats, snacks, bakery;
    fruits.insert(1, "Apple", 25);
    fruits.displayList();

}