/*
  ZanyCircles - An example sketch for the Color LCD Shield Library
  by: Jim Lindblom
  SparkFun Electronics
  date: 6/23/11
  license: CC-BY SA 3.0 - Creative commons share-alike 3.0
  use this code however you'd like, just keep this license and
  attribute. Let me know if you make hugely, awesome, great changes.
  
  This simple sketch shows how you can use setCircle and setPixel
  with the Color LCD Shield library. 
*/
#include <ColorLCDShield.h>
#include "pong_support.h"

  // When the text on the LED circuit board is upside down, it is oriented properly

int radius = 4;
vel velocity = MED; //set velocity: SLOW, MED, FAST
unsigned long ms_current=0; //millisecond variable for loop timing
unsigned long ms_previous=0; //millisecond variable for loop timing
int length = 40;      //length of paddle
int width = 5;        // paddle width
Paddle left_paddle(XMIN, XMIN+width, length, 1, PADDLECOLOR);
Paddle right_paddle(XMAX-width, XMAX, length, 1, PADDLECOLOR);
Paddle paddle_array[2] = {left_paddle, right_paddle};
LCDShield lcd;
Ball ball(radius, velocity);  //Create ball object

void setup()
{
  
// initiailize screen  
lcd.init(EPSON);
lcd.contrast(40); 
lcd.clear(BACKGROUND); 

}

void loop()
{

    paddle_array[0].update_paddle_position(analogRead(0));
    
    
    
    if(paddle_array[0].get_Yoffset() > paddle_array[0].get_Yoffset_prev())  //if paddle moves up
    {
       lcd.setRect(paddle_array[0].get_x_left(), paddle_array[0].get_y_bottom_prev(), paddle_array[0].get_x_right(), paddle_array[0].get_y_bottom(), 1, BACKGROUND);
       lcd.setRect(paddle_array[0].get_x_left(), paddle_array[0].get_y_top_prev(), paddle_array[0].get_x_right(), paddle_array[0].get_y_top(), paddle_array[0].get_fill(), paddle_array[0].get_color());
     }
    else  //if paddle moves down
    {
       lcd.setRect(paddle_array[0].get_x_left(), paddle_array[0].get_y_top(), paddle_array[0].get_x_right(), paddle_array[0].get_y_top_prev(), 1, BACKGROUND);
       lcd.setRect(paddle_array[0].get_x_left(), paddle_array[0].get_y_bottom(), paddle_array[0].get_x_right(), paddle_array[0].get_y_bottom_prev(), paddle_array[0].get_fill(), paddle_array[0].get_color());
    }
    
    
     paddle_array[1].update_paddle_position(analogRead(1));
    
    
    
    if (paddle_array[1].get_Yoffset() > paddle_array[1].get_Yoffset_prev())  //if paddle moves up
    {
       lcd.setRect(paddle_array[1].get_x_left(), paddle_array[1].get_y_bottom_prev(), paddle_array[1].get_x_right(), paddle_array[1].get_y_bottom(), 1, BACKGROUND);
       lcd.setRect(paddle_array[1].get_x_left(), paddle_array[1].get_y_top_prev(), paddle_array[1].get_x_right(), paddle_array[1].get_y_top(), paddle_array[1].get_fill(), paddle_array[1].get_color());
     }
    else  //if paddle moves down
    {
       lcd.setRect(paddle_array[1].get_x_left(), paddle_array[1].get_y_top(), paddle_array[1].get_x_right(), paddle_array[1].get_y_top_prev(), 1, BACKGROUND);
       lcd.setRect(paddle_array[1].get_x_left(), paddle_array[1].get_y_bottom(), paddle_array[1].get_x_right(), paddle_array[1].get_y_bottom_prev(), paddle_array[1].get_fill(), paddle_array[1].get_color());
    }
    
    ms_current = millis();  
    
    if ((ms_current-ms_previous) > ball.get_loop_rate())  //This statement ensures that the loop always runs at the same rate. Delay doesn't guarantee that.
    {
      
        lcd.setSolidCircle(ball.get_x_pos(), ball.get_y_pos(), ball.get_radius(), BACKGROUND);  // clear previous ball
        ball.updatePosition();                                                                  // get new ball position
      
      
      if(ball.collision_int ==0)
      {
        lcd.setSolidCircle(ball.get_x_pos(), ball.get_y_pos(), ball.get_radius(), BALLCOLOR);  // draw updated ball
      }
      
     else if(ball.collision_int==1 && ball.y_pos<paddle_array[0].y_top && ball.y_pos > paddle_array[0].y_bottom)
      {
        lcd.setSolidCircle(ball.get_x_pos(), ball.get_y_pos(), ball.get_radius(), BALLCOLOR);  // draw updated ball
      }
            
      else if(ball.collision_int==2 && ball.y_pos<paddle_array[1].y_top && ball.y_pos > paddle_array[1].y_bottom)
      {
        lcd.setSolidCircle(ball.get_x_pos(), ball.get_y_pos(), ball.get_radius(), BALLCOLOR);  // draw updated ball
      }
    
    else
    {
        ball.set_x_pos(64);
        ball.set_y_pos(65);
        lcd.setSolidCircle(ball.get_x_pos(), ball.get_y_pos(), ball.get_radius(), BALLCOLOR); // draw updated ball
        ball.collision_int=0;
        
        
     }
     
     ms_previous=ms_current;  
     
     
  }
  

  
    else
    delay(1);
    



}
