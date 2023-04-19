
#include "menubutton.h"

#include <MAINCONTROLLER.h>

StartButton::StartButton(QWidget* parent) : UI_BUTTON(parent, QString("Start Game "))
{
    //TODO: there should be one more layer of abstraction to differentiate between debug buttons and regular buttons.
    label->hide();
    Content->hide();
    downButton->hide();
    upButton->setText(QString("Start"));

}
void StartButton::onUpButtonPressed()
{
    MAINCONTROLLER::BeginGame();
}
void StartButton::onDownButtonPressed(){}

TestButton::TestButton(QWidget* parent) : UI_BUTTON(parent, QString("Test Button"))
{
    //TODO: there should be one more layer of abstraction to differentiate between debug buttons and regular buttons.
    label->hide();
    Content->hide();
    downButton->hide();
    upButton->setText(QString("TEST"));
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

}
void TestButton::onUpButtonPressed()
{

}
void TestButton::onDownButtonPressed(){}
