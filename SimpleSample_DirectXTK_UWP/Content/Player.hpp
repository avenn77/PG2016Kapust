//For educational use only
//NOT TO BE USED IN COMMERCIAL OR SCHOOL PROJECTS

#pragma once

#include <wrl.h>


//#include "..\Common\DirectXHelper.h"	// For ThrowIfaFailed and ReadDataAsync

#include <Content\AnimatedTexture.h>
#include <SpriteBatch.h>

#include <DirectXMath.h>
#include <SimpleMath.h>
#include "..\Common\\SpriteSheet.hpp"


class Player
{
public:
	Player(std::shared_ptr<SpriteSheet> playerSpriteSheet) : framesOfAnimation(4), framesToBeShownPerSecond(4)
	{

		//positions.push_back(DirectX::XMFLOAT2(300, 512));

		positions.push_back(DirectX::XMFLOAT2(250, 500));
		positions.push_back(DirectX::XMFLOAT2(350, 500));

		positions.push_back(DirectX::XMFLOAT2(250, 350));
		positions.push_back(DirectX::XMFLOAT2(350, 350));

		positions.push_back(DirectX::XMFLOAT2(300, 550));

		positions.push_back(DirectX::XMFLOAT2(250, 430));
		positions.push_back(DirectX::XMFLOAT2(350, 430));

		positions.push_back(DirectX::XMFLOAT2(270, 480));
		positions.push_back(DirectX::XMFLOAT2(330, 480));

		positions.push_back(DirectX::XMFLOAT2(300, 512));
		
		//Instantiate animation here
		spriteSheet = playerSpriteSheet;

		//parts.push_back(spriteSheet->Find(L"Mech5"));
		parts.push_back(spriteSheet->Find(L"Mech5_arm_l"));
		parts.push_back(spriteSheet->Find(L"Mech5_arm_r"));
		parts.push_back(spriteSheet->Find(L"Mech5_foot_l"));
		parts.push_back(spriteSheet->Find(L"Mech5_foot_r"));
		parts.push_back(spriteSheet->Find(L"Mech5_head"));
		parts.push_back(spriteSheet->Find(L"Mech5_leg_l"));
		parts.push_back(spriteSheet->Find(L"Mech5_leg_r"));
		parts.push_back(spriteSheet->Find(L"Mech5_shoulder_l"));
		parts.push_back(spriteSheet->Find(L"Mech5_shoulder_r"));
		parts.push_back(spriteSheet->Find(L"Mech5_torso"));
		
		

		float rotation = 0.f;
		float scale = 3.f;
		//animation.reset(new AnimatedTexture(DirectX::XMFLOAT2(0.f, 0.f), rotation, scale, 0.5f));
		//animation->Load(texture.Get(), framesOfAnimation, framesToBeShownPerSecond);

		width = textureWidth = parts[0]->size.x;
		height = textureHeight = parts[0]->size.y;

		rectangle.X = position.x;
		rectangle.Y = position.y;
		rectangle.Height = height;
		rectangle.Width = width;
		
	}

	void setPosition(DirectX::XMFLOAT2 newPosition)
	{
		//set the position
		position = newPosition;
		updateBoundingRect();
	}

	void setPosition(float posX, float posY)
	{
		position.x = posX;
		position.y = posY;
		updateBoundingRect();
	}

	DirectX::XMFLOAT2 getPosition()
	{
		return position; 
	}

	void Update(float elapsed)
	{

		//update the animation of the player
		//animation->Update(elapsed);
	}

	void Draw(DirectX::SpriteBatch* batch)
	{
		//animation->Draw(batch, position);
		for (size_t i = 0; i < parts.size(); i++)
			spriteSheet->Draw(batch, *parts[i], parts[i]->origin);
	}


public:
	Windows::Foundation::Rect							rectangle;

private:
	void updateBoundingRect()
	{
		//TODO: proper updating when rotating player object
		rectangle.X = position.x;
		rectangle.Y = position.y;
		rectangle.Height = height;
		rectangle.Width = width;
	}

	Windows::Foundation::Rect getBoundingRect()
	{
		return rectangle;
	}

	std::vector<DirectX::XMFLOAT2>						positions;
	DirectX::XMFLOAT2									position;

	int													width;
	int													height;
	int													textureWidth;
	int													textureHeight;
	int													framesOfAnimation;
	int													framesToBeShownPerSecond;

	//Texture and animation
	std::vector<const SpriteSheet::SpriteFrame*>		parts;

	std::shared_ptr <SpriteSheet>						spriteSheet;
	//std::unique_ptr<AnimatedTexture>					animation;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>    mTexture;

};