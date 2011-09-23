/*
 *  FPSCamera.h
 *  05-Input-FPS-Camera
 *
 *  Created by Sean Chapel on 9/27/10.
 *  Copyright 2010 Seoushi Games. All rights reserved.
 *
 */

#include <lavish/core/keyboard.hpp>
#include <lavish/core/mouse.hpp>
#include <lavish/math/matrix4.hpp>
#include <lavish/math/vector2.hpp>

#ifndef _FPS_CAMERA_HPP_
#define _FPS_CAMERA_HPP_

class FPSCamera : public lavish::KeyboardListener, public lavish::MouseListener
{
	public:
	
		FPSCamera();
		virtual ~FPSCamera();
	
		virtual void OnKeyDown(const lavish::keyboard::Key key);
		virtual void OnKeyUp(const lavish::keyboard::Key key);
	
		virtual void OnButtonDown(const lavish::mouse::Button button);
		virtual void OnButtonUp(const lavish::mouse::Button button);
		virtual void OnMouseMove(const unsigned int x, const unsigned int y, const int dx, const int dy);
	
		//should be called every frame
		void Update();

		lavish::Matrix4 CameraMatrix() const;
	
		bool ShouldQuit();
	
		void Reset();
	
	private:
	
		float degreesToRadians(float degrees);
	
		lavish::Vector2 cameraAngle;
		lavish::Vector3 cameraPosition;
		lavish::Matrix4 cameraMatrix;
		unsigned int lastUpdateTime;
	
		bool leftIsDown;
		bool rightIsDown;
		bool upIsDown;
		bool downIsDown;
		bool shouldQuit;
	
		float mouseTrackingSpeedY;
		float mouseTrackingSpeedX;
		float moveSpeed;
	
		lavish::Vector2 mouseMovement;
};

#endif