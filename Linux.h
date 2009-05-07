typedef unsigned long size_t;

#define GetRValue(rgb)   ((unsigned char) (rgb))
#define GetGValue(rgb)   ((unsigned char) ((rgb) >> 8))
#define GetBValue(rgb)   ((unsigned char) ((rgb) >> 16))
#define abs(x)           ((x)>0 ? (x) : -(x))
#define FLT_EPSILON 1.192092896e-07F 

struct POINT {
    double x,y;
};

struct RECT {
    double x,y;
    double width,height;
    double left() const;
    double right() const;
};

struct PIXELFORMATDESCRIPTOR {
  unsigned int nSize;
  unsigned int nVersion;
  unsigned long dwFlags;
  unsigned char iPixelType;
  unsigned char cColorBits;
  unsigned char cRedBits;
  unsigned char cRedShift;
  unsigned char cGreenBits;
  unsigned char cGreenShift;
  unsigned char cBlueBits;
  unsigned char cBlueShift;
  unsigned char cAlphaBits;
  unsigned char cAlphaShift;
  unsigned char cAccumBits;
  unsigned char cAccumRedBits;
  unsigned char cAccumGreenBits;
  unsigned char cAccumBlueBits;
  unsigned char cAccumAlphaBits;
  unsigned char cDepthBits;
  unsigned char cStencilBits;
  unsigned char cAuxBuffers;
  unsigned char iLayerType;
  unsigned char bReserved;
  unsigned long dwLayerMask;
  unsigned long dwVisibleMask;
  unsigned long dwDamageMask;
};

unsigned long GetTickCount();
void ZeroMemory(void* dest,size_t length);

