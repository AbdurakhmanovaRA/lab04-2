#include <iostream>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(0, "Russian");
    const size_t MAX_SIZE = 256;
    char name[MAX_SIZE];
    cout << "Введите имя файла: ";
    fgets(name, MAX_SIZE, stdin);
    const char* fsymbols = "*\"<>|?";
    char* filename = name;
    filename[strlen(filename) - 1] = '\0';

    while (true){
        if (strcspn(filename, fsymbols) == strlen(filename));
        else{
            cout << "Ошибка ввода. \n";
            break;
        }
        if (strchr(filename, 58)!= NULL){        //:
            if (isalpha(filename[0])){
                if (strcspn(filename, ":") == 1){
                    if (strcspn(filename, "\\") == 2){}
                    else{
                        cout << "Ошибка ввода. \n";
                        break;
                    }
                }
                else{
                    cout << "Ошибка ввода. \n";
                    break;
                }
            }
            else{
                cout << "Ошибка ввода. \n";
                break;
            }
        }

        if (strchr(filename, '.') == nullptr){
            strcat(filename, ".txt");
        }
        else{
            char* extention = strrchr(filename, '.');
            for (int i = 0; extention[i] != '\0'; i++){
                *(extention + i) = char(tolower(*(extention + i)));
            }
            if (strncmp(extention, ".txt", 4) != 0){
                cout << "Ошибка ввода. \n";
                break;
            }
        }

        FILE *fp;
        fp = fopen(filename, "r+");
        if (fp == 0){
            break;
        }
        fseek(fp, 0, SEEK_END);
        long size;
        size = ftell(fp);
        char* file_mas = new char[size];
        fseek(fp, 0, SEEK_SET);
        fread(file_mas, 1, size, fp);
        file_mas[size] = '\0';
        char strng[MAX_SIZE];
        cout << "Введите строку: ";
        fgets(strng, MAX_SIZE, stdin);
        char* str =strng;
        *(str + strlen(strng) -1) = '\0';
        int c = 0;
        while (*file_mas != '\0'){
            if (strncmp(file_mas, str, strlen(str)) != 0)
                file_mas += 1;
            else{
                c++;
                file_mas += 1;
            }
        }
        cout << "Количество вхождений строки в файл: " << c << endl;
        delete[] file_mas;
        fclose(fp);
        break;
    }

    system("pause");
}
