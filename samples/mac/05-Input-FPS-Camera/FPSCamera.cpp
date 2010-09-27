/*
 *  FPSCamera.cpp
 *  05-Input-FPS-Camera
 *
 *  Created by Sean Chapel on 9/27/10.
 *  Copyright 2010 Seoushi Games. All rights reserved.
 *
 */

#include <iostream>

#include <lavish/core/timer.hpp>

#include "FPSCamera.hpp"

using namespace lavish;


FPSCamera::FPSCamera()
{
	cameraAngle = Vector2::Zero();
	cameraPosition = Vector3::Zero();
	cameraMatrix = Matrix4::Identity();
	mouseMovement = Vector2::Zero();
	lastUpdateTime = Timer::GetCurrentGameTime();
	
	leftIsDown	= false;
	rightIsDown	= false;
	upIsDown	= false;
	downIsDown	= false;
	shouldQuit	= false;
	
	mouseTrackingSpeedY = 0.1f;
	mouseTrackingSpeedX = 0.1f;
}


FPSCamera::~FPSCamera()
{
}


void FPSCamera::OnKeyDown(const keyboard::Key key)
{
	switch (key)
	{
		case keyboard::UpArrow:
			upIsDown = true;
			break;
		case keyboard::DownArrow:
			downIsDown = true;
			break;
		case keyboard::LeftArrow:
			leftIsDown = true;
			break;
		case keyboard::RightArrow:
			rightIsDown = true;
			break;
		case keyboard::R:
			Reset();
			break;
		default:
			break;
	}
}

void FPSCamera::OnKeyUp(const keyboard::Key key)
{
	switch (key)
	{
		case keyboard::UpArrow:
			upIsDown = false;
			break;
		case keyboard::DownArrow:
			downIsDown = false;
			break;
		case keyboard::LeftArrow:
			leftIsDown = false;
			break;
		case keyboard::RightArrow:
			rightIsDown = false;
			break;
		case keyboard::Escape:
			shouldQuit = true;
			break;
		default:
			break;
	}
}


// buttons are ignored
void FPSCamera::OnButtonDown(const mouse::Button button){}
void FPSCamera::OnButtonUp(const mouse::Button button){}


void FPSCamera::OnMouseMove(const unsigned int x, const unsigned int y, const int dx, const int dy)
{
	mouseMovement += Vector2((float)dx, (float)dy);
}


void FPSCamera::Update()
{
	float frameTime = Timer::GetCurrentGameTime() - lastUpdateTime;
	lastUpdateTime = Timer::GetCurrentGameTime();
	
	
	// update the looking direction
	cameraAngle.y = mouseMovement.x * mouseTrackingSpeedY * frameTime;
	cameraAngle.x -= mouseMovement.y * mouseTrackingSpeedX * frameTime; // regular / not inverted
	mouseMovement = Vector2::Zero();
	
	cameraMatrix = Matrix4::RotateY(cameraAngle.y)		// left and right movement
				   * Matrix4::RotateX(cameraAngle.x);	// updown movement
}


Matrix4 FPSCamera::CameraMatrix() const
{
	return cameraMatrix;
}


bool FPSCamera::ShouldQuit()
{
	return shouldQuit;
}


void FPSCamera::Reset()
{
	cameraAngle = Vector2::Zero();
	cameraPosition = Vector3::Zero();
	cameraMatrix = Matrix4::Identity();	
	mouseMovement = Vector2::Zero();

	lastUpdateTime = Timer::GetCurrentGameTime();
}	
