#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    system("chcp 1251 > nul");

    // Запрос у пользователя количества вводимых книг
    int size;
    cout << "Введите кол-во книг: ";
    cin >> size;

    // Очистка экрана консоли
    system("cls");

    // Объявление динамических массивов для хранения данных о книгах
    char** books_titles = new char* [size];
    char** books_authors = new char* [size];
    int* books_years = new int[size];
    int* books_copies = new int[size];

    cin.ignore(); 

    // Цикл для считывания вводимых данных о книгах
    for (int i = 0; i < size; ++i) {
        cout << "Введите название книги: " << endl;
        char buffer_for_titles[100];
        char buffer_for_authores[50];

        // Ввод названия книги
        cin.getline(buffer_for_titles, 100);
        books_titles[i] = new char[strlen(buffer_for_titles)+1];
        strcpy_s(books_titles[i], strlen(buffer_for_titles) + 1, buffer_for_titles);
        
        cout << endl;

        // Ввод автора книги
        cout << "Введите автора книги: " << endl;
        cin.getline(buffer_for_authores, 50);
        books_authors[i] = new char[strlen(buffer_for_authores)+1];
        strcpy_s(books_authors[i], strlen(buffer_for_authores) + 1, buffer_for_authores);

        cout << endl;

        // Ввод года издания книги
        cout << "Введите год издания книги: " << endl;
        cin >> books_years[i];
        cin.ignore();

        cout << endl;

        // Ввод кол-ва копий книги в библиотеке
        cout << "Введите кол-во копий книги в библиотеке: " << endl;
        cin >> books_copies[i];
        cin.ignore();

        // Очистка экрана консоли
        system("cls");
    }

    // Очистка экрана консоли
    system("cls");

    // Сортировка книг по алфавиту
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(books_titles[j], books_titles[j + 1]) > 0) {
                swap(books_titles[j], books_titles[j + 1]);
                swap(books_authors[j], books_authors[j + 1]);
                swap(books_years[j], books_years[j + 1]);
                swap(books_copies[j], books_copies[j + 1]);
            }
        }
    }

    // Вывод отсортированных книг
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". " << books_titles[i] << " Автор: " << books_authors[i] << ", Год издания: " << books_years[i] << ", Количество копий: " << books_copies[i] << endl;
    }

    system("pause > nul");
}

