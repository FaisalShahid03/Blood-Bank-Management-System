#ifndef DONOR_H
#define DONOR_H
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
#include "citizen.h"
#define PI 3.141
#define encryptionvalue 10;

using namespace std;
class donor : public citizen
{
public:
    bool CheckDonorHealthProfile()
    {
        int criteria = 0;
        if (getgender() == 'F')
        {
            if (gethb() > 12.5 && gethb() < 20.0)
                criteria++;
        }
        else if (getgender() == 'M')
        {
            if (gethb() > 13.0 && gethb() < 20.0)
                criteria++;
        }
        if (getweight() > 45)
            criteria++;

        if (getpulserate() > 50 && getpulserate() < 100)
            criteria++;

        if (getage() >= 18 && getage() <= 65)
            criteria++;

        if (getdbp() < 180 && getdbp() > 100)
            criteria++;
        if (criteria == 5)
        {
            cout << "\nHealth Profile Verified\n";
            Sleep(1500);
            return true;
        }
        else
        {
            cout << "\nHealth Profile Not Verified\n";

            Sleep(1500);
            return false;
        }
    }
    bool checkLastDonate()
    {
        int found = 0, current = 0;
        string line;
        fstream myfile;
        myfile.open("donor.txt", ios::in);
        if (!myfile)
        {
            throw runtime_error("Cannot open file.");
        }
        while (!myfile.eof())
        {
            current++;
            getline(myfile, line);
            if (line.find(getname()) != string::npos)
            {
                found = 1;
                break;
            }
        }
        myfile.close();
        if (found == 1)
        {
            int target = current + 9;
            current = 0;
            string line, temp, temp2, filedate, currentdate;
            myfile.open("donor.txt", ios::in);
            if (!myfile)
            {
                throw runtime_error("Cannot open file.");
            }
            while (1)
            {
                current++;
                if (current == target)
                {
                    myfile >> temp >> temp2 >> filedate;
                    break;
                }
                else
                {
                    getline(myfile, line);
                }
            }
            time_t targetTime = convertDate(filedate);
            time_t currentDate = time(nullptr);
            double diffInSeconds = difftime(currentDate, targetTime);
            double seconds56 = 56 * 24 * 60 * 60;
            if (diffInSeconds > seconds56)
            {
                return true;
            }
            else
            {
                cout << "Sorry you can not donate blood, you have to wait 58 days after your last donation" << endl;
                return false;
            }
            myfile.close();
        }
    }
};

#endif