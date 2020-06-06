#ifndef MOVEITEM_3_H
#define MOVEITEM_3_H

#include "mainwindow.h"

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
class MoveItem_3 : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MoveItem_3(QObject *parent = 0);
    ~MoveItem_3();

signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
};

#endif // MOVEITEM_3_H
