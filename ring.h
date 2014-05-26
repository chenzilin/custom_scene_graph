#ifndef RING_H
#define RING_H

#include <QQuickItem>

class Ring : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(qreal ro READ ro WRITE setRo NOTIFY roChanged)
    Q_PROPERTY(qreal ri READ ri WRITE setRi NOTIFY riChanged)
    Q_PROPERTY(int div READ div WRITE setDiv NOTIFY divChanged)

public:
    explicit Ring(QQuickItem *parent = 0);
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

    qreal ro() const { return mRo; }
    qreal ri() const { return mRi; }
    int div() const { return mDiv; }

    void setRo(qreal);
    void setRi(qreal);
    void setDiv(int);

signals:
    void roChanged(qreal);
    void riChanged(qreal);
    void divChanged(int);

private:
    qreal mRo;
    qreal mRi;
    int mDiv;
    bool mRegenGeometry;
    bool mReallocGeometry;
};

#endif // RING_H
