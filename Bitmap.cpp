#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"
#include <fstream>

using namespace std;

Bitmap::Bitmap(int width, int height) :m_Pixels(new uint8_t[width*height * 3]{})  //every pixel have 3 bites  
																				  // new returns null
{
	this->m_width = width;
	this->m_height = height;
		
}
void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{

	uint8_t *pPixel = m_Pixels.get();            //pointer whole memory block that represents whole screen
	pPixel +=	(y *3) *m_width + (x*3);        //number of pixels

	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;

}
bool Bitmap::write(string filename) {

	BitmapFileHeader fileheader; //fileheader contains information about file							
	BitmapInfoHeader infoheader; //infoheader contains information about bitmap struct
	fileheader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
	fileheader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoheader.width = m_width;
	infoheader.height = m_height;


	ofstream file;
	file.open(filename, ios::out | ios::binary);
	if (!file) {
		return false;
	}

	
	file.write((char *)&fileheader, sizeof(fileheader));
	file.write((char *)&infoheader, sizeof(infoheader));
	file.write((char *)m_Pixels.get(), m_width*m_height*3);

	file.close();

	if (!file) {
	
		return false;
	}
	return true;
}
Bitmap::~Bitmap()
{
}

