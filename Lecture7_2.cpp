// falingBall A

int main(void)
{
    double m,x,y,vx,vy,dt;

    m=1.0;

    x=0.0;
    y=50.0;

    vx=10.0;
    vy=0.0;

    dt=0.02;

    FsOpenWindow(16,16,800,600,1);

    while(y>0.0)
    {
        move(x,y,vx,vy,m,dt);

        glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
        glColor3ub(0,0,0);
        drawCircle(400+(x*10.0),600-y*10.0,10,1);
        FsSwapBuffers();

        FsSleep(10);
    }
}