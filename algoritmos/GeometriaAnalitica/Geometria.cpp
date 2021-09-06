#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x, y; //Las coordenadas x, y del punto


    Point(double a,double b) { //Constructor para el punto
        x = a;
        y = b;
    }

    double angle() { 
        return atan2(y,x);
    }

    double mod() { 
        return sqrt(x*x+y*y);
    }

    Point unit() {
        double modulo = mod();
        return Point(x/modulo, y/modulo);
    }
};

Point operator +(const Point &a, const Point &b) { 
    return Point(a.x + b.x, a.y + b.y);
}

Point operator -(const Point &a, const Point &b) { 
    return Point(a.x - b.x, a.y-b.y);
}

Point operator *(const Point &a, double k) { 
    return Point(a.x*k,a.y*k);
}

Point operator /(const Point &a, double k) {
    return Point(a.x/k, a.y/k);
}

bool operator <(const Point &a, const Point &b) { 
    if(a.x != b.x) {
        return a.x < b.x;
    } else {
        return  a.y < b.y;
    }
}

ostream& operator<<(ostream&os, Point p) {

    return os <<"("<<p.x<< "," << p.y <<")";

}

double dist(const Point &A, const Point &B) { 
    return hypot(A.x-B.x,A.y - B.y);
}

double dot(const Point &A, const Point &B) { 
    return A.x * B.x + A.y * B.y;
}

double cross(const Point &V, const Point &U) { 
    return V.x * U.y - V.y * U.x;
}

double areaP(const Point &V, const Point &U) { 
    return abs(cross(V,U));
}

// Area de 3 puntos

double area(const Point &A, const Point &B, const Point &C) {
    return cross(B - A, C - A);
}

double areaTriangulo(const Point &A, const Point &B, const Point &C) { 
    return abs(area(A,B,C))/2.0;
}

double areaHeron(double a, double b, double c) {
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

Point lineIntersection(const Point &A,const Point &B,const Point &C,const Point &D) { 
    return A+(B-A)*(cross(C-A,D-C)/cross(B-A,D-C));
}

bool onSegment(const Point &A, const Point&B, const Point &P) {
    return areaTriangulo(A,B,P) == 0 && 
    (P.x >= min(A.x,B.x) && P.x <= max(A.x,B.x)) &&
    (P.y >= min(A.y,B.y) && P.y <= max(A.y,B.y)); 
}

bool intersectsSegment(const Point &A,const Point &B,const Point &C,const Point &D) {
    double A1 = area(C,A,D); 
    double A2 = area(C,B,D); 
    double A3 = area(A,B,C);  
    double A4 = area(A,B,D);  

    if(((A1 > 0 && A2 < 0) || (A1<0 && A2>0)) && 
    ((A3 > 0 && A4 < 0) || (A3<0 && A4>0)))  {
        return true;
    }

    if(A1 == 0 && onSegment(C,D,A)) { 
        return true;
    }

    if(A2 == 0 && onSegment(C,D,B)) {
        return true;
    }

    if(A3 == 0 && onSegment(A,B,C)) {
        return true;
    }

    if(A4 == 0 && onSegment(A,B,D)) {
        return true;
    }

    return false;
}



// poligono Convexo o No convexo

bool isConvex(const vector<Point> &polign) {
    int nroPoints = polign.size();
    int areasPositive =  0, areasNegative = 0;
    for(int i = 0; i < nroPoints ;i++) {
        double areaPoints = area(polign[i],polign[(i+1)%nroPoints],polign[(i+2)%nroPoints]);
        if(areaPoints>0) {
            areasPositive++;
        } else if(areaPoints<0) {
            areasNegative++;
        }
    }
    return areasPositive == 0 || areasNegative == 0;
}

// Area de un Poligono

double areaPoligono(const vector<Point> &poligono) {
    int nroPoints = poligono.size();
    double areaTotal = 0;
    for(int i = 1; i < nroPoints - 1; i++) {
        areaTotal += area(poligono[0],poligono[i],poligono[i+1]);
    }
    return abs(areaTotal/2);
}

int main() {

    Point A(0,0);
    Point B(1,0);
    cout<<A+B<<endl;

    return 0;


}
