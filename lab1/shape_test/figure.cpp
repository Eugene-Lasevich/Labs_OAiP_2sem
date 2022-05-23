#include "figure.h"

Figure::Figure()
{

}

void Figure::move_up_()
{
    this->setPos(this->x(),this->y()-1);

}

void Figure::move_down_()
{

    this->setPos(this->x(),this->y()+1);
}

void Figure::move_right_()
{
    this->setPos(this->x()+1,this->y());

}

void Figure::move_left_()
{
    this->setPos(this->x()-1,this->y());

}


void Figure::rotate_left_()
{
    this->setRotation(this->rotation()+1);

}
void Figure::rotate_right_()
{
    this->setRotation(this->rotation()-1);

}
void Figure::size_plus_()
{

   if(this->scale()+0.01 <= 4 )
   this->setScale(this->scale()+0.01);

}
void Figure::size_minus_()
{

    if(this->scale()-0.01 >= 0)
    this->setScale(this->scale()-0.01);

}













