  
  //Bottom left corner is not (0,0), it is (0,2)
  //Bottom right corner is (129, 2)
  //Upper left corner is (4, 131)
  //Upper right corner is (129, 131)
  //X coordinates go from 0 to 129
  //Y coordinates go from 2 to 131
  
#include <ColorLCDShield.h>

#define XMIN 0
#define XMAX 129
#define YMIN 2
#define YMAX 131
#define BACKGROUND BLACK
#define BALLCOLOR ORANGE
#define PADDLECOLOR GREEN

enum vel
{
  SLOW = 30,
  MED = 40,
  FAST = 50
};

class Ball
{
  private:
            int x_vel;
            int y_vel;
            int x_pos;
            int loopfreq;
            enum collisiontype
              {
                TOP,
                LEFT,
                RIGHT,
                BOTTOM,
                TOPLEFT,
                TOPRIGHT,
                BOTTOMLEFT,
                BOTTOMRIGHT,
                NOCOLLISION,
                PADDLE
              };
            collisiontype collision(int,int,int,int);
            
   public:  Ball();
            Ball(int,vel);
            int collision_int;
            int y_pos;
            int radius;
            int get_x_pos();
            int get_y_pos();
            int get_radius();
            int get_loop_rate();
            void set_x_pos(int);
            void set_y_pos(int);
            void set_radius(int);
            void setVel(vel);
            void reset_ball_pos();
            void updatePosition();
};

class Paddle
{
  private:
            int length;
            int Yoffset;
            int Yoffset_prev;
            int x_left;
            int x_right;
            int y_bottom_prev;
            int y_top_prev;
            int fill;
            int color;
   public:
            Paddle();
            Paddle(int, int, int, int, int);
            void update_paddle_position(int);
            int y_top;
            int y_bottom;
            int get_Yoffset();
            int get_Yoffset_prev();
            int get_x_left();
            int get_x_right();
            int get_y_bottom();
            int get_y_top();
            int get_y_bottom_prev();
            int get_y_top_prev();
            int get_fill();
            int get_color();            
};
            
  
