#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "quizz.h"
#include "conio2.h"
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;
bool ispresent(vector<int>,int);
void Admin::create_admin(string userid, string password, string username)
{
    fstream fobj("Admin.bin",ios::in|ios::binary);
    if(fobj.fail())
    {
        fobj.open("Admin.bin",ios::out|ios::binary);
        Admin adminObj;
        adminObj.setUserDetails(userid,password,username);
        fobj.write((char *)&adminObj,sizeof(Admin));
        cout<<"File created";
    }

    fobj.close();

}
void User::setUserDetails(string userid,string pwd, string uname)
{
    strcpy(this->userid,userid.c_str());
    strcpy(this->pwd,pwd.c_str());
    strcpy(this->uname,uname.c_str());

}
int User::input()
{
    clrscr();
    textcolor(LIGHTGREEN);
    for(int i=1;i<=80;i++)
        cout<<"*";
    textcolor(LIGHTRED);
    gotoxy(32,2);
    cout<<"Quiz Application";
    gotoxy(1,3);
    textcolor(LIGHTGREEN);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(58,4);
    textcolor(WHITE);
    cout<<"Press 0 to Exit/Go back";
    gotoxy(1,8);
    textcolor(YELLOW);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(1,17);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(28,11);
    cout<<"Enter UserID:";
    textcolor(WHITE);
    cin.getline(userid,20);
    if(strcmp(userid,"0")==0)
        return 0;
    char ch;
    int i =0;
    textcolor(YELLOW);
    gotoxy(28,12);
    cout<<"Enter password:";
    while(true)
    {
        ch=getch();
        if(ch==13)
            break;
        if(ch==8)
        {
            if(i==0)
                continue;
            cout<<"\b \b";
            i--;
            continue;
        }
        cout<<ch;
        delay(200);
        cout<<"\b*";
        pwd[i]=ch;
        i++;
    }
pwd[i]='\0';
if(strcmp(pwd,"0")==0)
    return 0;
return 1;
}
int User::checkUserExists(string usertype)
{
    if(strcasecmp(userid,"")==0 || strcmp(pwd,"")==0)
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        cout<<"BOTH THE FEILDS ARE MANDATORY";
        getch();
        return 0;

    }
    ifstream fin;
    User *uptr;
    if(usertype == "admin")
    {
        fin.open("Admin.bin",ios::in|ios::binary);
        uptr=new Admin;
    }
    else if(usertype == "student")
    {
        fin.open("Student.bin",ios::in | ios::binary);
        uptr=new Student;
    }
    else
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        cout<<"Wrong User Type Passed";
        getch();
        return 0;
    }
    bool useridfound=0,pwdfound=0;
    while(1)
    {
        fin.read((char *)uptr,sizeof(*uptr));
        if(fin.eof())
            break;
        if(strcmp(userid,uptr->userid)==0)
        {
            if(strcmp(pwd,uptr->pwd)==0)
            {
                useridfound=pwdfound=1;
                break;
            }
            useridfound = 1;
        }

    }
    bool result =0;
    if(useridfound==0)
    {
        gotoxy(28,18);
        textcolor(LIGHTRED);
        cout<<"NO SUCH UISER EXIST!";
        getch();
    }
    else if(pwdfound==0)
    {
        gotoxy(28,18);
        textcolor(LIGHTRED);
        cout<<"INVAILED PASSWORD";
        getch();
    }
    else
    {
        result =1;
        strcpy(uname,uptr->uname);
    }

    fin.close();
    return result;
}
string User :: getName()
{
    string USERNAME(uname);
    return USERNAME;
}
string User::getUserId()
{
    string userID;
    userID=userid;
    return userID;
}
void Admin::addQuestion()
{
    Question quesObj;
    quesObj.add();
    clrscr();
}
void Question:: add()
{
    fstream fobj("Question.bin",ios::app|ios::binary|ios::in);
    if(!fobj)
    {
        gotoxy(32,18);
        textcolor(RED);
        cout<<"File cant be opened";
        getch();
        return;
    }
    fobj.seekg(0,ios::end);
    if(fobj.tellg()==0)
        quesid=1;
    else
    {
        fobj.seekg(-1*sizeof(*this),ios::end);
        fobj.read((char *)this,sizeof(*this));
        cout<<"Last Question ID is "<<quesid;
        quesid++;
        cout<<endl<<"New Question ID is "<<quesid;
        getch();
    }
    char uchoice;
    do
    {
        clrscr();
        textcolor(WHITE);
        gotoxy(58,4);
        cout<<"Press 0 to exit / go back";
        textcolor(LIGHTGREEN);
        gotoxy(1,1);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(1,3);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(32,2);
        textcolor(LIGHTRED);
        cout<<"QUIZ APP";
        textcolor(WHITE);
        gotoxy(25,5);
        cout<<"***** ADD QUESTION *****";
        gotoxy(1,8);
        textcolor(YELLOW);
        cout<<"Enter Question:: ";
        string str;
        cin.ignore();
        textcolor(WHITE);
        getline(cin,str,'*');
        if(strcmp(str.c_str(),"0")==0)
        {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"Closing add question";
            getch();
            fobj.close();
            return;
        }
        strncpy(ques,str.c_str(),499);
        textcolor(LIGHTGREEN);
        cout<<endl<<"Carrier marks:: ";
        cin>>tot_marks;
        textcolor(LIGHTGREEN);
        cout<<endl<<"Options"<<endl<<endl;
        textcolor(YELLOW);
        cout<<"(a)";
        cin.ignore();
        textcolor(WHITE);
        getline(cin,str);
        strncpy(op1,str.c_str(),99);
        textcolor(YELLOW);
        cout<<"(b)";
        textcolor(WHITE);
        getline(cin,str);
        strncpy(op2,str.c_str(),99);
        textcolor(YELLOW);
        cout<<"(c)";
        textcolor(WHITE);
        getline(cin,str);
        strncpy(op3,str.c_str(),99);
        textcolor(YELLOW);
        cout<<"(d)";
        textcolor(WHITE);
        getline(cin,str);
        strncpy(op4,str.c_str(),99);
        bool valid;
        do
        {
            gotoxy(1,19);
            textcolor(YELLOW);
            cout<<endl<<"Enter Right Answer(a/b/c/d):  \b";
            textcolor(WHITE);
            cin>>ans;
            if(ans>='a' && ans<='d'){
                valid=true;}
            else
            {
                gotoxy(24,22);
                textcolor(LIGHTRED);
                cout<<"Please Try Again";
                getch();
                valid=false;
            }
        }while(valid!=true);

        fobj.write((char *)this,sizeof(*this));
        quesid++;
        gotoxy(24,22);
        cout<<"\t\t\t\t\t\t\t";
        gotoxy(34,22);
        textcolor(LIGHTGREEN);
        cout<<"Question Added Successfully!";
        getch();
        gotoxy(1,24);
        textcolor(LIGHTMAGENTA);
        cout<<"Do you want to add more questions?(Y/N):: ";
        textcolor(WHITE);
        cin>>uchoice;
    }while(uchoice=='y' || uchoice=='Y');
    fobj.close();
}



void Admin::viewQuestion()
{
    Question quesObj;
    quesObj.viewQuestion();
    clrscr();
}
void Question::viewQuestion()
{
    ifstream fin("Question.bin",ios::in|ios::binary);
    if(!fin)
    {
        gotoxy(32,18);
        textcolor(LIGHTRED);
        cout<<"Sorry! File cannot be opened.";
        getch();
        return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
        gotoxy(1,10);
        textcolor(LIGHTRED);
        cout<<"No Questions present in the file!";
        getch();
        return;
    }
    clrscr();
    fin.seekg(0);
    while(1)
    {
        textcolor(LIGHTGREEN);
        gotoxy(1,1);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(1,3);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(32,2);
        textcolor(LIGHTRED);
        cout<<"QUIZ APP";
        textcolor(WHITE);
        gotoxy(24,5);
        cout<<"***** SHOW QUESTION *****";
        gotoxy(1,6);
        textcolor(LIGHTGREEN);
        for(int i=1;i<=80;i++)
            cout<<"*";
        fin.read((char*)this,sizeof(*this));
        if(fin.eof())
        {
            cout<<endl;
            textcolor(LIGHTRED);
            gotoxy(35,10);
            cout<<"No more Question file is present!";
            getch();
            break;
        }
        else
        {
            show();
            getch();
            clrscr();
        }
    }
fin.close();
}
void Question::show()
{

    cout<<endl;
    textcolor(YELLOW);
    cout<<"Q."<<quesid<<"  ";
    cout<<ques<<endl;
    cout<<"Carries marks:: "<<tot_marks<<endl;
    cout<<"a. "<<op1<<endl;
    cout<<"b. "<<op2<<endl;
    cout<<"c. "<<op3<<endl;
    cout<<"d. "<<op4<<endl;
    textcolor(LIGHTGREEN);
    cout<<endl<<"Correct option:: "<<ans;
}
void Admin::removeQuestion()
{
    Question quesObj;
    quesObj.Remove();
    clrscr();
}
void Question::Remove()
{
    clrscr();
    textcolor(LIGHTGREEN);
    gotoxy(1,1);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(1,3);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(32,2);
    textcolor(LIGHTRED);
    cout<<"QUIZ APP";
    textcolor(WHITE);
    gotoxy(24,5);
    cout<<"***** Remove QUESTION *****";
    gotoxy(58,4);
    textcolor(WHITE);
    cout<<"Press 0 to Exit/Go back";

    ifstream fin("Question.bin",ios::in|ios::binary);
    if(!fin)
    {
        gotoxy(35,10);
        textcolor(RED);
        cout<<"Sorry! File cant be opened";
        getch();
        return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
        gotoxy(1,10);
        textcolor(LIGHTRED);
        cout<<"No Questions available for deletion!";
        getch();
        fin.close();
        return;
    }
    getch();
    gotoxy(1,8);
    textcolor(YELLOW);
    cout<<"Enter Question ID: ";
    bool found=false,valid;
    int id;
    ofstream fout("temp.bin",ios::out|ios::binary);
    if(!fout)
    {
        gotoxy(35,10);
        textcolor(LIGHTRED);
        cout<<"Sorry! File  cannot be opened";
        getch();
        fin.close();
        return;
    }
    fin.seekg(0);
    do
    {
        valid=true;
        cin>>id;
        if(id==0)
        {
            fin.close();
            fout.close();
            remove("temp.bin");
            return;
        }
        if(id<0)
        {
            valid=false;
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"\t\t\t\t\t\t\t\t\t\t\rInvalid Question ID";
            getch();
            gotoxy(19,8);
            cout<<"\t\t\t\t\t\t\t\t\t";

        }
        else
        {
            while(true)
            {
                fin.read((char*)this,sizeof(*this));
                if(fin.eof())
                    break;
                if(this->quesid==id)
                {
                    found=true;
                    continue;
                }
                else
                {
                    fout.write((char*)this,sizeof(*this));
                }
            }
            fout.close();
            fin.close();
            if(found)
            {
                textcolor(WHITE);
                gotoxy(1,24);
                cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\rQuestion removed successfully!";
                getch();
                remove("Question.bin");
                rename("temp.bin","Question.bin");
            }
            else
            {
                textcolor(LIGHTRED);
                gotoxy(1,24);
                cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\rQuestion not found!";
                getch();
                remove("temp.bin");
                getch();
            }
        }
    }while(valid==false);
}
void Admin::addStudent()
{
    Student studobj;
    studobj.add();
}
void Student::add()
{
    char uchoice;
    int id;
    char stuid[10];
    string str;
    fstream fobj("Student.bin",ios::app|ios::in|ios::binary);
    fobj.seekg(0,ios::end);
    if(fobj.tellg()==0)
        id=1;
    else
    {
        fobj.seekg(-1*sizeof(*this),ios::end);
        fobj.read((char*)this,sizeof(*this));
        char *pos=strchr(userid,'-');
        if(pos!=NULL)
        {
            id=atoi(pos+1);
            id++;

        }

    }
    cout<<"Next id is:"<<id;
    getch();
    fobj.seekg(0,ios::end);
    do
    {
        clrscr();
        textcolor(WHITE);
        gotoxy(58,4);
        cout<<"Press 0 to exit/ Go Back";
        textcolor(LIGHTGREEN);
        gotoxy(1,1);
        for(int i=1;i<=80;i++)
            cout<<"~";
        gotoxy(1,3);
        for(int i=1;i<=80;i++)
            cout<<"~";
        gotoxy(32,2);
        textcolor(LIGHTRED);
        cout<<"QUIZ APP";
        textcolor(WHITE);
        gotoxy(25,5);
        cout<<"***** ADD STUDENT DETAILS *****";
        gotoxy(1,8);
        textcolor(YELLOW);
        cout<<"Enter student name:: ";
        cin.ignore();
        textcolor(WHITE);
        getline(cin,str);
        strncpy(uname,str.c_str(),19);
        if(strcmp(uname,"0")==0)
        {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"Cancelling Add Student....."<<endl;
            getch();
            fobj.close();
            return;
        }
        textcolor(YELLOW);
        cout<<"Enter Student Password:: ";
        textcolor(WHITE);
        getline(cin,str);
        strncpy(pwd,str.c_str(),19);
        if(strcmp(pwd,"0")==0)
        {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"Cancelling Add Student....."<<endl;
            getch();
            fobj.close();
            return;
        }
        sprintf(stuid,"STU-%d",id);
        strcpy(userid,stuid);
        fobj.write((char*)this,sizeof(*this));
        gotoxy(30,15);
        textcolor(LIGHTGREEN);
        cout<<"Student added successfully!";
        cout<<endl<<"Student ID is: "<<userid;
        getch();
        gotoxy(1,20);
        textcolor(LIGHTMAGENTA);
        cout<<"Do you want to add more Students(Y/N):: ?";
        cin>>uchoice;
        id++;
    }while(uchoice=='Y' || uchoice =='y');
    fobj.close();
}
void Admin::viewStudent()
{
    Student studObj;
    studObj.showStudentDetails();
    clrscr();
}
void Student::showStudentDetails()
{
    ifstream fin("Student.bin",ios::in|ios::binary);
    if(!fin)
    {
        gotoxy(32,18);
        textcolor(LIGHTRED);
        cout<<"Sorry! File cannot be opened.";
        getch();
        return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
        gotoxy(1,10);
        textcolor(LIGHTRED);
        cout<<"No Student present in the file!";
        getch();
        return;
    }
    clrscr();
    fin.seekg(0);
    while(1)
    {
        textcolor(LIGHTGREEN);
        gotoxy(1,1);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(1,3);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(32,2);
        textcolor(LIGHTRED);
        cout<<"QUIZ APP";
        textcolor(WHITE);
        gotoxy(24,5);
        cout<<"***** SHOW STUDENT *****";
        gotoxy(1,6);
        textcolor(LIGHTGREEN);
        for(int i=1;i<=80;i++)
            cout<<"*";
        fin.read((char*)this,sizeof(*this));
        if(fin.eof())
        {
            cout<<endl;
            textcolor(LIGHTRED);
            gotoxy(35,10);
            cout<<"No more STUDENT is present!";
            getch();
            break;
        }
        else
        {
            show();
            getch();
            clrscr();
        }
    }
fin.close();
}
void Student::show()
{

    cout<<endl;
    textcolor(YELLOW);
    cout<<"user ID"<<userid<<"  ";
    textcolor(LIGHTGREEN);
    cout<<userid<<endl;

    textcolor(YELLOW);
    cout<<"User name:: ";
    textcolor(LIGHTGREEN);
    cout<<uname<<endl;

    textcolor(YELLOW);
    cout<<"Password:: ";
    textcolor(LIGHTGREEN);
    cout<<pwd<<endl;
}
void Admin::removeStudent()
{
    Student studobj;
    studobj.Remove();
}
void Student::Remove()
{
    clrscr();
    textcolor(LIGHTGREEN);
    gotoxy(1,1);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(1,3);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(32,2);
    textcolor(LIGHTRED);
    cout<<"QUIZ APP";
    textcolor(WHITE);
    gotoxy(24,5);
    cout<<"***** Remove STUDENT *****";
    gotoxy(58,4);
    textcolor(WHITE);
    cout<<"Press 0 to Exit/Go back";

    ifstream fin("Student.bin",ios::in|ios::binary);
    if(!fin)
    {
        gotoxy(35,10);
        textcolor(RED);
        cout<<"Sorry! File cant be opened";
        getch();
        return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
        gotoxy(1,10);
        textcolor(LIGHTRED);
        cout<<"No Student is available for deletion!";
        getch();
        fin.close();
        return;
    }
    getch();
    gotoxy(1,8);
    textcolor(YELLOW);
    cout<<"Enter Student ID: STU- ";
    bool found=false,valid;
    int id;
    char uid[10];
    ofstream fout("temp.bin",ios::out|ios::binary);
    if(!fout)
    {
        gotoxy(35,10);
        textcolor(LIGHTRED);
        cout<<"Sorry! File  cannot be opened";
        getch();
        fin.close();
        return;
    }
    fin.seekg(0);
    do
    {
        valid=true;
        cin>>id;
        if(id==0)
        {
            fin.close();
            fout.close();
            remove("temp.bin");
            return;
        }
        if(id<0)
        {
            valid=false;
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"\t\t\t\t\t\t\t\t\t\t\rInvalid Student ID";
            getch();
            gotoxy(19,8);
            cout<<"\t\t\t\t\t\t\t\t\t";

        }
        else
        {
            while(true)
            {
                fin.read((char*)this,sizeof(*this));
                if(fin.eof())
                    break;
                sprintf(uid,"STU-%d",id);
                int res = strcmp(this->userid, uid);
                if(res==0)
                {
                    found=true;
                    continue;
                }
                else
                {
                    fout.write((char*)this,sizeof(*this));
                }
            }
            fout.close();
            fin.close();
            if(found)
            {
                textcolor(WHITE);
                gotoxy(1,24);
                cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\rStudent removed successfully!";
                getch();
                remove("Student.bin");
                rename("temp.bin","Student.bin");
            }
            else
            {
                textcolor(LIGHTRED);
                gotoxy(1,24);
                cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\rStudent not found!";
                remove("temp.bin");
                getch();
            }
        }
    }while(valid==false);
}
void Student::quiz()
{
    Question quesObj;
    quesObj.startQuiz(userid);
}
void Question::startQuiz(string id)
{
    int local_marks;
    int local_tot_marks;
    ifstream fin("Question.bin",ios::in|ios::binary);
    if (fin.fail())
    {
       gotoxy(28,20);
       textcolor(LIGHTRED);
       cout<<"No Questions have been added yet!";
       getch();
       return;
    }
    vector <Question> vecQues;
    while(1)
    {
        fin.read((char*)this,sizeof(*this));
        if(fin.eof())
            break;
        vecQues.push_back(*this);
    }
    fin.close();
    vector <int> vecRand;
    srand((unsigned int)time(NULL));
    int randno;
    while(1)
    {
        randno=rand()%vecQues.size();
        if(isspresent(vecRand,randno)==true)
            continue;
        vecRand.push_back(randno);
        if(vecRand.size()==vecQues.size())
            break;
    }
    //int local_marks=0;
    //int local_tot_marks=0;
    int count=0;
    User userObj;
    string name=userObj.getName(id);
    for(int i=0;i<vecQues.size();i++)
    {
        int index=vecRand.at(i);
        *this=vecQues.at(index);
        clrscr();
        gotoxy(37,2);
        textcolor(LIGHTRED);
        cout<<"Quiz App";
        textcolor(YELLOW);
        gotoxy(1,4);
        for(int j=1;j<80;j++)
            cout<<"*";
        gotoxy(1,6);
        for(int j=1;j<80;j++)
            cout<<"*";
        textcolor(WHITE);
        gotoxy(50,5);
        cout<<name;
        gotoxy(10,5);
        cout<<"Total Question: "<<vecQues.size()<<endl;
        gotoxy(1,6);
        textcolor(YELLOW);
        gotoxy(1,4);
        for(int j=1;j<80;j++)
            cout<<"*";
        gotoxy(1,6);
        for(int j=1;j<80;j++)
            cout<<"*";
        textcolor(GREEN);
        gotoxy(1,8);
        count++;
        cout<<count++<<")";
        gotoxy(4,8);
        cout<<this->ques<<endl <<endl;
        textcolor(LIGHTGRAY);
        cout<<"a."<<this->op1<<endl<<endl;
        cout<<"b."<<this->op2<<endl<<endl;
        cout<<"c."<<this->op3<<endl<<endl;
        cout<<"d."<<this->op4<<endl<<endl;
        bool valid;
        char uans;

        do
        {
            textcolor(YELLOW);
            cout<<"Enter your option:  \b";
            cin>>uans;
            if(uans>='a' && uans<='d')
                valid = true;
            else
            {
                valid = false;
                gotoxy(24,22);
                textcolor(LIGHTRED);
                cout<<"Invalid option entered. Try again";
                getch();
                gotoxy(24,22);
                cout<<"\t\t\t\t\t\t\t\t\t\t\t";
                gotoxy(1,18);
            }
        }while(valid==false);
        local_tot_marks+=this->tot_marks;
        //this->tot_marks+=local_tot_marks;
        if(uans==this->ans)
            local_marks+=this->tot_marks;
    }
    clrscr();
    gotoxy(37,2);
    textcolor(LIGHTRED);
    cout<<"Quiz App";
    textcolor(YELLOW);
    gotoxy(1,4);
    for(int j=1;j<80;j++)
        cout<<"*";
    gotoxy(1,6);
    for(int j=1;j<80;j++)
        cout<<"*";
    gotoxy(32,10);
    textcolor(LIGHTRED);
    cout<<"** TEST FINISHED **";
    gotoxy(22,12);
    cout<<"PRESS ANY KEY TO GO BACK TO MAIN  MENU";
    getch();
    StudentPerformance stp;
    stp.setMarksDetails(id, local_marks, local_tot_marks);
}

void StudentPerformance::setMarksDetails(string id, int marks, int tot_marks)
{
    strcpy(studid,id.c_str());
    this->marks=marks;
    this->tot_marks=tot_marks;

    saveMarksDetails();
}
void StudentPerformance::saveMarksDetails()
{
    ofstream fout("Performance.bin",ios::app|ios::binary);
    if(!fout)
    {
        gotoxy(1,26);
        textcolor(LIGHTRED);
        cout<<"Error in creating file\opening file";
        getch();
        return;
    }
    fout.write((char *)this,sizeof(*this));
    cout<<marks<<" "<<tot_marks;
    fout.close();
}
string User::getName(string id)
{
    ifstream fin("Student.bin",ios::in|ios::binary);
    while(1)
    {
        fin.read((char*)this,sizeof(User));
        if(fin.eof())
        {
            cout<<"No match of record found";
            break;
        }
        int result=strcmp(this->getUserId().c_str(),id.c_str());
        if(result==0)
        {
            fin.close();
            return this->uname;
        }

    }
    fin.close();
    getch();
}
bool isspresent(vector<int> & v,int value)
{
    for(int i=0;i<v.size();i++)
    {
        if(v.at(i)==value)
            return true;
    }
    return false;
}



