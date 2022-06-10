#ifndef MAZEBUILDER_H
#define MAZEBUILDER_H

#include <QString>
#include <QLabel>

class Maze {
public:
  virtual void createMaze(QLabel* lbl) = 0;
  virtual ~Maze(){}
};

class MazeBuilder : virtual public Maze {
public:
  MazeBuilder(){}

  virtual ~MazeBuilder(){}


  void setShape(QString str){
    this->shape = str;
  }
  void setStyle(QString str){
    this->style = str;
  }
  void setSize(int s){
    this->size = s;
  }

  QString getShape(){ return this->shape; }
  virtual void createMaze(QLabel* lbl) override{
    lbl->setPixmap(QPixmap("://mazes//Maze//RectangularOrthogonal20.png"));
  }

protected:
  QString shape;
  QString style;
  int size;
};

class MiddleMazeBuilder : public virtual MazeBuilder {
public:
  virtual ~MiddleMazeBuilder(){}

  MiddleMazeBuilder(){}
  MiddleMazeBuilder(QString shape, int size){
    this->shape = shape;
    this->size = size;
  }

  virtual void createMaze(QLabel* lbl) override{
    shape = (shape == "Rectangular") ? "RectangularOrthogonal" : shape;
    lbl->setPixmap(QPixmap("://mazes//Maze//"+shape+QString::number(size)+".png"));
  }
};

class ComplexMazeBuilder : public virtual MazeBuilder {
public:
  virtual ~ComplexMazeBuilder(){}

  ComplexMazeBuilder(QString shape){this->shape = shape;}
  ComplexMazeBuilder(QString shape, QString style, int size){
    this->shape = shape;
    this->style = style;
    this->size = size;
  }

  virtual void createMaze(QLabel* lbl) override{
    QString str;
    str = ((getShape()) == "Rectangular") ? style : "";
    lbl->setPixmap(QPixmap("://mazes//Maze//"+shape+str+QString::number(size)+".png"));
  }
};

class SimpleMazeBuilder : public ComplexMazeBuilder, public MiddleMazeBuilder {
public:
  virtual ~SimpleMazeBuilder(){}

  SimpleMazeBuilder(QString str):ComplexMazeBuilder(str){}
  virtual void createMaze(QLabel* lbl) override{
    QString str;
    str = ((getShape()) == "Rectangular") ? "RectangularOrthogonal" : getShape();
    lbl->setPixmap(QPixmap("://mazes//Maze//"+str+"20.png"));
  }
};
#endif // MAZEBUILDER_H
