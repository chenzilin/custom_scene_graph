#ifndef RING_H
#define RING_H

#include <QQuickItem>
#include <QSGGeometry>

class QSGMaterial;

class Ring : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(qreal ro READ ro WRITE setRo NOTIFY roChanged)
    Q_PROPERTY(qreal ri READ ri WRITE setRi NOTIFY riChanged)
    Q_PROPERTY(qreal startAngle READ startAngle WRITE setStartAngle NOTIFY startAngleChanged)
    Q_PROPERTY(qreal endAngle READ endAngle WRITE setEndAngle NOTIFY endAngleChanged)
    Q_PROPERTY(qreal angle READ angle WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(int div READ div WRITE setDiv NOTIFY divChanged)
    Q_PROPERTY(QUrl tex READ tex WRITE setTex NOTIFY texChanged)
    Q_PROPERTY(bool clockwise READ clockwise WRITE setClockwise NOTIFY clockwiseChanged)
public:
    explicit Ring(QQuickItem *parent = 0);
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

    qreal ro() const { return mRo; }
    qreal ri() const { return mRi; }
    qreal startAngle() const { return mStartAngle; }
    qreal endAngle() const { return mEndAngle; }
    qreal angle() const { return mAngle; }
    int div() const { return mDiv; }
    QUrl tex() const { return mTex; }
    bool clockwise() const { return mClockwise; }

    void setRo(qreal);
    void setRi(qreal);
    void setStartAngle(qreal);
    void setEndAngle(qreal);
    void setAngle(qreal);
    void setDiv(int);
    void setTex(const QUrl &);
    void setClockwise(bool);

signals:
    void roChanged();
    void riChanged();
    void startAngleChanged();
    void endAngleChanged();
    void angleChanged();
    void divChanged();
    void texChanged();
    void clockwiseChanged();

private:
    qreal mRo;
    qreal mRi;
    qreal mStartAngle;
    qreal mEndAngle;
    qreal mAngle;
    int mDiv;
    QUrl mTex;
    bool mClockwise;
    bool mUpdateVertex;

    QSGMaterial *createMaterial(const QUrl &);
    void setVertex(QSGGeometry::TexturedPoint2D *vertex, qreal a);
    bool urlToPath(const QUrl &url, QString &path);
};

#endif // RING_H
