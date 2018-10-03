#include <stdio.h>
#include <string.h>
#include <iostream>
#include "yssimplesound.h"
#include "fssimplewindow.h"

using namespace std;

void visualizeSound(YsSoundPlayer::SoundData wav);

int main()
{
	YsSoundPlayer player;
	YsSoundPlayer::SoundData wav;

	char fName[256];
	printf("WAV File Name:");
	cin >> fName;

	if (YSOK != wav.LoadWav(fName))
	{
		printf("Failed to read %s\n", fName);
		return 1;
	}

	player.Start();
	player.PlayOneShot(wav);
	while (YSTRUE == player.IsPlaying(wav))
	{
		player.KeepPlaying();
	}

	player.End();

	//visualizeSound(wav);

	return 0;
}

void visualizeSound(YsSoundPlayer::SoundData wav)
{
	FsOpenWindow(0, 0, 800, 600, 1);

	int ptr0 = 0;
	int range = wav.GetNumSamplePerChannel();
	int rate = wav.PlayBackRate();
	cout << "Numb of data points is " << range << ", Number of channels is " 
		<< wav.GetNumChannel() << ", Rate is " << rate << endl;

	bool continueLoop = true;
	while (continueLoop)
	{
		FsPollDevice();
		auto key = FsInkey();
		switch (key){
		case FSKEY_ESC:
			continueLoop = false;
			break;
		case FSKEY_Z:
			range /= 2;
			if (range < 500)
				range = 500;
			break;
		case FSKEY_M:
			range *= 2;
			if (wav.GetNumSamplePerChannel() < range)
				range = wav.GetNumSamplePerChannel();
			break;
		case FSKEY_LEFT:
			ptr0 += range / 4;
			break;
		case FSKEY_RIGHT:
			ptr0 -= range / 4;
			break;
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		int wid, hei;
		FsGetWindowSize(wid, hei);
		for (int channel = 0; channel < wav.GetNumChannel(); ++channel)
		{
			switch (channel)
			{
			case 0:
				glColor3ub(0, 0, 255);
				break;
			case 1:
				glColor3ub(255, 0, 0);
				break;
			}
			glBegin(GL_LINE_STRIP);
			long long timePtr;
			int y;
			for (long long int x = 0; x < wid; ++x)
			{
				timePtr = ptr0 + x * range / wid;

				y = wav.GetSignedValue16(channel, timePtr);
				y = hei / 2 - y * (hei / 5) / 32767;

				glVertex2i(x, y);
			}
			glEnd();
		}

		FsSwapBuffers();
		FsSleep(10);
	}
	FsCloseWindow();

}