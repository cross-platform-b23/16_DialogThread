#ifndef QPROGRESSTHREAD_H
#define QPROGRESSTHREAD_H

#include <QThread>

class QProgressThread : public QThread
{
    Q_OBJECT
    volatile bool m_fStart;
    QString m_strId;
public:
    explicit QProgressThread(const QString& id, QObject *parent = nullptr);
    void startThread();
    void stopThread();

signals:
    void onProgress(int nCount);

protected:
    void run();
};

#endif // QPROGRESSTHREAD_H
