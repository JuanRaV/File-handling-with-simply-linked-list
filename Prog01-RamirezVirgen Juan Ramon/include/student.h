#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;

class student
{
    public:
        student();
        student(string,string,int);
        void setName(string);
        string getName();
        void setDegree(string);
        string getDegree();
        void setId(int);
        int getId();

    private:
        string name;
        string degree;
        int id;
};

#endif // STUDENT_H
