#pragma once
#include "Scene.h"
#include "Framebuffer.h"
#include <memory>
#include <SDL.h>

class ExampleScene : public Scene
{
public:
	bool Initialize() override;
	void Update() override;
	void Draw() override;

public:
	std::unique_ptr<Framebuffer> m_framebuffer;
};

