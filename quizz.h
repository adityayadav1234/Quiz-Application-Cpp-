#ifndef QUIZZ_H_INCLUDED
#define QUIZZ_H_INCLUDED
#include <string>
#include <vector>
using namespace std;
class User{
protected:
    char userid[20];
    char pwd[20];
    char uname[50];
public:
    void setUserDetails(string,string,string);
    string getName(string);
    string getName();
    string getUserId();
    int checkUserExists(string);
    void show();
    int input();

};
class Student:public User{
public:

    void add();
    void Remove();
    void showStudentDetails();
    void quiz();
    void viewPerformance();
    void show();


    // string getName(string);
};
class Admin:public User{
public:
    static void create_admin(string,string,string);
    void addStudent();
    void removeStudent();
    void viewStudent();
    void addQuestion();
    void removeQuestion();
    void viewQuestion();
};
class Question{
private:
    int quesid,tot_marks;
    char ques[500],op1[100],op2[100],op3[100],op4[100],ans;
public:

    void add();
    void Remove();
    void setQuestionDetails(int,string,string,string,string,string,char);
    void show();
    void viewQuestion();
    void startQuiz(string);
    int ques_count();
    void marksc(string);//testing
};
class StudentPerformance
{
    char studid[10];
    int marks,tot_marks;
public:
    void setMarksDetails(string,int,int);
    void saveMarksDetails();
    void viewDetails(string);
    void show();
    string getName(string);
    void marksss();

};
bool isspresent(vector<int>&,int);
#endif // QUIZZ_H_INCLUDED







