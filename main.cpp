/*
 * @Description: 
 * @Version: 1.0
 * @Author: ding.rongqi
 * @Date: 2023-11-08 07:20:36
 * @LastEditors: ding.rongqi
 * @LastEditTime: 2023-11-15 23:20:16
 */
#include <iostream>

#include <thread>
#include <chrono>
// #include <opencv4/opencv2/imgproc.hpp>
// #include <opencv4/opencv2/highgui.hpp>

#include "utils.hpp"

/**
 * @description: 
 * @param {int} freq
 * @return {*}
 * @author: ding.rongqi
 */
void SleepWithCout(int freq)
{
    while (true) {
        std::cout << "thread with freq: " << freq << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(freq));
    }
}

/**
 * @description: 
 * @return {*}
 * @author: ding.rongqi
 */
int main()
{
    std::cout << "hello world" << std::endl;

    std::string stamp("1234.4321");
    double stampDou;
    TimestampStr2Double(stamp, stampDou);
    std::cout << "main: " << stamp << "--" << stampDou << std::endl;

    // std::thread T1(SleepWithCout,1);
    // std::thread T2(SleepWithCout,2);

    // T1.detach();
    // T2.detach();

    // while(true){
    //     // std::this_thread::sleep_for(std::chrono::seconds(3));
    //     // std::cout<<"____ while true cout with freq 3____"<<std::endl;
    // }

    // cv::Mat img = cv::imread("test.jpg");
    // cv::imshow("src", img);
    // cv::waitKey(0);
    // cv::destroyAllWindows();

    return 0;
}