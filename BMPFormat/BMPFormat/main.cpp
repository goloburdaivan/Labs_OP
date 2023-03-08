#include<iostream>
#include<fstream>
#include<errno.h>

#pragma pack(push, 1)
struct BMPHEAD {
    int8_t type[2] = { 'B', 'M' };
    int32_t size = 54 + 786432;
    int16_t reserved1 = 0;
    int16_t reserved2 = 0;
    int32_t offset = 54;

} bmpHeader;
#pragma pack(pop)

#pragma pack(push, 1)
struct BmpInfoHeader {
    uint32_t sizeOfThisHeader = 40;
    int32_t width = 512;
    int32_t height = 512;
    uint16_t numberOfColorPlanes = 1;
    uint16_t colorDepth = 24;
    uint32_t compressionMethod = 0;
    uint32_t rawBitmapDataSize = 0;
    int32_t horizontalResolution = 3780;
    int32_t verticalResolution = 3780;
    uint32_t colorTableEntries = 0;
    uint32_t importantColors = 0;
} bmpInfoHeader;
#pragma pack(pop)

#pragma pack(push, 1)
struct Pixel {
    uint8_t blue = 0;
    uint8_t green = 0;
    uint8_t red = 255;
} pixel;
#pragma pack(pop)

int main() {

    std::ofstream file("./test.bmp", std::ios::binary);
    file.write((char*)&bmpHeader, sizeof(bmpHeader));
    file.write((char*)&bmpInfoHeader, sizeof(bmpInfoHeader));

    for (int i = 0; i < bmpInfoHeader.width * bmpInfoHeader.height; i++) {
        if (i >= 131072) {
            Pixel pixel;
            pixel.blue = 184;
            pixel.green = 87;
            pixel.red = 0;
            file.write((char*)&pixel, 3);
        }
        else {
            Pixel pixel;
            pixel.red = 255;
            pixel.green = 216;
            pixel.blue = 0;
            file.write((char*)&pixel, 3);
        }

    }

    file.close();

	return 0;
}