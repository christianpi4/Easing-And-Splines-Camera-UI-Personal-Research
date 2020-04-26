#include "p2Log.h"
#include "UI_Button.h"
#include "j1Gui.h"
#include "UI_element.h"
#include "j1Render.h"
#include "j1Audio.h"
#include "j1Scene.h"
#include "j1EasingAndSplines.h"

#include "..//Brofiler/Brofiler.h"

UI_Button::UI_Button(int x, int y, UI_Type type, SDL_Rect idle, SDL_Rect hover, SDL_Rect click, UI_element * parent, j1Module * Observer) : UI_element(x, y, type, parent, Observer)
{
	this->pos.x = x;
	this->pos.y = y;
	this->Button_idle = idle;
	this->Button_hover = hover;
	this->Button_click = click;

	t = type;

	dimensions = idle;
	click_fx = App->audio->LoadFx("audio/fx/Button_click.wav");
	hover_fx = App->audio->LoadFx("audio/fx/Button_hover.wav");
}

bool UI_Button::CleanUp()
{
	return true;
}

bool UI_Button::Draw()
{
	texture = App->gui->GetAtlas();

	if (texture != nullptr)
	{
		App->render->Blit_UI(texture, pos.x, pos.y, &dimensions, SDL_FLIP_NONE, 0.0f);
	}

	if (App->gui->debug_UI == true) {

		SDL_Rect b{ pos.x, pos.y, Button_click.w, Button_click.h };

		App->render->DrawQuad(b, 255, 0, 0, 255, false, 0.0f);
	}

	return true;
}

bool UI_Button::Update(float dt)
{
	BROFILER_CATEGORY("PreUpdate UI_element", Profiler::Color::Black);

	//if cursor is inside button rectangle
	if (IsIntersection() == true) {
		
		counter++;

		//rect is button hover
		dimensions = Button_hover;

		if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN) {

			//rect is button pressed
			dimensions = Button_click;

		}

		else {
			
		}

	}

	else {
		dimensions = Button_idle;
		
	}

	return true;

}
