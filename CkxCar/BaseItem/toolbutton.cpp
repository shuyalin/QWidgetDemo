#include "toolbutton.h"
#include <QDebug>
ToolButton::ToolButton(QWidget *parent):QWidget(parent)
{
    this->setAttribute(Qt::WA_StyledBackground, true);
    isMove = false;
}

