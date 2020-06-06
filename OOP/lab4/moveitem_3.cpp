#include "moveitem_3.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
MoveItem_3::MoveItem_3(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}
MoveItem_3::~MoveItem_3()
{

}

QRectF MoveItem_3::boundingRect() const
{
    return QRectF (-30,-30,90,60);
}

void MoveItem_3::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
            painter->drawLine(50,-50,-40,40);

    Q_UNUSED(option);
    Q_UNUSED(widget);
            update();
}

void MoveItem_3::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
      update();
}

void MoveItem_3::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MoveItem_3::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);

}
