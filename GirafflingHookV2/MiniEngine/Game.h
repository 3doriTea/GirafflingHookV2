#pragma once
#include <Windows.h>

class Game
{
public:
	Game();
	virtual ~Game();

	/// <summary>
	/// �Q�[�������s����
	/// </summary>
	/// <typeparam name="GameT">�Q�[���̌^</typeparam>
	/// <returns>���s����</returns>
	template<typename GameT>
	static HRESULT Run()
	{
		if (running_)
		{
			return S_FALSE;
		}
		running_ = new GameT{};

		running_->Init();
		while (true)
		{
			if (running_->toExit_)
			{
				break;
			}
			running_->Update();
		}
		running_->End();
		delete running_;

		return S_OK;
	}
	/// <summary>
	/// �Q�[�����I������
	/// </summary>
	static void Exit();

protected:
	virtual void Update() = 0;
	virtual void Init() = 0;
	virtual void End() = 0;

private:
	bool toExit_;
	static Game* running_;
};
