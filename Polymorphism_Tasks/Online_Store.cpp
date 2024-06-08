#include <iostream>
using namespace std;

class Product {

   public:
   virtual void showDetails() = 0;
 
};

class Book : public Product{
    void showDetails() override {
        cout<<"Books Available"<<endl;
    }
};

class Clothing : public Product{

    void showDetails() override {
        cout<<"Clothes Available"<<endl;
    }
};


class Electronics : public Product {
    void showDetails() override {
        cout<<"Electronic Items Available"<<endl;
    }
};


//Function Accepts Reference
void CheckProducts(Product &product){

    product.showDetails();
}

int main (){ 

Book book;
Clothing   clothes;
Electronics  electronics;

CheckProducts(book);
CheckProducts(clothes);
CheckProducts(electronics);


}