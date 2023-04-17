
#include "dashboardfield.h"



DashboardField::DashboardField(QWidget* parent) : QWidget(parent)
{
    upButton = new QPushButton("+");
    QFont f = upButton->font();
    f.setPointSize(f.pointSize()+ 2);
    f.setWeight(QFont::Weight::Bold);
    upButton->setFont(f);
    downButton = new QPushButton("-");
    downButton->setFont(f);
    label = new QLabel(fieldName());
    label->setFont(f);
    Content = ContentWidget();
    Content->setFont(f);
        f.setPointSize(f.pointSize()+5);

    connect(upButton, SIGNAL(pressed()), this, SLOT(onUpButtonPressed()));
        connect(downButton, SIGNAL(released()), this, SLOT(onDownButtonPressed()));


    setBaseSize(400,100);
    setMaximumSize(450, 100);

    QPalette pal;
    pal.setColor(QPalette::Window, Qt::blue);
    setAutoFillBackground(true);
    setPalette(pal);
    auto grid = new QGridLayout();
    setLayout(grid);

    grid->addWidget(label, 0, 0, 3, 2, Qt::AlignTop);
    grid->addWidget(Content,  0, 2, 3, 2, Qt::AlignTop);
    grid->addWidget(downButton, 7, 0, 4, 1, Qt::AlignBottom);
    grid->addWidget(upButton,7,2, 4,1, Qt::AlignBottom);
    label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    grid->activate();
}

