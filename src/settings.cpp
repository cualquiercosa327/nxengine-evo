
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include "settings.h"
#include "input.h"
#include "common/stat.h"

const uint32_t SETTINGS_VERSION = ( ( '0' << 24 ) + ( 'N' << 16 ) + ( 'W' << 8 ) + 'C' );		// serves as both a version and magic

Settings normal_settings;
Settings *settings = &normal_settings;

static bool tryload(Settings *setfile)
{
FILE *fp;

	char* basepath = SDL_GetPrefPath("nxengine", "nxengine-evo");
	std::string path = std::string(basepath) + "settings.dat";
	SDL_free(basepath);

	stat("Loading settings...");
	
	fp = fopen(path.c_str(), "rb");
	if (!fp)
	{
		stat("Couldn't open file %s.", path.c_str());
		return 1;
	}
	
	setfile->version = 0;
	fread(setfile, sizeof(Settings), 1, fp);
	if (setfile->version != SETTINGS_VERSION)
	{
		stat("Wrong settings version %04x.", setfile->version);
		fclose(fp);
		return 1;
	}
	
	fclose(fp);
	return 0;
}

bool settings_load(Settings *setfile)
{
	if (!setfile) setfile = &normal_settings;
	
	if (tryload(settings))
	{
		stat("No saved settings; using defaults.");
		
		memset(setfile, 0, sizeof(Settings));
		setfile->resolution = 2;		// 640x480 Windowed, should be safe value
		setfile->last_save_slot = 0;
		setfile->multisave = true;
		setfile->fullscreen = false;
		
		setfile->enable_debug_keys = false;
		setfile->sound_enabled = true;
		setfile->music_enabled = 1;	// both Boss and Regular music
		setfile->rumble = false;
		setfile->framerate = false;
		
		return 1;
	}
	else
	{
		input_set_mappings(settings->input_mappings);
	}
	
	return 0;
}

/*
void c------------------------------() {}
*/


bool settings_save(Settings *setfile)
{
FILE *fp;

	char* basepath = SDL_GetPrefPath("nxengine", "nxengine-evo");
	std::string path = std::string(basepath) + "settings.dat";
	SDL_free(basepath);

	if (!setfile)
		setfile = &normal_settings;
	
	stat("Writing settings...");
	fp = fopen(path.c_str(), "wb");
	if (!fp)
	{
		stat("Couldn't open file %s.", path.c_str());
		return 1;
	}
	
	for(int i=0;i<INPUT_COUNT;i++)
		setfile->input_mappings[i] = input_get_mapping(i);
	
	setfile->version = SETTINGS_VERSION;
	fwrite(setfile, sizeof(Settings), 1, fp);
	
	fclose(fp);
	return 0;
}




