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
		{ {-.25, .25, -.25, 1}, 0xFFFFFFFF}
	};

	VERTEX_4D grid[40]
	{
		//Outline
		{{-.5, 0, -.5, 0}, 0xFFFFFFFF},
		{{.5, 0, -.5, 0}, 0xFFFFFFFF},
		{{.5, 0, .5, 0}, 0xFFFFFFFF},
		{{-.5, 0, .5, 0}, 0xFFFFFFFF},

		//Rows - Negative
		{{-.5, 0, -.1, 0}, 0xFFFFFFFF},
		{{.5, 0, -.1, 0}, 0xFFFFFFFF},
		{ {-.5, 0, -.2, 0}, 0xFFFFFFFF},
		{{.5, 0, -.2, 0}, 0xFFFFFFFF},
		{ {-.5, 0, -.3, 0}, 0xFFFFFFFF},
		{{.5, 0, -.3, 0}, 0xFFFFFFFF},
		{ {-.5, 0,-.4, 0}, 0xFFFFFFFF},
		{{.5, 0, -.4, 0}, 0xFFFFFFFF},

		//Rows - Positive
		{{-.5, 0, .1, 0}, 0xFFFFFFFF},
		{{.5, 0, .1, 0}, 0xFFFFFFFF},
		{ {-.5, 0, .2, 0}, 0xFFFFFFFF},
		{{.5, 0, .2, 0}, 0xFFFFFFFF},
		{ {-.5, 0, .3, 0}, 0xFFFFFFFF},
		{{.5, 0, .3, 0}, 0xFFFFFFFF},
		{ {-.5, 0, .4, 0}, 0xFFFFFFFF},
		{{.5, 0, .4, 0}, 0xFFFFFFFF},

		//Center - Row
		{{-.5, 0.0, 0, 0}, 0xFFFFFFFF},
		{{.5, 0.0, 0, 0}, 0xFFFFFFFF},
		//Center Collumn
		{{0, 0, -.5, 0}, 0xFFFFFFFF},
		{ {0, 0, .5, 0}, 0xFFFFFFFF},

		//Collumns Negative
		{ {-.1, 0, -.5, 0}, 0xFFFFFFFF},
		{ {-.1, 0, .5, 0}, 0xFFFFFFFF},
		{ {-.2, 0, -.5, 0}, 0xFFFFFFFF},
		{ {-.2, 0, .5, 0}, 0xFFFFFFFF},
		{ {-.3, 0, -.5, 0}, 0xFFFFFFFF},
		{ {-.3, 0, .5, 0}, 0xFFFFFFFF},
		{ {-.4, 0, -.5, 0}, 0xFFFFFFFF},
		{ {-.4, 0, .5, 0}, 0xFFFFFFFF},

		//Collumns Positive
		{ {.1, 0, -.5, 0}, 0xFFFFFFFF},
		{ {.1, 0, .5, 0}, 0xFFFFFFFF},
		{ {.2, 0, -.5, 0}, 0xFFFFFFFF},
		{ {.2, 0, .5, 0}, 0xFFFFFFFF},
		{ {.3, 0, -.5, 0}, 0xFFFFFFFF},
		{ {.3, 0, .5, 0}, 0xFFFFFFFF},
		{ {.4, 0, -.5, 0}, 0xFFFFFFFF},
		{ {.4, 0, .5, 0}, 0xFFFFFFFF}

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

		VertexShader = nullptr;

		PixelShader = PS_ChangeColor;
		SP_Color = White;

		//Outline
		Parametric(grid[0], grid[1]);
		Parametric(grid[1], grid[2]);
		Parametric(grid[2], grid[3]);
		Parametric(grid[3], grid[0]);

		//Negative Rows
		Parametric(grid[4], grid[5]);
		Parametric(grid[6], grid[7]);
		Parametric(grid[8], grid[9]);
		Parametric(grid[10], grid[11]);

		//Positive Row
		Parametric(grid[12], grid[13]);
		Parametric(grid[14], grid[15]);
		Parametric(grid[16], grid[17]);
		Parametric(grid[18], grid[19]);

		//Center Lines
		Parametric(grid[20], grid[21]);
		Parametric(grid[22], grid[23]);

		//Collumns Negative
		Parametric(grid[24], grid[25]);
		Parametric(grid[26], grid[27]);
		Parametric(grid[28], grid[29]);
		Parametric(grid[30], grid[31]);

		//Collumn Positive
		Parametric(grid[32], grid[33]);
		Parametric(grid[34], grid[35]);
		Parametric(grid[36], grid[37]);
		Parametric(grid[38], grid[39]);

		VertexShader = VS_World;
		SV_WorldMatrix = Matrix_Rotation_4D_Y(degree);

		PixelShader = PS_ChangeColor;
		SP_Color = Green;

		Parametric(square[0], square[1]);
		Parametric(square[1], square[2]);
		Parametric(square[2], square[3]);
		Parametric(square[3], square[0]);

		Parametric(square[4], square[5]);
		Parametric(square[5], square[6]);
		Parametric(square[6], square[7]);
		Parametric(square[7], square[4]);

		Parametric(square[0], square[4]);
		Parametric(square[1], square[5]);
		Parametric(square[2], square[6]);
		Parametric(square[3], square[7]);




	};

	RS_Shutdown();

}