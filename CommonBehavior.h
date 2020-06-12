#ifndef COMMONS_H
#define COMMONS_H
#include <bits/stdc++.h>
using namespace std;

class CommonBehavior{
public:


    string DrName,StName,DrID,StID;

    bool Verify(string FileName,string ID);


    void LoadDoctorFile(string FileName);
    /**********************************************/
    void LoadStudentFile(string FileName);
    void SaveStudentFile(string FileName);

    vector <string> CoursesName     ;
    vector <string> CoursesTeacher  ;
    vector <string> Assignments     ;
    vector <string> CoursesData     ;
    vector <string> StudentAnswer   ;
    vector <int   > AssignmentsNum  ;
    int CoursesNum;

    string studentfile;
    string Spass;
    /************************************************/
    vector <vector <int> >split(vector<string> lines);
    /************************************************/




    string CourseName;
    vector <string> StudentNames;
    vector <string> Questions;
    vector <int> MaxGrade;
    vector <string> ModelAnswer;

    int StudentNumber;






    /************************************************/


};

#endif // COMMONS_H
