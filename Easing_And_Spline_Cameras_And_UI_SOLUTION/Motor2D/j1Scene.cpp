#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Scene.h"
#include "j1Gui.h"
#include "j1EasingAndSplines.h"

#include "UI_Button.h"
#include "j1Image.h"

#include "p2SString.h"

#include "..//Brofiler/Brofiler.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");

}



// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake(pugi::xml_node& config)
{

	LOG("Loading Scene");
	pugi::xml_node map;
	pugi::xml_document n;

	for (map= config.child("map"); map; map = map.next_sibling("map"))
	{
		p2SString* lvl = new p2SString();

		lvl->create(map.attribute("name").as_string());
		map_list.add(lvl->GetString());

	}

	return true;

}

// Called before the first frame

// Loads map and audio
bool j1Scene::Start()
{
	if (App->map->active==true) {

		current_map = map_list.start->data;
	
		App->map->Load(current_map.GetString());

	}

	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate(float dt)
{
	BROFILER_CATEGORY("PreUpdate scene", Profiler::Color::DarkSalmon);

	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	BROFILER_CATEGORY("Update scene", Profiler::Color::Salmon);

	static char score_timer[6];
	
	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT) {
		App->render->camera.x -= 10;
	}

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT) {
		if (App->render->camera.x <= -5)
		App->render->camera.x += 10;
	}

	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT) {
		if(App->render->camera.y <= -5)
		App->render->camera.y += 10;
	}

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT) {
		if (App->render->camera.y <= 300)
		App->render->camera.y -= 10;
	}

	//DEBUG SPLINES
	{

		if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE);
			
		}

		if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_QUAD);
		}

		if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_OUT_QUAD);
		}

		if (App->input->GetKey(SDL_SCANCODE_4) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_OUT_QUAD);
		}

		if (App->input->GetKey(SDL_SCANCODE_5) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_CUBIC);
		}

		if (App->input->GetKey(SDL_SCANCODE_6) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_OUT_CUBIC);
		}

		if (App->input->GetKey(SDL_SCANCODE_7) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_OUT_CUBIC);
		}

		if (App->input->GetKey(SDL_SCANCODE_8) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_QUART);
		}

		if (App->input->GetKey(SDL_SCANCODE_9) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_OUT_QUART);
		}

		if (App->input->GetKey(SDL_SCANCODE_0) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_OUT_QUART);
		}

		if (App->input->GetKey(SDL_SCANCODE_KP_1) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_QUINT);
		}

		if (App->input->GetKey(SDL_SCANCODE_KP_2) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_OUT_QUINT);
		}

		if (App->input->GetKey(SDL_SCANCODE_KP_3) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_OUT_QUINT);
		}

		if (App->input->GetKey(SDL_SCANCODE_KP_4) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_SINE);
		}

		if (App->input->GetKey(SDL_SCANCODE_KP_5) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_OUT_SINE);
		}

		if (App->input->GetKey(SDL_SCANCODE_KP_6) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_OUT_SINE);
		}

		if (App->input->GetKey(SDL_SCANCODE_KP_7) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_EXPO);
		}

		if (App->input->GetKey(SDL_SCANCODE_KP_8) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_OUT_EXPO);
		}

		if (App->input->GetKey(SDL_SCANCODE_KP_9) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_OUT_EXPO);
		}

		if (App->input->GetKey(SDL_SCANCODE_KP_0) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_CIRC);
		}

		if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_OUT_CIRC);
		}

		if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_OUT_CIRC);
		}

		if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_OUT_BOUNCE);
		}

		if (App->input->GetKey(SDL_SCANCODE_F4) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_BACK);
		}

		if (App->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_OUT_BACK);
		}

		if (App->input->GetKey(SDL_SCANCODE_F6) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_IN_OUT_BACK);
		}

		if (App->input->GetKey(SDL_SCANCODE_F7) == KEY_DOWN) {
			App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 6000, 3000, Spline_Type::EASE_OUT_ELASTIC);
		}
	
	}
	
	App->map->Draw();

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate(float dt)
{
	BROFILER_CATEGORY("PreUpdate scene", Profiler::Color::LightSalmon);
	bool ret = true;

	if (count == 0) {
		button = (UI_Button*)App->gui->CreateButton(1000, 250, BUTTON, { 1049,515,89,89 }, { 455,513,89,89 }, { 451,396,89,89  }, NULL, this);
		count++;
	}

	if (App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN) {
		ret = false;
	}

	return ret;

}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");
	return true;
}

//load function
bool j1Scene::Load(pugi::xml_node& data)
{
	LOG("Loading Scene state");
	current_map = data.child("scene").attribute("name").as_string();					//check which map have to be loaded and load it
	
	return true;
}

bool j1Scene::Save(pugi::xml_node& data) const
{
	LOG("Saving Scene state");
	pugi::xml_node scene = data.append_child("scene");
	scene.append_attribute("name") = current_map.GetString();

	return true;
}

