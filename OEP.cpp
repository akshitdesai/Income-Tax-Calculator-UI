#include<bits/stdc++.h>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include "ui.h"
#include "pass.h"


using namespace std;

class student{
    public:
    char ID[15];
    char name[20];
    long long income;
    int age;
    int Class;
    long unsigned int phone_no;
};

student stu;

void add_student(){
    clearWindow();
    print_heading("Add Record");
    int print = 37;
    FILE *fp;
    fp = fopen("record.txt","ab+");
    SetColor(45);
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }else{
        fflush(stdin);
        gotoxy(print,10);printf("ID: ");gets(stu.ID);
        //here you can confirms the ID
        gotoxy(print,12);printf("Name: ");gets(stu.name);
        gotoxy(print,14);printf("Income: ");scanf("%lld",&stu.income);
        gotoxy(print,16);printf("Age: ");scanf("%d",&stu.age);
        gotoxy(print,18);printf("Class: ");scanf("%d",&stu.Class);
        gotoxy(print,20);printf("Phone Number: ");scanf("%ld",&stu.phone_no);
        fwrite(&stu, sizeof(stu), 1, fp);
        gotoxy(40,22); printf("The record is sucessfully added");
    }
    SetColor(28);
    fclose(fp);
    return;
}

void search_student(){
    clearWindow();
    print_heading("Search Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0;
    gotoxy(37,10);printf("Enter ID to Search: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp) == 1){
        if(strcmp(s_id,stu.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        gotoxy(37,12);printf("The record is Found");
        gotoxy(37,14);printf("ID: %s",stu.ID);
        gotoxy(37,15);printf("Name: %s",stu.name);
        gotoxy(37,16);printf("Income: %d",stu.income);//printf("Income: ********");
        gotoxy(37,17);printf("Age: %d",stu.age);
        gotoxy(37,18);printf("Class: %d",stu.Class);
        gotoxy(37,19);printf("Phone No: %ld",stu.phone_no);
    }else{
        gotoxy(37,12);printf("Sorry, No record found in the database");
    }
    SetColor(28);
    fclose(fp);
    return;
}

void mod_student(){
    clearWindow();
    print_heading("Modify Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb+");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fflush(stdin);
            gotoxy(print,12);printf("ID: ");gets(stu.ID);
            gotoxy(print,13);printf("Name: ");gets(stu.name);
            gotoxy(print,14);printf("Income: ");scanf("%lld",&stu.income);
            gotoxy(print,15);printf("Age: ");scanf("%d",&stu.age);
            gotoxy(print,16);printf("Class: ");scanf("%d",&stu.Class);
            gotoxy(print,17);printf("Phone Number: ");scanf("%ld",&stu.phone_no);
            fseek(fp,-sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        gotoxy(print, 12);printf("Sorry, No record found in the database");
    }
    fclose(fp);
    SetColor(28);
    return;
}

double calculate_tax(long long inc,int ag,int z){

    double tax;
    if((inc<=250000 && ag<=60) || (inc<=300000 && 60<ag && ag<=80)|| (inc<=500000 && ag>80))
        return 0;
    else if(z==2)
    {
         if(60<ag && ag<=80)
        {
            if(300000<inc && inc<=500000)
                tax=double(inc)*0.05;
            else if(500000<inc && inc<=1000000)
                tax=double(inc)*0.2;
            else
                tax=double(inc)*0.3;
        }
        else
        {
            if(500000<inc && inc<=1000000)
                tax=double(inc)*0.2;
            else
                tax=double(inc)*0.3;
        }

        return tax*0.04;
    }

    else
    {
        if(ag<=60)
        {
            if(250000<inc && inc<=500000)
                tax=double(inc)*0.05;
            else if(500000<inc && inc<=1000000)
                tax=double(12500)+double(inc-500000)*0.2;
            else
                tax=double(112500)+double(inc-1000000)*0.3;
        }
        else if(60<ag && ag<=80)
        {
            if(300000<inc && inc<=500000)
                tax=double(inc)*0.05;
            else if(500000<inc && inc<=1000000)
                tax=double(inc)*0.2;
            else
                tax=double(inc)*0.3;
        }
        else
        {
            if(500000<inc && inc<=1000000)
                tax=double(inc)*0.2;
            else
                tax=double(inc)*0.3;
        }
    }
    if(inc>5000000 && inc<=10000000)
        tax+=(tax*0.1);
    else
        tax+=(tax*0.15);
    return tax;
}
void generate_tax(){

    clearWindow();
    print_heading("Search Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0;
    gotoxy(37,10);printf("Enter ID to Search: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp) == 1){
        if(strcmp(s_id,stu.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1)
    {
            long long x=stu.income;
            int y=stu.age;
            int z=stu.Class;
            double tax1=calculate_tax(x,y,z);
            gotoxy(37,12);printf("The record is Found");
            if(tax1!=0)
            {
                gotoxy(37,14);printf("Tax on your income  %ld is:",x);
                gotoxy(43,16);std::cout<<tax1<<" Rupees";
            }
            else
                {gotoxy(43,15);printf("NO TAX! Enjoy!");}
    }
    else{
        gotoxy(37,12);printf("Sorry, No record found in the database");
    }
    SetColor(28);
    fclose(fp);
    return;
}

void delete_student()
{
    int deleteflag=1;
    clearWindow();
    print_heading("Delete Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp, *temp;
    fp = fopen("record.txt","rb");
    temp = fopen("temp.txt", "wb");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) != NULL)
            fwrite(&stu,sizeof(stu),1,temp);

        if(strcmp(s_id, stu.ID) == NULL)
            deleteflag=0;
    }
    fclose(fp);
    fclose(temp);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(37,12);
    if(deleteflag==0)
        printf("The record is sucessfully deleted");
    else
        printf("Sorry, No record found in the database");
    SetColor(28);
    return;
}




void main_window(){
    int choice;
    SetColor(28);
    int x = 2;
    while(1){
        gotoxy(x,8);printf("1. Add Taxpayee");
        gotoxy(x,10);printf("2. Search Taxpayee");
        gotoxy(x,12);printf("3. Modify Taxpayee Record");
        gotoxy(x,14);printf("4. Calculate Tax");
        gotoxy(x,16);printf("5. Delete Taxpayee Record");
        gotoxy(x,18);printf("6. Change password");
        gotoxy(x,20);printf("7. Exit");
        gotoxy(x,22);printf("Enter your choice:  ");
        gotoxy(21,22);
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_student();
                break;
            case 2:
                search_student();
                break;
            case 3:
                mod_student();
                break;
            case 4:
                generate_tax();
                break;
            case 5:
                delete_student();
                break;
            case 6:
                changepass();
                break;
            case 7:
                gotoxy(0,25);
                exit(0);
                break;
            default:
                break;
        }

    }

}

int main()
{
    loginw();
    x:
    if(use_pass_field())
    {
        window();
        ClearConsoleToColors(17,15);
        SetConsoleTitle("Code_stromer rocks..");
        window();

        main_window();
        return 0;
    }
    else
    {
        char ch;
        SetColor(28);
        gotoxy(25,16);printf("Do you want to retry? (y/n):");
        fflush(stdin);
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
            goto x;
    }
}

