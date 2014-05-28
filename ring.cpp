#include "ring.h"
#include <QSGNode>
#include <QtMath>
#include <QQuickWindow>
#include <QSGTextureMaterial>
#include <QDebug>

Ring::Ring(QQuickItem *parent)
    : QQuickItem(parent), mRo(100), mRi(50),
      mStartAngle(0), mEndAngle(360), mAngle(0), mDiv(20),
      mUpdateVertex(false), mUpdateTexture(false), mUpdateGeometry(false)
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
    mUpdateVertex = true;
    emit roChanged(v);
    update();
}

void Ring::setRi(qreal v)
{
    if (v == mRi)
        return;

    mRi = v;
    mUpdateVertex = true;
    emit riChanged(v);
    update();
}

void Ring::setStartAngle(qreal v)
{
    if (v == mStartAngle)
        return;

    mStartAngle = v;
    mUpdateVertex = true;
    emit startAngleChanged(v);
    update();
}

void Ring::setEndAngle(qreal v)
{
    if (v == mEndAngle)
        return;

    mEndAngle = v;
    mUpdateVertex = true;
    emit endAngleChanged(v);
    update();
}

void Ring::setAngle(qreal v)
{
    if (v == mAngle)
        return;

    mAngle = v;
    mUpdateTexture = true;
    emit angleChanged(v);
    update();
}

void Ring::setDiv(int v)
{
    if (v == mDiv)
        return;

    mDiv = v;
    mUpdateGeometry = true;
    emit divChanged(v);
    update();
}

void Ring::setTex(const QString &v)
{
    if (v == mTex)
        return;

    mTex = v;
    emit texChanged(v);
    update();
}

QSGNode *Ring::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    QSGGeometryNode *node;
    QSGGeometry *geometry;

    if (!oldNode) {
        node = new QSGGeometryNode;
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_TexturedPoint2D(), 2 * (mDiv + 1));
        geometry->setDrawingMode(GL_TRIANGLE_STRIP);
        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);

        QSGTextureMaterial *material = new QSGTextureMaterial;
        QSGTexture *texture = window()->createTextureFromImage(QImage(mTex));
        texture->setFiltering(QSGTexture::Linear);
        material->setTexture(texture);
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);
    }
    else {
        node = static_cast<QSGGeometryNode *>(oldNode);
        geometry = node->geometry();
        if (mUpdateGeometry)
            geometry->allocate(2 * (mDiv + 1));
    }

    QSGGeometry::TexturedPoint2D *vertices = geometry->vertexDataAsTexturedPoint2D();

    if (mUpdateGeometry || mUpdateVertex) {
        for (int i = 0; i <= mDiv; i++) {
            qreal alpha = ((mEndAngle - mStartAngle) * i / mDiv + mStartAngle) * M_PI / 180;
            qreal cosAlpha = qCos(alpha);
            qreal sinAlpha = qSin(alpha);
            vertices[2 * i].x = mRo + mRo * cosAlpha;
            vertices[2 * i].y = mRo + mRo * sinAlpha;
            vertices[2 * i + 1].x = mRo + mRi * cosAlpha;
            vertices[2 * i + 1].y = mRo + mRi * sinAlpha;
        }
    }

    if (mUpdateGeometry || mUpdateVertex || mUpdateTexture) {
        qreal start = 0.5 - 0.5 * (mAngle - mStartAngle) / (mEndAngle - mStartAngle);
        for (int i = 0; i <= mDiv; i++) {
            qreal delta = 0.5 * i / mDiv;
            vertices[2 * i].tx = 0;
            vertices[2 * i].ty = start + delta;
            vertices[2 * i + 1].tx = 1;
            vertices[2 * i + 1].ty = start + delta;
        }
    }

    mUpdateGeometry = mUpdateVertex = mUpdateTexture = false;

    node->markDirty(QSGNode::DirtyGeometry);

    return node;
}
