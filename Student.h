#include <bits/stdc++.h>
using namespace std;

#include "CommonBehavior.h"

#ifndef STUDENT_H
#define STUDENT_H

class Student : public CommonBehavior
{
public:
    GetNameAndPass(string StName,string StID)
    {
        this->StName=StName;
        this->StID=StID;
    }

    vector<string > AllCourses;
    vector<string > AllCoursesData;

    void RegisterInCourse();
    void UnRegister();
    void DisplayCourses();
    void ViewCourse();
    void Total_Grades();
    void StudentChatRoom();
    void Doctors_Announcement();


    void ShowAssignments(int Start_Display, int NumOfAssinments);
    void SolutionSubmit(int Start_Display, int NumOfAssinments );

    void SignUp(string username, string password);
};

#endif // STUDENT_H
