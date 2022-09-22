#include "node.h"
#include<iostream>
using namespace std;
node::node(){

}
node::node(student s)
{
    this->s=s;

}
student node::getStudent()
{
    return s;
}

void node::setStudent(student s)
{
    this->s=s;
}

node* node::getNext()
{
    return next;
}

void node::setNext(node *next)
{
    this->next=next;
}
