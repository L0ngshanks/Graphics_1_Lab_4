#include "Rasterizer.h"
#include "RasterSurface.h"

int main(int argc, char** argv)
{
	RS_Initialize(RASTER_WIDTH, RASTER_HEIGHT);

	VERTEX_4D square[12]
	{
		//{ {-.25, -.25, .25, 1}, 0xFFFFFFFF},
		//{ {.25, -.25, .25, 1}, 0xFFFFFFFF},
		//{ {.25, .25, .25, 1}, 0xFFFFFFFF},
		//{ {-.25, .25, .25, 1}, 0xFFFFFFFF},

		//{ {}, 0xFFFFFFFF},
		//{ {}, 0xFFFFFFFF},
		//{ {}, 0xFFFFFFFF},
		//{ {}, 0xFFFFFFFF},

		//{ {}, 0xFFFFFFFF},
		//{ {}, 0xFFFFFFFF},
		//{ {}, 0xFFFFFFFF},
		//{ {}, 0xFFFFFFFF};

	};

	VERTEX_4D test_inverse = { {7, 8, 5, 1}, 0xFFFFFFFF };
	MATRIX_4D test_inverse_4x4 = { 1, 0, 0, 0,
									0, 0.309, 0.951, 0,
									0, -.951, 0.309, 0,
									7, -2.282, 9.153, 1 };

	test_inverse_4x4 = Fast_Inverse(test_inverse_4x4);

	for(int x = 0; x < 4; ++x)
		for (int y = 0; y < 4; ++y)
		{
			std::cout << test_inverse_4x4.mat[x][y] << std::endl;
		}

	while (RS_Update(Raster, NUM_PIXELS))
	{
		ClearScreen();

		PixelShader = PS_ChangeColor;
		SP_Color = Red;

		Parametric(square[0], square[1]);
		Parametric(square[1], square[2]);
		Parametric(square[2], square[3]);
		Parametric(square[3], square[0]);

	};

	RS_Shutdown();

}