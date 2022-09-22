#ifndef LIST_H
#define LIST_H
#include"node.h"
#include"student.h"
#include<fstream>
#include<iostream>

using namespace std;
class list
{

    public:
        list();
        void addFront(student);
        void guardar();
        void guardar1();
        void cargar();
        void print();
        void remove(int);
        void search(int);
        int tamanio();
        bool empty();


        node* getH(void){
        return h;
        }
        void setH(node *tmp){
            h=tmp;
        }
    private:
        node *h;
};

#endif // LIST_H
