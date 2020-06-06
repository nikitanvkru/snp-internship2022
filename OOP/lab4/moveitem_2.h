#ifndef MOVEITEM_2_H
#define MOVEITEM_2_H

#include "mainwindow.h"

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
class MoveItem_2 : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MoveItem_2(QObject *parent = 0);
    ~MoveItem_2();

signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
};


#endif // MOVEITEM_2_H
