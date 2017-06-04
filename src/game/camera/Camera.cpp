#include <game\camera\Camera.h>

namespace Palette3D
{





	Camera::Camera(Vec3 pos, Vec3 target, Vec3 worldUp)
	{

		mPosition = pos;
		mDirection = (pos - target).normalize();


		mWorldUp = worldUp;

		mRight = (mDirection.cross(worldUp)).normalize();


		mUp = mDirection.cross(mRight);
		std::cout <<mDirection <<mUp << mRight;

	}

	Camera::~Camera()
	{
	}

	Matrix4 Camera::lookAt()
	{

		return Matrix4(
			mRight.x, mRight.y, mRight.z, 0,
			mUp.x, mUp.y, mUp.z, 0,
			mDirection.x, mDirection.y, mDirection.z,0,
			0,0,0,1
		) * Matrix4::translate(mPosition.x, mPosition.y, mPosition.z) ;
	}

}