#ifndef REC_H
#define REC_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsItemGroup>
#include <QAction>
#include <QGraphicsView>
#include <QList>
#include <QKeyEvent>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <QVariant>

class Rec : public QGraphicsScene
{
public:
    enum Mode {NoMode, SelectObject, DrawRec};
    Rec(QObject* parent = 0);
    void setMode(Mode mode);
    QString ClassName;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void saveJson(QString fileName);

private:
    Mode sceneMode;
    QPointF origPoint;
    QGraphicsItemGroup *group;
    QGraphicsRectItem* itemToDraw;
    QGraphicsSimpleTextItem* simpleTextToDraw;

    void makeItemsControllable(bool areControllable);
};

#endif // REC_H
