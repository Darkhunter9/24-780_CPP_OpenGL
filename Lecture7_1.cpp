// drawCircle() code

void drawCircle(int cx,int cy, int rad, bool fill)
{
    const double PI=3.1415927;

    if(fill)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_LINE_LOOP);

    int i;
    for(i=0; i<64; i++) {
        double angle=(double)i * PI / 32.0;
        double x=(double)cx+cos(angle)*(double)rad;
        double y=(double)cy+sin(angle)*(double)rad;
        glVertex2d(x,y);
    }

    glEnd();
}