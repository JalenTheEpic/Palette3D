#ifndef _GAME_CAMERA_CAMERA_
#define _GAME_CAMERA_CAMERA_

#include <core\math\Math.h>

namespace Palette3D
{
	/////////////////////////////////////////FINISH ME///////////////////////////////////////////////
	class Camera 
	{
		//only public for now
	public:
		// Camera Attributes
		Vec3 mPosition;
		Vec3 mFront;
		Vec3 mUp;
		Vec3 mRight;
		Vec3 mWorldUp;
		Vec3 mDirection;
	
	
	public:
		// Eular Angles
		float mYaw;
		float mPitch;
		// Camera options
		float mMovementSpeed;
		float mMouseSensitivity;
		float mZoom;

	public:
		Camera(Vec3 pos = Vec3(0, 0, -3), Vec3 target = Vec3(0, 0, 0), Vec3 worldUp = Vec3(0,1,0));
		~Camera();


		void setPosition();
		


		Matrix4 lookAt();



	};

}







#endif // !_GAME_CAMERA_CAMERA_

