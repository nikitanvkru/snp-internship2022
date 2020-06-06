#include "moveitem_4.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
MoveItem_4::MoveItem_4(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}
MoveItem_4::~MoveItem_4()
{

}

QRectF MoveItem_4::boundingRect() const
{
    return QRectF (-30,-30,90,60);
}





void MoveItem_4::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
      update();
}

void MoveItem_4::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MoveItem_4::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);

}
