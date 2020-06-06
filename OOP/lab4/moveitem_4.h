#ifndef MOVEITEM_4_H
#define MOVEITEM_4_H

#include "mainwindow.h"

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
class MoveItem_4 : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MoveItem_4(QObject *parent = 0);
    ~MoveItem_4();

signals:

private:
    QRectF boundingRect() const;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
};

#endif // MOVEITEM_4_H
