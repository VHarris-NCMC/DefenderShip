#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <Box2D/Common/b2Math.h>


namespace components
{
	class  Thrust
	{
		public:
			float acceleration;
			float maxThrust;
			float  maxSpeed;
			Thrust(float acceleration, float maxThrust_, float maxSpeed_) : acceleration(acceleration), maxThrust(maxThrust_), maxSpeed(maxSpeed_){};

	};
	class Engine
	{


	public:
			Engine(b2Vec2* localPos, Thrust* thrust_);;

		Thrust* thust;
		b2Vec2* positionOnVehicle;

		float getForce(float32 currentSpeed);
		b2Vec2* getGlobalPosition(b2Vec2 bodyPosition);

		private:

		float currentThrust;


			void Ignite(bool b)
			{
				if (b == true)
				{

					//constexpr lerp(currentThrust, thust.max, thrust.min);
				}
			}
	};

	inline Engine::Engine(b2Vec2* localPos, Thrust* thrust_) : thust(thrust_), positionOnVehicle(localPos) {}
	inline float Engine::getForce(float32 currentSpeed)
	{
		return 1000;
	}
	inline b2Vec2* Engine::getGlobalPosition( b2Vec2 bodyPosition )
	{
		b2Vec2* rPos = new b2Vec2();
		rPos->x = bodyPosition.x + positionOnVehicle->x;
		rPos->y = bodyPosition.y + positionOnVehicle->y;

		return rPos;
	}
}








#endif // COMPONENTS_H
