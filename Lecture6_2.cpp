int main()
{
    FsOpenWindow(16,16,800,600,1);
    bool terminate = false;
	int stepSize = 10;
    int playerX=400, playerY=580;
    int key;
    while(!terminate) {
        FsPollDevice();
        key=FsInkey();

        switch(key) {
        case FSKEY_ESC:
            terminate=true;
            break;
        case FSKEY_LEFT:
            playerX-= stepSize;
            break;
        case FSKEY_RIGHT:
            playerX+= stepSize;
            break;
        }

        glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
        drawPlayer(playerX,playerY);
        FsSwapBuffers();
        FsSleep(20);
    }

    return 0;
}