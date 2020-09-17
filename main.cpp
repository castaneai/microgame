#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(640, 480, 32, 30);
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	SetMainWindowText("microgame");

	int bgm = LoadSoundMem("BGM/hohoemi.mp3");
	if (bgm == -1)
	{
		MessageBox(NULL, "failed to load BGM/hohoemi.mp3", "Error", MB_OK);
	}
	PlaySoundMem(bgm, DX_PLAYTYPE_LOOP, TRUE);

	char i = 0;
	while (true)
	{
		if (ScreenFlip() == -1) break;
		if (ClearDrawScreen() == -1) break;
		if (ProcessMessage() == -1) break;

		DrawBox(0, 0, 300, 300, GetColor(i, i, i), TRUE);
		i++;
	}
	DxLib_End();
	return 0;
}
