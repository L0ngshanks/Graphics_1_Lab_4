#pragma once
#include "RendererMath.h"

MATRIX_4D SV_WorldMatrix = Matrix_Identity_4D();

MATRIX_4D SV_View = Matrix_Identity_4D();

MATRIX_4D SV_Perspective = Matrix_Identity_4D();

unsigned int SP_Color = 0x00000000;

//Vertex Shader
void(*VertexShader)(VERTEX_4D&) = nullptr;

//Pixel Shader
void(*PixelShader)(unsigned int&) = nullptr;

// VS_Shaders
void VS_World(VERTEX_4D& _v)
{
	_v = Vertex_Matrix_Multipication_4D(_v, SV_WorldMatrix);
	_v = Vertex_Matrix_Multipication_4D(_v, SV_View);
	_v = Vertex_Matrix_Multipication_4D(_v, SV_Perspective);

	_v.pos.x /= _v.pos.w;
	_v.pos.y /= _v.pos.w;
	_v.pos.z /= _v.pos.w;
}

// PS_Shaders

void PS_White(unsigned int& makeWhite)
{
	makeWhite = White;
}

void PS_Red(unsigned int& makeRed)
{
	makeRed = Red;
}

void PS_Green(unsigned int& makeGreen)
{
	makeGreen = Green;
}

void PS_Blue(unsigned int& makeBlue)
{
	makeBlue = Blue;
}

void PS_ChangeColor(unsigned int& changeColor)
{
	changeColor = SP_Color;
}