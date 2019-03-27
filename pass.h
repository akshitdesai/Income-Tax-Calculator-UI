
using namespace std;
void changepass()
{
    clearWindow();
    print_heading("Change Password");
    SetColor(45);
    char b[11],str[11],s1[11],s2[11],c;
    int i=0;
    string line;
    ifstream myfile ("root.txt");
    if (myfile.is_open() && getline (myfile,line))
    {
        myfile.close();
    }
    else
    {
        ofstream pass ("root.txt");
        if (pass.is_open())
        {
           pass << "root\n";
           pass.close();
        }
        else
            cout << "Unable to open file";
        line="root";
    }
    strcpy(b,line.c_str());

    gotoxy(37,11);printf("USERNAME:- ADMIN");
    gotoxy(37,12);printf("OLD PASSWORD:- ");

    while (i<=9){
        str[i]=getch();
        c=str[i];
        if(c==13) break;
        else printf("*");
        i++;
    }
    str[i]='\0';
    i=0;
    strcpy(s1,str);
    if(strcmp(b,s1)==0)
    {
        gotoxy(37,14);printf("NEW PASSWORD:- ");
        while (i<=9){
            str[i]=getch();
            c=str[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        str[i]='\0';
        i=0;
        strcpy(s1,str);

        gotoxy(37,15);printf("RENTER PASSWORD:- ");
        while (i<=9){
            str[i]=getch();
            c=str[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        str[i]='\0';
        i=0;
        strcpy(s2,str);
        if(strcmp(s1,s2)==0)
        {
            strcpy(b,s1);
            line=b;
            ofstream pass ("root.txt");
            if (pass.is_open())
            {
               pass << line <<"\n";
               pass.close();
            }

            gotoxy(37,17);printf("Password Changed Successfully!");
        }
        else
            {gotoxy(37,17);printf("Passwords didn't match!");}
    }
    else
        {gotoxy(37,14);printf("You entered incorrect Password");}
}


bool get_password()
{

    char b[11];
    string line;
    ifstream myfile ("root.txt");
    if (myfile.is_open() && getline (myfile,line))
    {
        myfile.close();
    }
    else
    {
        ofstream pass ("root.txt");
        if (pass.is_open())
        {
           pass << "root\n";
           pass.close();
        }
        else
            cout << "Unable to open file";
        line="root";
    }

    strcpy(b,line.c_str());
    int i=0;
    char str[10],v[10],c;
    fflush(stdin);
    login:
    while (i<=9){
        str[i]=getch();
        c=str[i];
        if(c==13) break;
        else printf("*");
        i++;
    }
    str[i]='\0';
    i=0;
    strcpy(v,str);
    if(strcmp(v,b)==0)
        {SetColor(28);gotoxy(25,15);printf("\n\tYou are loged in successfully");return true;}
    else
        {SetColor(28);gotoxy(25,15);printf("You entered incorrect password");return false;}
}


bool use_pass_field()
{
    for(int j=15;j<17;j++)
    {
        for(int i=19;i<60;i++)
            {gotoxy(i,j);printf(" ");}
    }
    int use;
    char pass[10];
    SetColor(28);
    gotoxy(25,9);printf("The database is password protected.");
    gotoxy(25,10);printf("Enter Valid ADMIN password");
    SetColor(17);
    gotoxy(30,12);printf("USERNAME:- ADMIN");
    gotoxy(30,13);printf("PASSWORD:- ");
     for(int i = 41; i < 52; i++)
                {gotoxy(i,13);printf(" ");}
    gotoxy(41,13);
    if(get_password())
        return true;
    else
        return false;
}
