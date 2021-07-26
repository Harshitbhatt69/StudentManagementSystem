#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
using namespace std;
map<int, pair<string, string>> m;
void record(int roll, string name, string address);
class StudentManagementSystem
{
public:
    void MainMeat()
    {
        system("cls");
        ShowHeading();
        cout << endl << endl;
        while (true) {
            system("cls");
            ShowOptionsHomeScreen();
            cout << "\t\t\t\t\t\t\t\t\t";
            char action = getch();
            if (action == '1')
            {
                //writing in file
                addingDetails();
                // cout << "Adding file..." << endl;
            }
            else if (action == '2')
            {
                //reading from file
                // viewStudentDetails();
                finalDeletion();
                // cout << "Reading file..." << endl;
            }
            else if (action == '3')
            {
                //deleting student from roll no.
                deleteStudentDetails();
                cout << "Deleting file..." << endl;
            }
            else if (action == '4')
            {
                exit(0);
            } else
            {
                cout << "Invalid input...";
            }
        }
    }
    void addingDetails()
    {
        system("cls");
        ShowHeading();

        // string ch;
        // ifstream in("list.txt");


        ofstream studentList;
        studentList.open("list.txt", ios_base::app);
        string name, address;
        string rollno, space = "             ";
        int rno;
        cout << "\t\t\t\t\t\t\t\t\tRoll no: ";
        cin >> rno;
        fflush(stdin);
        cout << "\t\t\t\t\t\t\t\t\tName: ";
        getline(cin, name);
        fflush(stdin);
        cout << "\t\t\t\t\t\t\t\t\tAddress: ";
        getline(cin, address);
        fflush(stdin);
        //writing data to file
        rollno = (rno - '0');
        string final = rollno + space + name + space + address + "\n";
        studentList << final;
        studentList.close();
        //adding to set
        record(rno, name, address);

        //recurtion call
        cout << "\t\t\t\t\t\t\t\t\tDo you want to add anothor data?(Y/N)" << endl;
        while (true) {
            cout << "\t\t\t\t\t\t\t\t\t";
            char flag = getch();
            if (flag == 'Y' or flag == 'y')
                addingDetails();
            else if (flag == 'n' or flag == 'N')
                return;
        }

    }
    void viewStudentDetails()
    {
        system("cls");
        ShowHeading();
        ifstream in("list.txt");
        stringstream sstr;
        while (in >> sstr.rdbuf());
        cout << sstr.str() << endl;
        in.close();

        cout << "Press Q to exit";
        while (true) {
            char quit = getch();
            if (quit == 'Q' or quit == 'q')
                return;
        }
    }
    void finalDeletion()
    {
        for (auto ch : m)
        {
            cout << ch.first << " ";
            cout << ch.second.first << endl;
            // cout << ch.second.second << endl;
        }
    }
    void deleteStudentDetails()
    {
        system("cls");
        ShowHeading();
        int roll;
        cout << "\t\t\t\t\t\t\t\t\tInput Student's Roll number: ";
        cin >> roll;
        char sure;
        cout << "\t\t\t\t\t\t\t\t\tAre you sure you want to delete?(Y?N)";
        while (true) {
            sure = getch();
            if (sure == 'Y' or sure == 'y')
            {
                finalDeletion();
                cout << "\n\t\t\t\t\t\t\t\t\tRecord deleted successfully\n\t\t\t\t\t\t\t\t\t";
                system("pause");
                return;
            }
            else if (sure == 'N' or sure == 'n')
            {
                cout << "\n\t\t\t\t\t\t\t\t\tDeleting process cancelled !\n\t\t\t\t\t\t\t\t\t";
                system("pause");
                return;
            }
        }
    }
    void ShowHeading()
    {
        cout << "\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~ Student MANAGEMENT SYSTEM ~~~~~~~~~~~~~~~~~~~~\n\t\t\t\t\t\t\t\t\t\t\t\t\tBy: Harshit Bhatt\n";
    }
    void ShowOptionsHomeScreen()
    {
        system("cls");
        ShowHeading();
        cout << "\t\t\t\t\t\t\t\t\tSelect one option" << endl;
        cout << "\t\t\t\t\t\t\t\t\t1.Add Student Record\n" << "\t\t\t\t\t\t\t\t\t2.View Student Record\n" << "\t\t\t\t\t\t\t\t\t3.Delete Student Record\n" << "\t\t\t\t\t\t\t\t\t4.Quit" << endl;
    }
    void pass() {
        system("cls");
        ShowHeading();
        int i = 0;
        char s[21], str[21] = "Admin123", ch;
        cout << "\n\t\t\t\t\t\t\t\t\tEnter Password: ";
        while (true) {
            ch = getch();
            if (ch == 13) {
                s[i] = '\0';
                break;
            }
            else if (ch == 8 && i > 0) {
                i--;
                cout << "\b \b";
            }
            else {
                cout << "*";
                s[i] = ch;
                i++;
            }
        }
        ifstream inf("password.txt");
        inf >> str;
        inf.close();

        for (i = 0; s[i] == str[i] && s[i] != '\0' && str[i] != '\0'; i++);
        if (s[i] == '\0' && str[i] == '\0') {
            system("cls");
            MainMeat();
        }
        else {
            cout << "\n\n\t\t\t\t\t\t\t\t\tWRONG PASSWORD!!\n\t\t\t\t\t\t\t\t\t";
            system("PAUSE");
            system("cls");
            start();
        }
    }
    void start() {
        system("cls");
        ShowHeading();
        cout << "\n\t\t\t\t\t\t\t\t\t>>> LOGIN MENU <<<\n";;
        cout << "\n\t\t\t\t\t\t\t\t\t1. Admin User\n\t\t\t\t\t\t\t\t\t2. Exit\n";
        cout << "\t\t\t\t\t\t\t\t\t";

        while (true) {
            char quit = getch();
            if (quit == '1')
                pass();
            else if (quit == '2')
                exit(0);
        }
    }
};
void record(int roll, string name, string address)
{
    m[roll] = make_pair(name, address);
}
int main()
{
    StudentManagementSystem st;
    st.start();
    return 0;
}