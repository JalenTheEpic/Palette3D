#include <game\camera\Camera.h>

namespace Palette3D
{




	//Soon I'll bake the controls right into the camera simply for testing purposes 

	Camera::Camera(Vec3 pos, Vec3 target, Vec3 worldUp)
	{

		mPosition = pos;
		mDirection = (pos - target).normalize();


		mWorldUp = worldUp;

		mRight = (worldUp.cross(mDirection)).normalize();


		mUp = mDirection.cross(mRight);
		std::cout <<"Pos"<<mPosition << "Dir" <<mDirection << "Up" <<mUp<<"Right" << mRight;

	}

	Camera::~Camera()
	{
	}

	Matrix4 Camera::getView()
	{
		//not done 
		return Matrix4::lookAt(mPosition, mPosition + mFront, mUp);
	}

	void updateCameraVectors()
	{
	
	}


}