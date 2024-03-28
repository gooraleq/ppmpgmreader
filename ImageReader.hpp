#ifndef _IMAGE_READER_HPP_
#define _IMAGE_READER_HPP_

class ImageReader {
public:
	virtual void drukujInfoObrazu() = 0;
	virtual void drukujNajczestszyKolor() = 0;
	virtual int obliczLiczbeUnikalnychKolorow() = 0;
};

#endif