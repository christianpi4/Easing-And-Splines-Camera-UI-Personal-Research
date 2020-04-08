#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"
#include "j1Timer.h"

struct SDL_Texture;
enum UI_Type;
class j1Image;
class UI_Button;

class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

	// Called before render is available
	bool Awake(pugi::xml_node& config);

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate(float dt);

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate(float dt);

	// Called before quitting
	bool CleanUp();

	bool Load(pugi::xml_node &node);
	bool Save(pugi::xml_node &node)const;

	p2SString current_map;

private:

	p2List<p2SString> map_list;

public:
	
	SDL_Texture* debug_tex;

	UI_Button* button = nullptr;
	int count = 0;

};

#endif // __j1SCENE_H__