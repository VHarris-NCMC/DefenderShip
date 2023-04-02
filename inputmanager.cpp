#include "inputmanager.h"

#include <qDebug>

InputManager::InputManager()
{
	qDebug() << "Input Ready";
	QWidget::grabKeyboard();


}


