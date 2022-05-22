#include <iostream>
using namespace std;

struct book_node
{
    char title[50];
    int down_count;
    book_node *down[10];
};

class Book
{
private:
    book_node *root;

public:
    void create()
    {
        root = new book_node();

        cout << "Enter the name of book : ";
        cin >> root->title;

        cout << "Enter the no. of chapters in book : ";
        cin >> root->down_count;

        for (int i = 0; i < root->down_count; i++)
        {
            book_node *chapter = new book_node();
            cout << "Enter the name of chapter " << i + 1 << " : ";
            cin >> chapter->title;

            cout << "Enter the number of sections in chapter " << chapter->title << " : ";
            cin >> chapter->down_count;

            for (int j = 0; j < chapter->down_count; j++)
            {
                book_node *section = new book_node();
                cout << "Enter the name of section no. " << j << " in chapter " << chapter->title << " : ";
                cin >> section->title;
                chapter->down[j] = section;
            }
            root->down[i] = chapter;
        }
    }

    void display()
    {
        cout << root->title << endl;
        for (int i = 0; i < root->down_count; i++)
        {
            cout << "  |- " << root->down[i]->title << endl;
            for (int j = 0; j < root->down[i]->down_count; j++)
            {
                cout << "  |  |- " << root->down[i]->down[j]->title << endl;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Book b = Book();

    b.create();
    b.display();
    return 0;
}
