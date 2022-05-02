#include <math.h>
#include <opencv2/opencv.hpp>
#include "similarity.hpp"

Smr::Smr(cv::Mat temp_img, cv::Mat input_img, cv::Mat temp_mask){
    this->temp_img = temp_img;
    this->temp_height = temp_img.rows;
    this->temp_width = temp_img.cols;
    this->input_img = input_img;

    if(temp_mask.empty())   this->temp_mask = cv::Mat::ones(temp_img.rows, temp_img.cols, CV_8U);

    this->roop_h = input_img.rows-temp_height+1;
    this->roop_w = input_img.cols-temp_width+1;

    this->score_map = cv::Mat(roop_h, roop_w, CV_32S, cv::Scalar(0));
}
Smr::~Smr(){

}

void Smr::ExtractCandidates_min(){
    int min = 9999;
    // Roop (input image)
    for(int jj = 0; jj < this->roop_h; jj++){
        for(int ii = 0; ii < this->roop_w; ii++){
            if(min > this->score_map.at<int>(jj, ii)){
                min = this->score_map.at<int>(jj,ii);
                this->p.x = ii;
                this->p.y = jj;
            }
        }
    }
    return;
}

void Smr::Bounding_box(){
    cv::cvtColor(input_img, output_img, CV_GRAY2BGR);
    cv::Rect rect1(p.x-1, p.y-1, temp_width+2, temp_height+2);
    cv::Rect rect2(p.x+1, p.y+1, temp_width-2, temp_height-2);
    cv::rectangle(this->output_img, rect1, cv::Scalar(0,255,255), 1);
    cv::rectangle(this->output_img, rect2, cv::Scalar(0,255,255), 1);
    cv::imwrite("result/output.bmp", this->output_img);
    return;
}

void Smr::ZNCC(){
    unsigned char in_val, temp_val;

    // Roop (input image)
    for(int jj = 0; jj < this->input_img.rows-temp_height+1; jj++){
        for(int ii = 0; ii < this->input_img.cols-temp_width+1; ii++){
            // Roop (ROI)
            for(int j = 0; j < this->temp_height; j++){
                for(int i = 0; i < this->temp_width; i++){
                    in_val = this->input_img.at<unsigned char>(jj+j, ii+i);
                    temp_val = this->temp_mask.at<unsigned char>(j, i) * this->temp_img.at<unsigned char>(j, i);
                }
            }
        }
    }
    return;
}

void Smr::SAD(){
    unsigned char in_val, temp_val;

    // Roop (input image)
    for(int jj = 0; jj < this->input_img.rows-temp_height+1; jj++){
        for(int ii = 0; ii < this->input_img.cols-temp_width+1; ii++){
            // Roop (ROI)
            for(int j = 0; j < this->temp_height; j++){
                for(int i = 0; i < this->temp_width; i++){
                    in_val = this->input_img.at<unsigned char>(jj+j, ii+i);
                    temp_val = this->temp_mask.at<unsigned char>(j, i) * this->temp_img.at<unsigned char>(j, i);
                    this->score_map.at<int>(jj, ii) += abs(in_val - temp_val);
                }
            }
        }
    }
    ExtractCandidates_min();
    Bounding_box();
    return;
}