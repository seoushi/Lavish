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
	moveSpeed = 0.1f;
}


FPSCamera::~FPSCamera()
{
}


void FPSCamera::OnKeyDown(const keyboard::Key key)
{
	switch (key)
	{
		case keyboard::W:
			upIsDown = true;
			break;
		case keyboard::S:
			downIsDown = true;
			break;
		case keyboard::A:
			leftIsDown = true;
			break;
		case keyboard::D:
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
		case keyboard::W:
			upIsDown = false;
			break;
		case keyboard::S:
			downIsDown = false;
			break;
		case keyboard::A:
			leftIsDown = false;
			break;
		case keyboard::D:
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
	
	
	// update the looking angles
	cameraAngle.y += mouseMovement.x * mouseTrackingSpeedY * frameTime;
	cameraAngle.x += mouseMovement.y * mouseTrackingSpeedX * frameTime;
	mouseMovement = Vector2::Zero();
	
	// create forward and left strafing angles
	Vector3 forwardVec = Vector3(sin(-degreesToRadians(cameraAngle.y)), 
								 0.0f, //sin(degreesToRadians(cameraAngle.x)), //change this line if you want a "fly cam"
								 cos(-degreesToRadians(cameraAngle.y)));
	forwardVec *= (frameTime * moveSpeed);
	
	Vector3 leftVec = Vector3(cos(degreesToRadians(cameraAngle.y)), 
							  0.0f,
							  sin(degreesToRadians(cameraAngle.y)));
	leftVec *= (frameTime * moveSpeed);
	
	
	//update the position based on input
	if(upIsDown)
	{
		cameraPosition -= forwardVec;
	}
	if(downIsDown)
	{
		cameraPosition += forwardVec;
	}
	if(leftIsDown)
	{
		cameraPosition -= leftVec;
	}
	if(rightIsDown)
	{
		cameraPosition += leftVec;
	}


	cameraMatrix = Matrix4::RotateX(cameraAngle.x) *	// updown movement
					Matrix4::RotateY(cameraAngle.y) *	// left and right movement
					Matrix4::Translate(-cameraPosition);
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

float FPSCamera::degreesToRadians(float degrees)
{
	return (degrees / 180.0f) * M_PI;
}

