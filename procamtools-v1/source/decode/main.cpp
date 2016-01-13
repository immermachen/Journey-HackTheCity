//
// Copyright (c) 2009-2011  Shuntaro Yamazaki (shun-yamazaki (at) aist.go.jp) 
//  and the National Institute of Advanced Industrial Science and Technology   
//
// $Id: decode.cpp 4546 2011-05-24 12:20:43Z shun $
//

#include "stdafx.h"

#include "decode.h"
#include <sstream>

void print_usage(const char *basename)
{
	const char *p = strrchr(basename, '//');
	if (p)
		p++;
	else
		p = basename;
	fprintf(stderr, "Usage: %s <options> <images....>/n", p);
	exit(-1);
}

int main(int argc, char *argv[])
{
	try
	{
		options_t option;
		option.load("options.ini");
		//CDecode decode(argv[1]);  
		
		//Loop all captured images
		//TODO d: means how many sets of images, now just use 1 time. 
		for (int d = 0; d < 2; d++)
		{
			CDecode decode(option);
			int numImages = option.get_num_bits(0) * 2 + option.get_num_bits(1) * 2 + option.num_fringes * 2;

			std::vector<std::string> files(numImages);
			std::ostringstream dir;
			//dir << "aCam1-";
			//dir << d;
			//dir << "/";
			dir << "D:/data/";
			//string path = dir.str();// "aCam1-/Capture-";
			string path = dir.str();// "aCam1-/Capture-";

			std::cout << "path = " << path << ":  numImages=" << numImages << std::endl;

			for (int i = 0; i < numImages; i++)
			{
				std::ostringstream oss;
				oss << path << d <<"-";
				if (i < 10)
					oss << "0";
				oss << i << ".bmp";
				files[i] = oss.str();
			}

			decode.Decode(files);

			std::ostringstream outdir;
			outdir << "decoded/" << d;
			
			decode.WriteMap(0, outdir.str() + "h.map");
			decode.WriteMap(1, outdir.str() + "v.map");
			decode.WriteModulation(0, outdir.str() + "h-modulation.map");
			decode.WriteModulation(1, outdir.str() + "v-modulation.map");
			decode.WriteMask(outdir.str() + "mask.bmp");
			decode.WriteReliable(outdir.str() + "reliable.bmp");

			std::cout << "-----------------------Finished Decoded: " << d << std::endl;
			//using opencv Mat

		}
	}
	catch(const std::exception & e)
	{
		fprintf(stderr, "exception: %s/n", e.what());
		return -1;
	}

	return 0;
}
