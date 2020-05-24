

#include "InputManager.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <vector>
#include <iostream>
#include "DEFINITIONS.hpp"
namespace avi{

    

    InputManager::InputManager()
    {
        closed_palm_cascade.load(CLOSED_PALM_FILEPATH);
        std::cout<<"input manager constructor"<<std::endl;
        cap.open(0);
        found = false;
        
        
    }

    bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
        {
            if(sf::Mouse::isButtonPressed(button))
            {
                sf::IntRect tempRect(object.getPosition().x,object.getPosition().y,object.getGlobalBounds().width,object.getGlobalBounds().height);
                
                if(tempRect.contains(sf::Mouse::getPosition(window)))
                {
                    return true;
                }
            }
                
            return false;
        }

    sf::Vector2i InputManager::GetMousePosition( sf::RenderWindow &window)
        {
            return sf::Mouse::getPosition(window);
            
        }

cv::Rect InputManager::IsPalmClosed()
    {

        if (!cap.isOpened()) {
            std::cout << "Could not open Camera stream!";
            return cv::Rect();
        }

        
        if (closed_palm_cascade.empty()) {
            std::cout << "Could not load closed_palm configuration file! "
                "Check directory! " << std::endl << "Press Q to Quit!" << std::endl;
            return cv::Rect();
        }

        // Start the open_palm and eye detection phase
        std::vector<cv::Rect> closed_palms;

       // while (char(cv::waitKey(1)) != 'q' && cap.isOpened()) {
            cv::Mat frame;
         cv::Mat subframe;
        
            cap >> frame;
         
        if(found)
        {
            subframe = frame(lastPos);
            
            closed_palm_cascade.detectMultiScale(subframe, closed_palms, 1.1, 4, 0, cv::Size(110, 110),cv::Size(500,500));
            
        }
        else
        {
            closed_palm_cascade.detectMultiScale(frame, closed_palms, 1.1, 4, 0, cv::Size(110, 110),cv::Size(500,500));

        }
        
            // Detect all the open_palms.
            cv::Rect newPos;

            if (closed_palms.size() != 0) {
            
                found = true;
               for (int i = 0; i < closed_palms.size(); i++) {

                    //cout << "=============Detected a closed_palm!=============" << endl;

                   int p1x,p1y,p2x,p2y;
                   
                   // Top left and bottom right points of rectangle.
                   cv::Point closed_palm_rect_p1(closed_palms[i].x, closed_palms[i].y);
                   cv::Point closed_palm_rect_p2(closed_palms[i].x + closed_palms[i].width, closed_palms[i].y + closed_palms[i].height);
                   
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
                   
                    if(closed_palms[i].x+closed_palms[i].width+120>SCREEN_WIDTH)
                    {
                        p2x = closed_palms[i].x+closed_palms[i].width;
                    }
                                          
                   if(closed_palms[i].y+closed_palms[i].height+120>SCREEN_HEIGHT)
                   {
                       p2y = closed_palms[i].y+closed_palms[i].height;
                   }
                   
                   cv::Point largeRectp1(p1x,p1y);
                   cv::Point largeRectp2(closed_palms[i].x + closed_palms[i].width+120, closed_palms[i].y + closed_palms[i].height+120);
                   
                    // Draw the rectangle in the image.
                    rectangle(frame, closed_palm_rect_p1, closed_palm_rect_p2, cv::Scalar(0, 255, 0));
                    putText(frame, "Closed Palm", closed_palm_rect_p1, cv::FONT_HERSHEY_SIMPLEX,
                        1, cv::Scalar(0, 255, 0), 1, 5, false);

                   cv::Rect newPos(largeRectp1,largeRectp2);
                   
                   
                   rectangle(frame,largeRectp1,largeRectp2,cv::Scalar(255,0,0));
                   
                   subframe = frame(newPos);
                }
            }
            else
            {
                found = false;
            }
            
        lastPos = newPos;

            if(found){
                imshow("Video Capture", subframe);
                
                return newPos;

            }

             
             //imshow("Video Capture", frame);
            
            return cv::Rect();
    
    }

bool InputManager::IsPalmClosedNormal()
{
    
    
    if (!cap.isOpened()) {
               std::cout << "Could not open Camera stream!";
            return false;
           }

           
           if (closed_palm_cascade.empty()) {
               std::cout << "Could not load closed_palm configuration file! "
                   "Check directory! " << std::endl << "Press Q to Quit!" << std::endl;
               return false;
           }

           // Start the open_palm and eye detection phase
           std::vector<cv::Rect> closed_palms;

          // while (char(cv::waitKey(1)) != 'q' && cap.isOpened()) {
               cv::Mat frame;
           
               cap >> frame;
            
        
           
               closed_palm_cascade.detectMultiScale(frame, closed_palms, 1.1, 4, 0, cv::Size(110, 110),cv::Size(500,500));

           
           
             

               if (closed_palms.size() != 0) {
               
                   found = true;
                  for (int i = 0; i < closed_palms.size(); i++) {

                       //cout << "=============Detected a closed_palm!=============" << endl;

                      
                      // Top left and bottom right points of rectangle.
                      cv::Point closed_palm_rect_p1(closed_palms[i].x, closed_palms[i].y);
                      cv::Point closed_palm_rect_p2(closed_palms[i].x + closed_palms[i].width, closed_palms[i].y + closed_palms[i].height);
                      
                   
                      
                 
                      
                       // Draw the rectangle in the image.
                       rectangle(frame, closed_palm_rect_p1, closed_palm_rect_p2, cv::Scalar(0, 255, 0));
                       putText(frame, "Closed Palm", closed_palm_rect_p1, cv::FONT_HERSHEY_SIMPLEX,
                           1, cv::Scalar(0, 255, 0), 1, 5, false);

                      
                      
                  }
               }
               else
               {
                   found = false;
               }
               
          
    cv::namedWindow("Video Capture",cv::WINDOW_NORMAL);
   cv::resizeWindow("Video Capture", 700,400);
    
                   imshow("Video Capture", frame);

                 

                
               
    return found;
    
    
    
    
}

int InputManager::test()
{
    
    
    
    
    return 1;
}


cv::VideoCapture InputManager::getCap()
{
    return cap;
}

void InputManager::setFound(bool _found)
{
    found = _found;
    
}


bool InputManager::getFound()
{
    return found;
}



}
