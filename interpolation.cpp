#include "interpolation.h"

Interpolation::Interpolation(QImage *image)
{
    this->image = image;
    range =1;
}

QRgb Interpolation::getVertical(int x, double y)
{
  double sumWeight = 0;
  double sumR = 0, sumG = 0, sumB = 0;

  for(int j = top; j <= bottom; j++)
  {
    double dy = (double)j - y;
    double w = weight(dy);
    sumR += w * getRed(x, j);
    sumG += w * getGreen(x, j);
    sumB += w * getBlue(x, j);
    sumWeight += w;
  }

  sumR /= sumWeight;
  sumG /= sumWeight;
  sumB /= sumWeight;
  if(sumR > 255) sumR = 255;
  if(sumG > 255) sumG = 255;
  if(sumB > 255) sumB = 255;
  if(sumR < 0) sumR = 0;
  if(sumG < 0) sumG = 0;
  if(sumB < 0) sumB = 0;
  return qRgb((int)sumR, (int)sumG, (int)sumB);
}

QRgb Interpolation::getHorizontal(double x, double y)
{


  top = (int)(y - range);
  bottom = (int)(y + range);
  left = (int)(x - range);
  right = (int)(x + range);
  if(top < 0) top = 0;
  if(bottom > image->height()- 1) bottom = image->height() - 1;
  if(left < 0) left = 0;
  if(right > image->width() - 1) right = image->width() - 1;

  double sumWeight = 0;
  double sumR = 0, sumG = 0, sumB = 0;

  for(int i = left; i <= right; i++)
  {
    double dx = (double)i - x;
    double w = weight(dx);
    QRgb vval = getVertical(i, y);
    sumR += w * qRed(vval);
    sumG += w * qGreen(vval);
    sumB += w * qBlue(vval);
    sumWeight += w;
  }

  sumR /= sumWeight;
  sumG /= sumWeight;
  sumB /= sumWeight;

  if(sumR > 255) sumR = 255;
  if(sumG > 255) sumG = 255;
  if(sumB > 255) sumB = 255;
  if(sumR < 0) sumR = 0;
  if(sumG < 0) sumG = 0;
  if(sumB < 0) sumB = 0;
  return qRgb((int)sumR, (int)sumG, (int)sumB);
}

  double Interpolation::weight(double dx)
  {
    if(dx < 0)
      dx = -dx;

    if(dx > range)
      return 0;

    if(dx < 1)
    {
            double dx2 = dx * dx;
            return 0.5 * (dx * dx2) - dx2 + 2.0/3.0;
    }

    dx = 2.0 - dx;
    return 1.0/6.0 * dx * dx * dx;
  }


/*
double Interpolation::weight(double dx)
{
  if(dx < 0.0)
    dx = -dx;

  if(dx > range)
    return 0;

  return 1 - dx;
}
*/
