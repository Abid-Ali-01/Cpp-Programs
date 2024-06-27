#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Book {
public:
    int bookID;
    string bookTitle;
    string bookAuthor;
    int availableCopies;

    Book(int id, string T, string A, int available)
        : bookID(id), bookTitle(T), bookAuthor(A), availableCopies(available) {}

    void getDetails() const {
        cout << "Book ID: " << bookID << endl;
        cout << "Title : " << bookTitle << endl;
        cout << "Author : " << bookAuthor << endl;
        cout << "Available Copies: " << availableCopies << endl;
    }

    void borrowBook() {
        if (availableCopies > 0) {
            availableCopies--;
            cout << "Book Borrowed Successfully" << endl;
        } else {
            cout << "No Copies Available" << endl;
        }
    }

    void returnBook() {
        availableCopies++;
        cout << "Book Returned Successfully" << endl;
    }

    bool operator==(const Book &other) const {
        return bookID == other.bookID;
    }
};

class Member {
public:
    int memberId;
    string memberName;
    string phoneNum;
    vector<Book*> borrowedBooks; // Store pointers to books

    Member(int id, string name, string number)
        : memberId(id), memberName(name), phoneNum(number) {}

    void getDetails() const { 
        cout << "Member ID: " << memberId << endl;
        cout << "Name : " << memberName << endl;
        cout << "Phone Number: " << phoneNum << endl;
    }

    void borrowBook(Book &book) {
        if (book.availableCopies > 0) {
            book.borrowBook();
            borrowedBooks.push_back(&book); // Store pointer to the book
        } else {
            cout << "No Copies Available" << endl;
        }
    }

    void returnBook(Book &book) {
        book.returnBook();
        borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), &book), borrowedBooks.end());
    }
};

class Library {
public:
    vector<Book> books;
    vector<Member> members;

    void addBooks(Book &book) {
        books.push_back(book);
    }

    void removeBookByID(int bookID) {
        books.erase(remove_if(books.begin(), books.end(), [bookID](const Book &b) {
            return b.bookID == bookID;
        }), books.end());
    }

    void searchBook(string title) {
        for (const Book &book : books) {
            if (book.bookTitle == title) {
                book.getDetails();
                return;
            }
        }
        cout << "Book Not Available" << endl;
    }

    void registerMember(Member member) {
        members.push_back(member);
    }

    void removeMemberByID(int memberID) {
        members.erase(remove_if(members.begin(), members.end(), [memberID](const Member &m) {
            return m.memberId == memberID;
        }), members.end());
    }

    void listBooks() const {
        cout << "Listing all books in the library:" << endl;
        for (const Book &book : books) {
            book.getDetails();
        }
    }

    void listMembers() const {
        cout << "Listing all members of the library:" << endl;
        for (const Member &member : members) {
            member.getDetails();
        }
    }
};

int main() {
    Library lib;

    // Create some Book instances and add to library
    Book book1(1, "The Great Gatsby", "F. Scott Fitzgerald", 5);
    Book book2(2, "1984", "George Orwell", 3);
    Book book3(3, "To Kill a Mockingbird", "Harper Lee", 2);

    lib.addBooks(book1);
    lib.addBooks(book2);
    lib.addBooks(book3);

    // Create some Member instances and register them in library
    Member member1(01, "Abid Ali", "0390-1213256");
    Member member2(02, "Waqar Ali","0380-2323234");
    Member member3(03, "Zahir Iqbal","0350-2323234");

    lib.registerMember(member1);
    lib.registerMember(member2);

    // Test borrowing and returning books
    member1.borrowBook(book1);
    member2.borrowBook(book1);
    member3.borrowBook(book1);

    cout << "After borrowing books:" << endl;
    lib.listBooks();
    cout << endl;
    lib.listMembers();
    cout << endl;

    member1.returnBook(book1);

    cout << "After returning a book:" << endl;
    lib.listBooks();
    cout << endl;
    lib.listMembers();
    cout << endl;

    // Test removing a book and a member by ID
    lib.removeBookByID(2);
    lib.removeMemberByID(102);

    cout << "After removing a book and a member:" << endl;
    lib.listBooks();
    cout << endl;
    lib.listMembers();
    cout << endl;

    lib.searchBook("Kite Runner");
    lib.searchBook("To Kill a Mockingbird");

    return 0;
}
