#ifndef DIALOGTHREAD_H
#define DIALOGTHREAD_H

#include <QDialog>
#include "qprogressthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DialogThread; }
QT_END_NAMESPACE

class DialogThread : public QDialog
{
    Q_OBJECT

public:
    DialogThread(QWidget *parent = nullptr);
    ~DialogThread();

private slots:
    void on_pushButtonStartA_clicked();
    void on_pushButtonStartB_clicked();
    void on_pushButtonStartC_clicked();
    void on_pushButtonStopA_clicked();
    void on_pushButtonStopB_clicked();
    void on_pushButtonStopC_clicked();

    void onProgressA(int nCount);
    void onProgressB(int nCount);
    void onProgressC(int nCount);

private:
    Ui::DialogThread *ui;
    QProgressThread m_threadA;
    QProgressThread m_threadB;
    QProgressThread m_threadC;
};
#endif // DIALOGTHREAD_H
