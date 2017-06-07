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
		F32 mYaw;
		F32 mPitch;
		// Camera options
		F32 mMovementSpeed;
		F32 mMouseSensitivity = 0.05f;
		F32 mZoom;

	public:
		Camera(Vec3 pos = Vec3(0, 0, -3), Vec3 front = Vec3(0, 0, -1), Vec3 worldUp = Vec3(0,1,0));
		~Camera();


		void setPosition();
		void update(F32 dt);


		Matrix4 getView();



	};

}







#endif // !_GAME_CAMERA_CAMERA_

