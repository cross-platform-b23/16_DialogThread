#include "dialogthread.h"
#include "ui_dialogthread.h"

DialogThread::DialogThread(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogThread), m_threadA("A"), m_threadB("B"), m_threadC("C")
{
    ui->setupUi(this);
    connect(&m_threadA, SIGNAL(onProgress(int)), this, SLOT(onProgressA(int)));
    connect(&m_threadB, &QProgressThread::onProgress, this, &DialogThread::onProgressB);
    connect(&m_threadC, &QProgressThread::onProgress, this, &DialogThread::onProgressC);
    ui->progressBarA->setValue(0);
    ui->progressBarB->setValue(0);
    ui->progressBarC->setValue(0);
}

DialogThread::~DialogThread()
{
    delete ui;
}


void DialogThread::on_pushButtonStartA_clicked()
{
    m_threadA.startThread();
}

void DialogThread::on_pushButtonStartB_clicked()
{
    m_threadB.startThread();
}

void DialogThread::on_pushButtonStartC_clicked()
{
    m_threadC.startThread();
}

void DialogThread::on_pushButtonStopA_clicked()
{
    m_threadA.stopThread();
}

void DialogThread::on_pushButtonStopB_clicked()
{
    m_threadB.stopThread();
}

void DialogThread::on_pushButtonStopC_clicked()
{
    m_threadC.stopThread();
}

void DialogThread::onProgressA(int nCount)
{
    ui->progressBarA->setValue(nCount);
}

void DialogThread::onProgressB(int nCount)
{
    ui->progressBarB->setValue(nCount);
}

void DialogThread::onProgressC(int nCount)
{
    ui->progressBarC->setValue(nCount);
}

