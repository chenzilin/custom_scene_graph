#include "ring.h"
#include <QSGNode>
#include <QtMath>
#include <QSGVertexColorMaterial>
#include <QDebug>

Ring::Ring(QQuickItem *parent)
    : QQuickItem(parent), mRo(100), mRi(50), mAngle(0), mDiv(20),
      mRegenGeometry(false), mRegenColor(false), mReallocGeometry(false)
{
    setWidth(mRo * 2);
    setHeight(mRo * 2);
    setFlag(ItemHasContents, true);
}

void Ring::setRo(qreal v)
{
    if (v == mRo)
        return;

    mRo = v;
    setWidth(mRo * 2);
    setHeight(mRo * 2);
    mRegenGeometry = true;
    mRegenColor = true;
    emit roChanged(v);
    update();
}

void Ring::setRi(qreal v)
{
    if (v == mRi)
        return;

    mRi = v;
    mRegenGeometry = true;
    mRegenColor = true;
    emit riChanged(v);
    update();
}

void Ring::setAngle(qreal v)
{
    if (v == mAngle)
        return;

    mAngle = v;
    mRegenColor = true;
    emit angleChanged(v);
    update();
}

void Ring::setDiv(int v)
{
    if (v == mDiv)
        return;

    mDiv = v;
    mRegenGeometry = true;
    mRegenColor = true;
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
        mRegenColor = true;
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
        geometry = node->geometry();
        if (mReallocGeometry) {
            geometry->allocate(2 * mDiv + 2);
            mReallocGeometry = false;
        }
    }

    QSGGeometry::ColoredPoint2D *vertices = geometry->vertexDataAsColoredPoint2D();

    if (mRegenGeometry) {
        for (int i = 0; i <= mDiv; i++) {
            vertices[i * 2].x = mRo + mRo * qCos(2 * M_PI * i / mDiv);
            vertices[i * 2].y = mRo + mRo * qSin(2 * M_PI * i / mDiv);
            vertices[i * 2 + 1].x = mRo + mRi * qCos(2 * M_PI * i / mDiv);
            vertices[i * 2 + 1].y = mRo + mRi * qSin(2 * M_PI * i / mDiv);
        }
        mRegenGeometry = false;
    }

    if (mRegenColor) {
        for (int i = 0; i <= mDiv; i++) {
            QColor color;
            if (360.0 * i / mDiv < mAngle)
                color = QColor(255, 0, 0, 128);
            else
                color = QColor(0, 255, 0, 128);

            vertices[i * 2].r = vertices[i * 2 + 1].r = color.red();
            vertices[i * 2].b = vertices[i * 2 + 1].b = color.blue();
            vertices[i * 2].g = vertices[i * 2 + 1].g = color.green();
            vertices[i * 2].a = vertices[i * 2 + 1].a = color.alpha();
        }
        mRegenColor = false;
    }

    node->markDirty(QSGNode::DirtyGeometry);

    qDebug() << "paint";
    return node;
}
