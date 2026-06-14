#include <iostream>
using namespace std;

class BookType
{
    string title, author[4], pub;
    int ISBN, noOfCpy, noOfAuth;
    float price;

public:
    // operations on title
    string getTitle()
    {
        return title;
    }
    void setTitle(const string t)
    {
        title = t;
    }
    bool checkTitle(const string t)
    {
        return title == t;
    }
    // operations of number of copies in stock
    int getCopies()
    {
        return noOfCpy;
    }
    void setCopies(const int num)
    {
        noOfCpy = num;
    }
    void updateCopies(const int num)
    {
        noOfCpy += num;
        if (noOfCpy < 0)
            noOfCpy = 0;
    }
    // operations on authors
    void setAuth(const string auth)
    {
        if (noOfAuth < 4)
            author[noOfAuth++] = auth;
        else
            cout << "Max Limit Reached!!\n";
    }
    void getAuth()
    {
        cout << "No. of authors: " << noOfAuth << endl;
        for (int i = 0; i < noOfAuth; i++)
        {
            cout << "\tAuthor" << i + 1 << ": " << author[i] << endl;
        }
    }
    // operations on Publisher
    string getPub()
    {
        return pub;
    }
    void setPub(const string t)
    {
        pub = t;
    }
    // operations on book price
    float getPrice()
    {
        return price;
    }
    void setPrice(float p)
    {
        price = p;
    }
    // operations on ISBN
    int getISBN()
    {
        return ISBN;
    }
    void setISBN(int i)
    {
        ISBN = i;
    }
    // constructor
    BookType()
    {
        pub = title = "Unknown";
        for (int i = 0; i < 4; i++)
            author[i] = "N/A";
        ISBN = noOfCpy = noOfAuth = price = 0;
    }
};

void listFeatures(BookType book)
{
    cout << "Title: " << book.getTitle() << endl;
    cout << "Publisher: " << book.getPub() << endl;
    cout << "Price: $" << book.getPrice() << endl;
    cout << "ISBN: " << book.getISBN() << endl;
    book.getAuth();
    int copies = book.getCopies();
    if (copies == 0)
        cout << "\033[1;31mUnavailable.\033[0m" << endl;
    else
        cout << "\033[1;32mIn Stock " << copies << " copies available.\033[0m" << endl;
}

int main()
{
    BookType books[100];
    cout << "====Welcome to ABC Book Shop!====" << endl;
    int choice, totalBooks = 0;
    do
    {
        cout << "\nSelect options from below:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Display all books" << endl;
        cout << "3. Search by Title" << endl;
        cout << "4. Search by ISBN" << endl;
        cout << "5. Search by Publisher" << endl;
        cout << "6. Update number of copies" << endl;
        cout << "7. Exit" << endl;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            if (totalBooks < 100)
            {
                string title, author, pub;
                int ISBN, noOfCpy, noOfAuth;
                float price;
                cout << "Enter title of the book: ";
                cin >> title;
                books[totalBooks].setTitle(title);
                cout << "Enter number of authors: ";
                cin >> noOfAuth;
                if (noOfAuth > 4)
                    cout << "Only 4 authors allowed at max.\n";
                for (int i = 0; i < noOfAuth && i < 4; i++)
                {
                    cout << "Enter the name of author " << i + 1 << ": ";
                    cin >> author;
                    books[totalBooks].setAuth(author);
                }
                cout << "Enter the name of publisher: ";
                cin >> pub;
                books[totalBooks].setPub(pub);
                cout << "Enter the ISBN number: ";
                cin >> ISBN;
                books[totalBooks].setISBN(ISBN);
                cout << "Enter the number of copies available in stock: ";
                cin >> noOfCpy;
                books[totalBooks].setCopies(noOfCpy);
                cout << "Enter the price of the book: $";
                cin >> price;
                books[totalBooks].setPrice(price);
                totalBooks++;
            }
            else
                cout << "Max limit of books entered." << endl;
            break;
        case 2:
            cout << "\033[1;33mTotal number of books (" << totalBooks << "):\033[0m" << endl;
            for (int i = 0; i < totalBooks; i++)
            {
                cout << "\033[1;34m==========================\033[0m" << endl;
                listFeatures(books[i]);
                cout << "\033[1;34m==========================\033[0m" << endl;
            }
            break;
        case 3:
        {
            string title;
            cout << "Enter the title: ";
            cin >> title;
            int matches = 0;
            for (int i = 0; i < totalBooks; i++)
                if (books[i].checkTitle(title))
                {
                    matches++;
                    cout << "\033[1;34m==========================\033[0m" << endl;
                    listFeatures(books[i]);
                    cout << "\033[1;34m==========================\033[0m" << endl;
                }
            cout << "\033[1;33mFound " << matches << " matches.\033[0m" << endl;
        }
        break;
        case 4:
        {
            int ISBN;
            cout << "Enter the ISBN: ";
            cin >> ISBN;
            bool found = false;
            for (int i = 0; i < totalBooks; i++)
                if (books[i].getISBN() == ISBN)
                {
                    cout << "\033[1;34m==========================\033[0m" << endl;
                    listFeatures(books[i]);
                    cout << "\033[1;34m==========================\033[0m" << endl;
                    found = true;
                    break;
                }
            if (!found)
                cout << "\033[1;31mThe book with ISBN " << ISBN << " doesn't exists.\033[0m" << endl;
        }
        break;
        case 5:
        {
            string pub;
            cout << "Enter the Publisher: ";
            cin >> pub;
            int matches = 0;
            for (int i = 0; i < totalBooks; i++)
                if (books[i].getPub() == pub)
                {
                    matches++;
                    cout << "\033[1;34m==========================\033[0m" << endl;
                    listFeatures(books[i]);
                    cout << "\033[1;34m==========================\033[0m" << endl;
                }
            cout << "\033[1;33mFound " << matches << " matches.\033[0m" << endl;
        }
        break;
        case 6:
        {
            int ISBN, i;
            cout << "Enter the ISBN: ";
            cin >> ISBN;
            bool found = false;
            for (i = 0; i < totalBooks; i++)
                if (books[i].getISBN() == ISBN)
                {
                    cout << "\033[1;34m==========================\033[0m" << endl;
                    listFeatures(books[i]);
                    cout << "\033[1;34m==========================\033[0m" << endl;
                    found = true;
                    break;
                }
            if (!found)
                cout << "\033[1;31mThe book with ISBN " << ISBN << " doesn't exists.\033[0m" << endl;
            else {
                int cpy;
                cout << "Current number of copies: " << books[i].getCopies() << endl;
                cout << "Add number of copies: ";
                cin >> cpy;
                books[i].updateCopies(cpy);
            }
        }
        break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "\033[1;31mInvalid option\033[0m" << endl;
            break;
        }
    } while (choice != 7);
    return 0;
}
