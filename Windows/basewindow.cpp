#include "basewindow.h"

#define kLoginWindowW 500
#define kLoginWindowH 500

BaseWindow::BaseWindow(QWidget *parent)
    : QWidget(parent)
{
    Initial();
    InitView();
    InitConnect();
}

BaseWindow::~BaseWindow()
{

}

void BaseWindow::Initial()
{
    m_titleBar = new UITitleBar(this);
    m_titleBar->move(0, 0);
    m_titleBar->setTitleContent(QString("UF技统"), 20);
    m_titleBar->setTitleColor(Qt::white);
    m_titleBar->setTitleIcon(":/image/Resources/login_logo.png", QSize(35,35));
    m_titleBar->setTitleHeight(80);
    m_titleBar->setButtonType(MIN_MAX_BUTTON);
}

void BaseWindow::InitView()
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    this->setMinimumSize(100, 100);
    this->setMaximumSize(kVirtualScreenW - 10, kVirtualScreenH - 10);
    this->resize(kLoginWindowW, kLoginWindowH);
}

void BaseWindow::InitConnect()
{
    connect(m_titleBar, SIGNAL(signalButtonMinClicked()), this, SLOT(onButtonMinClicked()));
    connect(m_titleBar, SIGNAL(signalButtonRestoreClicked()), this, SLOT(onButtonRestoreClicked()));
    connect(m_titleBar, SIGNAL(signalButtonMaxClicked()), this, SLOT(onButtonMaxClicked()));
    connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
}

void BaseWindow::paintEvent(QPaintEvent* event)
{
    //设置背景色;
    QPainter painter(this);
    QPainterPath pathBack;
    pathBack.setFillRule(Qt::WindingFill);
    pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.fillPath(pathBack, QBrush(QColor(238, 223, 204)));

    return QWidget::paintEvent(event);
}

void BaseWindow::resizeEvent(QResizeEvent* size)
{
    m_titleBar->setFixedWidth(this->width());
}

void BaseWindow::onButtonMinClicked()
{
    showMinimized();
}

void BaseWindow::onButtonRestoreClicked()
{
    QPoint windowPos;
    QSize windowSize;
    m_titleBar->getRestoreInfo(windowPos, windowSize);
    this->setGeometry(QRect(windowPos, windowSize));
}

void BaseWindow::onButtonMaxClicked()
{
    QDesktopWidget *deskTop = QApplication::desktop();
    int curMonitor = deskTop->screenNumber(this);//获取当前屏幕的标号,多屏幕

    m_titleBar->saveRestoreInfo(this->pos(), QSize(this->width(), this->height()));
    QRect rect = deskTop->screenGeometry(curMonitor);
    QRect FactRect = QRect(rect.x() + 3, rect.y() - 3, rect.width() - 6, rect.height() - 6);
    this->setGeometry(FactRect);
}

void BaseWindow::onButtonCloseClicked()
{
    close();
}
