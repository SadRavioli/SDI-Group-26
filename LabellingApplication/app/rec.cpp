#include "rec.h"

Rec::Rec(QObject* parent): QGraphicsScene(parent)
{
    itemToDraw = 0;
    simpleTextToDraw = 0;
    sceneMode = NoMode;
}

void Rec::setMode(Mode mode){
    sceneMode = mode;
    QGraphicsView::DragMode vMode =
            QGraphicsView::NoDrag;
    if(mode == DrawRec){
        vMode = QGraphicsView::NoDrag;
    }
    else if(mode == SelectObject){
        makeItemsControllable(true);
        vMode = QGraphicsView::RubberBandDrag;
    }
}

void Rec::makeItemsControllable(bool areControllable){
    foreach(QGraphicsItem* item, items()){
        item->setFlag(QGraphicsItem::ItemIsSelectable,
                      areControllable);
        item->setFlag(QGraphicsItem::ItemIsMovable,
                      areControllable);
    }
}

void Rec::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(sceneMode == DrawRec)
        origPoint = event->scenePos();
    QGraphicsScene::mousePressEvent(event);
}

void Rec::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(sceneMode == DrawRec)
    {
         if(!itemToDraw)
         {
             itemToDraw = new QGraphicsRectItem;
             this->addItem(itemToDraw);

             simpleTextToDraw = new QGraphicsSimpleTextItem;
             this->addItem(simpleTextToDraw);


             itemToDraw->setPen(QPen(Qt::red, 3, Qt::SolidLine));

         }

         float top = qMin(origPoint.y(), event->scenePos().y());
         float left = qMin(origPoint.x(), event->scenePos().x());

         itemToDraw->setPos(left, top);

         QFont font("Helvetica",12);
         simpleTextToDraw->setFont(font);

         itemToDraw->setRect(0, 0, qAbs(event->scenePos().x() - origPoint.x()),
                    qAbs(event->scenePos().y() - origPoint.y()));

         simpleTextToDraw->setText(ClassName);
         simpleTextToDraw->QGraphicsItem::setParentItem(itemToDraw);
    }
    else
    {
         QGraphicsScene::mouseMoveEvent(event);
    }

}
void Rec::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    itemToDraw = 0;
    simpleTextToDraw = 0;
    QGraphicsScene::mouseReleaseEvent(event);
}

void Rec::keyPressEvent(QKeyEvent *event){


    if(event->key() == Qt::Key_Delete)
        foreach(QGraphicsItem* item, items()){
            QJsonObject recordObject;
            recordObject.insert("FirstName", item);


        }

}

void saveJson(QString fileName) {



    QJsonObject recordObject;
    recordObject.insert("FirstName", QJsonValue::fromVariant(1));
    recordObject.insert("LastName", QJsonValue::fromVariant("Doe"));
    recordObject.insert("Age", QJsonValue::fromVariant(43));

    QJsonDocument doc(recordObject);

    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(doc.toJson());
}

