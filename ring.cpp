#include "ring.h"
#include <QSGNode>
#include <QtMath>
#include <QSGTextureMaterial>
#include <QDebug>

Ring::Ring(QQuickItem *parent)
    : QQuickItem(parent), mRo(100), mRi(50),
      mStartAngle(0), mEndAngle(360), mAngle(0), mDiv(20)
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
    emit roChanged(v);
    update();
}

void Ring::setRi(qreal v)
{
    if (v == mRi)
        return;

    mRi = v;
    emit riChanged(v);
    update();
}

void Ring::setStartAngle(qreal v)
{
    if (v == mStartAngle)
        return;

    mStartAngle = v;
    emit startAngleChanged(v);
    update();
}

void Ring::setEndAngle(qreal v)
{
    if (v == mEndAngle)
        return;

    mEndAngle = v;
    emit endAngleChanged(v);
    update();
}

void Ring::setAngle(qreal v)
{
    if (v == mAngle)
        return;

    mAngle = v;
    emit angleChanged(v);
    update();
}

void Ring::setDiv(int v)
{
    if (v == mDiv)
        return;

    mDiv = v;
    emit divChanged(v);
    update();
}

void Ring::setSrc1(const QString &v)
{
    if (v == mSrc1)
        return;

    mSrc1 = v;
    emit src1Changed(v);
    update();
}

void Ring::setSrc2(const QString &v)
{
    if (v == mSrc2)
        return;

    mSrc2 = v;
    emit src2Changed(v);
    update();
}

QSGNode *Ring::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    QSGGeometryNode *node;
    QSGGeometry *geometry;

    int sp = qCeil((mAngle - mStartAngle) / (mEndAngle - mStartAngle) * mDiv);
    int ep = qCeil((mEndAngle - mAngle) / (mEndAngle - mStartAngle) * mDiv);
    int vn = (sp ? 2 * (sp + 1) : 0) + (ep ? 2 * (ep + 1) : 0);

    if (!oldNode) {
        node = new QSGGeometryNode;
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_TexturedPoint2D(), vn);
        geometry->setDrawingMode(GL_TRIANGLE_STRIP);
        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);

        QSGTextureMaterial *material = new QSGTextureMaterial;
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);
    }
    else {
        node = static_cast<QSGGeometryNode *>(oldNode);
        geometry = node->geometry();
        geometry->allocate(vn);
    }

    int n = 0;
    QSGGeometry::TexturedPoint2D *vertices = geometry->vertexDataAsTexturedPoint2D();

    if (sp) {
        for (int i = 0; i <= sp; i++, n += 2) {
            qreal alpha = ((mAngle - mStartAngle) * i / sp + mStartAngle) * M_PI / 180;
            vertices[n].set(mRo + mRo * qCos(alpha), mRo + mRo * qSin(alpha),
                            230, 147, 67, 255);
            vertices[n + 1].set(mRo + mRi * qCos(alpha), mRo + mRi * qSin(alpha),
                                55, 12, 3, 255);
        }
    }

    if (ep) {
        for (int i = 0; i <= ep; i++, n += 2) {
            qreal alpha = ((mEndAngle - mAngle) * i / ep + mAngle) * M_PI / 180;
            vertices[n].set(mRo + mRo * qCos(alpha), mRo + mRo * qSin(alpha),
                            189, 35, 3, 255);
            vertices[n + 1].set(mRo + mRi * qCos(alpha), mRo + mRi * qSin(alpha),
                                63, 12, 0, 255);
        }
    }

    node->markDirty(QSGNode::DirtyGeometry);

    //qDebug() << "paint";
    return node;
}
