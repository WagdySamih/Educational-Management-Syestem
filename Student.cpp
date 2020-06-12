

#include "Student.h"

void Student :: UnRegister()
{
    int choice,start=0;
    cout<<endl<<"Choose The Course You Wanna Unregister From [ 1 : "<<CoursesNum<<" ] : "<<endl;
    cout<<"Enter Your Choice: ";
    cin>>choice;

    choice--;

    CoursesName.erase(CoursesName.begin()+choice);
    CoursesTeacher.erase(CoursesTeacher.begin()+choice);

    for(int i=0; i<choice; i++)
        start+=AssignmentsNum[i];
    for(int i=0; i<AssignmentsNum[choice]; i++)
    {
        ;
        Assignments.erase(Assignments.begin()+start);
        CoursesData.erase(CoursesData.begin()+start);
        StudentAnswer.erase(StudentAnswer.begin()+start);
    }
    CoursesNum--;
    AssignmentsNum.erase(AssignmentsNum.begin()+choice);
    /*********************************************************/
    /*********************************************************/

    /**        delete name from Doctor File                  */
    /*********************************************************/

}
void Student :: RegisterInCourse()
{
    string line;
    vector <int > AssNum;
    AllCourses.clear();
    AllCoursesData.clear();
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
    int check=0,choice;
    vector<int> Indices_NotExistCourses;
    for(int i=0 ; i <AllCourses.size(); i++)
    {
        check=0;
        for(int j=0; j<CoursesName.size(); j++)
            if (AllCourses[i]==CoursesName[j])
            {
                check=1;
                break;
            }
        if (check==0)
            Indices_NotExistCourses.push_back(i);
    }
    if(Indices_NotExistCourses.size()==0)
        cout<<"\n  There Is No Courses To Register In\n";
    else
    {
        cout<<"  The Unregistered Courses Are: \n";
        cout<<"  __________________________________\n";
        for(int i=0 ; i <Indices_NotExistCourses.size(); i++)
            cout<<"  "<<i+1<<" - "<<AllCourses[Indices_NotExistCourses[i]]<<" |"<<endl;
        cout<<"  __________________________________|\n";
        cout<<"\n  Choose The Course You Want To Register In [ 1 : "<<Indices_NotExistCourses.size()<<" ] (else to Back) :",cin>>choice;


        if(choice<=Indices_NotExistCourses.size())
        {
            choice=Indices_NotExistCourses[choice-1];
            int start=0;


            for(int i=0; i<choice; i++)
                start+=AssNum[i];
            CoursesName.push_back(AllCourses[choice]);

            CoursesTeacher.push_back(AllCoursesData[start]);

            for(int i=start+1; i<start+AssNum[choice]-1; i+=3)
            {
                Assignments.push_back(AllCoursesData[i]);
                CoursesData.push_back(AllCoursesData[i+1]);
                StudentAnswer.push_back(AllCoursesData[i+2]);
            }
            AssignmentsNum.push_back((AssNum[choice]-1)/3);
            Student :: CoursesNum++;
        }
    }
}
void Student :: DisplayCourses()
{
    cout<<"   _____________________________\n";
    cout<<"  |My Courses List:             |\n";
    cout<<"  |_____________________________|\n";
    for(int i=0; i<CoursesName.size(); i++)
        cout<<"  |"<<CoursesName[i]<<"|"<<endl;
    cout<<"  |_____________________________|\n";
}
void Student :: StudentChatRoom()
{
    fstream file ;
    file.open("Students_chat.txt");
    string line;
    cout<<endl<<"****************************************************"<<endl;
    cout<<"****************************************************"<<endl<<endl;
    while (getline (file,line))
        cout<<line<<endl;
    cout<<endl<<"****************************************************"<<endl;
    cout<<"****************************************************"<<endl<<endl;
    file.close();
    int x=0;
    cout<<"Press 1 To send Message 2 For Back:  ";
    fstream file1;
    file1.open("Students_chat.txt",fstream::app|fstream::app);


    // StName.erase (StName.end()-4, StName.end());
    while(cin>>x && x!=2)
    {
        if (x==1 )
        {
            cin.ignore();
            getline(cin,line);
            file1 <<StName<<": "<<line<<"\n";
        }
        cout<<"Press 1 To send Message 2 For Back: ";
    }
    file1.close();
}
void Student :: Doctors_Announcement()
{
    cout<<endl;
    fstream file ;
    file.open("DoctorsAnnouncement.txt");
    string line;
    cout<<endl<<"****************************************************"<<endl;
    cout<<"****************************************************"<<endl<<endl;
    while (getline (file,line))
        cout<<line<<endl;
    cout<<endl<<"****************************************************"<<endl;
    cout<<"****************************************************"<<endl<<endl;
    cout<<endl;
    file.close();
}
void Student :: ViewCourse()
{
    int Num,Start_Display=0;
    cout<<"Choose The Course You Want To Display [ 1 : "<<CoursesNum<<" ]\n";
    cin>>Num,Num--;
    cout<<CoursesTeacher[Num]<<endl;
    cout<<"This Course Have "<<AssignmentsNum[Num]<<" Assignments"<<endl;
    vector<vector<int> >Data = CommonBehavior::split(CoursesData);
    for(int i=0; i<Num; i++)
        Start_Display+=AssignmentsNum[i];
    for(int i=Start_Display; i<Start_Display+AssignmentsNum[Num]; i++)
    {
        cout<<"Assignment Number "<<i+1-Start_Display;
        (Data[i][0]==1)? cout<<" Submitted     ":cout<<" Not Submitted ";
        (Data[i][1]==-1)? cout<<"NA / ",cout<<Data[i][2]<<endl:cout<<Data[i][1]<<" / "<<Data[i][2]<<endl;

    }
    while(1)
    {
        int choice;
        cout<<"\n\nPlease Make a Choice\n";
        cout<<"1 - Submit a Solution\n";
        cout<<"2 - Show Assignments\n";
        cout<<"3 - Back\n";
        cout<<"Enter Choice: ",cin>>choice;
        if( choice==3)
            break;
        switch (choice)
        {
        case 1:
            SolutionSubmit( Start_Display,AssignmentsNum[Num] );
            break;
        case 2:
            ShowAssignments( Start_Display, AssignmentsNum[Num]);
            break;
        default:
            break;
        }
    }
}
void Student :: ShowAssignments(int Start_Display,int NumOfAssinments)
{
    cout<<endl;
    for(int i=Start_Display; i<Start_Display+NumOfAssinments; i++)
    {
        cout<<"Assignment Number "<<i+1-Start_Display<<": "<<endl;;
        cout<<"     "<<Assignments[i]<<endl<<endl;

    }
}
void Student :: SolutionSubmit(int Start_Display, int NumOfAssinments )
{
    string line;
    int num;
    cout<<"Choose The Number Of The Assignment You Want To send [ 1 : "<<NumOfAssinments<<" ] : ";
    cin>>num,num--;
    cout<<"Enter Your Answer (NO SPACE): ";
    cin.ignore();
    getline(cin,line);
    StudentAnswer[Start_Display+num]=line;
    CoursesData[Start_Display+num][0]='1';
}
void Student :: Total_Grades()
{
    vector<vector<int> >Data = CommonBehavior :: split(CoursesData);
    int Start_Display=0;
    for(int i=0 ; i<CoursesNum ; i++)
    {
        cout<<CoursesName[i]<<":  ";

        int total_submitted=0,total_marks=0,max_mark=0;
        for(int j=Start_Display; j<Start_Display+AssignmentsNum[i]; j++)
        {
            total_submitted+=Data[j][0];
            if(Data[j][1]>-1)
                total_marks+=total_marks+Data[j][1];
            max_mark+=Data[j][2];
        }
        Start_Display+=AssignmentsNum[i];
        cout<<"Number Of Submitted Assignments is: "<<total_submitted<<" Total Grades is "<<total_marks<<" / "<<max_mark<<endl;
    }
}
void Student ::  SignUp(string username, string password)
{
    username+=".txt";
    ofstream file;
    file.open (username.c_str());
    file<<password<<endl;
    file<<"__";
}
