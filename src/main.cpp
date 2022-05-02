#include <iostream>
#include<chrono>
#include "opencv2/opencv.hpp"
#include "similarity.hpp"

int main(void){
    std::chrono::system_clock::time_point start, end;   // 時間計測用
    double time;                                        // 実行時間
    cv::Mat temp_img; // 外部から読み込む
    cv::Mat temp_mask; // プログラム内で生成する
    cv::Mat input_img; // 外部から読み込む

    temp_img = cv::imread("image/template.bmp", cv::IMREAD_GRAYSCALE);
    input_img = cv::imread("image/input.bmp", cv::IMREAD_GRAYSCALE);

    start = std::chrono::system_clock::now();               //計測スタート
    Smr test(temp_img, input_img);
    test.SAD();

    // タイムの表示
    end = std::chrono::system_clock::now();                 // 計測終了
    time = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);
    printf("time %lf[ms]\n", time);

    printf("--> Finished!!\n");
    return 0;
}


