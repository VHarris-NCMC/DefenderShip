
#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <UI_BUTTON.h>





class StartButton : public UI_BUTTON
{
public:
    explicit StartButton(QWidget* parent);

    // UI_BUTTON interface
protected slots:
    void onUpButtonPressed()override;
    void onDownButtonPressed()override;

};

class TestButton: public UI_BUTTON
{
public:
    explicit TestButton(QWidget* parent);

    // UI_BUTTON interface
protected slots:
    void onUpButtonPressed()override;
    void onDownButtonPressed()override;

};

#endif // MENUBUTTON_H
