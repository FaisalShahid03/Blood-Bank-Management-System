#ifndef CITIZEN_H
#define CITIZEN_H
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "user.h"
#include "verification.h"

#define PI 3.141
#define encryptionvalue 10;

using namespace std;
class citizen : public user
{
private:
    string name;
    int age;
    char gender;
    float weight;
    string bloodtype;
    float hb;
    float pulse;
    float systolicbp;
    float diastolicbp;

public:
    citizen() : name(" "), age(0), gender(' '), weight(0.0), bloodtype(" "), hb(0.0), pulse(0), systolicbp(0.0), diastolicbp(0.0) {}
    citizen(string n, int a, char g, float w, string bt, float hb, float pr, float sbp, float dbp) : name(n), age(a), gender(g), weight(w), bloodtype(bt), hb(hb), pulse(pr), systolicbp(sbp), diastolicbp(dbp) {}

    void setname(string n) { name = n; }

    void setage(int age)
    {
        int flag = 0;
        do
        {
            if (age > 0)
            {
                this->age = age;
                flag = 1;
            }
            else
            {
                cout << "Please enter a number greater than 0 " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> age;
            }
        } while (flag == 0);
    }
    void setgender(char gender)
    {
        int flag = 0;
        do
        {
            if (gender == 'M' || gender == 'F')
            {
                this->gender = gender;
                flag = 1;
            }
            else
            {
                cout << "Please enter M or F only " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> gender;
            }
        } while (flag == 0);
    }
    void setweight(float weight)
    {
        int flag = 0;
        do
        {
            if (weight > 0)
            {
                this->weight = weight;
                flag = 1;
            }
            else
            {
                cout << "Please enter a number greater than 0 " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> weight;
            }
        } while (flag == 0);
    }
    void setpulse(int pulse)
    {
        int flag = 0;
        do
        {
            if (pulse > 0)
            {
                this->pulse = pulse;
                flag = 1;
            }
            else
            {
                cout << "Please enter a number greater than 0 " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> pulse;
            }
        } while (flag == 0);
    }
    void sethb(float hb)
    {
        int flag = 0;
        do
        {
            if (hb > 0)
            {
                this->hb = hb;
                flag = 1;
            }
            else
            {
                cout << "Please enter a number greater than 0 " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> hb;
            }
        } while (flag == 0);
    }
    void setsbp(float SystolicBP)
    {
        int flag = 0;
        do
        {
            if (SystolicBP > 0)
            {
                systolicbp = SystolicBP;
                flag = 1;
            }
            else
            {
                cout << "Please enter a number greater than 0 " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> SystolicBP;
            }
        } while (flag == 0);
    }
    void setdbp(float DiastolicBP)
    {
        int flag = 0;
        do
        {
            if (DiastolicBP > 0)
            {
                diastolicbp = DiastolicBP;
                flag = 1;
            }
            else
            {
                cout << "Please enter a number greater than 0 " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> DiastolicBP;
            }
        } while (flag == 0);
    }
    void setbloodtype(string bloodgroup)
    {
        int flag = 0;
        do
        {
            if (bloodgroup == "O+" || bloodgroup == "O-" || bloodgroup == "A+" || bloodgroup == "A-" || bloodgroup == "B+" || bloodgroup == "B-" || bloodgroup == "AB+" || bloodgroup == "AB-")
            {
                bloodtype = bloodgroup;
                flag = 1;
            }
            else
            {
                cout << "This blood group doesn't exists.Please enter a correct blood group " << endl;
                cin >> bloodgroup;
            }
        } while (flag == 0);
    }

    string getname() { return name; }
    int getage() { return age; }
    char getgender() { return gender; }
    float getweight() { return weight; }
    string getbloodtype() { return bloodtype; }
    float gethb() { return hb; }
    float getpulserate() { return pulse; }
    float getsbp() { return systolicbp; }
    float getdbp() { return diastolicbp; }

    void registration()
    {
        string user, pass;
        cout << "\t\t\tUsername: ";
        cin >> user;
        if (verification::checkUsername(user))
        {
            set_username(user);
        }
        else
        {
            cout << "\t\t\tUsername already exist.Please select unique username" << endl;
            return;
        }
        cout << "\t\t\tPassword: ";
        char ch;
        while (true)
        {
            ch = _getch();
            if (ch == '\r')
                break;
            if (ch == '\b' && !pass.empty())
            {
                pass.pop_back();
                cout << "\b \b";
            }
            else
            {
                pass.push_back(ch);
                cout << '*';
            }
        }
        if (verification::checkPassword(pass))
        {
            set_password(pass);
        }
        else
        {
            cout << "\t\t\tPassword already exist.Please select unique password" << endl;
            return;
        }
        // yahan pr check krna hai k username or pass pehle se to nahi hai kisi ka
        pass = encryption(pass);
        fstream my_file;
        my_file.open("citizen.txt", ios::out | ios::app);
        if (!my_file)
        {
            throw runtime_error("Cannot open file.");
        }
        my_file << user << " " << pass << endl;
        my_file.close();
    }
    bool login()
    {
        int found = 0;
        string cuser, cpass;
        string user, pass;
        cout << "\t\t\tUsername: ";
        cin >> user;
        set_username(user);
        cout << "\t\t\tPassword: ";
        char ch;
        while (true)
        {
            ch = _getch();
            if (ch == '\r')
                break;
            if (ch == '\b' && !pass.empty())
            {
                pass.pop_back();
                cout << "\b \b";
            }
            else
            {
                pass.push_back(ch);
                cout << '*';
            }
        }
        set_password(pass);

        fstream my_file;
        my_file.open("citizen.txt", ios::in);
        if (!my_file)
        {
            throw runtime_error("Cannot open file.");
        }
        while (!my_file.eof())
        {
            my_file >> cuser >> cpass;
            cpass = decryption(cpass);
            if (cuser == get_username() && cpass == get_password())
            {
                cout << "\n\n\t\t\tLogging In...";
                Sleep(1000);
                return true;
                found = 1;
            }
        }
        if (found==0)
        {
            cout << "Invalid Username or Password" << endl;
            pressKey(); // yaha pr bhi exception lag sakti
            return false;
        }
    }
};

#endif