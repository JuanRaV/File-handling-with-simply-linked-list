#include "student.h"

student::student()
{
    name="";
    degree="";
    id=0;
}
student::student(string name, string degree, int id)
{
    this->name=name;
    this->degree=degree;
    this->id=id;
}

void student::setName(string name)
{
    this->name=name;
}



string student::getName()
{
    return name;
}

void student::setDegree(string degree)
{
    this->degree=degree;
}

string student::getDegree()
{
    return degree;
}

void student::setId(int id)
{
    this->id=id;
}

int student::getId()
{
    return id;
}
