#include "parkinglot.h"
using namespace std;
#include <vector>

void Vehicle::rotate(double *direction_list,double angle) {
    *direction_list+=angle;
}
void Car::draw() {
    for(int i=0;i<4;i++)
    {
        fig[i]->draw();
    }
}

Car::Car(Vec anchor_, double direction_) {
    //initialize
    anchor=anchor_;
    direction=direction_;
    double l=0.1;
    Vec p1,p2,p3,p4;
    //rectangle
    p1={-l,-l};
    p2={l,0};
    fig[0]=new Rectang(anchor,p1,p2);
    //trapezium
    p1={-0.75*l,0};
    p2={-0.5*l,0.5*l};
    p3={0.5*l,0.5*l};
    p4={0.75*l,0};
    fig[1]=new Trapezium(anchor,p1,p2,p3,p4);
    //circle1
    p1={-0.5*l,-l};
    fig[2]=new Circle(anchor,p1,0.25*l);
    //circle2
    p1={0.5*l,-l};
    fig[3]=new Circle(anchor,p1,0.25*l);
    for(int i=0;i<4;i++)
    {
        fig[i]->rotate(direction);
    }
}

Car::~Car() {
    for(int i=0;i<4;i++)
    {
        delete fig[i];
    }
}


int Car::gotolot(Vec *anchor_list,double *direction_list,
                 int position,double *direction2_list,double *l_list,int *flag,int *flag2) {
    *l_list/=1;
    *flag/=1;
    *flag2/=1;
    return movetolot(anchor_list,direction_list,position,direction2_list,flag);
}
UFO::UFO(Vec anchor_, double direction_,double direction2_) {
    //initialize
    anchor=anchor_;
    direction=direction_;
    direction2=direction2_;
    Vec p1,p2;
    double r=0.1;
    //halfcirciel;
    p1={0,0};
    fig[0]=new HalfCircle(anchor,p1,r,0);
    //line1
    p1={-TWO*r,TWO*r};
    p2={-2*TWO*r,2*TWO*r};
    fig[1]=new Line(anchor,p1,p2);
    //line2
    p1={TWO*r,TWO*r};
    p2={2*TWO*r,2*TWO*r};
    fig[2]=new Line(anchor,p1,p2);
    //rectangle1
    p1={-0.75*r,-0.1*r};
    p2={-0.25*r,0};
    fig[3]=new Rectang(anchor,p1,p2);
    //rectangle2
    p1={0.25*r,-0.1*r};
    p2={0.75*r,0};
    fig[4]=new Rectang(anchor,p1,p2);
    for(int i=1;i<5;i++)
    {
        fig[i]->rotate(direction_);
    }
    fig[0]->rotate(direction_);
    for(int i=1;i<5;i++)
    {
        fig[i]->rotate(direction2_);
    }
    fig[0]->rotate(direction2_);
}

UFO::~UFO() {
    for(int i=0;i<5;i++)
    {
        delete fig[i];
    }
}

void UFO::draw() {
    for(int i=0;i<5;i++)
    {
        fig[i]->draw();
    }
}

int UFO::gotolot(Vec *anchor_list,double *direction_list,
                 int position,double *direction2_list,double *l_list,int *flag,int *flag2) {
    rotate(direction2_list,0.2);
    *l_list/=1;
    *flag2/=1;
    return movetolot(anchor_list,direction_list,position,direction2_list,flag);
}

Spacecraft::Spacecraft(Vec anchor_, double direction_,double l_) {
    //initialize
    anchor=anchor_;
    direction=direction_;
    l=l_;
    Vec p1,p2,p3;
    //rectangle
    p1={-l,-3*l};
    p2={l,2*l};
    fig[0]=new Rectang(anchor,p1,p2);
    //triangle1
    p1={-l,2*l};
    p2={0,3*l};
    p3={l,2*l};
    fig[1]=new Triangle(anchor,p1,p2,p3);
    //triangle2
    p1={-2.5*l,-2*l};
    p2={-l,0};
    p3={-l,-2*l};
    fig[2]=new Triangle(anchor,p1,p2,p3);
    //triangle3
    p1={2.5*l,-2*l};
    p2={l,0};
    p3={l,-2*l};
    fig[3]=new Triangle(anchor,p1,p2,p3);
    for(int i=0;i<4;i++)
    {
        fig[i]->rotate(direction);
    }
}

Spacecraft::~Spacecraft() {
    for(int i=0;i<4;i++)
    {
        delete fig[i];
    }
}

void Spacecraft::draw() {
    for(int i=0;i<4;i++)
    {
        fig[i]->draw();
    }
}

void Spacecraft::zoom(double *l_list,int *flag2) {
    if(l>=0.007&&*flag2==0)
    {
        *l_list/=1.01;
    }
    else if(l<=0.03)
    {
        *flag2=1;
        *l_list*=1.01;
    }
    else
    {
        *flag2=0;
    }
}

int Spacecraft::gotolot(Vec *anchor_list,double *direction_list,
                        int position,double *direction2_list,double *l_list,int *flag,int *flag2) {
    zoom(l_list,flag2);
    *l_list/=1;
    return movetolot(anchor_list,direction_list,position,direction2_list,flag);
}
Teleported::Teleported(Vec anchor_, double direction_) {
    //initialize
    anchor=anchor_;
    direction=direction_;
    double r,g,b;
    double l=0.18;
    Vec p1,p2;
    p1={-unit/2.2,-l};
    p2={unit/2.2,l};
    paint(&r,&g,&b);
    fig[0]=new Rectang(anchor,p1,p2,r,g,b);
}
void Teleported::paint(double *r, double *g, double *b) {
    srand((unsigned int)time(nullptr));
    *r=(double)rand()/RAND_MAX;
    *g=(double)rand()/RAND_MAX;
    *b=(double)rand()/RAND_MAX;
}
Teleported::~Teleported() {
    delete fig[0];
}
void Teleported::draw() {
    fig[0]->draw();
}
int Lot::getposition(){return position;}
int Lot::getstate(){return state;}
Lot::Lot(int position_,int state_)
{
    position=position_;
    state=state_;
}

bool Lot::isempty()
{
    if(state==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Parking::~Parking()
{
    if(status==1)
    {
        for (int i = 0; i < MAX; i++)
        {
            delete a[i];
        }
        for (int i = 0; i < 15; i++)
        {
            delete fig[i];
        }
    }
    else
    {
        for(int i=0;i<num;i++)
        {
            delete a0[i];
        }
        delete[] b;
    }

}
Parking::Parking(int size_,int num_,Vec *anchor_list,double *direction_list,double *direction2_list,
                 double *l_list,int *rand_list)
{
    status = 1;
    size=size_;
    num=num_;
    Vec anchor_;
    for(int i=0;i<num;i++)
    {
        switch(rand_list[i]%3)
        {
            case 0:
                a[i]=new Car(anchor_list[i],direction_list[i]);
                break;
            case 1:
                a[i]=new UFO(anchor_list[i],direction_list[i],direction2_list[i]);
                break;
            case 2:
                a[i]=new Spacecraft(anchor_list[i],direction_list[i],l_list[i]);
                break;
        }
    }
    anchor_={-2*unit,-0.8};
    a[num]=new Teleported(anchor_,0);
    anchor_={2*unit,0.8};
    a[num+1]=new Teleported(anchor_,0);
    Vec anchor={0,0};
    Vec p1,p2;
    //12lines
    for(int i=0;i<7;i++)
    {
        p1={-3.5*unit+i*unit,0.6};
        p2={-3.5*unit+i*unit,1};
        fig[i]=new Line(anchor,p1,p2);
    }
    for(int i=0;i<7;i++)
    {
        p1={-3.5*unit+i*unit,-0.6};
        p2={-3.5*unit+i*unit,-1};
        fig[i+7]=new Line(anchor,p1,p2);
    }
    //rectangle
    p1={-0.625,-0.2};
    p2={0.625,0.2};
    fig[14]=new Rectang(anchor,p1,p2,0.1,0.3,0.6,0.7);
}
void Parking::draw() {
    for(int i=0;i<15;i++)
    {
        fig[i]->draw();
    }
    for(int i=0;i<num+2;i++)
    {
        a[i]->draw();
    }
}

void Parking::run(Vec *anchor_list, double *direction_list, double *direction2_list,
                  double *l_list, int *flag, int *flag2)
{
    for (int i = 0; i < num; i++)
    {
        if (i<1)    
        {    
         
           if(a[i]->gotolot(&anchor_list[i],&direction_list[i],i+1,
            
                         &direction2_list[i],&l_list[i],&flag[i],&flag2[i]))
            {}
            else{
                break;
            }
        } 

        else  if(i< 5) 
        {    
            if(a[i]->gotolot(&anchor_list[i],&direction_list[i],i+2,
                             &direction2_list[i],&l_list[i],&flag[i],&flag2[i]))
            {}  
            else{
                  break;
            }  
        }  
         else  
        {
             if(a[i]->gotolot(&anchor_list[i],&direction_list[i],i+3 , 
                          &direction2_list[i],&l_list[i],&flag[i],&flag2[i]))
            {}  
            else{
                break;
            }}     
    }
}  
void Vehicle::move(Vec *anchor_list,Vec path) {
    Vec dis=(path)<<direction;
    *anchor_list=*anchor_list+dis;
}
int Vehicle::movetolot(Vec *anchor_list,double *direction_list,
                       int position,double *direction2_list,int *flag)
{
    double dis=0.05;
    double angle=0.11;
    *direction2_list/=1;
    if(position<=6)
    {
        if((*anchor_list).getX()<-3.2*unit+(position+1)*unit&&*flag==0)
        {
            move(anchor_list,{dis,0});
            return 0;
        }
        else if(*direction_list<=PI/2)
        {
            *flag=1;
            move(anchor_list,{-dis,0});
            rotate(direction_list,angle);
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else {
        angle = 0.15;
        if ((*anchor_list).getX() < 2 * unit && *flag == 0) {
            move(anchor_list, {dis, 0});
            return 0;
        } else if (*direction_list <= PI && *flag != 2) {
            *flag = 1;
            move(anchor_list, {dis, 0});
            rotate(direction_list, angle);
            return 0;
        } else if ((*anchor_list).getX() > 3.2 * unit - (position - 4) * unit && *flag != 3) {
            *flag = 2;
            rotate(direction_list, 0);
            move(anchor_list, {dis, 0});
            return 0;
        } else if (*direction_list <= PI * 3 / 2) {
            *flag = 3;
            angle = 0.11;
            move(anchor_list, {-dis, 0});
            rotate(direction_list, angle);
            return 0;
        } else {
            return 1;
        }
    }
}

void glDraw()
{
    static double direction_list[MAX]={0};
    static double direction2_list[MAX]={0};
    static int rand_list[MAX]={0};
    static double l_list[MAX]={0.03,0.03,0.03,0.03,0.03,0.03,0.03,0.03,0.03,0.03,0.03,0.03};
    static int flag2[MAX]={0};
    static int flag[MAX]={0};
    static Vec anchor_list[MAX];
    static int pos = 0;
     srand((unsigned int)time(nullptr));
     if(pos==0)
     {
          for(int i=0;i<MAX;i++)
     {
         int ran=rand()%3;
         rand_list[i]=ran;
     }
     pos = 1;
     }
     Parking p(12, 10, anchor_list, direction_list, direction2_list, l_list, rand_list);
     glClearColor(1.0, 1.0, 1.0, 0.0);
     glClear(GL_COLOR_BUFFER_BIT);
     glEnable(GL_BLEND);
     glDisable(GL_DEPTH);
     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
     p.run(anchor_list, direction_list, direction2_list, l_list, flag, flag2);
     p.draw();
     glDisable(GL_BLEND);
     glutSwapBuffers();
     p.run(anchor_list,direction_list,direction2_list,l_list,flag,flag2);
    p.draw();
    glDisable(GL_BLEND);
    glutSwapBuffers();
    glFlush();
}

void TimeStep(int n)
{
    glutTimerFunc((unsigned int)n, TimeStep, n); glutPostRedisplay();
}
void help(){
    printf("*********************************Welcome to the Parking Lot!*****************************************\n");
    printf("-h                        Print this help message\n");
    printf("-n n                      n cars , n must be larger than 2 less than 12              (default: 5)\n");
    printf("-s s                      Parkinglot has s slots, s must be at least 2 at most 10    (default: 5)\n");
    printf("-m                        Run in which mode, 0 for regular, 1 for interstellar       (default: 0)\n");
    printf("*****************************************************************************************************\n"); // ?????????????????
}
int main(int argc,char *argv[]) {
    int i,num=5,size=5,mode=0;
    for ( i = 1; i < argc; i++){
        if ((argv[i][0])!='-'){
            printf("You input the wrong parameter!");
            return 1; 
        }
        switch (*(argv[i] + 1)){
            case 'h':
                help();
                return 0;
            case 'n':
                num = atoi(argv[i + 1]);  i++;
                break;
            case 's':
                size = atoi(argv[i + 1]); i++;
                break;
            case 'm':
                mode = atoi(argv[i + 1]); i++;
                break;
        }
    }
    if (mode==1) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
        glutCreateWindow("Parkinglot");
        glClearColor(1.0, 1.0, 1.0, 0.0); glClear(GL_COLOR_BUFFER_BIT);
        glutDisplayFunc(glDraw);
        glutTimerFunc(50, TimeStep, 50);
        glutMainLoop();
    }
    else {
        srand((unsigned int)time(NULL));
        Parking park(size, num);
        for (i = 0; i < num; i++){
            park.enterticket(i);
            usleep(3000000*((unsigned int)rand()%2+1));
        }
        cout << "After some time..." << endl;
        for (int j = 0; j < num; j++){
            sleep(((unsigned int)rand()) % 4);
            park.exitticket(j);
        }
    }
    return 0;
}