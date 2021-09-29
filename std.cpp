#include<bits/stdc++.h>
using namespace std;
class Point
{
public:
    double x,y;
    Point(double _x=0,double _y=0):x(_x),y(_y) {}
    Point operator - (Point p)
    {
        return Point(x-p.x,y-p.y);
    }double norm()
    {
        return x*x+y*y;
    }
    double ABS()
    {
        return sqrt(norm());   //俩点间的距离
    }
    
    
};
struct Segment
{
    Point p1,p2;
};
double cross(Point a,Point b)//求向量积
{
    return a.x*b.y-a.y*b.x;
}
double dot(Point a,Point b)//求数量积
{
    return a.x*b.x+a.y*b.y;
}



int ccw(Point p0,Point p1,Point p2)//判断三个点相对位置
{
    Point a=p1-p0;
    Point b=p2-p0;
    if(cross(a,b)>0) return 1;//p0,p1,p2成逆时针方向
    if(cross(a,b)<0) return -1;//p0,p1,p2成顺时针方向
    if(dot(a,b)<0) return 2;//p2 p0 p1一次排列在同一直线上
    if(a.norm()<b.norm()) return -2;// p0 p1 p2一次排列在同一直线上
    return 0;//p2在线段p0p1上

}
bool intersect(Point p1,Point p2,Point p3,Point p4)
{
    return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}
int main()
{   //freopen("ooo.in","r",stdin);
    //freopen("oo.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double x0,y0,x1,y1,x2,y2,x3,y3;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x0,&y0,&x1,&y1,&x2,&y2,&x3,&y3);
        Point p0(x0,y0),p1(x1,y1),p2(x2,y2),p3(x3,y3);
        if(intersect(p0,p1,p2,p3)) printf("1\n");
        else printf("0\n");
    }

    return 0;
}