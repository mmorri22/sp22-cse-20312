#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
 public:
  virtual ~Shape();
  virtual int GetArea() const =0;
  virtual void Draw() const;
};

#endif
