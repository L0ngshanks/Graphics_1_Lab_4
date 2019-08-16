#include "Rasterizer.h"
#include "RasterSurface.h"

int main(int argc, char** argv)
{
	RS_Initialize(RASTER_WIDTH, RASTER_HEIGHT);

	VERTEX_4D square[8]
	{
		{ {-.25, -.25, .25, 1}, 0xFFFFFFFF},
		{ {.25, -.25, .25, 1}, 0xFFFFFFFF},
		{ {.25, .25, .25, 1}, 0xFFFFFFFF},
		{ {-.25, .25, .25, 1}, 0xFFFFFFFF},

		{ {-.25, -.25, -.25, 1}, 0xFFFFFFFF},
		{ {.25, -.25, -.25, 1}, 0xFFFFFFFF},
		{ {.25, .25, -.25, 1}, 0xFFFFFFFF},
		{ {-.25, .25, -.25, 1}, 0xFFFFFFFF},
	};



	double startTime = GetTickCount64();
	float degree = 0;

	while (RS_Update(Raster, NUM_PIXELS))
	{
		if (GetTickCount() - startTime >= 200)
		{
			startTime = 0;
			if (degree > 360)
				degree = 0.0f;
			degree += .1f;
		}

		ClearScreen();

		VertexShader = VS_World;
		SV_WorldMatrix = Matrix_Rotation_4D_Y(degree);

		PixelShader = PS_ChangeColor;
		SP_Color = Red;

		//Parametric(square[0], square[1]);
		//Parametric(square[1], square[2]);
		//Parametric(square[2], square[3]);
		//Parametric(square[3], square[0]);

		//Parametric(square[4], square[5]);
		//Parametric(square[5], square[6]);
		//Parametric(square[6], square[7]);
		//Parametric(square[7], square[4]);

		//Parametric(square[0], square[4]);
		//Parametric(square[1], square[5]);
		//Parametric(square[2], square[6]);
		//Parametric(square[3], square[7]);




	};

	RS_Shutdown();

}