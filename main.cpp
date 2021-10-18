#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

float GetDotProduct(Vector3f& a,Vector3f& n)
{
  return ((a.x*n.x)+(a.y*n.y)+(a.z*n.z));
};

Vector3f GetCrossProduct(Vector3f& a,Vector3f& n)
{
  return {(a.y*n.z - a.z*n.y),(a.z*n.x - a.x*n.z),(a.x*n.y - a.y*n.x)};
};

Vector3f Projection(Vector3f& a,Vector3f& n)
{
    Vector3f tempN = {n*(GetDotProduct(a,n)/ GetDotProduct(n,n))};
    return {a-tempN};
};

// TODO : mirar esta funcion.
Vector3f Reflection(Vector3f& a, Vector3f& n)
{
    Vector3f TempA = {a.x*-1,a.y*-1,a.z*-1};
    float Prod = GetDotProduct(TempA,n);
    return {2.0f*(Prod*n+a)};
}

int main()
{
    Vector3f a={-0.71f,0.0f,0.71f};
    Vector3f n={1,0,0};
    Vector3f b={1,1,3};
    Vector3f c={2,0,5};

    Vector3f proA ={-0.6,0,-0.8};
    Vector3f NegProA = {-proA.x,-proA.y,-proA.z};
    Vector3f proN ={0.71,0,0.71};

    return 0;
}
