#pragma once
#include<string>
#include<cstdint>
using namespace std;

class Bitmap
{

private:
	int m_width{ 0 };
	int m_height{ 0 };
	unique_ptr<uint8_t[]>	m_Pixels{nullptr};
public: 
	Bitmap(int width, int height);
	void setPixel(int x, int y,uint8_t red,uint8_t green,uint8_t blue ); //uint8_t is basicly unsigned 8 bit int (unsigned char)

	bool write(string filename);
	virtual ~Bitmap();
};

