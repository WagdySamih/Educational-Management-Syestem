#include "Doctor.h"

void Doctor :: AddAnnouncement()
{
    fstream file ;
    file.open("DoctorsAnnouncement.txt",ios::app);
    cout<<"Enter Your Announcement: ";
    string line;
    cin.ignore();
    getline(cin,line);
    file<<DrName<<": "<<line<<endl;
    file.close();
}

void Doctor :: ViewCourse()
{
    int option;
    cout<<"\nThis Is "<<CourseName<<endl;
    cout<<"This Course Have "<<StudentNumber<<" Students."<<endl;
    while(1)
{

    cout<<"\n\nPlease Make a Choice: \n";
    cout<<"        1 - List Of Students\n";
    cout<<"        2 - Show Assignments \n";
    cout<<"        3 - Add An Assignment\n";
    cout<<"        4 - Grade Assignments\n";
    cout<<"        5 - Back\n";
    cout<<"    Your Choice:  ",cin>>option;
    cout<<endl;

    if(option==5)
        break;
    switch(option)
    {
    case 1:
        StudentsList();
        break;
    case 2:
        ShowAssignments();
        break;
    case 3:
        AddAssignment();
        break;
    case 4:
        ShowXstudentAnswer();
        break;
    default:
        break;
    }
}
}
void Doctor :: StudentsList()
{
    cout<<"This Course Have "<<StudentNumber<<" Students"<<endl;
    for(int i=0; i<StudentNames.size(); i++)
        cout<<i+1<<" -  "<<StudentNames[i]<<endl;
}
void Doctor :: ShowAssignments()
{
     cout<<"*******************************************************************"<<endl;
    for (int i=0 ; i<Questions.size(); i++)
    {

        cout<<"  Assignment Number "<<i+1<<": ";
        cout<<"   "<<Questions[i]<<endl;
        cout<<"  The Model Answer is: ";
        cout<<"   "<<ModelAnswer[i]<<endl;
        cout<<"  This Assignment Worth "<<MaxGrade[i]<<" Marks"<<endl<<endl;
        cout<<"*******************************************************************"<<endl;
    }
}
void Doctor :: AddAssignment()
{
    string line1,line2,line3;
    int num;
    cin.ignore();
    cout<<"     Enter The Question: ";
    getline(cin,line1);
    Questions.push_back(line1);
    cout<<"     Enter The Proper Answer: ";
    getline(cin,line2);
    ModelAnswer.push_back(line2);
    cout<<"     Enter Its Marks: ";
    cin>>num;
    MaxGrade.push_back(num);
    /**
    what is left here


    store in doc file                     ......... Easy
    store in All Courses File             ......... Medium
    Store In all Students File            ......... Hard
    */
    /**_________________________________________________________________________________________________________________*/
    /**_________________________________________________________________________________________________________________*/
    /**__________________________________PART 1 CHANGE IT IN DOC FILE      _____________________________________________*/
    ofstream Doc_File;
    string FileName=DrName+".txt";
    Doc_File.open(FileName.c_str(), std::ofstream::out  | std::ofstream::trunc);
    Doc_File<<DrID<<endl;
    Doc_File<<CourseName<<endl<<"__"<<endl;
    for(int i=0; i<StudentNames.size(); i++)
        Doc_File<<StudentNames[i]<<endl;
    Doc_File<<"__"<<endl;
    for(int i=0; i<Questions.size(); i++)
        Doc_File<<Questions[i]<<endl,Doc_File<<ModelAnswer[i]<<endl,Doc_File<<MaxGrade[i]<<endl;
    Doc_File<<"__";
    Doc_File.close();

    /**_________________________________________________________________________________________________________________*/
    /**_________________________________________________________________________________________________________________*/
    /**______________________________PART 1 CHANGE IT IN all courses FILE      _________________________________________*/
    vector<string>AllCourses;
    vector<string>AllCoursesData;
    vector <int > AssNum;
    int CourseIndex;
    string line;
    fstream file ("Allcourses.txt");
    while(getline(file,line) && line!="__")
        AllCourses.push_back(line);


    int number=AllCourses.size();
    int cnt=0;
    for(int i=0 ; i<number ; i++)
    {
        cnt=0;
        while(getline(file,line) && line!="__")
            AllCoursesData.push_back(line),cnt++;
        AssNum.push_back(cnt);
    }
    ///>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    for(int i=0 ; i<AllCourses.size(); i++)
        if(CourseName==AllCourses[i])
        {
            CourseIndex=i;
            break;
        }
    int start=0;
    for(int i=0 ; i<=CourseIndex; i++)
        start+=AssNum[i];


    stringstream ss;
    ss<<num;
    string str = ss.str();
    line="0 -1 "+str;
    AllCoursesData.insert(AllCoursesData.begin() + CourseIndex+start, line1);///Question Added
    AllCoursesData.insert(AllCoursesData.begin() + CourseIndex+start+1, line); /// some format in text file + Question Grade
    AllCoursesData.insert(AllCoursesData.begin() + CourseIndex+start+2, "no answer.............");
    file.close();


    file.open("Allcourses.txt", std::ofstream::out  | std::ofstream::trunc);
    for(int i=0; i<AllCourses.size(); i++)
        file<<AllCourses[i]<<endl;
    file<<"__"<<endl;
    start=0;
    int j;
    for(int i=0; i<AllCourses.size(); i++)
    {
        for(j=start ; j<AssNum[i]+start ; j++)
            file<<AllCoursesData[j]<<endl;
        start+=AssNum[i];
        if(i==CourseIndex)
        {
            file<<AllCoursesData[j]<<endl;
            file<<AllCoursesData[j+1]<<endl;
            file<<AllCoursesData[j+2]<<endl;
            start+=3;

        }
        file<<"__"<<endl;
    }
    /**_________________________________________________________________________________________________________________*/
    /**_________________________________________________________________________________________________________________*/
    /**__________________________________PART 3 CHANGE IT IN STUDENTS FILE______________________________________________*/
    for(int i=0 ; i<StudentNames.size(); i++)
    {
        string FileName=StudentNames[i]+".txt";
        LoadStudentFile(FileName);

        for(int i=0 ; i<CoursesName.size(); i++)
            if(CourseName==CoursesName[i])
            {
                CourseIndex=i;
                break;
            }
        int start=0;
        for(int i=0 ; i<=CourseIndex; i++)
            start+=AssignmentsNum[i];



        AssignmentsNum[CourseIndex]++;

        Assignments.insert(Assignments.begin() + start, line1);///Question Added
        CoursesData.insert(CoursesData.begin() + start, line); /// some format in text file + Question Grade
        StudentAnswer.insert(StudentAnswer.begin() + start, "no answer.............");

        SaveStudentFile(FileName);
    }
}
void Doctor :: ShowXstudentAnswer()
{
    while(1)
    {
        int choice,index,shift=0,grade,cnt=0,Num0fUngraded=0,NumOfSubmitted=0;
        cout<<"Choose a Student File To Show: "<<endl;
        StudentsList();
        cout<<StudentNames.size()+1<<" -  Back"<<endl;
        cin>>choice;
        if(choice==StudentNames.size()+1)
            break;
        string FileName=StudentNames[choice-1]+".txt";
        Doctor ::  LoadStudentFile(FileName);

        vector<vector<int> >Data = Doctor :: split(CoursesData);

        for(int i=0; i<CoursesName.size(); i++)
            if(CourseName==CoursesName[i])
                index=i;

        for(int i=0; i<index; i++)
            shift+=AssignmentsNum[i];

        for(int i=shift ; i<shift+AssignmentsNum[index] ; i++)
            if(Data[i][0]==1 && Data[i][1]==-1 )
                Num0fUngraded++,NumOfSubmitted++;
            else if(Data[i][0]==1)
                NumOfSubmitted++;

        cout<<"Number Of Submitted Assignments Is: "<<NumOfSubmitted<<endl;
        cout<<"Number Of Ungraded  Assignments Is: "<<Num0fUngraded<<endl;
        if(NumOfSubmitted==0)
            cout<<endl<<"There Is No Assignments To Grade"<<endl<<endl;
        else if(NumOfSubmitted >= Num0fUngraded)
        {
            if (NumOfSubmitted == Num0fUngraded)
                cout<<"All Assignments Is Graded"<<endl;
            cout<<"1- Show And Grade All Assignments: "<<endl;
            cout<<"2- Show And Grade Ungraded Only  : "<<endl;
            cout<<"3- Back: "<<endl;
            cout<<"     Enter Your Choice: ";
            cin>>choice;
            if(choice==1)
                for(int i=shift ; i<shift+AssignmentsNum[index]  ; i++)
                {
                    if(Data[i][0]==1)
                    {
                        cout<<endl<<"Assignment #     :   "<<i-shift+1<<" ";
                        cout<<"Student Answer Is:   "<<StudentAnswer[i]<<endl;
                        cout<<"Enter Student Grade: ",cin>>grade;
                        Data[i][1]=grade;

                        stringstream s1,s2,s3;
                        s1<<Data[i][0],s2<<Data[i][1],s3<<Data[i][2];
                        string str = s1.str()+" "+s2.str()+" "+s3.str();
                        CoursesData[i]=str;
                    }
                }
            else if(choice==2)
                for(int i=shift ; i<shift+AssignmentsNum[index]; i++)
                {
                    if( Data[i][0]==1 &&  Data[i][1]==-1)
                    {
                        cout<<endl<<"Assignment #     :   "<<i-shift+1;
                        cout<<"Student Answer Is:   "<<StudentAnswer[i]<<endl;
                        cout<<"Enter Student Grade: ",cin>>grade;
                        Data[i][1]=grade;

                        stringstream s1,s2,s3;
                        s1<<Data[i][0],s2<<Data[i][1],s3<<Data[i][2];
                        string str = s1.str()+" "+s2.str()+" "+s3.str();
                        CoursesData[i]=str;
                    }
                }
                cout<<endl;
            SaveStudentFile(FileName);
        }
    }
}
