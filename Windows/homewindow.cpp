#include "homewindow.h"

HomeWindow::HomeWindow(QWidget *parent)
    : BaseWindow(parent)
{
    initial();
    initSize();
    initText();
    initLayout();
    initView();
    initConnect();
}

HomeWindow::~HomeWindow()
{
    delete m_topWhiteWidget; m_topWhiteWidget = NULL;
    delete m_dateTimeEdit; m_dateTimeEdit = NULL;
    delete m_createMatchBtn; m_createMatchBtn = NULL;
    delete m_tableView; m_tableView = NULL;
}

void HomeWindow::initial()
{
    m_topWhiteWidget = new QWidget(this);
    m_dateTimeEdit = new QDateTimeEdit(this);
    m_createMatchBtn = new UIPushButton(this);
    m_tableView = new QTableView(this);
}

void HomeWindow::initSize()
{
    int homeWindowW = 800;
    int homeWindowH = 800;
    int topWidgetH = 50;

    resize(homeWindowW, homeWindowH);
    m_topWhiteWidget->resize(homeWindowW, topWidgetH);
    m_dateTimeEdit->resize(120, 30);
    m_createMatchBtn->resize(100, 30);
    m_tableView->resize(homeWindowW, homeWindowH - topWidgetH);
}

void HomeWindow::initText()
{
    m_dateTimeEdit->setDisplayFormat("yyyy-MM-dd");
    m_dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    m_dateTimeEdit->setCalendarPopup(true);
    m_createMatchBtn->setText(TextLocal("创建比赛"));
}

void HomeWindow::initLayout()
{
    int dataEditY = m_titleBar->height() + (m_topWhiteWidget->height()-m_dateTimeEdit->height())/2;
    int createMatchBtnY = m_titleBar->height() + (m_topWhiteWidget->height()-m_createMatchBtn->height())/2;
    m_topWhiteWidget->move(0, m_titleBar->height());
    m_dateTimeEdit->move(30, dataEditY);
    m_createMatchBtn->move(m_topWhiteWidget->width()-m_createMatchBtn->width()-30,createMatchBtnY);
    m_tableView->move(0, m_titleBar->height() + m_topWhiteWidget->height());
}

void HomeWindow::initView()
{
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, Qt::white);
    m_topWhiteWidget->setAutoFillBackground(true);
    m_topWhiteWidget->setPalette(pal);

    m_titleBar->setButtonType(MIN_BUTTON);

    m_createMatchBtn->setStyleSheet("background-color:rgb(45,152,253);\
                              border:0px; border-radius:4px;\
                              font-size:14px;color:white;");

    m_tableView->setStyleSheet("background-color:rgb(242,242,242);");
}

void HomeWindow::initConnect()
{
    connect(m_dateTimeEdit, SIGNAL(dateChanged(QDate)), this, SLOT(onDateTimeEditChanged(QDate)));
    connect(m_createMatchBtn, SIGNAL(clicked()), this, SLOT(onCreateMatchBtn()));
}


void HomeWindow::onDateTimeEditChanged(const QDate &date)
{
    qDebug() << date;
}

void HomeWindow::onCreateMatchBtn()
{

}
