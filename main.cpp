#include <QCoreApplication>

#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{

    const int n=10;
    //Индексная переменная:
    int i;
    //Массивы статистических значений:
    double x[n],y[n];
    //Параметры модели:
    double a,b;
    //Средние значения:
    double Sx=0,Sy=0,Sxy=0,Sxx=0;
    //Ввод сттистических данных:
    cout << "x = ";
    for(i=0; i < n; i++)
     cin >> x[i];
    cout << "y = ";
    for(i=0; i < n; i++)
     cin >> y[i];
    //Вычисление параметров модели:
    for(i=0; i < n; i++){
     Sx+=x[i];
     Sy+=y[i];
     Sxy+=x[i]*y[i];
     Sxx+=x[i]*x[i];
    }
    Sx/=n;
    Sy/=n;
    Sxy/=n;
    Sxx/=n;
    a=(Sx*Sy-Sxy)/(Sx*Sx-Sxx);
    b=(Sxy-a*Sxx)/Sx;
    //Результат:
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}



