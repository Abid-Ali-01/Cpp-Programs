#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
private:
    int ID;
    string name;
    int price;
    int quantity;

public:
    Product(int id, const string& productName, int productPrice, int productQuantity) 
        : ID(id), name(productName), price(productPrice), quantity(productQuantity) {}

    int getID() const {
        return ID;
    }

    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    void Display() const {
        cout << "Product ID: " << ID << endl;
        cout << "Product Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Available Quantity: " << quantity << endl;
    }
};

class Inventory {
private:
    vector<Product> productInventory;

public:
    void addProduct(const Product& product) {
        productInventory.push_back(product);
        cout<<"Product Added Successfully"<<endl;
    }

    void removeProductByID(int id) {
        for (auto it = productInventory.begin(); it != productInventory.end(); ++it) {
            if (it->getID() == id) {
                productInventory.erase(it);
                cout << "Product with ID " << id << " removed." << endl;
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }

    void updateQuantityById(int newQuantity, int id) {
        for (auto& product : productInventory) {
            if (product.getID() == id) {
                product.setQuantity(newQuantity);
                cout << "Quantity for product ID " << id << " updated to " << newQuantity << "." << endl;
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }

    void displayAllProducts() const {
        for (const auto& product : productInventory) {
            product.Display();
            cout << endl;
        }
    }
};

int main() {
          //ID , Product Name  ,  Price , Quantity
 Product P1(01, "Lenovo Laptops",50000, 10 );
 Product P2(02, "NVIDIA GFX Card",70000, 5 );
 Product P3(03, "Iphone 13 Pro Max",100000, 20 );
 Product P4(04, "LogiTech Keyboards",7000, 50 );

 Inventory inventory;
 inventory.addProduct(P1);
 inventory.addProduct(P2);
 inventory.addProduct(P3);
 inventory.addProduct(P4);


inventory.displayAllProducts();
inventory.updateQuantityById(10, 2);
inventory.displayAllProducts();


inventory.removeProductByID(3);
inventory.displayAllProducts();


    return 0;
}
