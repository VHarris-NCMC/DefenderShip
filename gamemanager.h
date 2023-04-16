#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <Player.h>
#include <mutex>
#include <inputmanager.h>



class GameManager{

    private:
    Player* player = nullptr;

        inline static InputManager* input{ nullptr};
		 GameManager();


		 ~GameManager(){};
		 inline static std::mutex mutex_;
		 inline static GameManager* _instance_{nullptr};
        void InitializePlayer();

		 //Prevent Singleton from being copied.
		 GameManager(GameManager const&){};
		 void operator=(GameManager const&){};

	public:
		void addPlayerToScene();
		void update();

		static GameManager* Instance()
		{
			//lock
			std::lock_guard<std::mutex> lock(mutex_);
			//If instance does not exist, create a new one
			if (_instance_ == nullptr){  _instance_ = new GameManager();}
			// return signleton instance;
			return _instance_;
		}


};




#endif // GAMEMANAGER_H
