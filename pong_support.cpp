#include "pong_support.h"
#include <stdlib.h>

Ball::Ball()
{
  //When using default contructor, assume radius is 4 and velocity is MED.
  radius = 4;
  x_vel = MED;
  y_vel = MED;
  loopfreq = 0.25*x_vel;
  x_pos = XMAX/2; 
  y_pos = YMAX/2; 
  collision_int = 0;  
}


Ball::Ball(int r, vel v)
{
  radius = r;
  x_vel = v;
  y_vel = v;
  loopfreq = 0.25*x_vel;
  x_pos = XMAX/1.2;
  y_pos = YMAX/20;
  collision_int = 0;
}

Ball::collisiontype Ball::collision(int x_min_ball, int x_max_ball, int y_min_ball, int y_max_ball)
{

//Determines if there is a collision and if so, where it is on the screen.  

  if (x_min_ball < XMIN+10 && y_min_ball < YMIN)
  {
    collision_int = 1;
    return BOTTOMLEFT;
  }
  if (x_max_ball > XMAX-10 && y_min_ball < YMIN)
  {
    collision_int = 2;
    return BOTTOMRIGHT;
  }
  if (x_min_ball < XMIN+10 && y_max_ball > YMAX)
  {
    collision_int = 1;
    return TOPLEFT;
  }
  if (x_max_ball > XMAX-10 && y_max_ball > YMAX)
  {
    collision_int = 2;
    return TOPRIGHT;
  }
  if (x_max_ball > XMAX-10)
  {
    collision_int = 2;
    return RIGHT;
  }
  if (x_min_ball < XMIN+10)
  {
    collision_int = 1;
    return LEFT;
  }
  if (y_max_ball > YMAX)
  {
    collision_int = 0;
    return TOP;
  }
  if (y_min_ball < YMIN)
  {
    collision_int = 0;
    return BOTTOM;
  }
  else
  {
    collision_int = 0;
    return NOCOLLISION;
  } 
}

void Ball::updatePosition()
{
  switch(collision(x_pos - radius, x_pos + radius, y_pos - radius, y_pos + radius))
  {
    case NOCOLLISION:
      break;
    
    case RIGHT:
    case LEFT:
      x_vel = -x_vel;
      break;
      
    case TOP:
    case BOTTOM:
      y_vel = -y_vel;
      break;
      
    case BOTTOMLEFT:
    case BOTTOMRIGHT:
    case TOPLEFT:
    case TOPRIGHT:
      x_vel = -x_vel;
      y_vel = -y_vel;
      break;
  }
  
  x_pos = x_pos + (x_vel / loopfreq);
  y_pos = y_pos + (y_vel / loopfreq);   
      
}

int Ball::get_x_pos()
{
  return x_pos;
}

int Ball::get_y_pos()
{
  return y_pos;
}

int Ball::get_radius()
{
  return radius;
}

int Ball::get_loop_rate()
{
  return 1000/loopfreq;
}

void Ball::set_x_pos(int x)
{
  x_pos = x;
}

void Ball::set_y_pos(int y)
{
  y_pos = y;
}

void Ball::set_radius(int r)
{
  radius = r;
}

/////////////////////////////////////////

Paddle::Paddle()
{
  length = 40;
  Yoffset = (YMAX-YMIN-length)/2;
  Yoffset_prev = 0;
  x_left = XMIN;
  x_right = XMIN;
  y_bottom = YMIN + Yoffset;
  y_top = YMIN + Yoffset + length;
  y_bottom_prev = 0;
  y_top_prev = 0;
  fill = 1;
  color = PADDLECOLOR;
}

Paddle::Paddle(int xl, int xr, int l, int f, int c)
{
  length = l;
  Yoffset = (YMAX-YMIN-length)/2;
  Yoffset_prev = 0;
  x_left = xl;
  x_right = xr;
  y_bottom = YMIN + Yoffset;
  y_top = YMIN + Yoffset + length;
  y_bottom_prev = 0;
  y_top_prev = 0;
  fill = f;
  color = c;
}

void Paddle::update_paddle_position(int AI)
{
  Yoffset_prev = Yoffset;
  y_bottom_prev = y_bottom;
  y_top_prev = y_top;
  Yoffset = (AI/1024.0)*(YMAX-YMIN-length);
  y_bottom = YMIN+Yoffset;
  y_top = YMIN+Yoffset+length;
}

int Paddle::get_Yoffset()
{
  return Yoffset;
}
            
int Paddle::get_Yoffset_prev()
{
  return Yoffset_prev;
}

int Paddle::get_x_left()
{
  return x_left;
}

int Paddle::get_x_right()
{
  return x_right;
}

int Paddle::get_y_top()
{
  return y_top;
}

int Paddle::get_y_bottom()
{
  return y_bottom;
}

int Paddle::get_y_bottom_prev()
{
  return y_bottom_prev;
}

int Paddle::get_y_top_prev()
{
  return y_top_prev;
}

int Paddle::get_fill()
{
  return fill;
}           
            
int Paddle::get_color()
{
  return color;
}  

