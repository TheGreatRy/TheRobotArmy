#include "ExampleScene.h"

bool ExampleScene::Initialize()
{
	m_renderer.Initialize();
	m_renderer.CreateWindow("Example", 800, 600);

	m_input.Initialize();
	m_input.Update();

	m_framebuffer = std::make_unique<Framebuffer>(m_renderer, m_renderer.m_width, m_renderer.m_height);

	return true;
}

void ExampleScene::Update()
{
	m_time.Tick();
	m_input.Update();

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_quit = true;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		{
			m_quit = true;
		}
	}
}

void ExampleScene::Draw()
{
	m_framebuffer->Clear(color_t{ 0, 0, 0, 255 });

	
	for (int i = 0; i < 1000; i++)
	{
		m_framebuffer->DrawPoint(rand() % m_renderer.m_width, rand() % m_renderer.m_height, color_t{255,255,255,255});
	}

	// update framebuffer
	m_framebuffer->Update();

	// show screen
	m_renderer = *m_framebuffer;
	SDL_RenderPresent(m_renderer.m_renderer);
}
