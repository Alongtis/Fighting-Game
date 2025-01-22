#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <set>

using namespace std;

void clear();
bool home();
string signup();
bool isduplicate(const string &data, const string filename);
string signin();
int findLineNumber(const string& data, const string filename);
bool checklinefive(const int& line, string filename, const string& data);

string login()
{
    string name;
    bool sign;
    sign = home();
    if (sign == true)
    {
        name = signup();
        if (name == "signin")
        {
            sign = false;
        }
    }
    if (sign == false)
    {
        system("cls");
        name = signin();
    }
    return name;
}

bool home()
{
    int ch = 0;
    bool sign;
    do
    {
        sign = true;
        clear();
        cout << "  Sign Up \r>\n";
        cout << "  Sign in\n\n";
        ch = _getch();
        if (ch != 13)
        {
            sign = false;
            system("cls");
            cout << "  Sign Up \n";
            cout << "  Sign in \r>\n\n";
            clear();
            ch = _getch();
        }
        if (ch == 13)
        {
            break;
        }
        system("cls");
    } while (true);
    return sign;
}

bool isduplicate(const string &data, const string filename)
{
    ifstream MyFile(filename);
    string line;
    set<string> existingData; // store data read from file for comparison.
    while (getline(MyFile, line))
    {
        existingData.insert(line);
    }
    MyFile.close();
    return existingData.find(data) != existingData.end(); // Check if it is repeated.
}

string signup()
{
    string username, password;
    bool again;
    char yn;
    system("cls");
    cout << "Sign Up\n";
    cout << "Username\n";
    cin >> username;
    again = isduplicate(username, "username.txt");
    if (again == 0)
    {
        cout << "Password\n";
        cin >> password;
        ofstream Fileuser("username.txt", ios::app);
        Fileuser << username << endl;
        Fileuser.close();
        ofstream Filepass("password.txt", ios::app);
        Filepass << password << endl;
        Filepass.close();
    }
    else
    {
        cout << "This username already exists\n";
        cout << "Do you want to Sign in?\n";
        cout << "Sing in (Y/y): ";
        cin >> yn;
        if (yn == 'y' || yn == 'Y')
        {
            return "signin";
        }
        else
        {            
            return signup();
        }
    }
    return username;
}

void clear()
{
    while (_kbhit())
    {
        _getch();
    }
}

string signin()
{
    string username, password;
    int line;
    cout << "Sign in\n";
    cout << "Username\n";
    cin >> username;
    if (isduplicate(username, "username.txt") == 1)
    {
        line = findLineNumber(username,"username.txt");
        bool signedIn = false;
        for (int i = 0; i < 3; i++)
        {
            cout << "Password\n";
            cin >> password;

            if (checklinefive( line, "password.txt", password) == 0)
            {
                system("cls");
                cout << "Your password wrong (" << i + 1 << "/3)\n";
                cout << "--------------------------\n";
                cout << "Sign in\n";
                cout << "Username\n";
                cout << username << endl;
            }else{
                signedIn = true;
                break;
            }
        }
        if (!signedIn) {
            cout << "Failed to sign in after 3 attempts." << endl;
        }
    }

    return username;
}

int findLineNumber(const string& data, const string filename) {
    ifstream MyFile(filename);
    string line;
    int lineNumber = 1;

    // อ่านไฟล์ทีละบรรทัด
    while (getline(MyFile, line)) {
        if (line == data) {
            MyFile.close();
            return lineNumber;  // คืนหมายเลขบรรทัดที่พบข้อมูล
        }
        lineNumber++;
    }

    MyFile.close();
    return -1;  // คืนค่า -1 ถ้าไม่พบข้อมูลในไฟล์
}

bool checklinefive(const int& line, string filename, const string& data){
    ifstream Myfile(filename);
    string dataline;
    int linenumber = 1;
    for (linenumber; linenumber < line+1; linenumber++)
    {
        getline(Myfile, dataline);
        if (linenumber == line)
        {
            if (dataline == data)
            {
                Myfile.close();
                return true;
            }else {
                Myfile.close();
                return false;
            }
        }
    }
    Myfile.close();
    return false;
}
