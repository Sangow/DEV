#include <iostream>

class Book {
    private:
        int id;
        std::string title;
    public:
        static int totalBooks;
        static int lastId;

    public:
        Book(const std::string& title) {
            totalBooks += 1;
            lastId     += 1;
            this->id    = lastId;
            this->title = title;
        }

        // конструктор копирования
        Book(const Book& copy) {
            totalBooks += 1;
            lastId     += 1;
            this->id    = lastId;
            this->title = copy.title;
        }

        // оператор присваивания
        Book& operator=(const Book& copy) {
            this->title = copy.title; // копируем остальные поля

            return *this;
        }

        ~Book() {
            totalBooks -= 1;
        }

        int getId() const {
            return this->id;
        }

        const std::string& getTitle() const {
            return this->title;
        }
};

int Book::totalBooks = 0;
int Book::lastId     = 0;


int main() {
    Book *book1 = new Book("Gulliver");
    Book *book2 = new Book(*book1);

    std::cout << "book1 id: " << book1->getId() << ", title: " << book1->getTitle() << std::endl;    // book1 id = 1
    std::cout << "book2 id: " << book2->getId() << ", title: " << book2->getTitle() << std::endl;    // book1 id = 2
    std::cout << "totalBooks: " << Book::totalBooks << std::endl; // totalBooks: 3

    *book1 = *book2;

    std::cout << "book1 id: " << book1->getId() << ", title: " << book1->getTitle() << std::endl;    // book1 id = 1
    std::cout << "book2 id: " << book2->getId() << ", title: " << book2->getTitle() << std::endl;    // book1 id = 2
    std::cout << "totalBooks: " << Book::totalBooks << std::endl; // totalBooks: 3


    delete book1;
    delete book2;

    return 0;
}