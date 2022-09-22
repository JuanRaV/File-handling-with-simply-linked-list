#ifndef NODE_H
#define NODE_H
#include<iostream>
#include"student.h"

using namespace std;

class node
{
    public:
        node();
        node(student);
        student getStudent();
        void setStudent(student);

        node* getNext();
        void setNext(node *);


    private:
        student s;
        node *next;
};

#endif // NODE_H
