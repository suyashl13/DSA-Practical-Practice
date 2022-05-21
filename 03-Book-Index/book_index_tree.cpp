#include <iostream>
using namespace std;

struct book_node
{
    char title[50];
    int count;
    book_node *down[10];
} * root;

void make_book_contents()
{
    root = new book_node();

    cout << "Enter the name of book : ";
    cin >> root->title;
    cout << "Enter the number of chapters in book : ";
    cin >> root->count;

    for (int i = 0; i < root->count; i++)
    {
        book_node *chapter = new book_node();

        cout << "Enter the name of chapter " << i + 1 << " : ";
        cin >> chapter->title;

        cout << "Enter no of Sections in chapter (>10): ";
        cin >> chapter->count;

        for (int i = 0; i < chapter->count; i++)
        {
            book_node *section = new book_node();
            cout << "Enter name of section  " << i + 1 << " : ";
            cin >> section->title;
            chapter->down[i] = section;
        }
        root->down[i] = chapter;
    }
}

void display()
{
    cout << root->title << endl;
    for (int i = 0; i < root->count; i++)
    {
        cout << "  |- " << root->down[i]->title << " (" << root->down[i]->count << ") " << endl;
        for (int j = 0; j < root->down[i]->count; j++)
        {
            cout << "  |  |-" << root->down[i]->down[j]->title << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    make_book_contents();
    cout << endl
         << endl;
    display();
    return 0;
}