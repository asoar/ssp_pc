#include "uititlebar.h"

#include <QHBoxLayout>
#include <QPainter>
#include <QFile>
#include <QMouseEvent>
#include <QPalette>

#define BUTTON_HEIGHT 20        // 按钮高度;
#define BUTTON_WIDTH 20         // 按钮宽度;
#define TITLE_HEIGHT 30         // 标题栏高度;

UITitleBar::UITitleBar(QWidget *parent)
    : QWidget(parent)
    , m_colorR(45)
    , m_colorG(153)
    , m_colorB(253)
    , m_isPressed(false)
    , m_buttonType(MIN_MAX_BUTTON)
    , m_windowBorderWidth(0)
    , m_isTransparent(false)
    , m_isDrag(true)
{
    // 初始化;
    Initial();
    initView();
    initConnect();
}

UITitleBar::~UITitleBar()
{

}

void UITitleBar::Initial()
{
    m_pIcon = new QLabel;
    m_pTitleContent = new QLabel;

    m_pButtonMin = new UiImageButton();
    m_pButtonRestore = new UiImageButton();
    m_pButtonMax = new UiImageButton();
    m_pButtonClose = new UiImageButton();

    m_pButtonMin->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonRestore->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonMax->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonClose->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));

    m_pTitleContent->setObjectName("TitleContent");
    m_pButtonMin->setObjectName("ButtonMin");
    m_pButtonRestore->setObjectName("ButtonRestore");
    m_pButtonMax->setObjectName("ButtonMax");
    m_pButtonClose->setObjectName("ButtonClose");

    m_pButtonMin->setToolTip(QStringLiteral("最小化"));
    m_pButtonRestore->setToolTip(QStringLiteral("还原"));
    m_pButtonMax->setToolTip(QStringLiteral("最大化"));
    m_pButtonClose->setToolTip(QStringLiteral("关闭"));

    QHBoxLayout* mylayout = new QHBoxLayout(this);

    mylayout->addWidget(m_pIcon);
    mylayout->addWidget(m_pTitleContent);
    mylayout->addWidget(m_pButtonMin);
    mylayout->addWidget(m_pButtonRestore);
    mylayout->addWidget(m_pButtonMax);
    mylayout->addWidget(m_pButtonClose);

    mylayout->setContentsMargins(20, 0, 20, 0);
    mylayout->setSpacing(20);

    m_pTitleContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setFixedHeight(TITLE_HEIGHT);//默认高度
    this->setWindowFlags(Qt::FramelessWindowHint);
}

void UITitleBar::initView()
{
    m_pButtonMin->setBtnBackImgFile(":/image/Resources/login_mini.png", \
                                    ":/image/Resources/login_mini.png", \
                                    ":/image/Resources/login_mini.png", \
                                    ":/image/Resources/login_mini.png");


    m_pButtonMax->setBtnBackImgFile(":/image/Resources/login_max.png", \
                                    ":/image/Resources/login_max.png", \
                                    ":/image/Resources/login_max.png", \
                                    ":/image/Resources/login_max.png");

    m_pButtonClose->setBtnBackImgFile(":/image/Resources/login_close.png", \
                                      ":/image/Resources/login_close.png", \
                                      ":/image/Resources/login_close.png", \
                                      ":/image/Resources/login_close.png");

    m_pButtonRestore->setBtnBackImgFile(":/image/Resources/login_close.png", \
                                      ":/image/Resources/login_close.png", \
                                      ":/image/Resources/login_close.png", \
                                      ":/image/Resources/login_close.png");


}

void UITitleBar::initConnect()
{
    connect(m_pButtonMin, SIGNAL(clicked()), this, SLOT(onButtonMinClicked()));
    connect(m_pButtonRestore, SIGNAL(clicked()), this, SLOT(onButtonRestoreClicked()));
    connect(m_pButtonMax, SIGNAL(clicked()), this, SLOT(onButtonMaxClicked()));
    connect(m_pButtonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
}

void UITitleBar::setBackgroundColor(int r, int g, int b, bool isTransparent)
{
    m_colorR = r;
    m_colorG = g;
    m_colorB = b;
    m_isTransparent = isTransparent;
    // 重新绘制（调用paintEvent事件）;
    update();
}

void UITitleBar::setTitleHeight(int height)
{
    this->setFixedHeight(height);
}

void UITitleBar::setTitleIcon(QString filePath, QSize IconSize)
{
    QPixmap titleIcon(filePath);
    m_pIcon->setPixmap(titleIcon.scaled(IconSize));
}

void UITitleBar::setTitleContent(QString titleContent, int titleFontSize)
{
    // 设置标题字体大小;
    QFont font = m_pTitleContent->font();
    font.setPointSize(titleFontSize);
    m_pTitleContent->setFont(font);
    // 设置标题内容;
    m_pTitleContent->setText(titleContent);
    m_titleContent = titleContent;
}

#pragma mark 设置标题字体颜色
void UITitleBar::setTitleColor(const QColor &color)
{
    QPalette pe;
    pe.setColor(QPalette::WindowText, color);
    m_pTitleContent->setPalette(pe);
}

void UITitleBar::setButtonType(ButtonType buttonType)
{
    m_buttonType = buttonType;

    switch (buttonType) {
        case MIN_BUTTON:{
            m_pButtonRestore->setVisible(false);
            m_pButtonMax->setVisible(false);
        } break;
        case MIN_MAX_BUTTON:{
            m_pButtonRestore->setVisible(false);
        } break;
        case ONLY_CLOSE_BUTTON:{
            m_pButtonMin->setVisible(false);
            m_pButtonRestore->setVisible(false);
            m_pButtonMax->setVisible(false);
        } break;
        default:  break;
    }
}

void UITitleBar::setTitleRoll()
{
    connect(&m_titleRollTimer, SIGNAL(timeout()), this, SLOT(onRollTitle()));
    m_titleRollTimer.start(200);
}

void UITitleBar::setWindowBorderWidth(int borderWidth)
{
    m_windowBorderWidth = borderWidth;
}

void UITitleBar::saveRestoreInfo(const QPoint point, const QSize size)
{
    m_restorePos = point;
    m_restoreSize = size;
}

void UITitleBar::getRestoreInfo(QPoint& point, QSize& size)
{
    point = m_restorePos;
    size = m_restoreSize;
}

void UITitleBar::paintEvent(QPaintEvent *event)
{
    // 是否设置标题透明;
    if (!m_isTransparent) {
        //设置背景色;
        QPainter painter(this);
        QPainterPath pathBack;
        pathBack.setFillRule(Qt::WindingFill);
        pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 0, 0);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.fillPath(pathBack, QBrush(QColor(m_colorR, m_colorG, m_colorB)));
    }

    // 当窗口最大化或者还原后，窗口长度变了，标题栏的长度应当一起改变;
    // 这里减去m_windowBorderWidth ，是因为窗口可能设置了不同宽度的边框;
    // 如果窗口有边框则需要设置m_windowBorderWidth的值，否则m_windowBorderWidth默认为0;
    if (this->width() != (this->parentWidget()->width() - m_windowBorderWidth)) {
        this->setFixedWidth(this->parentWidget()->width() - m_windowBorderWidth);
    }
    QWidget::paintEvent(event);
}

// 双击响应事件，主要是实现双击标题栏进行最大化和最小化操作;
void UITitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    // 只有存在最大化、还原按钮时双击才有效;
    if (m_buttonType == MIN_MAX_BUTTON) {
        // 通过最大化按钮的状态判断当前窗口是处于最大化还是原始大小状态;
        // 或者通过单独设置变量来表示当前窗口状态;
        if (m_pButtonMax->isVisible()) {
            onButtonMaxClicked();
        } else {
            onButtonRestoreClicked();
        }
    }

    return QWidget::mouseDoubleClickEvent(event);
}

// 以下通过mousePressEvent、mouseMoveEvent、mouseReleaseEvent三个事件实现了鼠标拖动标题栏移动窗口的效果;
void UITitleBar::mousePressEvent(QMouseEvent *event)
{
    if (m_buttonType == MIN_MAX_BUTTON) {
        if(m_isDrag){//窗口最大化不允许拖动
            m_isPressed = true;
            m_startMovePos = event->globalPos();
        }
    } else {
        m_isPressed = true;
        m_startMovePos = event->globalPos();
    }

    return QWidget::mousePressEvent(event);
}

void UITitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isPressed) {
        QPoint movePoint = event->globalPos() - m_startMovePos;
        QPoint widgetPos = this->parentWidget()->pos();
        m_startMovePos = event->globalPos();
        this->parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
    }
    return QWidget::mouseMoveEvent(event);
}

void UITitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    m_isPressed = false;
    return QWidget::mouseReleaseEvent(event);
}

// 以下为按钮操作响应的槽;
void UITitleBar::onButtonMinClicked()
{
    emit signalButtonMinClicked();
}

void UITitleBar::onButtonRestoreClicked()
{
    m_pButtonRestore->setVisible(false);
    m_pButtonMax->setVisible(true);
    emit signalButtonRestoreClicked();
}

void UITitleBar::onButtonMaxClicked()
{
    m_pButtonMax->setVisible(false);
    m_pButtonRestore->setVisible(true);
    emit signalButtonMaxClicked();
}

void UITitleBar::onButtonCloseClicked()
{
    emit signalButtonCloseClicked();
}

// 该方法主要是让标题栏中的标题显示为滚动的效果;
void UITitleBar::onRollTitle()
{
    static int nPos = 0;
    QString titleContent = m_titleContent;
    // 当截取的位置比字符串长时，从头开始;
    if (nPos > titleContent.length())
        nPos = 0;

    m_pTitleContent->setText(titleContent.mid(nPos));
    nPos++;
}
