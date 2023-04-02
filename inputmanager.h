#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <QWidget>
#include<qevent.h>


class InputManager : QWidget
{

	public:
		const std::map<Qt::Key,const char*> KeyMap = {
			{Qt::Key_W, "Up" },
			{ Qt::Key_S,"Down"},
			{Qt::Key_A,"Left" },
			{Qt::Key_D,"Right" },
			{Qt::Key_Space,"Fire" },
		};
		InputManager();

	private:


		// QWidget interface
		protected:

};

#endif // INPUTMANAGER_H
