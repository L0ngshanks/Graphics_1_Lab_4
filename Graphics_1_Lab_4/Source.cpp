#include "Rasterizer.h"
#include "RasterSurface.h"

int main(int argc, char** argv)
{
	RS_Initialize(RASTER_WIDTH, RASTER_HEIGHT);

	while (RS_Update(Raster, NUM_PIXELS))
	{
		ClearScreen();


	};

	RS_Shutdown();

}