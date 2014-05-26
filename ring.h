#ifndef RING_H
#define RING_H

#include <QQuickItem>

class Ring : public QQuickItem
{
    Q_OBJECT
public:
    explicit Ring(QQuickItem *parent = 0);
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

signals:

public slots:

};

#endif // RING_H
