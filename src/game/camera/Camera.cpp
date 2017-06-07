#include <game\camera\Camera.h>
#include <input\InputManager.h>
namespace Palette3D
{




	//Soon I'll bake the controls right into the camera simply for testing purposes 

	Camera::Camera(Vec3 pos, Vec3 front, Vec3 worldUp):
		mPosition(pos),
		mFront(front),
		mMovementSpeed(6),
		mWorldUp(worldUp),
		mUp(worldUp)
	{

	}

	Camera::~Camera()
	{
	}

	void Camera::update(F32 dt)
	{
		if (INPUT_MANAGER->getKey(GLFW_KEY_W))
			mPosition +=  mFront * dt * mMovementSpeed;
		if (INPUT_MANAGER->getKey(GLFW_KEY_S))
			mPosition -= mFront * dt * mMovementSpeed;
		if (INPUT_MANAGER->getKey(GLFW_KEY_A))
			mPosition -= mFront.cross(mUp).normalize() * mMovementSpeed * dt;
		if (INPUT_MANAGER->getKey(GLFW_KEY_D))
			mPosition += mFront.cross(mUp).normalize() * mMovementSpeed * dt;


		if (INPUT_MANAGER->getKeyDown(GLFW_KEY_UP))
			mMovementSpeed += 5;
		
		if (INPUT_MANAGER->getKeyDown(GLFW_KEY_DOWN))
			mMovementSpeed -= 5;

		

	

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