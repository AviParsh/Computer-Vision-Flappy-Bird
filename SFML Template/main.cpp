
#include <iostream>
#include "Game.hpp"
#include "DEFINITIONS.hpp"


#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/objdetect/objdetect.hpp>
cv::Rect palmDetect(cv::VideoCapture cap,cv::CascadeClassifier closed_palm_cascade,cv::Rect lastPos,bool found);


int main(){
    
    avi::Game(SCREEN_WIDTH,SCREEN_HEIGHT,"Flappy Bird");
    
//    cv::CascadeClassifier closed_palm_cascade;
//    closed_palm_cascade.load(CLOSED_PALM_FILEPATH);
//    cv::VideoCapture cap;
//    cap.open(0);
//    bool found=false;
//    cv::Rect lastPos;
//
//
//    while(cv::waitKey(1)){
//        lastPos = palmDetect(cap,closed_palm_cascade,lastPos,found);
//
//        if(found)
//        {
//            std::cout<<"Found is true"<<std::endl;
//            //found = true;
//
//        }
//
//
//    }

}


cv::Rect palmDetect(cv::VideoCapture cap,cv::CascadeClassifier closed_palm_cascade,cv::Rect lastPos,bool found){
 
    using namespace cv;
    using namespace std;
 //VideoCapture cap;
   // cap.open(0);
    

 if (!cap.isOpened()) {
     cout << "Could not open Camera stream!";
     return cv::Rect();
     
 }

 // Load open_palm cascade and eye cascade files (.xml file) The XML files should be
 // in the same directory as the project.

 



 if (closed_palm_cascade.empty()) {
     cout << "Could not load closed_palm configuration file! "
         "Check directory! " << endl << "Press Q to Quit!" << endl;
     while (char(waitKey(0)) != 'q') {}
     return cv::Rect();
 }

 // Start the open_palm and eye detection phase
 //create in input manager constructor
 vector<Rect> closed_palms;

 //while (char(waitKey(1)) != 'q' && cap.isOpened()) {
     Mat frame;
    Mat subframe;
     cap >> frame;
     if (frame.empty()) {
         cout << "Video over!";
         //break;
     }

    
    if(found)
    {
        subframe = frame(lastPos);
        
        

        // Detect all the open_palms.
            closed_palm_cascade.detectMultiScale(subframe, closed_palms, 1.1, 4, 0, Size(110, 110),Size(500,500));
        
    }
    else
    {
        closed_palm_cascade.detectMultiScale(frame, closed_palms, 1.1, 4, 0, Size(110, 110),Size(500,500));

    }
    
    
    cv::Rect newPos;
    if (closed_palms.size() != 0) {
        found=true;
                   for (int i = 0; i < closed_palms.size(); i++) {

                      // cout << "=============Detected a closed_palm!=============" << endl;

                       int p1x,p1y,p2x,p2y;
                       
                       // Top left and bottom right points of rectangle.
                       Point closed_palm_rect_p1(closed_palms[i].x, closed_palms[i].y);
                       Point closed_palm_rect_p2(closed_palms[i].x + closed_palms[i].width, closed_palms[i].y + closed_palms[i].height);
                       
                       if(closed_palms[i].x-120<0)
                       {
                           p1x = closed_palms[i].x;
                       }else{
                           p1x = closed_palms[i].x-120;
                       }
                       
                       if(closed_palms[i].y-120<0)
                       {
                           p1y = closed_palms[i].y;
                       }else{
                           p1y = closed_palms[i].y-120;
                       }
                       
//                       if(closed_palms[i].y+closed_palms[i].height>)
//                       {
//                           p1y = closed_palms[i].y;
//                       }
//                       if(closed_palms[i].y-120<0)
//                       {
//                           p1y = closed_palms[i].y;
//                       }
                       Point largeRectp1(p1x,p1y);
                       Point largeRectp2(closed_palms[i].x + closed_palms[i].width+120, closed_palms[i].y + closed_palms[i].height+120);
                       
                       
                       // Draw the rectangle in the image.
                       rectangle(frame, closed_palm_rect_p1, closed_palm_rect_p2, Scalar(0, 255, 0));
                       putText(frame, "Closed Palm", closed_palm_rect_p1, FONT_HERSHEY_SIMPLEX,
                           1, Scalar(0, 255, 0), 1, 5, false);
                       
                       cv::Rect newPos(largeRectp1,largeRectp2);
                       
                       
                       rectangle(frame,largeRectp1,largeRectp2,Scalar(255,0,0));
                       
                       subframe = frame(newPos);
                       
                   }

        
                   
                   
               }
    else{
        found = false;
        
    }
    
    
    //rectangle slightly larger than closed palm area
    if(found){
        imshow("Video Capture", subframe);
        return newPos;

    }
    
     
     imshow("Video Capture", frame);
    
    return cv::Rect();
    
}

