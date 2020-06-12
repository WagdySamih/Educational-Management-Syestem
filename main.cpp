#include <bits/stdc++.h>
using namespace std;
#include "Doctor.h"
#include "Student.h"
#include "CommonBehavior.h"
int main()
{
    int choice,occur=0;
    while(1)
    {
        cout<<"\nPlease Make a Choice: \n ";
        cout<<"1- Log In\n ";
        cout<<"2- Sign Up\n "  ;
        cout<<"3- Shutdown System\n\n";
        cout<<"    Your Choice:  ",cin>>choice;
        if(choice==1)
        {
            string UserName,PassWord;
            cout<<"\nMake a choice:\n";

            cout<<" 1- Student  \n";
            cout<<" 2- Doctor  \n";
            cout<<"    Your Choice:  ",cin>>choice;
            cout<<"\nPlease enter your user name and password\n";
            cout<<"    User Name: ";
            cin.ignore();
            getline(cin,UserName);
            cout<<"    Password : ";
            getline(cin,PassWord);
            if(choice==1)
            {
                Student x ;
                x.GetNameAndPass(UserName,PassWord);
                UserName+=".txt";
                if (x.Verify(UserName,PassWord))
                {
                    x.LoadStudentFile(UserName);
                    {
                        int option;
                        while(1)
                        {
                            cout<<"\n\n\nPlease Make a Choice: \n";
                            cout<<"        1 - Register in a Course\n";
                            cout<<"        2 - List of My Courses\n";
                            cout<<"        3 - View Course\n";
                            cout<<"        4 - Unregister From a Course\n";
                            cout<<"        5 - Grades Reports\n";
                            cout<<"        6 - Enter Students Chat Room\n";
                            cout<<"        7 - View Doctors Announcement\n";
                            cout<<"        8 - Log Out\n";
                            cout<<"    Your Choice:  ",cin>>option;
                            cout<<endl;


                            switch (option)
                            {
                            case 1:
                                x.RegisterInCourse();
                                break;
                            case 2:
                                x.DisplayCourses();
                                break;
                            case 3:
                                x.ViewCourse();
                                break;
                            case 4:
                                x.UnRegister();
                                break;
                            case 5:
                                x.Total_Grades();
                                break;
                            case 6:
                                x.StudentChatRoom();
                                break;
                            case 7:
                                x.Doctors_Announcement();
                                break;
                            default:
                                break;
                            }
                            if(option==8)
                            {
                                x.SaveStudentFile(UserName);
                                break;
                            }
                        }
                    }
                }
            }
            else if(choice==2)
            {

                Doctor Xx;
                Xx.GetNameAndPass(UserName,PassWord);
                UserName+=".txt";
                if (Xx.Verify(UserName,PassWord))
               {
                   cout<<"    Welcome "<<UserName<<" You Are Logged In \n";

                    Xx.LoadDoctorFile(UserName);
                int option;
                while(1)
                {
                    cout<<"\n\n\nPlease Make a Choice: \n";
                    cout<<"        1 - View Course\n";
                    cout<<"        2 - List of Student\n";
                    cout<<"        3 - Add An Announcement\n";
                    cout<<"        4 - Log Out\n";
                    cout<<"    Your Choice:  ",cin>>option;
                    cout<<endl;
                    switch(option)
                    {
                    case 1:
                        Xx.ViewCourse();
                        break;
                    case 2:
                        Xx.StudentsList();
                        break;
                    case 3:
                        Xx.AddAnnouncement();
                        break;
                    case 4:
                        break;
                    }
                    if(option==4)
                        break;
                }
               }
            }
        }
        else if(choice==2)
        {
            string userName,pass;
            cout<<"Enter Your User Name: ";
            cin.ignore();
            getline(cin,userName);
            cout<<"Enter Your  PassWord: ";
            cin>>pass;

            Student Xx;
            Xx.SignUp(userName,pass);

        }
    }
    return 0;
}
