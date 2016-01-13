//
// Copyright (c) 2009-2011  Shuntaro Yamazaki (shun-yamazaki (at) aist.go.jp) 
//  and the National Institute of Advanced Industrial Science and Technology   
//
// $Id: main.cpp 4590 2011-05-30 22:13:45Z shun $
//

#include "stdafx.h"

#include "Field.h"
#include "ImageBmpIO.h"

#include "calibrate.h"

#undef min
#undef max

void print_usage(const char *argv0)
{
	const char *prog = strrchr(argv0, '\\');
	if (prog)
		prog++;
	else
		prog = argv0;
	printf("Usage: %s <options> <h.map> <v.map> <mask.bmp>\n",prog);
	exit(-1);
}

int main(int argc, char *argv[]) 
{
	try 
	{
		char* numCam = argv[1];

		if (*numCam == '0')
		{

			std::cout << "Use Camera=" << *numCam << std::endl;
			// parse commandline options
			//if (argc!=5) print_usage(argv[0]);

			// load correspondences estimated by decode program 
			//slib::Field<2,float> horizontal(argv[2]);
			//slib::Field<2,float> vertical(argv[3]);  
			slib::Field<2, float> horizontal("decoded//0h.map");
			slib::Field<2, float> vertical("decoded//0v.map");

			slib::Field<2, float> mask;
			//slib::image::Read(mask, argv[4]);
			slib::image::Read(mask, "decoded//0reliable.bmp");

			//CProCamCalibrate calib(argv[1]);
			CProCamCalibrate calib("decoded//0options.ini");
			calib.Calibrate(horizontal, vertical, mask);

			calib.WriteCamIntrinsic("decoded//0cam-intrinsic.txt");
			calib.WriteCamDistortion("decoded//0cam-distortion.txt");
			calib.WriteProIntrinsic("decoded//0pro-intrinsic.txt");
			calib.WriteProDistortion("decoded//0pro-distortion.txt");
			calib.WriteProExtrinsic("decoded//0pro-extrinsic.txt");
		}
		else if (*numCam == '1')
		{

			std::cout << "Use Camera=" << *numCam << std::endl;
			// parse commandline options
			//if (argc!=5) print_usage(argv[0]);

			// load correspondences estimated by decode program 
			//slib::Field<2,float> horizontal(argv[2]);
			//slib::Field<2,float> vertical(argv[3]);  
			slib::Field<2, float> horizontal("decoded//1h.map");
			slib::Field<2, float> vertical("decoded//1v.map");

			slib::Field<2, float> mask;
			//slib::image::Read(mask, argv[4]);
			slib::image::Read(mask, "decoded//1reliable.bmp");

			//CProCamCalibrate calib(argv[1]);
			CProCamCalibrate calib("decoded//1options.ini");
			calib.Calibrate(horizontal, vertical, mask);

			calib.WriteCamIntrinsic("decoded//1cam-intrinsic.txt");
			calib.WriteCamDistortion("decoded//1cam-distortion.txt");
			calib.WriteProIntrinsic("decoded//1pro-intrinsic.txt");
			calib.WriteProDistortion("decoded//1pro-distortion.txt");
			calib.WriteProExtrinsic("decoded//1pro-extrinsic.txt");
		}
		else
		{
			std::cout << "Select a Camera Number 0 or 1: e.g.: calibrator.exe 0" << std::endl;

		}
	} 
	catch (const std::exception& e) 
	{
		fprintf(stderr,"error: %s\n", e.what());
		return -1;
	}

	return 0;
}

