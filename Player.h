#ifndef PLAYER_H
#define PLAYER_H
#include <GameObject.h>
#include <InputManager.h>
#include <QGraphicsItem>
#include <vehicle.h>
#include <QTimer>
#include <qobjectdefs.h>


class Player : QWidget{
    public:

		 Player();


    private:
		int score;
		Vehicle* vehicle;
		void keyPressEvent(QKeyEvent* event)override;
		void keyReleaseEvent(QKeyEvent* event)override;
		void InitializeInput();
		InputManager* input;

		void stopKeyAction(QKeyEvent* event);
		void startKeyAction(QKeyEvent* event);

		QTimer* InputTimer;

};
#endif // PLAYER_H
