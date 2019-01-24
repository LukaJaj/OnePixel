#pragma once
#define BITMAPINFOHEADER_H_
#include<cstdint>
#pragma pack(2)
struct BitmapInfoHeader {

	int32_t headerSize{ 40 };   
	int32_t width;
	int32_t height;
	int16_t planes{ 1 };        //int16_t possibly change with short but for portability I prefer int16_t 
	int16_t bitsPerPixel{ 24 };  //one byte (8x4)
	int32_t compression{ 0 };   
	int32_t dataSize{ 0 };    
	int32_t horizontalResolution{ 2400 };  //2400 bits for pixel
	int32_t verticalResolution{ 2400 };    
	int32_t colors{ 0 };
	int32_t importantColors{ 0 }; 
};