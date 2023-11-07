#include <algorithm>

#include "utils.hpp"

//txt读入
int readSlotTxt(const std::string txtPath, std::map<int, std::map<int, std::vector<Point3f>>>& slotsInFrame)
{
    char line[1024]; //字符数组，用于读取,这里假设每次读取的整数不超过1024个字符
    std::ifstream infile;
    infile.open(txtPath, std::ios::in); //打开文件
    if (!infile.is_open()) {
        std::cout << "无法打开文件: " << txtPath << std::endl;
        return -1;
    }

    int lastFrameId(-1);
    std::map<int, std::vector<Point3f>> slot;
    while (infile.getline(line, sizeof(line))) {
        std::string line_ = std::string(line);
        int num_space = std::count(line_.begin(), line_.end(), ' ');

        std::istringstream iss(line_);
        int frameId, sId;
        Point3f p1, p2, p3, p4;
        iss >> frameId;
        iss >> sId;
        iss >> p1.x;
        iss >> p1.y;
        iss >> p2.x;
        iss >> p2.y;
        iss >> p3.x;
        iss >> p3.y;
        iss >> p4.x;
        iss >> p4.y;
        if (frameId != lastFrameId) {
            slot.clear();
            lastFrameId = frameId;
        }

        std::vector<Point3f> ps = {p1, p2, p3, p4};
        slot[sId] = ps;
        slotsInFrame[frameId] = slot;
    }
    infile.close();
    return 0;
}

//时间戳str2double
void TimestampStr2Double(const std::string& timestampStr, double& timestampDou)
{
    //input(string): xxxxx.xxxxx ; output(double): xxxxx.xxxxx
    auto dotIndex = timestampStr.find(".");

    std::string secStr = timestampStr.substr(0, dotIndex);
    std::string nsecStr = timestampStr.substr(dotIndex + 1, -1);

    // std::cout << timestampStr << " sec: " << (secStr) << " nsec: " << (nsecStr) << std::endl;

    timestampDou = std::stod(timestampStr);
}