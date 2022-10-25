#pragma once

#include <vector>

struct Color {
	float r, g, b;

	Color();
	Color(float r, float g, float b);
	~Color();
};

class Image
{
public:
	Image(int width, int height);
	~Image();

	Color getColor(int x, int y) const;
	void setColor(const Color& color, int x, int y);

	void Export(const char* path);
	
private:
	int m_width;
	int m_height;
	std::vector<Color> m_colors;
};