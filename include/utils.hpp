#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <string>
#include <map>

struct Point3f
{
    /* data */
    float x = 0.;
    float y = 0.;
    float z = 1.;
};

//txt读入
int readSlotTxt(std::string txtPath, std::map<int, std::map<int, std::vector<Point3f>>>& slotsInFrame);

//时间戳str2double
void TimestampStr2Double(const std::string& timestampStr, double& timestampDou);

//