#include <iostream>
using namespace std;

struct Student
{

    int code;
    string name;
    string school;
    string level;
    int age;
    Student *next;
    Student() {}
    Student(int c, string nm, string schl, string lvl, int g)
    {
        code = c;
        name = nm;
        school = schl;
        level = lvl;
        age = g;
        next = NULL;
    }
};

void display(Student *head)
{
    while (head)
    {
        cout << head->code << " " << head->name << " " << head->school << "" << head->level << " "
             << head->age << endl;
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Student *s1 = new Student();
    s1->code = 101;
    s1->name = "Mary";
    s1->school = "RCA";
    s1->level = "Y2";
    s1->age = 15;

    Student *s2 = new Student(102, "Peter", "RCA", "Y3", 17);
    Student *s3 = new Student(103, "John", "RCA", "Y1", 16);
    Student *s4 = new Student(104, "Doe", "RCA", "Y4", 18);
    s1->next = s2;
    s2->next = s3;
    s3->next = s4;
    s4->next = NULL;
    display(s1);
    return 0;
}
