/* vokoscreen - A desktop recorder
 * Copyright (C) 2011-2012 Volker Kohaupt
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef regionselection_H 
#define regionselection_H

#include <QPainter>
#include <QDialog>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QPropertyAnimation>
#include <QPixmap>

class regionselection : public QWidget
{ 
Q_OBJECT
public:
  regionselection( int x, int y, int width, int height, int border );
  virtual ~regionselection();
  void lockFrame( bool status = true );
  bool isFrameLocked();

  
public slots:
  int getX();
  int getY();
  int getHeight();
  int getWidth();
  //void printSize();

  
private slots:
  void moveTopLeft    ( QMouseEvent *event );
  void moveTopMiddle  ( QMouseEvent *event );
  void moveTopRight   ( QMouseEvent *event );
  void moveRightMiddle( QMouseEvent *event );
  void moveBottomRight( QMouseEvent *event );
  void moveBottomMiddle( QMouseEvent *event);

  void HandleTopMiddle();
  void HandleTopRight();
  void HandleRightMiddle();
  void HandleBottomRight();
  
protected:  
  //void mouseMoveEvent( QMouseEvent *event );
  //void moveEvent( QMoveEvent * event );
  //void hideEvent( QHideEvent * event );
  //void showEvent( QShowEvent * event );
protected:
  void mouseMoveEvent( QMouseEvent *event );
  void mousePressEvent( QMouseEvent *event );
  void mouseReleaseEvent ( QMouseEvent * event );
  
  void paintEvent( QPaintEvent *event );
  QPainter * painter;
  
private:
  enum Handle { NoHandle, TopLeft, TopMiddle, TopRight, RightMiddle, BottomRight, BottomMiddle, BottomLeft, LeftMiddle, Middle };

  int Rand;  
  int frameWidth;
  int radius;
  int penWidth;
  int penHalf;

  int borderLeft;
  int borderTop;
  int borderRight;
  int borderBottom;
  
  QLabel *handleTopLeft;
  //QLabel *handleTopMiddle;
//  QLabel *handleTopRight;
//  QLabel *handleRightMiddle;
  
  bool frameLocked;
  void handlingFrameLock();
  
  //QLabel *labelSize;

  //! Fuer die Bewegung des Fensters
  QPoint m_dragPosition;
  
  int currentMouseLocalX;
  int currentMouseLocalY;
  
  int currentWidgetWidth;
  int currentWidgetHeight;
  int currentWidgetY;
  int currentbottomY;
  
  //QCursor myCursor;
  
  Handle handlePressed;
  Handle handleUnderMouse;
};
#endif
