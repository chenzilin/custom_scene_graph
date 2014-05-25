#ifndef RING_H
#define RING_H

#include <QQuickItem>

class ring : public QQuickItem
{
    Q_OBJECT
public:
    explicit ring(QQuickItem *parent = 0);
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

signals:

public slots:

};

#endif // RING_H
