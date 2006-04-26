/*
 *  libcucul++    C++ bindings for libcucul
 *  Copyright (c) 2006 Jean-Yves Lamoureux <jylam@lnxscene.org>
 *                All Rights Reserved
 *
 *  $Id$
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the Do What The Fuck You Want To
 *  Public License, Version 2, as published by Sam Hocevar. See
 *  http://sam.zoy.org/wtfpl/COPYING for more details.
 */

/** \file cucul++.h
 *  \version \$Id$
 *  \author Jean-Yves Lamoureux <jylam@lnxscene.org>
 *  \brief The \e libcucul++ public header.
 *
 *  This header contains the public types and functions that applications
 *  using \e libcucul++ may use.
 */

#ifndef _CUCUL_PP_H
#define _CUCUL_PP_H

#include <cucul.h>


class Cucul;

/* Ugly, I know */
class Font
{
 public:
    ~Font();
    Font(void const *, unsigned int);
    char const *const * getList(void);
    unsigned int getWidth();
    unsigned int getHeight();
    void renderCanvas(Cucul *, unsigned char *, unsigned int, unsigned int, unsigned int);

 private:
    cucul_font *font;

};

class Dither
{
 public:
    Dither(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    ~Dither();

    void setPalette(unsigned int r[], unsigned int g[], unsigned int b[], unsigned int a[]);
    void setBrightness(float);
    void setGamma(float);
    void setContrast(float);
    void setInvert(int);
    void setAntialias(char const *);
    char const *const * getAntialiasList();
    void setColor(char const *);
    char const *const * getColorList();
    void setCharset(char const *);
    char const *const * getCharsetList();
    void setMode(char const *);
    char const *const * getModeList();
    void Bitmap(Cucul *, int, int, int, int, void *);

 private:
    cucul_dither *dither;

};

class Buffer
{
    friend class Cucul;
 public:
    Buffer(Cucul *cv, char const *);
    ~Buffer();
    char const *const * getExportList(void);

 protected:
    cucul_buffer *get_buffer();

 private:
    cucul_buffer *buffer;
};


class Cucul
{
    friend class Caca;
    friend class Dither;
    friend class Font;
    friend class Buffer;
  public:
    Cucul();
    Cucul(int width, int height);
    Cucul(Buffer *, char const *);
    ~Cucul();

    void setSize(unsigned int w, unsigned int h);
    unsigned int getWidth(void);
    unsigned int getHeight(void);
    void setColor(unsigned int f, unsigned int b);
    char const * getColorName(unsigned int color);
    void Printf(int x , int y , char const * format,...);
    void putChar(int x, int y, char ch);
    void putStr(int x, int y, char *str);
    void Clear(void);
    void Blit(int, int, Cucul* c1, Cucul* c2);
    void Invert();
    void Flip();
    void Flop();
    void Rotate();
    void drawLine(int, int, int, int, char const *);
    void drawPolyline(int const x[], int const y[], int, char const *);
    void drawThinLine(int, int, int, int);
    void drawThinPolyline(int const x[], int const y[], int);
    void drawCircle(int, int, int, char const *);
    void drawEllipse(int, int, int, int, char const *);
    void drawThinEllipse(int, int, int, int);
    void fillEllipse(int, int, int, int, char const *);
    void drawBox(int, int, int, int, char const *);
    void drawThinBox(int, int, int, int);
    void fillBox(int, int, int, int, char const *);
    void drawTriangle(int, int, int, int, int, int, char const *);
    void drawThinTriangle(int, int, int, int, int, int);
    void fillTriangle(int, int, int, int, int, int, char const *);
    int Rand(int, int);

  protected:
    cucul_canvas_t *get_cucul_canvas_t();

  private:
    cucul_canvas_t *cv;
};


#endif /* _CUCUL_PP_H */