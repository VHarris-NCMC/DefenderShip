#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <Box2D/Common/b2Math.h>


namespace components
{
	struct Thrust (float x, float y);


	class Engine
	{


		public:
			Engine(b2Vec2* localPos, Thrust* thrust_);

			//components::Thrust thust;


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
	components::Thrust(float accel_, float max_)
	{

	}







}





#endif // COMPONENTS_H
