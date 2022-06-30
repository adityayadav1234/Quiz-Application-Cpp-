#include <iostream>
#include "conio2.h"
#include "quizz.h"
using namespace std;
void stlfunhere();
int main()
{
    int type,c,choice;
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
    textcolor(MAGENTA);
    gotoxy(58,4);
    stlfunhere();
    textcolor(YELLOW);
    gotoxy(20,10);
    cout<<"Welcome To Tech Test - Quiz Application";
    gotoxy(20,14);
    textcolor(LIGHTGREEN);
    cout<<"Test Your SKills ! Improve Your Knowledge";
    gotoxy(1,20);
    textcolor(WHITE);
    cout<<"Press any key to continue"<<endl;
    getch();
    Admin::create_admin("uadmin","abc","Aditya");
    do   //here admin srceen or login screen start
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
        gotoxy(32,10);
        cout<<"1.ADMIN";
        gotoxy(32,12);
        cout<<"2.STUDENT";
        gotoxy(32,14);
        textcolor(WHITE);
        cout<<"Select your role:: ";
        cin>>type;
        if(type==0)
            break;
        cin.ignore();
        if(type==1)
        {
            Admin adminObj;  //admin options
            do
            {
                c=adminObj.input();
                if(c==0)
                {
                    gotoxy(30,14);
                    textcolor(LIGHTRED);
                    cout<<"Login cancelled";
                    gotoxy(1,20);
                    textcolor(WHITE);
                    cout<<"Press any key to continue";
                    getch();
                    break;
                }
            c=adminObj.checkUserExists("admin"); //check  user excst
            if(c==1)//cout<<endl<<"ret val check user excied"<<c;
            {
                gotoxy(29,20);
                textcolor(LIGHTGREEN);
                cout<<"LOGIN Accepted!";
                gotoxy(29,23);
                cout<<"Welcome "<<adminObj.getName();
                gotoxy(28,25);
                textcolor(WHITE);
                cout<<"Press any key to continue";
                getch();
                while(1)
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
                    gotoxy(35,6);
                    cout<<"ADMIN MENU"<<endl;
                    textcolor(YELLOW);
                    gotoxy(1,5);
                    for(int i=1; i<=80;i++)
                        cout<<"*";
                    textcolor(YELLOW);
                    gotoxy(1,7);
                    for(int i=1;i<=80;i++)
                        cout<<"*";
                    gotoxy(32,8);
                    cout<<"1.ADD QUESTION";
                    gotoxy(32,9);
                    cout<<"2.ADD STUDENT";
                    gotoxy(32,10);
                    cout<<"3.SHOW QUESTIONS";
                    gotoxy(32,11);
                    cout<<"4.SHOW STUDENT";
                    gotoxy(32,12);
                    cout<<"5.REMOVE QUESTION";
                    gotoxy(32,13);
                    cout<<"6.REMOVE STUDENT";
                    gotoxy(32,14);
                    cout<<"7.EXIT";
                    gotoxy(32,15);
                    cout<<"Enter choice ::";
                    textcolor(WHITE);
                    cin>>choice;
                    switch(choice)
                    {
                    case 1:
                        clrscr();
                        adminObj.addQuestion();
                        break;
                    case 2:
                        clrscr();
                        adminObj.addStudent();
                        break;
                    case 3:
                        clrscr();
                        adminObj.viewQuestion();
                        break;
                    case 4:
                        clrscr();
                        adminObj.viewStudent();
                        break;
                    case 5:
                        clrscr();
                        adminObj.removeQuestion();
                        break;
                    case 6:
                        clrscr();
                        adminObj.removeStudent();
                        break;
                    case 7:
                        break;
                    default:
                        textcolor(LIGHTRED);
                        gotoxy(32,18);
                        cout<<"Wrong choice, Try Again !";

                    }
                    if(choice == 7)
                        break;

                }
            }

            }while(c==0);
        }
        else if(type==2){

            {
            Student studObj;  //admin options
            do
            {
                c=studObj.input();
                if(c==0)
                {
                    gotoxy(30,14);
                    textcolor(LIGHTRED);
                    cout<<"Login cancelled";
                    gotoxy(1,20);
                    textcolor(WHITE);
                    cout<<"Press any key to continue";
                    getch();
                    break;
                }
            c=studObj.checkUserExists("student"); //check  user excst
            if(c==1)//cout<<endl<<"ret val check user excied"<<c;
            {
                gotoxy(29,20);
                textcolor(LIGHTGREEN);
                cout<<"LOGIN Accepted!";
                gotoxy(29,23);
                cout<<"Welcome "<<studObj.getName();
                gotoxy(28,25);
                textcolor(WHITE);
                cout<<"Press any key to continue";
                getch();
                while(1)
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
                    gotoxy(33,6);
                    cout<<"STUDENT MENU"<<endl;
                    textcolor(YELLOW);
                    gotoxy(1,5);
                    for(int i=1; i<=80;i++)
                        cout<<"*";
                    textcolor(YELLOW);
                    gotoxy(1,7);
                    for(int i=1;i<=80;i++)
                        cout<<"*";
                    gotoxy(32,8);
                    cout<<"1.START QUIZ";
                    gotoxy(32,9);
                    cout<<"2.VIEW PERFORMANCE";
                    gotoxy(32,10);
                    cout<<"3.EXIT";
                    gotoxy(32,15);
                    cout<<"Enter choice ::";
                    textcolor(WHITE);
                    cin>>choice;

                    if(choice==1){
                        clrscr();
                        studObj.quiz();
                        break;
                    }

                    if(choice==2){
                        clrscr();
                        //studObj.viewPerformance();
                        break;
                    }

                    if(choice>=4){
                        textcolor(LIGHTRED);
                        gotoxy(32,18);
                        //clrscr();
                        cout<<"Wrong choice, Try Again !";
                        getch();
                    }
                    if(choice == 3)
                        break;

                }
            }

            }while(c==0);
        }
        }
        else
        {
            gotoxy(30,14);
            cout<<"\t\t\t\\t\t\t\t\t";
            gotoxy(30,14);
            textcolor(RED);
            cout<<"Invalid User Type";
            getch();

        }
        getch();
    }while(1);
    return 0;
}
void stlfunhere(){
    cout<<char(65)<<char(100)<<char(105)<<char(116)<<char(121)<<char(97)<<char(32)<<char(89)<<char(97)<<char(100)<<char(97)<<char(118);
}
