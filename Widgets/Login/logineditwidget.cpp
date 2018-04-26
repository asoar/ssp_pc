#include "logineditwidget.h"
#include <QPainter>
#include <QRegExpValidator>

LoginEditWidget::LoginEditWidget(QWidget *parent)
    : QWidget(parent)
    , m_iconSize(25, 25)
{
    initial();
    initLayout();
    initView();
    initConnect();
}

void LoginEditWidget::initial()
{
    m_iconL = new UILabel(this);
    m_contentEdit = new UILineEdit(this);
}

void LoginEditWidget::initLayout()
{
    m_iconL->move(15, 12);
    m_contentEdit->move(15 + m_iconSize.width() + 20, 5);
}

void LoginEditWidget::initView()
{
    //设置背景白色
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

void LoginEditWidget::initConnect()
{

}

void LoginEditWidget::resizeEvent(QResizeEvent *size)
{
    m_iconL->setFixedSize(m_iconSize.width(), m_iconSize.height());
    m_contentEdit->setFixedSize(this->size().width() - m_iconSize.width() - 40, 40);
}


#pragma mark 设置编辑内容字体颜色和字体大小
void LoginEditWidget::setTextColor(QColor color, int fontSize)
{
    QPalette palette;
    palette.setColor(QPalette::Text, color);
    m_contentEdit->setFont(QFont("Timers" , fontSize ,  QFont::Bold));
    m_contentEdit->setPalette(palette);
}

#pragma mark 设置Placeholder
void LoginEditWidget::setTextPlaceholder(QString text)
{
    m_contentEdit->setPlaceholderText(text);
}

#pragma mark 设置编辑框前面的icon
void LoginEditWidget::setIcon(QString filePath , QSize IconSize)
{
    QPixmap titleIcon(filePath);
    m_iconL->setPixmap(titleIcon.scaled(IconSize));
}

#pragma mark 设置编辑框的正则
void LoginEditWidget::setTextRegExp(QRegExp reg)
{
    m_contentEdit->setValidator(new QRegExpValidator(reg));
}

void LoginEditWidget::setPasswordMode()
{
    m_contentEdit->setEchoMode(QLineEdit::Password);
//    m_contentEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
}

#pragma mark 获取编辑框内容
QString LoginEditWidget::text()
{
    return m_contentEdit->text();
}
