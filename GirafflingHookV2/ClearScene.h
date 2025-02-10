#pragma once
#include "GameScene.h"

class ClearScene : public GameScene
{
public:
	ClearScene();
	~ClearScene(); // âíE

	void Init()       override;
	void Update()     override;
	void Draw() const override;
	void End()        override; // TransMigrationópä÷êî

	void      SetTotalScore_(int);
	void       SetClearTime_(int);
	void  SetGirafferingNum_(int);

private:
	int         totalScore_;
	int          clearTime_;
	int     girafferingNum_;
};
