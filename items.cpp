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
    
    fruits.insert(1, "Apple", 150);
    fruits.insert(2, "Banana", 60);
    fruits.insert(3, "Grape", 25);
    fruits.insert(4,"Peaches",100);
    fruits.insert(5,"Pineapple",65);
    fruits.insert(6,"Papaya",50);
    fruits.insert(7,"Dragon fruit",120);
    fruits.insert(8,"Orange",65);
    fruits.insert(9,"Mango",180);
    fruits.insert(10,"Litchi",50);

    vegetables.insert(1, "Potatoes", 40);
    vegetables.insert(2,"Tomatoes",60);
    vegetables.insert(3,"Onion",50);
    vegetables.insert(4,"Spinach",30);
    vegetables.insert(5,"Bell Pepper",100);
    vegetables.insert(6,"Carrot",25);
    vegetables.insert(7,"Raddish",60);
    vegetables.insert(8,"Cucumber",40);
    vegetables.insert(9,"Cabbage",35);
    vegetables.insert(10,"Eggplant",65);

    dairy.insert(1,"Milk",65);
    dairy.insert(2,"Cottage Cheese",120);
    dairy.insert(3,"Curd",80);
    dairy.insert(4,"Butter",75);
    dairy.insert(5,"Eggs",60);
    dairy.insert(6,"Cream Cheese",100);
    dairy.insert(7,"Sour Cream",110);
    dairy.insert(8,"Yogurt",90);
    dairy.insert(9,"Cheese",120);
    dairy.insert(10,"Whipped Cream",60);

    meats.insert(1,"Boneless Chicken Tenders", 500);
    meats.insert(2,"Chicken Livers", 350);
    meats.insert(3,"Boneless Chicken Breast", 600);
    meats.insert(4,"Grounded veal", 300);
    meats.insert(5,"Chicken Wings", 400);
    meats.insert(6,"Chicken thigh", 225);
    meats.insert(7,"Turkey Drumstick", 700);
    meats.insert(8,"Chicken Drumstick", 400);
    meats.insert(9,"Bacon", 250);
    meats.insert(10,"Rack of Lamb", 1000);
    meats.insert(11,"Sausage", 200);
    meats.insert(12,"Ground Pork", 500);
    meats.insert(13,"Whole Fryer Chicken", 2000);
    meats.insert(14,"Pork Rib chops", 1000);

    snacks.insert(1, "Lays Chip Indian Masala", 20);
    snacks.insert(2, "Pringels Cream and Onions",100);
    snacks.insert(3, "Aloo Bhujia",50);
    snacks.insert(4, "Khata Mitha",50);
    snacks.insert(5, "Sev Bhujia",100);
    snacks.insert(6, "Mad Angles",20);
    snacks.insert(7, "Puffcorn",20);
    snacks.insert(8, "Doritos",50);
    snacks.insert(9, "Hide and Seek",30);
    snacks.insert(10, "Bourbon",50);
    snacks.insert(11, "Jim Jam",30);
    snacks.insert(12, "Peppy", 10);
    snacks.insert(13, "Lays Classic Salt",30);
    snacks.insert(14, "Bombay Mix",100);
    snacks.insert(15, "Kurkure",20);
    snacks.insert(16, "Too Yumm",30);

    bakery.insert(1,"French Baguette",200);
    bakery.insert(2,"Egg Twist Challah",350);
    bakery.insert(3,"Pumpkin Pie",500);
    bakery.insert(4,"Blueberry Muffins",200);
    bakery.insert(5,"Chocolate Chip Cookies",50);
    bakery.insert(6,"Crossiant",30);
    bakery.insert(7,"Bagel",50);
    bakery.insert(8,"Velvet Cupcake",50);
    bakery.insert(9,"Apple Pie",750);
    bakery.insert(10,"New York Cheesecake",150);
    bakery.insert(11,"Corn Muffins",75);
    bakery.insert(12,"Lemon Tart",125);
    bakery.insert(13,"Everything Bagel",80);
}