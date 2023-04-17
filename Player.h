#ifndef PLAYER_H
#define PLAYER_H
#include <GameObject.h>
#include <InputManager.h>
#include <QGraphicsItem>
#include <vehicle.h>
#include <QTimer>
#include <qobjectdefs.h>
#include <debug_mass_dashboard.h>

class Player : public QWidget{

Q_OBJECT
public:

         explicit Player();
    virtual ~Player(){};
        Vehicle* getVehicle();

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
    private slots:

        void increaseMass();

};
#endif // PLAYER_H
