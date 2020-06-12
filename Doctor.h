#include <bits/stdc++.h>
using namespace std;

#include "CommonBehavior.h"

#ifndef DOCTOR_H
#define DOCTOR_H

class Doctor : public CommonBehavior
{
public:
    bool Exist=false;
    fstream file ;
    GetNameAndPass(string DrName,string StID)
    {
        this->DrName=DrName;
        this->StID=StID;
    }

    void ViewCourse();

    void StudentsList();
    void AddAssignment();
    void ShowAssignments();
    void ShowStudentsGradesReport();
    void AddAnnouncement();
    void SetGrade();
    void ShowXstudentAnswer();


};
#endif // DOCTOR_H
