#include "CommonBehavior.h"

bool CommonBehavior :: Verify(string FileName,string ID)
{
    string pass,line;
    fstream file (FileName.c_str());

    if (!file.is_open())
    {
        cout<<"\n*****  Wrong User Name  *****\n";
        return false;
    }
    else if ( getline(file,pass) && pass!=ID )
    {
        cout<<"\n*****  Wrong Password  *****\n";
        return false;
    }

    return true;
}
void CommonBehavior :: SaveStudentFile(string FileName)
{
    ofstream file;
    file.open(FileName.c_str(), std::ofstream::out  | std::ofstream::trunc);
    file<<StID<<endl;

    for(int i=0 ; i<CoursesName.size(); i++)
        file<<CoursesName[i]<<endl;
    file<<"__"<<endl;


    for(int i=0,shift=0; i<CoursesName.size(); i++)
    {
        file<<CoursesTeacher[i]<<endl;
        for(int j=shift; j<AssignmentsNum[i]+shift; j++)
        {
            file<<Assignments[j]<<endl;
            file<<CoursesData[j]<<endl;
            file<<StudentAnswer[j]<<endl;
        }
        shift+=AssignmentsNum[i];
        file<<"__"<<endl;
    }


    CoursesName.clear();     ///shown when registered courses are asked to  shown
    CoursesData.clear();     /// its score
    CoursesTeacher.clear();  ///1st in detailed
    Assignments.clear();     ///the questions its self
    StudentAnswer.clear();   /// after score
    AssignmentsNum.clear();
    CoursesNum=0;
}
void CommonBehavior :: LoadStudentFile(string FileName)
{
    fstream file (FileName.c_str());
    string line;
    getline (file,line);
    StID=line;
    while(line!="__")
    {
        getline (file,line);
        CoursesName.push_back(line);
    }
    CoursesName.pop_back();
    CoursesNum=CoursesName.size();

    for(int i=0; i<CoursesNum; i++)
    {
        getline (file,line);
        CoursesTeacher.push_back(line);
        int cnt=0;
        while(line[0]!='_' )
        {
            getline (file,line);
            if(line[0]=='_' )
                break;
            Assignments.push_back(line);

            getline (file,line);
            CoursesData.push_back(line);

            getline (file,line);
            StudentAnswer.push_back(line);

            cnt++;
        }
        AssignmentsNum.push_back(cnt);
    }
}
vector <vector <int> >  CommonBehavior :: split(vector<string> lines)
{
    vector <vector <int> > num(lines.size());
    for(int i=0; i<lines.size(); i++)
    {
        string s = lines[i];
        istringstream iss(s);
        while (iss)
        {
            string subs;
            iss >> subs;
            num[i].push_back(atoi(subs.c_str()));
        }
    }

    return num;
}

void CommonBehavior :: LoadDoctorFile(string FileName)
{
    string line;
    fstream file (FileName.c_str());
    getline(file,DrID);
    getline (file,CourseName);
    getline(file,line);

    while(getline(file,line)&& line!="__")
        StudentNames.push_back(line);
    StudentNumber=StudentNames.size();

    while(getline(file,line)&& line!="__")
    {
        Questions.push_back(line);

        getline(file,line);
        ModelAnswer.push_back(line);

        getline(file,line);

        MaxGrade.push_back(atoi(line.c_str()));
    }
    CoursesNum=Questions.size();
}
