#include "rec.h"

Rec::Rec(QObject* parent): QGraphicsScene(parent)
{
    itemToDraw = 0;
    simpleTextToDraw = 0;
    sceneMode = NoMode;
    NoItems = 0;
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

             QFont font("Helvetica",12);
             simpleTextToDraw->setFont(font);
         }
         float top = qMin(origPoint.y(), event->scenePos().y());
         float left = qMin(origPoint.x(), event->scenePos().x());

         itemToDraw->setPos(left, top);

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
    if(sceneMode == DrawRec)
    {
        NoItems = NoItems + 1;     
    }
    itemToDraw = 0;
    simpleTextToDraw = 0;
    QGraphicsScene::mouseReleaseEvent(event);
}

void Rec::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Delete)
    {
        foreach(QGraphicsItem* item, selectedItems())
        {
            removeItem(item);
            delete item;
            NoItems = NoItems - 1;
        }
    }

    else
    {
    QGraphicsScene::keyPressEvent(event);
    }

}

void Rec::readJson(QString Load)
   {
    QFile jsonFile(Load);
    jsonFile.open(QFile::ReadOnly);
    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();

    QJsonValue valueX = object.value("X");
    QJsonValue valueY = object.value("Y");
    QJsonValue valueHeight = object.value("Height");
    QJsonValue valueWidth = object.value("Width");
    QJsonValue valueAnno = object.value("Annotation");

    QJsonValue valueNoShapes = object.value("No of Shapes");
    QJsonArray arrayX = valueX.toArray();
    QJsonArray arrayY = valueY.toArray();
    QJsonArray arrayHeight = valueHeight.toArray();
    QJsonArray arrayWidth = valueWidth.toArray();
    QJsonArray arrayAnno = valueAnno.toArray();

    for(int i = 0; i < valueNoShapes.toInt(); i++)
    {
       if (arrayX[i] != 0 && arrayX[i] != 0 && arrayHeight[i] != 0 && arrayWidth[i] != 0)
       {
           int X = arrayX[i].toInt();
           int Y = arrayY[i].toInt();
           int Height = arrayHeight[i].toInt();
           int Width = arrayWidth[i].toInt();
           QString Annotation = arrayAnno[i].toString();

           drawJson(X,Y,Height,Width,Annotation);
       }
       else
       {
           valueNoShapes = valueNoShapes.toInt() + 1;
       }

    }
   }

void Rec::drawJson(int x,int y,int Height,int Width, QString annotation)
    {
    itemToDraw = new QGraphicsRectItem;
    this->addItem(itemToDraw);

    simpleTextToDraw = new QGraphicsSimpleTextItem;
    this->addItem(simpleTextToDraw);


    itemToDraw->setPen(QPen(Qt::red, 3, Qt::SolidLine));


    QFont font("Helvetica",18);
    simpleTextToDraw->setFont(font);
    itemToDraw->setPos(x,y);
    itemToDraw->setRect(0,0, Width,Height);
    simpleTextToDraw->setText(annotation);
    simpleTextToDraw->QGraphicsItem::setParentItem(itemToDraw);
    NoItems = NoItems + 1;
    }

void Rec::saveJson(QString Save, QString ImageName)
{
        QJsonObject recordObject;
        recordObject.insert("Image Name", ImageName);
        recordObject.insert("No of Shapes", NoItems);

        QJsonArray arrayPosX;
        QJsonArray arrayPosY;
        QJsonArray arrayHeight;
        QJsonArray arrayWidth;
        QJsonArray arrayAnnotation;

        //for(int i = 0; i < 3; i++)
        //{


            foreach(QGraphicsItem* item, items())
            {
                if(QGraphicsRectItem* rect_item = qgraphicsitem_cast<QGraphicsRectItem *>(item))
                {
                arrayPosX.push_back(item->x());
                arrayHeight.push_back(item->boundingRect().height());
                arrayWidth.push_back(item->boundingRect().width());
                arrayPosY.push_back(item->y());
                }

                if(QGraphicsSimpleTextItem* text_item = qgraphicsitem_cast<QGraphicsSimpleTextItem *>(item))
                {
                    arrayAnnotation.push_back(text_item->text());
                }
            }

        recordObject.insert("X",arrayPosX);
        recordObject.insert("Y",arrayPosY);
        recordObject.insert("Height",arrayHeight);
        recordObject.insert("Width",arrayWidth);
        recordObject.insert("Annotation",arrayAnnotation);

        QJsonDocument doc(recordObject);

        QFile jsonFile(Save);
        jsonFile.open(QFile::WriteOnly);
        jsonFile.write(doc.toJson());
}

void Rec::clearRec()
{
        foreach(QGraphicsItem* item, items()){
            removeItem(item);
            NoItems = 0;
        }

}
//copy, array selected items, past print x y height width



