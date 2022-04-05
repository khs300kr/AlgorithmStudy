#include "pch.h"
#include "ConsoleHelper.h"
#include "Board.h"
#include "Player.h"

Board board;
Player player;

int main()
{
	::srand(static_cast<unsigned>(time(nullptr)));

	board.Init(25, &player);
	player.Init(&board);

	uint64 lastTick = 0;

	while (true)
	{
#pragma region frame manager
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = ::GetTickCount64() - lastTick;
		lastTick = currentTick;
		// 고정 프레임

#pragma  endregion

		// input

		// logic
		player.Update(deltaTick);

		// rendering(output)
		board.Render();

	}
}