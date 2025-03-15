#ifndef LOGIN_H
#define LOGIN_H
#include <string>


using namespace std;

void clear();
bool home();
string signup();
bool isduplicate(const string &data, const string filename);
string signin();
int findLineNumber(const string &data, const string filename);
bool checklinefive(const int &line, string filename, const string &data);
string login();


#endif