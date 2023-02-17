#pragma once
#include "Image.h"
#include <iostream>
#include  <fstream>
#define BLACK 0
#define WHITE 1
#define RED 2
Color::Color() :r(0), g(0), b(0)
{
}

Color::Color(float r, float g, float b) :r(r), g(g), b(b)
{
}

Color::~Color()
{
}

Image::Image(int width, int height) :m_width(width), m_height(height), m_colors(std::vector<Color>(width * height))
{
}

Image::~Image()
{
}







void Image::setColors(int x, int y, char**grid)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			switch(grid[y - i - 1][j])
			{
				case '?':
				setColor(Color(1, 1, 1), j, i);
				break;
				case ' ':
					setColor(Color(1, 1, 1), j, i);
					break;
				case '.':
					setColor(Color(1,0,0), j, i);
					if (i > 0 && j > 0 && j < m_width - 1)
					{
						setColor(Color(1, 0, 0), j + 1, i);
						setColor(Color(1, 0, 0), j - 1, i);
						setColor(Color(1, 0, 0), j, i + 1);
					}
					break;
				case '@':
					setColor(Color(0, 0, 1), j, i);
					break;
				case '!':
					setColor(Color(0, 1, 1), j, i);
					break;
				default:
					setColor(Color(0, 0, 0), j, i);

			}
		}
	}
}


Color Image::getColor(int x, int y) const
{
	return m_colors[y * m_width + x];
}

void Image::setColor(const Color& color, int x, int y)
{
	m_colors[y * m_width + x].r = color.r;
	m_colors[y * m_width + x].g = color.g;
	m_colors[y * m_width + x].b = color.b;

}

void Image::Export(const char* path)
{
	std::ofstream f;
	f.open(path, std::ios::out | std::ios::binary);

	if (!f.is_open())
	{
		std::cout << "File could not be opened\n";
		return;
	}

	unsigned char bmPad[3] = { 0, 0, 0 };
	const int paddingAmount = ((4 - (m_width * 3) % 4) % 4);

	const int fileHeaderSize = 14;
	const int informationHeaderSize = 40;
	const int fileSize = fileHeaderSize + informationHeaderSize + m_width * m_height * 3 + paddingAmount * m_height;

	unsigned char fileheader[fileHeaderSize];

	fileheader[0] = 'B';
	fileheader[1] = 'M';

	fileheader[2] = fileSize;
	fileheader[3] = fileSize >> 8;
	fileheader[4] = fileSize >> 16;
	fileheader[5] = fileSize >> 24;

	fileheader[6] = 0;
	fileheader[7] = 0;
	fileheader[8] = 0;
	fileheader[9] = 0;

	fileheader[10] = fileHeaderSize + informationHeaderSize;
	fileheader[11] = 0;
	fileheader[12] = 0;
	fileheader[13] = 0;

	unsigned char informationHeader[informationHeaderSize];

	informationHeader[0] = informationHeaderSize;
	informationHeader[1] = 0;
	informationHeader[2] = 0;
	informationHeader[3] = 0;

	informationHeader[4] = m_width;
	informationHeader[5] = m_width >> 8;
	informationHeader[6] = m_width >> 16;
	informationHeader[7] = m_width >> 24;

	informationHeader[8] = m_height;
	informationHeader[9] = m_height >> 8;
	informationHeader[10] = m_height >> 16;
	informationHeader[11] = m_height >> 24;

	informationHeader[12] = 1;
	informationHeader[13] = 0;

	informationHeader[14] = 24;
	informationHeader[15] = 0;

	informationHeader[16] = 0;
	informationHeader[17] = 0;
	informationHeader[18] = 0;
	informationHeader[19] = 0;
	informationHeader[20] = 0;
	informationHeader[21] = 0;
	informationHeader[22] = 0;
	informationHeader[23] = 0;
	informationHeader[24] = 0;
	informationHeader[25] = 0;
	informationHeader[26] = 0;
	informationHeader[27] = 0;
	informationHeader[28] = 0;
	informationHeader[29] = 0;
	informationHeader[30] = 0;
	informationHeader[31] = 0;
	informationHeader[32] = 0;
	informationHeader[33] = 0; 
	informationHeader[34] = 0;
	informationHeader[35] = 0;
	informationHeader[36] = 0;
	informationHeader[37] = 0;
	informationHeader[38] = 0;
	informationHeader[39] = 0;

	f.write(reinterpret_cast<char*>(fileheader), fileHeaderSize);
	f.write(reinterpret_cast<char*>(informationHeader), informationHeaderSize);

	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			unsigned char r = static_cast<unsigned char>(getColor(x, y).r * 255.0f);
			unsigned char g = static_cast<unsigned char>(getColor(x, y).g * 255.0f);
			unsigned char b = static_cast<unsigned char>(getColor(x, y).b * 255.0f);

			unsigned char color[] = { b, g, r };

			f.write(reinterpret_cast<char*>(color), 3);
		}
		f.write(reinterpret_cast<char*>(bmPad), paddingAmount);
	}
	f.close();
	
	std::cout << "File Created\n";
}
