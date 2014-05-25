#include "ring.h"
#include <QSGGeometryNode>

ring::ring(QQuickItem *parent) :
    QQuickItem(parent)
{
}

QSGNode *ring::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    QSGGeometryNode *node;
    QSGGeometry *geometry;

    if (!oldNode) {
        node = new QSGGeometryNode;
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_ColoredPoint2D(), 8, )
    }
}
