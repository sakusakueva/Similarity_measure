#ifndef SIMILARITY_HPP
#define SIMILARITY_HPP

#include <iostream>
#include"struct.hpp"

#define FNL 128
class Smr{

private:
    cv::Mat score_map;
    Point p;
    cv::Mat output_img;

    void ExtractCandidates_max();
    void ExtractCandidates_min();
    void Bounding_box();
public:

    cv::Mat temp_img; // 読み込む
    cv::Mat temp_mask; // 読み込む
    cv::Mat input_img;
    int temp_width, temp_height;
    int roop_w, roop_h;
    
    
    void SAD(); //Sum of Abusolute Difference
    void SSD(); //Sum of Squared Difference
    void NCC(); //Normalized Cross-Correlation
    void ZNCC(); //Zero-means Normalized Cross-Correlation
    void Fast_ZNCC(); //Zero-means Normalized Cross-Correlation (fast)
    

    Smr(cv::Mat temp_img, cv::Mat input_img, cv::Mat temp_mask = cv::Mat());
    ~Smr();

};

#endif