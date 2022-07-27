#include <iostream>

using namespace std;

enum class ImgType { JPG, PNG, BMP };

struct Img
{
	char name[20];
	int width;
	int height;
	ImgType type;
};

void showImg(Img*);

int main()
{
	Img img = { "backg.png", 1920, 1080, ImgType::PNG };

	showImg(&img);
	
	return 0;
}

void showImg(Img* imgPtr)
{
	cout << "The image \"" << imgPtr->name << "\" of size " <<
			imgPtr->width << 'x' << imgPtr->height << " is of format " << 
			(
				imgPtr->type == ImgType::PNG ? 
				"PNG" : 
				(
					imgPtr->type == ImgType::JPG ? 
					"JPG" : 
					"BMP"
				)
			) << ".\n";
}
