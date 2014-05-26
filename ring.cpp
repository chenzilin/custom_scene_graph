#include "ring.h"
#include <QSGNode>
#include <QSGFlatColorMaterial>
#include <QSGVertexColorMaterial>
#include <QDebug>

Ring::Ring(QQuickItem *parent) :
    QQuickItem(parent)
{
    setFlag(ItemHasContents, true);
}

QSGNode *Ring::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    QSGGeometryNode *node;
    QSGGeometry *geometry;

    if (!oldNode) {
        node = new QSGGeometryNode;
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_ColoredPoint2D(), 8);
        geometry->setDrawingMode(GL_TRIANGLE_STRIP);
        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);

        //QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
        //material->setColor(QColor(255,0,0));
        QSGVertexColorMaterial *material = new QSGVertexColorMaterial;
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);
    }
    else {
        node = static_cast<QSGGeometryNode *>(oldNode);
    }

    QSGGeometry::ColoredPoint2D *vertices = geometry->vertexDataAsColoredPoint2D();
    vertices[0].set(0, 100, 255, 0, 0, 128);
    vertices[1].set(50, 100, 255, 0, 0, 128);
    vertices[2].set(100, 0, 0, 255, 0, 128);
    vertices[3].set(100, 50, 0, 255, 0, 128);
    vertices[4].set(200, 100, 0, 0, 255, 128);
    vertices[5].set(150, 100, 0, 0, 255, 128);
    vertices[6].set(100, 200, 255, 255, 0, 128);
    vertices[7].set(100, 150, 255, 255, 0, 128);

    node->markDirty(QSGNode::DirtyGeometry);

    qDebug() << "paint";

    return node;
}
