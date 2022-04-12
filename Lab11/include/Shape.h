#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
 public:
  virtual ~Shape();
  virtual int GetArea() const =0;
  virtual void Draw() const;
};

#endif
