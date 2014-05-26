#include "ring.h"
#include <QSGNode>
#include <QtMath>
#include <QSGVertexColorMaterial>
#include <QDebug>

Ring::Ring(QQuickItem *parent)
    : QQuickItem(parent), mRo(100), mRi(50), mDiv(10),
      mRegenGeometry(false), mReallocGeometry(false)
{
    setFlag(ItemHasContents, true);
}

void Ring::setRo(qreal v)
{
    if (v == mRo)
        return;

    mRo = v;
    mRegenGeometry = true;
    emit roChanged(v);
    update();
}

void Ring::setRi(qreal v)
{
    if (v == mRi)
        return;

    mRi = v;
    mRegenGeometry = true;
    emit riChanged(v);
    update();
}

void Ring::setDiv(int v)
{
    if (v == mDiv)
        return;

    mDiv = v;
    mRegenGeometry = true;
    mReallocGeometry = true;
    emit divChanged(v);
    update();
}

QSGNode *Ring::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    QSGGeometryNode *node;
    QSGGeometry *geometry;

    if (!oldNode) {
        mRegenGeometry = true;
        node = new QSGGeometryNode;
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_ColoredPoint2D(), 2 * mDiv + 2);
        geometry->setDrawingMode(GL_TRIANGLE_STRIP);
        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);

        QSGVertexColorMaterial *material = new QSGVertexColorMaterial;
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);
    }
    else {
        node = static_cast<QSGGeometryNode *>(oldNode);
        if (mReallocGeometry) {
            geometry = node->geometry();
            geometry->allocate(2 * mDiv + 2);
            mReallocGeometry = false;
        }
    }

    if (mRegenGeometry) {
        QSGGeometry::ColoredPoint2D *vertices = geometry->vertexDataAsColoredPoint2D();
        for (int i = 0; i <= mDiv; i++) {
            vertices[i * 2].set(mRo + mRo * qCos(2 * M_PI * i / mDiv),
                                mRo + mRo * qSin(2 * M_PI * i / mDiv),
                                255, 0, 0, 128);
            vertices[i * 2 + 1].set(mRo + mRi * qCos(2 * M_PI * i / mDiv),
                                    mRo + mRi * qSin(2 * M_PI * i / mDiv),
                                    255, 0, 0, 128);
        }
        mRegenGeometry = false;
    }

    node->markDirty(QSGNode::DirtyGeometry);

    return node;
}
