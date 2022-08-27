#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int main();
void show_data(int searchkey);
void get_data(int i);
void search_student(int searchkey);
void add_student();
void edit_student(int idnumber);
void fullscreen();
int ts;

struct student
{
  int rollno;
  string name;
  string fname;
  string cell;
  string dob;
  string address;
};

student rec[50];
int main()
{
  system("CLS");
  system("color E6");
  int choice;
  int idnumber;
  int searchkey;

  cout<<"Enter The Total Number of Student(s)- Max 50: ";
  cin>>ts;

 while(ts--)
 {
  cout<<"\n\t\tWhat do you want to do?"<<endl;
  cout<<"\n\t\tPlease choose one option from below !"<<endl;
  cout<<"\t\t----------------------"<<endl;
  cout<<"\t\t1-Add student"<<endl;
  cout<<"\t\t2-Edit student"<<endl;
  cout<<"\t\t3-Search student"<<endl;
  cout<<"\t\t4-Quit Program"<<endl;
  cout<<"\t\t----------------------"<<endl;
  cout<<"Enter your choice: ";

  cin>>choice;
  switch(choice)
 {
   case 1:
    add_student();
    break;
   case 2:
    if(rec[0].rollno==0)
   {
     cout<<"Please Add sudents first."<<endl;
     system("pause");
    main();
   }
    else
   {
     cout<<endl;
     cout<<"--------------------------------------------------------------------------------"<<endl;
     cout<<"---------------------------Student record Table---------------------------------"<<endl;
     cout<<"--------------------------------------------------------------------------------"<<endl;
     cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
     cout<<"--------------------------------------------------------------------------------"<<endl;

     for(int i=0;i<=ts;i++)
    {
      show_data(i);
     }

     cout<<"--------------------------------------------------------------------------------"<<endl;
     cout<<"Which ID number your want to edit: ";

     cin>>idnumber;

    if(idnumber>ts || idnumber<0)
    {
          cout<<"\nInvalid ID Number."<<endl;
       }
       else
    {
          edit_student(idnumber);
       }
   }
   break;

  case 3:
    if(rec[0].rollno==0)
   {
     cout<<"Please Add sudents first."<<endl;
     system("pause");
     main();
    }
    else
   {
     cout<<"Enter roll_no of student you want to search: ";
     cin>>searchkey;
     search_student(searchkey);}
     break;
   case 4:
    return 0;
    break;
   default:
    cout<<"Invalid number."<<endl;
    system("pause");
  main();
  }
 }
  return 0;
}


void get_data(int i)
{
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Enter the student "<<i+1<< " data :"<<endl;
    cout<<"-------------------------------------------------------"<<endl;


  cout<<"Enter student roll number in  format(1XXX): ";
  cin>>rec[i].rollno;
  cout<<"Enter student name: ";
  cin>>rec[i].name;
  cout<<"Enter student's Father name: ";
  cin>>rec[i].fname;
  cout<<"Enter student's cell phone number: ";
  cin>>rec[i].cell;
  cout<<"Enter student's Date of Birth(dd/mm/yyyy): ";
  cin>>rec[i].dob;
  cout<<"Enter student's Address: ";
  cin>>rec[i].address;
}

void show_data(int searchkey)
{
  int i=searchkey;
  cout<<i<<"    ";
  cout<<rec[i].rollno<<"   ";
  cout<<rec[i].name<<"     ";
  cout<<rec[i].fname<<"\t";
  cout<<rec[i].cell<<"   ";
  cout<<rec[i].dob<<"   ";
  cout<<rec[i].address<<"\n\n";
}

void search_student(int searchkey)
{
  for(int i=0;i<=ts;i++)
 {
   if(rec[i].rollno==searchkey)
  {
    cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
    show_data(i);
   }
  }
}

void add_student()
{
  for(int i=0;i<=ts;i++)
 {
    get_data(i);
  }
  system("CLS");
  cout<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"---------------------------Student record Table---------------------------------"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
  cout<<"--------------------------------------------------------------------------------"<<endl;

  for(int i=0;i<=ts;i++)
 {
    show_data(i);
  }
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"---------------------------------FINISH-----------------------------------------"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  system("pause");

  main();
}

void edit_student(int idnumber)
{
  for(int i=0;i<=ts;i++)
 {
   if(idnumber==i)
  {
    cout<<"\nExisted information about this record.\n\n";
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
    cout<<"--------------------------------------------------------------------------------"<<endl;
    show_data(i);
    cout<<"\n\nEnter new data for above shown record.\n\n";
    get_data(i);
    cout<<"\n\nRecord updated successfully."<<endl;
    system("pause");
    main();
   }
  }
}
