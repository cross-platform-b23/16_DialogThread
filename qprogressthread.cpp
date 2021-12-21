#include "qprogressthread.h"

QProgressThread::QProgressThread(const QString &id, QObject *parent) : QThread(parent)
{
    m_fStart = false;
    m_strId = id;
}

void QProgressThread::startThread()
{
    m_fStart = true;
    start();
}

void QProgressThread::stopThread()
{
    m_fStart = false;
}

void QProgressThread::run()
{
    int nCount=0;
    while (m_fStart && nCount<=100)
    {
        qDebug("Thread %s nCount: %d", qPrintable(m_strId),
               nCount);
        emit onProgress(nCount);
        nCount++;
        msleep(200);
    }
}
