#include <iostream>
using namespace std;


class Media {
protected:
    string title;
    int    year;
    bool   isBorrowed;

public:
    Media(string title, int year)
        : title(title), year(year), isBorrowed(false) {}

    
    void borrow() {
        if (isBorrowed)
            cout << "\"" << title << "\" is already borrowed!\n";
        else {
            isBorrowed = true;
            cout << "\"" << title << "\" has been borrowed.\n";
        }
    }

   
    void returnMedia() {
        if (!isBorrowed)
            cout << "\"" << title << "\" was not borrowed!\n";
        else {
            isBorrowed = false;
            cout << "\"" << title << "\" has been returned.\n";
        }
    }

    virtual void display() const {
        cout << "Title: "  << title
             << " | Year: " << year
             << " | Status: " << (isBorrowed ? "Borrowed" : "Available") << "\n";
    }

    virtual ~Media() {}
};



class BookAttributes {
protected:
    string author;
    string genre;
    int    pages;

public:
    BookAttributes(string author, string genre, int pages)
        : author(author), genre(genre), pages(pages) {}
};



class MagazineAttributes {
protected:
    int    issueNumber;
    string publisher;

public:
    MagazineAttributes(int issueNumber, string publisher)
        : issueNumber(issueNumber), publisher(publisher) {}
};



class DVDAttributes {
protected:
    string director;
    double duration;    

public:
    DVDAttributes(string director, double duration)
        : director(director), duration(duration) {}
};



class Book : public Media, public BookAttributes {
public:
    Book(string title, int year, string author, string genre, int pages)
        : Media(title, year),
          BookAttributes(author, genre, pages) {}

    void display() const override {
        Media::display();
        cout << "  [Book] Author: " << author
             << " | Genre: "        << genre
             << " | Pages: "        << pages << "\n";
    }
};



class Magazine : public Media, public MagazineAttributes {
public:
    Magazine(string title, int year, int issueNumber, string publisher)
        : Media(title, year),
          MagazineAttributes(issueNumber, publisher) {}

    void display() const override {
        Media::display();
        cout << "  [Magazine] Issue: " << issueNumber
             << " | Publisher: "       << publisher << "\n";
    }
};



class DVD : public Media, public DVDAttributes {
public:
    DVD(string title, int year, string director, double duration)
        : Media(title, year),
          DVDAttributes(director, duration) {}

    void display() const override {
        Media::display();
        cout << "  [DVD] Director: " << director
             << " | Duration: "      << duration << " mins\n";
    }
};



int main() {

    cout << "========== Library System ==========\n\n";

    Book b("The Hobbit", 1937, "J.R.R. Tolkien", "Fantasy", 310);
    Magazine mag("National Geographic", 2023, 215, "Nat Geo Partners");
    DVD dvd("Inception", 2010, "Christopher Nolan", 148);

    
    cout << "-- Library Catalog --\n";
    b.display();
    mag.display();
    dvd.display();

    
    cout << "\n-- Borrowing --\n";
    b.borrow();
    dvd.borrow();
    b.borrow();     

    
    cout << "\n-- Updated Status --\n";
    b.display();
    dvd.display();

    
    cout << "\n-- Returning --\n";
    b.returnMedia();
    dvd.returnMedia();
    dvd.returnMedia();  

    
    cout << "\n-- Final Status --\n";
    b.display();
    mag.display();
    dvd.display();

    
    cout << "\n-- Polymorphism Demo --\n";
    Media* library[] = { &b, &mag, &dvd };
    for (auto* item : library) {
        item->display();
        cout << "\n";
    }

    return 0;
}